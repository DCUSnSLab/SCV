"""녹화 탭 — 프로파일 선택, 사전 점검, 시작·정지, 토픽 상태, 마커."""
from __future__ import annotations

import time

from PyQt5.QtCore import Qt, QTimer, pyqtSignal
from PyQt5.QtGui import QBrush, QColor, QKeySequence
from PyQt5.QtWidgets import (QAbstractItemView, QComboBox, QFormLayout, QGroupBox, QHBoxLayout,
                             QHeaderView, QLabel, QLineEdit, QListWidget, QListWidgetItem,
                             QMessageBox, QPushButton, QShortcut, QSizePolicy, QTableWidget,
                             QTableWidgetItem, QVBoxLayout, QWidget)

from ..core.command import estimate_mb_per_min
from ..core.preflight import ERROR, WARN, disk_free_gb, run_checks
from ..core.profile import ProfileError
from .common import (LEVEL_COLOR, LEVEL_ICON, STATUS_BG, STATUS_TEXT, fmt_bytes, fmt_duration,
                     fmt_kb, fmt_minutes, fmt_num)
from .context import AppContext
from .controller import IDLE, RECORDING, STARTING, STOPPING, WAITING, RecordingController
from .lidar_convert_button import LidarConvertButton
from .ros_bridge import RosBridge

COLUMNS = ['토픽', '기준 Hz', '현재 Hz', '마지막 수신', '크기 KB', '상태', '값 검사', '최근 변경']
CHECK_COL = COLUMNS.index('값 검사')

MARKER_BUTTONS = [
    ('F1', 'intervention', '개입'),
    ('F2', 'anomaly', '이상 동작'),
]


def check_text(check: dict | None) -> str:
    """값 검사 칸: 문제가 있으면 문제, 없으면 참고값."""
    if not check:
        return ''
    issues = check.get('issues') or []
    if issues:
        return '⚠ ' + issues[0] + (f' 외 {len(issues) - 1}건' if len(issues) > 1 else '')
    return ' · '.join(check.get('values') or [])


def check_tooltip(check: dict | None) -> str:
    if not check:
        return '값 검사 없음 (C++ 감시 노드에서만)'
    lines = [f'⚠ {x}' for x in check.get('issues') or []] + list(check.get('values') or [])
    return '\n'.join(lines) or '-'


class DragTable(QTableWidget):
    """행을 끌어다 놓아 순서를 바꾸는 표. 실제 순서는 RecordTab이 관리한다."""
    row_moved = pyqtSignal(int, int)          # (원래 행, 놓은 위치)

    def __init__(self, rows: int, cols: int):
        super().__init__(rows, cols)
        self.setSelectionBehavior(QAbstractItemView.SelectRows)
        self.setSelectionMode(QAbstractItemView.SingleSelection)
        self.setDragEnabled(True)
        self.setAcceptDrops(True)
        self.viewport().setAcceptDrops(True)
        self.setDragDropMode(QAbstractItemView.InternalMove)
        self.setDropIndicatorShown(True)

    def dropEvent(self, event) -> None:
        src = self.currentRow()
        dst = self.rowAt(event.pos().y())
        if dst < 0:
            dst = self.rowCount() - 1
        elif self.dropIndicatorPosition() == QAbstractItemView.BelowItem:
            dst += 1
        # 기본 동작(셀 단위 이동)은 막고 순서만 알린다
        event.setDropAction(Qt.IgnoreAction)
        event.accept()
        if src >= 0 and dst != src:
            self.row_moved.emit(src, dst)


class RecordTab(QWidget):
    def __init__(self, ctx: AppContext, controller: RecordingController, bridge: RosBridge):
        super().__init__()
        self.ctx = ctx
        self.ctl = controller
        self.bridge = bridge
        self._segment_open = False
        self._order: list[str] = []                 # 표에 보이는 토픽 순서
        self._topic_data: dict[str, dict] = {}      # 마지막 health 값
        self._prev_status: dict[str, str] = {}      # 상태 변화 감지용
        self._changes: dict[str, str] = {}          # 최근 변경 표시 문구
        self._shown: dict[str, tuple] = {}          # 행별 마지막 표시값 (바뀐 칸만 갱신)
        self._status_color = ''
        self._last_checks: list = []

        root = QVBoxLayout(self)

        # ---- 프로파일·라벨 ------------------------------------------------
        form_box = QGroupBox('녹화 설정')
        box_lay = QVBoxLayout(form_box)
        form = QFormLayout()
        form2 = QFormLayout()
        self.profile_combo = QComboBox()
        self.profile_combo.currentTextChanged.connect(self._on_profile_changed)
        self.profile_desc = QLabel()
        self.profile_desc.setWordWrap(True)
        self.profile_desc.setStyleSheet('color: #555')
        self.label_edit = QLineEdit()
        self.label_edit.setPlaceholderText('세션 폴더 이름에 붙음 (예: n026)')
        self.notes_edit = QLineEdit()
        self.notes_edit.setPlaceholderText('이번 주행에서 바꾼 것, 목적 등')
        # 줄바꿈 QLabel을 QFormLayout 안에 두면 높이를 과하게 잡아서 밖으로 뺀다
        form.addRow('프로파일', self.profile_combo)
        form2.addRow('라벨', self.label_edit)
        form2.addRow('메모', self.notes_edit)
        box_lay.addLayout(form)
        box_lay.addWidget(self.profile_desc)
        box_lay.addLayout(form2)
        form_box.setSizePolicy(QSizePolicy.Preferred, QSizePolicy.Maximum)
        root.addWidget(form_box)

        # ---- 점검 + 시작 버튼 --------------------------------------------
        mid = QHBoxLayout()
        self.checks = QListWidget()
        self.checks.setMaximumHeight(110)
        self.checks.setSelectionMode(QAbstractItemView.NoSelection)
        mid.addWidget(self.checks, 3)
        btn_col = QVBoxLayout()
        self.start_btn = QPushButton('● 녹화 시작')
        self.start_btn.setMinimumHeight(56)
        f = self.start_btn.font()
        f.setPointSize(f.pointSize() + 3)
        f.setBold(True)
        self.start_btn.setFont(f)
        self.start_btn.clicked.connect(self._on_start_stop)
        self.wait_label = QLabel()
        self.wait_label.setWordWrap(True)
        wait_btns = QHBoxLayout()
        self.now_btn = QPushButton('지금 시작')
        self.now_btn.clicked.connect(self.ctl.start_now)
        self.cancel_btn = QPushButton('취소')
        self.cancel_btn.clicked.connect(self.ctl.cancel_wait)
        wait_btns.addWidget(self.now_btn)
        wait_btns.addWidget(self.cancel_btn)
        # 녹화가 끝난 세션의 LiDAR 패킷 → 포인트 변환 (시작 버튼의 절반 높이)
        self.convert_btn = LidarConvertButton(ctx, controller)
        self.convert_btn.setFixedHeight(self.start_btn.minimumHeight() // 2)
        btn_col.addWidget(self.start_btn)
        btn_col.addWidget(self.convert_btn)
        btn_col.addWidget(self.wait_label)
        btn_col.addLayout(wait_btns)
        btn_col.addStretch()
        mid.addLayout(btn_col, 1)
        root.addLayout(mid)

        # ---- 상태 줄 -------------------------------------------------------
        self.status_label = QLabel()
        sf = self.status_label.font()
        sf.setPointSize(sf.pointSize() + 1)
        sf.setBold(True)
        self.status_label.setFont(sf)
        self.status_label.setStyleSheet('padding: 6px; border-radius: 4px; background: #eeeeee')
        root.addWidget(self.status_label)

        # ---- 토픽 표 -------------------------------------------------------
        self.table = DragTable(0, len(COLUMNS))
        self.table.setHorizontalHeaderLabels(COLUMNS)
        self.table.verticalHeader().setVisible(False)
        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.table.setToolTip('행을 끌어다 놓아 순서를 바꿀 수 있습니다.\n녹화 중 상태가 바뀐 토픽은 맨 위로 올라갑니다.')
        self.table.row_moved.connect(self._on_row_moved)
        hdr = self.table.horizontalHeader()
        hdr.setSectionResizeMode(0, QHeaderView.Stretch)
        for i in range(1, len(COLUMNS)):
            hdr.setSectionResizeMode(i, QHeaderView.ResizeToContents)
        hdr.setSectionResizeMode(CHECK_COL, QHeaderView.Interactive)   # 문구가 길어 고정 폭, 전체는 툴팁
        hdr.resizeSection(CHECK_COL, 260)
        root.addWidget(self.table, 1)

        # ---- 마커 ----------------------------------------------------------
        marker_box = QGroupBox('마커 (녹화 중)')
        mlay = QVBoxLayout(marker_box)
        row = QHBoxLayout()
        self.marker_btns: list[QPushButton] = []
        for key, kind, text in MARKER_BUTTONS:
            b = QPushButton(f'[{key}] {text}')
            b.clicked.connect(lambda _=False, k=kind, t=text: self._marker(k, t))
            QShortcut(QKeySequence(key), self, activated=lambda k=kind, t=text: self._marker(k, t),
                      context=Qt.ApplicationShortcut)
            row.addWidget(b)
            self.marker_btns.append(b)
        self.segment_btn = QPushButton('[F3] 구간 시작')
        self.segment_btn.clicked.connect(self._segment)
        QShortcut(QKeySequence('F3'), self, activated=self._segment, context=Qt.ApplicationShortcut)
        row.addWidget(self.segment_btn)
        self.marker_edit = QLineEdit()
        self.marker_edit.setPlaceholderText('마커 내용 입력 후 Enter')
        self.marker_edit.returnPressed.connect(self._free_marker)
        row.addWidget(self.marker_edit, 1)
        mlay.addLayout(row)
        self.marker_list = QListWidget()
        self.marker_list.setMaximumHeight(80)
        mlay.addWidget(self.marker_list)
        marker_box.setSizePolicy(QSizePolicy.Preferred, QSizePolicy.Maximum)
        root.addWidget(marker_box)

        # ---- 연결 ----------------------------------------------------------
        self.ctl.state_changed.connect(self._on_state)
        self.ctl.health_updated.connect(self._on_health)
        self.ctl.waiting_progress.connect(self.wait_label.setText)
        self.ctl.ready_timeout.connect(self._on_ready_timeout)
        self.ctl.session_started.connect(self._on_session_started)
        ctx.profiles_changed.connect(self.reload_profiles)
        ctx.catalog_changed.connect(lambda: self._on_profile_changed(self.profile_combo.currentText()))
        self._timer = QTimer(self, interval=1000)
        self._timer.timeout.connect(self._refresh_checks)
        self._timer.start()

        self.reload_profiles()
        self._on_state(self.ctl.state)

    # ---- 프로파일 -------------------------------------------------------
    def reload_profiles(self) -> None:
        current = self.profile_combo.currentText() or 'drive_standard'
        self.profile_combo.blockSignals(True)
        self.profile_combo.clear()
        names = self.ctx.profile_names()
        self.profile_combo.addItems(names)
        if current in names:
            self.profile_combo.setCurrentText(current)
        self.profile_combo.blockSignals(False)
        self._on_profile_changed(self.profile_combo.currentText())

    def _on_profile_changed(self, name: str) -> None:
        if not name:
            return
        try:
            resolved = self.ctx.resolve(name)
        except (ProfileError, ValueError) as e:
            self.profile_desc.setText(f'<span style="color:#c62828">프로파일 오류: {e}</span>')
            self.ctl.set_profile(None)
            return
        mb, unknown = estimate_mb_per_min(resolved, self.ctx.catalog)
        o = resolved.options
        est = f'예상 약 {mb:,.0f} MB/분' + (f' (크기 미상 {len(unknown)}개 제외)' if unknown else '')
        self.profile_desc.setText(
            f'{resolved.description}<br><span style="color:#777">토픽 {len(resolved.topics) + len(resolved.unknown_topics)}개 · '
            f'{o.storage} · 압축 {o.compression} · 분할 {o.split_duration_sec}s · {est}'
            f'{" · 상속: " + " → ".join(resolved.chain[1:]) if len(resolved.chain) > 1 else ""}</span>')
        self.ctl.set_profile(resolved)
        self._build_rows(resolved.topics + resolved.unknown_topics)

    def _build_rows(self, topics: list[str]) -> None:
        """표에 보일 토픽 설정. 이미 있던 토픽은 사용자가 정한 순서를 유지한다."""
        keep = [x for x in self._order if x in topics]
        self._order = keep + [x for x in topics if x not in keep]
        self._topic_data = {k: v for k, v in self._topic_data.items() if k in topics}
        self._changes = {k: v for k, v in self._changes.items() if k in topics}
        self._render()

    def _on_row_moved(self, src: int, dst: int) -> None:
        name = self._order.pop(src)
        self._order.insert(dst - 1 if dst > src else dst, name)
        self._render()
        self.table.clearSelection()           # 선택 강조가 상태 색을 가리지 않게

    def _render(self) -> None:
        """행 구조를 새로 만든다 — 순서·토픽이 바뀔 때만. 값 갱신은 _refresh_row."""
        self.table.setUpdatesEnabled(False)
        self.table.setRowCount(len(self._order))
        self._shown.clear()
        for i, name in enumerate(self._order):
            spec = self.ctx.catalog.topic(name)
            item = QTableWidgetItem(name)
            tips = []
            if spec and spec.required:
                f = item.font()
                f.setBold(True)
                item.setFont(f)
                tips.append('필수 토픽')
            if spec and spec.monitor_via:
                tips.append(f'주기는 {spec.monitor_via}로 측정')
            elif spec and spec.heavy:
                tips.append('큰 토픽을 직접 구독해 측정 (reliable)')
            if spec is None:
                tips.append('카탈로그에 없음 — 기준 없음')
            item.setToolTip('\n'.join(tips))
            self.table.setItem(i, 0, item)
            for c in range(1, len(COLUMNS)):
                self.table.setItem(i, c, QTableWidgetItem())
            self._refresh_row(i, name)
        self.table.setUpdatesEnabled(True)

    def _row_values(self, name: str) -> tuple:
        spec = self.ctx.catalog.topic(name)
        t = self._topic_data.get(name)
        if t is None:
            return (fmt_num(spec.hz if spec else None), '-', '-', '-', '-', '', self._changes.get(name, '')), None
        status = t.get('status', '')
        return (fmt_num(t.get('expected')), fmt_num(t.get('hz')),
                '-' if t.get('age') is None else f'{t["age"]:.1f} s',
                fmt_kb(t.get('size_kb')), STATUS_TEXT.get(status, status), check_text(t.get('check')),
                self._changes.get(name, '')), status

    def _refresh_row(self, row: int, name: str) -> None:
        """값이 바뀐 칸만 고친다 (매초 표 전체를 새로 만들지 않음)."""
        values, status = self._row_values(name)
        if self._shown.get(name) == (values, status):
            return
        old = self._shown.get(name)
        self._shown[name] = (values, status)
        if old is None or old[1] != status:
            bg = QBrush(STATUS_BG.get(status, QColor('white'))) if status is not None else QBrush()
            for c in range(len(COLUMNS)):
                item = self.table.item(row, c)
                if item is not None:
                    item.setBackground(bg)
        for c, v in enumerate(values, start=1):
            item = self.table.item(row, c)
            if item is not None and (old is None or old[0][c - 1] != v):
                item.setText(v)
                if c == CHECK_COL:
                    item.setToolTip(check_tooltip((self._topic_data.get(name) or {}).get('check')))

    # ---- 상태 갱신 -----------------------------------------------------
    def _on_health(self, h: dict) -> None:
        recording = self.ctl.state == RECORDING
        moved = []
        for name, t in h.get('topics', {}).items():
            if name not in self._order:
                continue
            self._topic_data[name] = t
            status = t.get('status', '')
            prev = self._prev_status.get(name)
            self._prev_status[name] = status
            # 녹화 중 상태가 바뀐 토픽 → 맨 위로 (첫 값·수신 대기에서 넘어온 건 기준값이라 제외)
            if recording and prev is not None and prev != status and prev != 'waiting':
                self._changes[name] = (f'{time.strftime("%H:%M:%S")}  '
                                       f'{STATUS_TEXT.get(prev, prev)} → {STATUS_TEXT.get(status, status)}')
                moved.append(name)
        if moved:
            for name in moved:
                self._order.remove(name)
                self._order.insert(0, name)
            self._render()
        else:
            self.table.setUpdatesEnabled(False)
            for i, name in enumerate(self._order):
                self._refresh_row(i, name)
            self.table.setUpdatesEnabled(True)
        self._update_status_line()

    def _update_status_line(self) -> None:
        h = self.ctl.latest_health or {}
        disk = h.get('disk', {})
        free = disk.get('free_gb')
        if free is None:
            free = disk_free_gb(self.ctx.settings.output_path)
        disk_txt = '-' if free is None else f'{free:.0f} GB'
        st = self.ctl.state
        if st == RECORDING:
            bag = h.get('bag', {})
            alive = h.get('recorder', {}).get('alive', True)
            text = (f'● 녹화 중  {fmt_duration(h.get("elapsed_sec"))}   {fmt_bytes(bag.get("bytes"))}   '
                    f'{fmt_num(bag.get("mbps"))} MB/s   디스크 {disk_txt} ({fmt_minutes(bag.get("remaining_min"))})')
            bad = h.get('summary', {}).get('bad', 0)
            if bad:
                text += f'   ⚠ 문제 토픽 {bad}개'
            color = '#ffd6d6' if alive else '#bbbbbb'
            if self.ctl.session:
                text += f'\n{self.ctl.session.id}'
        elif st == STOPPING:
            text, color = '■ 정지 중 — bag 마무리 대기', '#ffe7b3'
        elif st == STARTING:
            text, color = '세션 준비 중 (git·파라미터 스냅샷)', '#ffe7b3'
        elif st == WAITING:
            text, color = '녹화 대기 중', '#ffe7b3'
        else:
            s = h.get('summary', {})
            text = (f'대기   토픽 정상 {s.get("ok", 0)} / 문제 {s.get("bad", 0)}   '
                    f'디스크 {disk_txt}   저장 경로 {self.ctx.settings.output_path}')
            color = '#eeeeee'
        if self.status_label.text() != text:
            self.status_label.setText(text)
        if color != self._status_color:          # 스타일시트 재적용은 비싸서 색이 바뀔 때만
            self._status_color = color
            self.status_label.setStyleSheet(f'padding: 6px; border-radius: 4px; background: {color}')

    def _refresh_checks(self) -> None:
        self._update_status_line()
        if self.ctl.state not in (IDLE, WAITING) or self.ctl.resolved is None:
            return
        checks = run_checks(self.ctl.resolved, self.ctx.settings.output_path, self.ctl.latest_health)
        key = [(c.level, c.text) for c in checks]
        if key == self._last_checks:
            return
        self._last_checks = key
        self.checks.clear()
        for c in checks:
            item = QListWidgetItem(f'{LEVEL_ICON[c.level]} {c.text}')
            item.setForeground(QBrush(QColor(LEVEL_COLOR[c.level])))
            self.checks.addItem(item)

    def _on_state(self, state: str) -> None:
        recording = state == RECORDING
        idle = state == IDLE
        self.start_btn.setText('■ 녹화 정지' if recording else '● 녹화 시작')
        self.start_btn.setEnabled(state in (IDLE, RECORDING))
        self.start_btn.setStyleSheet('background: #c62828; color: white' if recording else '')
        for w in (self.profile_combo, self.label_edit, self.notes_edit):
            w.setEnabled(idle)
        waiting = state == WAITING
        self.now_btn.setVisible(waiting)
        self.cancel_btn.setVisible(waiting)
        self.wait_label.setVisible(waiting)
        for b in self.marker_btns + [self.segment_btn]:
            b.setEnabled(recording)
        self.marker_edit.setEnabled(recording)
        if recording:
            self.checks.clear()
            self.checks.addItem('녹화 중 — 점검은 녹화 전에만 표시')
            self._last_checks = []
        if idle:
            self._segment_open = False
            self.segment_btn.setText('[F3] 구간 시작')
            if self.ctl.resolved is not None:
                self._build_rows(self.ctl.resolved.topics + self.ctl.resolved.unknown_topics)
        self._update_status_line()

    # ---- 시작·정지 -----------------------------------------------------
    def _on_start_stop(self) -> None:
        if self.ctl.state == RECORDING:
            if QMessageBox.question(self, '녹화 정지', '녹화를 정지할까요?') == QMessageBox.Yes:
                self.ctl.request_stop()
            return
        if self.ctl.state != IDLE or self.ctl.resolved is None:
            return
        if self.convert_btn.proc is not None and QMessageBox.question(
                self, 'LiDAR 변환 중', 'LiDAR 포인트 변환이 진행 중입니다. CPU를 나눠 쓰게 되어 녹화가 '
                '메시지를 잃을 수 있습니다.\n그래도 녹화를 시작할까요?') != QMessageBox.Yes:
            return
        checks = run_checks(self.ctl.resolved, self.ctx.settings.output_path, self.ctl.latest_health)
        errors = [c.text for c in checks if c.level == ERROR]
        if errors:
            QMessageBox.critical(self, '녹화할 수 없음', '\n'.join(errors))
            return
        warns = [c.text for c in checks if c.level == WARN]
        if warns and QMessageBox.question(
                self, '경고 확인', '경고가 있습니다. 그래도 진행할까요?\n\n' + '\n'.join(f'⚠ {w}' for w in warns)
        ) != QMessageBox.Yes:
            return
        self.ctl.request_start(self.label_edit.text().strip(), self.notes_edit.text().strip())

    def _on_ready_timeout(self, bad: list) -> None:
        msg = ('준비 대기 시간이 지났지만 필수 토픽이 정상이 아닙니다:\n\n' + '\n'.join(bad[:10])
               + '\n\n그래도 녹화를 시작할까요?')
        if QMessageBox.question(self, '필수 토픽 미준비', msg) == QMessageBox.Yes:
            self.ctl.start_after_timeout()

    def _on_session_started(self, _path: str) -> None:
        self.marker_list.clear()
        self._prev_status.clear()          # 새 녹화 monitor의 첫 상태를 기준값으로

    # ---- 마커 ----------------------------------------------------------
    def _marker(self, kind: str, text: str) -> None:
        if self.ctl.state != RECORDING:
            return
        self.bridge.publish_marker(kind, text)
        elapsed = self.ctl.elapsed_sec()
        stamp = fmt_duration(elapsed) if elapsed is not None else time.strftime('%H:%M:%S')
        self.marker_list.insertItem(0, f'{stamp}  [{kind}] {text}')

    def _segment(self) -> None:
        if self.ctl.state != RECORDING:
            return
        self._segment_open = not self._segment_open
        self._marker('segment_start' if self._segment_open else 'segment_end',
                     '구간 시작' if self._segment_open else '구간 끝')
        self.segment_btn.setText('[F3] 구간 끝' if self._segment_open else '[F3] 구간 시작')

    def _free_marker(self) -> None:
        text = self.marker_edit.text().strip()
        if text:
            self._marker('note', text)
            self.marker_edit.clear()

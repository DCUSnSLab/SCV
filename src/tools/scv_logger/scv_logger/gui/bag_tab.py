"""녹화 점검 탭 — 세션 bag이 전체적으로 잘 녹화됐는지 한눈에.

토픽별 녹화율 표 + 타임라인(토픽 × 시간 구간 녹화율 색) + 녹화 속도·디스크 그래프.
원본(센서)이 끊긴 구간과 녹화기가 버린 구간을 다른 색으로 보여준다.
"""
from __future__ import annotations

from pathlib import Path

from PyQt5.QtCore import QRect, Qt, QThread, pyqtSignal
from PyQt5.QtGui import QColor, QFont, QPainter, QPen
from PyQt5.QtWidgets import (QAbstractItemView, QComboBox, QFileDialog, QHBoxLayout, QHeaderView,
                             QLabel, QProgressBar, QPushButton, QScrollArea, QSplitter, QTableWidget,
                             QTableWidgetItem, QToolTip, QVBoxLayout, QWidget)

from ..core.bag_analysis import VERDICT_TEXT, analyze
from ..core.session import STATUS_LABELS, list_sessions
from .common import fmt_bytes, fmt_duration, fmt_num
from .context import AppContext
from .controller import RecordingController

COLUMNS = ['토픽', '메시지', '녹화 Hz', '원본 Hz', '녹화율', '최대 공백', '녹화기 손실', '값 이상', '판정']
VERDICT_BG = {'good': '#d9f2d9', 'warn': '#fff0b3', 'bad': '#f7c6c6', 'source': '#e3d7f2',
              'missing': '#f7c6c6', 'noref': '#eeeeee', 'latched': '#eeeeee'}

C_GOOD, C_WARN, C_BAD = QColor('#5cb85c'), QColor('#f0c040'), QColor('#d9534f')
C_SRC, C_NONE, C_EMPTY = QColor('#9b7fc4'), QColor('#cfcfcf'), QColor('#ffffff')


def ratio_color(ratio: float | None, src_off: bool, count: int) -> QColor:
    if src_off and count == 0:
        return C_SRC
    if ratio is None:
        return C_NONE if count else C_EMPTY
    if ratio >= 0.9:
        return C_GOOD
    if ratio >= 0.5:
        return C_WARN
    return C_BAD


class NumItem(QTableWidgetItem):
    """숫자 기준으로 정렬되는 셀."""

    def __init__(self, text: str, value: float | None):
        super().__init__(text)
        self.value = -1.0 if value is None else float(value)

    def __lt__(self, other):
        if isinstance(other, NumItem):
            return self.value < other.value
        return super().__lt__(other)


class Timeline(QWidget):
    """토픽(행) × 시간 구간(열) 녹화율 히트맵 + 아래쪽 녹화 속도 그래프."""

    LABEL_W, ROW_H, AXIS_H, CHART_H = 320, 17, 22, 70

    def __init__(self):
        super().__init__()
        self.data: dict | None = None
        self.order: list[int] = []
        self.setMouseTracking(True)
        self.setMinimumHeight(120)

    def set_data(self, data: dict | None, order: list[int] | None = None) -> None:
        self.data = data
        self.order = order if order is not None else list(range(len(data['topics']))) if data else []
        rows = len(self.order)
        self.setMinimumHeight(self.AXIS_H + rows * self.ROW_H + self.CHART_H + 30)
        self.update()

    def _grid(self) -> tuple[int, float]:
        n = self.data['nbins']
        return n, max(1.0, (self.width() - self.LABEL_W - 10) / n)

    def paintEvent(self, _event) -> None:
        p = QPainter(self)
        p.fillRect(self.rect(), QColor('white'))
        if not self.data:
            p.drawText(self.rect(), Qt.AlignCenter, '세션을 고르고 분석하세요')
            return
        d = self.data
        n, cw = self._grid()
        x0, y0 = self.LABEL_W, self.AXIS_H
        small = QFont(p.font())
        small.setPointSize(max(7, small.pointSize() - 2))
        p.setFont(small)

        # 시간 축
        step = max(1, int(60 / d['bin_sec'])) if n * d['bin_sec'] > 300 else max(1, int(10 / d['bin_sec']))
        p.setPen(QColor('#666'))
        for b in range(0, n, step):
            x = int(x0 + b * cw)
            p.drawLine(x, y0 - 4, x, y0)
            p.drawText(x + 2, y0 - 6, fmt_duration(b * d['bin_sec'])[2:] if b * d['bin_sec'] < 3600 else fmt_duration(b * d['bin_sec']))

        # 히트맵
        for row, idx in enumerate(self.order):
            t = d['topics'][idx]
            y = y0 + row * self.ROW_H
            p.setPen(QColor('#222') if t['count'] else QColor('#999'))
            p.drawText(QRect(4, y, self.LABEL_W - 8, self.ROW_H), Qt.AlignVCenter | Qt.AlignLeft, t['name'])
            for b in range(n):
                p.fillRect(int(x0 + b * cw), y + 1, max(1, int(cw + 0.99)), self.ROW_H - 2,
                           ratio_color(t['ratios'][b], t['src_off'][b], t['bins'][b]))
        rows_bottom = y0 + len(self.order) * self.ROW_H

        # 마커
        pen = QPen(QColor('#e67e22'))
        pen.setWidth(2)
        p.setPen(pen)
        for m in d.get('markers', []):
            x = int(x0 + m['t'] / d['bin_sec'] * cw)
            p.drawLine(x, y0, x, rows_bottom)

        # 녹화 속도 그래프
        cy = rows_bottom + 12
        mbps = d['system']['mbps']
        vals = [v for v in mbps if v is not None]
        p.setPen(QColor('#444'))
        p.drawText(4, cy + 12, '녹화 쓰기 속도 (MB/s)')
        if vals:
            top = max(vals) or 1.0
            p.drawText(4, cy + 28, f'최대 {top:.0f} · 평균 {sum(vals) / len(vals):.0f}')
            free = [v for v in d['system']['free_gb'] if v is not None]
            if free:
                p.drawText(4, cy + 44, f'디스크 여유 {free[0]:.0f} → {free[-1]:.0f} GB')
            p.setPen(QPen(QColor('#3a7bd5'), 2))
            prev = None
            for b, v in enumerate(mbps):
                if v is None:
                    prev = None
                    continue
                pt = (int(x0 + (b + 0.5) * cw), int(cy + self.CHART_H - v / top * (self.CHART_H - 8)))
                if prev:
                    p.drawLine(prev[0], prev[1], pt[0], pt[1])
                prev = pt
            p.setPen(QColor('#bbb'))
            p.drawLine(x0, cy + self.CHART_H, int(x0 + n * cw), cy + self.CHART_H)

    def mouseMoveEvent(self, e) -> None:
        if not self.data:
            return
        d = self.data
        n, cw = self._grid()
        b = int((e.x() - self.LABEL_W) / cw)
        row = (e.y() - self.AXIS_H) // self.ROW_H
        if not (0 <= b < n):
            QToolTip.hideText()
            return
        start = b * d['bin_sec']
        lines = [f'{fmt_duration(start)} ~ {fmt_duration(start + d["bin_sec"])}']
        if 0 <= row < len(self.order):
            t = d['topics'][self.order[row]]
            r = t['ratios'][b]
            lines.insert(0, t['name'])
            lines.append(f'녹화 {t["bins"][b]}개 ({t["bins"][b] / d["bin_sec"]:.1f} Hz)')
            if r is not None:
                lines.append(f'녹화율 {r * 100:.0f}%')
            if t['src_off'][b]:
                lines.append('원본(센서) 끊김')
        mk = [m for m in d.get('markers', []) if start <= m['t'] < start + d['bin_sec']]
        for m in mk:
            lines.append(f'◆ [{m["kind"]}] {m["text"]}')
        mb = d['system']['mbps'][b]
        if mb is not None:
            lines.append(f'쓰기 {mb:.0f} MB/s, 디스크 {d["system"]["free_gb"][b]} GB')
        QToolTip.showText(e.globalPos(), '\n'.join(lines), self)


class AnalyzeThread(QThread):
    progress = pyqtSignal(int, int)
    done = pyqtSignal(object)
    failed = pyqtSignal(str)

    def __init__(self, path: Path, use_cache: bool, hint: dict[str, dict]):
        super().__init__()
        self.path, self.use_cache, self.hint = path, use_cache, hint

    def run(self) -> None:
        try:
            r = analyze(self.path, lambda d, t: self.progress.emit(d >> 20, max(t >> 20, 1)),
                        use_cache=self.use_cache, catalog_hint=self.hint)
        except Exception as e:  # noqa: BLE001 — 화면에 그대로 보여준다
            self.failed.emit(str(e))
        else:
            self.done.emit(r)


class BagTab(QWidget):
    def __init__(self, ctx: AppContext, controller: RecordingController):
        super().__init__()
        self.ctx = ctx
        self.ctl = controller
        self.thread: AnalyzeThread | None = None
        self.data: dict | None = None

        root = QVBoxLayout(self)
        top = QHBoxLayout()
        self.combo = QComboBox()
        self.combo.setMinimumWidth(420)
        self.combo.currentIndexChanged.connect(self._on_pick)
        top.addWidget(QLabel('세션'))
        top.addWidget(self.combo, 1)
        open_btn = QPushButton('다른 폴더…')
        open_btn.clicked.connect(self._open_dir)
        self.run_btn = QPushButton('분석')
        self.run_btn.clicked.connect(lambda: self._start(use_cache=True))
        self.rerun_btn = QPushButton('다시 분석')
        self.rerun_btn.setToolTip('캐시(analysis.json)를 무시하고 bag을 다시 읽습니다')
        self.rerun_btn.clicked.connect(lambda: self._start(use_cache=False))
        refresh = QPushButton('목록 새로고침')
        refresh.clicked.connect(self.reload_sessions)
        for w in (open_btn, self.run_btn, self.rerun_btn, refresh):
            top.addWidget(w)
        root.addLayout(top)

        self.bar = QProgressBar()
        self.bar.setVisible(False)
        root.addWidget(self.bar)
        self.summary = QLabel('세션을 고르고 [분석]을 누르세요. bag 본문은 읽지 않고 메시지 시각만 읽습니다 '
                              '(약 1.5 GB/s, 결과는 세션 폴더에 캐시).')
        self.summary.setWordWrap(True)
        self.summary.setTextFormat(Qt.RichText)
        self.summary.setStyleSheet('padding: 6px; background: #f4f4f4; border-radius: 4px')
        root.addWidget(self.summary)

        split = QSplitter(Qt.Vertical)
        self.table = QTableWidget(0, len(COLUMNS))
        self.table.setHorizontalHeaderLabels(COLUMNS)
        self.table.verticalHeader().setVisible(False)
        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.table.setSelectionBehavior(QAbstractItemView.SelectRows)
        hdr = self.table.horizontalHeader()
        hdr.setSectionResizeMode(0, QHeaderView.Stretch)
        for i in range(1, len(COLUMNS)):
            hdr.setSectionResizeMode(i, QHeaderView.ResizeToContents)
        # 처음엔 프로파일 순서 — 헤더를 누를 때만 정렬 (타임라인도 같은 순서로)
        hdr.setSectionsClickable(True)
        hdr.setSortIndicatorShown(False)
        hdr.sectionClicked.connect(self._sort_by)
        self._sort = (-1, Qt.AscendingOrder)
        split.addWidget(self.table)

        tl_box = QWidget()
        tl_lay = QVBoxLayout(tl_box)
        tl_lay.setContentsMargins(0, 0, 0, 0)
        legend = QLabel('타임라인 (표와 같은 순서, 녹화율 = 녹화된 개수 ÷ 원본 주기) &nbsp; '
                        '<span style="color:#5cb85c">■</span> 90% 이상 &nbsp;'
                        '<span style="color:#f0c040">■</span> 50~90% &nbsp;'
                        '<span style="color:#d9534f">■</span> 50% 미만 &nbsp;'
                        '<span style="color:#9b7fc4">■</span> 원본(센서) 끊김 &nbsp;'
                        '<span style="color:#cfcfcf">■</span> 기준 없음 &nbsp;'
                        '<span style="color:#e67e22">┃</span> 마커 &nbsp;· 칸에 마우스를 올리면 상세')
        legend.setTextFormat(Qt.RichText)
        tl_lay.addWidget(legend)
        self.timeline = Timeline()
        scroll = QScrollArea()
        scroll.setWidgetResizable(True)
        scroll.setWidget(self.timeline)
        tl_lay.addWidget(scroll)
        split.addWidget(tl_box)
        split.setStretchFactor(0, 2)
        split.setStretchFactor(1, 3)
        root.addWidget(split, 1)

        controller.session_finished.connect(lambda _: self.reload_sessions())
        ctx.settings_changed.connect(self.reload_sessions)
        self.reload_sessions()

    # ---- 세션 선택 -----------------------------------------------------
    def reload_sessions(self) -> None:
        keep = self.combo.currentData()
        self.combo.blockSignals(True)
        self.combo.clear()
        for s in list_sessions(self.ctx.settings.output_path):
            m = s.read_manifest()
            if m.get('status') == 'recording':
                continue                      # 녹화 중인 세션은 분석하지 않음
            cached = ' · 분석됨' if (s.path / 'analysis.json').exists() else ''
            size = (m.get('bag') or {}).get('total_bytes')
            self.combo.addItem(f'{s.id}   [{STATUS_LABELS.get(m.get("status"), m.get("status"))}, '
                               f'{fmt_duration(m.get("duration_sec"))}, {fmt_bytes(size)}{cached}]', str(s.path))
        idx = self.combo.findData(keep) if keep else 0
        self.combo.setCurrentIndex(max(idx, 0))
        self.combo.blockSignals(False)
        self._on_pick()

    def _on_pick(self, *_) -> None:
        path = self.combo.currentData()
        if path and (Path(path) / 'analysis.json').exists():
            self._start(use_cache=True)       # 캐시가 있으면 바로 표시
        else:
            self._show(None)

    def _open_dir(self) -> None:
        d = QFileDialog.getExistingDirectory(self, '세션 또는 bag 폴더', str(self.ctx.settings.output_path))
        if d:
            self.combo.blockSignals(True)
            self.combo.insertItem(0, d, d)
            self.combo.setCurrentIndex(0)
            self.combo.blockSignals(False)
            self._start(use_cache=True)

    # ---- 분석 ----------------------------------------------------------
    def _start(self, use_cache: bool) -> None:
        path = self.combo.currentData()
        if not path or self.thread is not None:
            return
        hint = {t.name: {'hz': t.hz, 'latched': t.latched} for t in self.ctx.catalog.topics()}
        self.thread = AnalyzeThread(Path(path), use_cache, hint)
        self.thread.progress.connect(self._on_progress)
        self.thread.done.connect(self._on_done)
        self.thread.failed.connect(self._on_failed)
        self.thread.finished.connect(self._on_thread_end)
        for b in (self.run_btn, self.rerun_btn):
            b.setEnabled(False)
        self.bar.setRange(0, 0)
        self.bar.setVisible(True)
        self.thread.start()

    def _on_progress(self, done_mb: int, total_mb: int) -> None:
        self.bar.setRange(0, total_mb)
        self.bar.setValue(done_mb)
        self.bar.setFormat(f'bag 읽는 중 {done_mb / 1024:.0f} / {total_mb / 1024:.0f} GB')

    def _on_done(self, data: dict) -> None:
        self._show(data)
        idx = self.combo.currentIndex()
        if idx >= 0 and '분석됨' not in self.combo.itemText(idx) and '[' in self.combo.itemText(idx):
            self.combo.setItemText(idx, self.combo.itemText(idx).rstrip(']') + ' · 분석됨]')

    def _on_failed(self, err: str) -> None:
        self._show(None)
        self.summary.setText(f'<span style="color:#c62828">분석 실패: {err}</span>')

    def _on_thread_end(self) -> None:
        self.thread = None
        self.bar.setVisible(False)
        for b in (self.run_btn, self.rerun_btn):
            b.setEnabled(True)

    # ---- 표시 ----------------------------------------------------------
    def _show(self, d: dict | None) -> None:
        self.data = d
        self.table.setRowCount(0)
        self._sort = (-1, Qt.AscendingOrder)
        self.table.horizontalHeader().setSortIndicatorShown(False)
        if d is None:
            self.timeline.set_data(None)
            self.summary.setText('세션을 고르고 [분석]을 누르세요. bag 본문은 읽지 않고 메시지 시각만 읽습니다 '
                                 '(약 1.5 GB/s, 결과는 세션 폴더에 캐시).')
            return
        c = d['counts']
        med = d['coverage_median']
        verdict_color = '#2e7d32' if med and med >= 0.9 else '#b26a00' if med and med >= 0.5 else '#c62828'
        lost = d['lost_total']
        if not d.get('recorder_log'):
            lost_txt = '<b style="color:#b26a00">recorder.log 없음 — 녹화기 손실 확인 불가</b>'
        elif lost:
            lost_txt = f'<b style="color:#c62828">녹화기 손실 {lost:,}건</b> (디스크·CPU가 못 따라감 — recorder.log)'
        else:
            lost_txt = '<b style="color:#2e7d32">녹화기 손실 없음</b>'
        n_abn = sum(1 for t in d['topics'] if t.get('abnormal_s'))
        med_txt = '-' if med is None else f'{med * 100:.0f}%'
        min_txt = '-' if d['coverage_min'] is None else f"{d['coverage_min'] * 100:.0f}%"
        self.summary.setText(
            f'<b>{d.get("profile") or ""}</b> · {fmt_duration(d["duration"])} · {fmt_bytes(d["size_bytes"])} · '
            f'메시지 {d["messages"]:,}개 · 구간 {d["bin_sec"]}초<br>'
            f'<b style="color:{verdict_color}">녹화율 중간값 {med_txt}</b> (최저 {min_txt}) · {lost_txt}<br>'
            f'양호 {c["good"]} · 일부 손실 {c["warn"]} · 손실 큼 {c["bad"]} · 녹화 안 됨 {c["missing"]} · '
            f'원본 없음 {c["source"]} · 기준 없음 {c["noref"]} · 1회성 {c["latched"]}'
            + (f'<br><b style="color:#c25a00">값 이상 토픽 {n_abn}개</b> (값 이상 칸에 마우스를 올리면 내용)' if n_abn else ''))
        self.table.setRowCount(len(d['topics']))
        for r, t in enumerate(d['topics']):
            cov = t['coverage']
            abn = t.get('abnormal_s', 0)
            gap = f'{t["max_gap"]:.1f}s' + (f' @{fmt_duration(t["gap_at"])}' if t['gap_at'] is not None else '')
            cells = [
                QTableWidgetItem(t['name']),
                NumItem(f'{t["count"]:,}', t['count']),
                NumItem(fmt_num(t['rec_hz']), t['rec_hz']),
                NumItem('-' if t['latched'] else fmt_num(t['src_hz']) if t['src_hz'] else fmt_num(t['expected']),
                        None if t['latched'] else t['src_hz'] or t['expected']),
                NumItem('-' if cov is None else f'{cov * 100:.0f}%', cov),
                NumItem(gap, t['max_gap']),
                NumItem(f'{t["lost"]:,}' if t['lost'] else '', t['lost']),
                NumItem(f'{abn} s' if abn else '', abn),
                QTableWidgetItem(VERDICT_TEXT[t['verdict']]),
            ]
            if abn:
                cells[7].setToolTip('녹화 중 값 검사에서 문제로 판정된 시간 (감시 1초 단위)\n'
                                    + '\n'.join(f'⚠ {x}' for x in t.get('abnormal_issues', [])))
            cells[0].setData(Qt.UserRole, r)
            if not t['src_hz'] and t['expected']:
                cells[3].setToolTip('녹화 중 감시 기록이 없어 카탈로그 기준값 표시')
            bg = QColor(VERDICT_BG[t['verdict']])
            for c_i, cell in enumerate(cells):
                cell.setBackground(QColor('#ffc890') if c_i == 7 and abn else bg)
                self.table.setItem(r, c_i, cell)
        self._sync_timeline_order()

    def _sort_by(self, col: int) -> None:
        if not self.data:
            return
        prev_col, prev_order = self._sort
        order = Qt.DescendingOrder if prev_col == col and prev_order == Qt.AscendingOrder else Qt.AscendingOrder
        self._sort = (col, order)
        hdr = self.table.horizontalHeader()
        hdr.setSortIndicatorShown(True)
        hdr.setSortIndicator(col, order)
        self.table.sortItems(col, order)
        self._sync_timeline_order()

    def _sync_timeline_order(self) -> None:
        if not self.data:
            return
        order = []
        for r in range(self.table.rowCount()):
            item = self.table.item(r, 0)
            if item is not None:
                order.append(item.data(Qt.UserRole))
        self.timeline.set_data(self.data, order)

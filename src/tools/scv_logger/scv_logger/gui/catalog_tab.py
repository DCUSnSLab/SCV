"""카탈로그 탭 — 토픽 목록 편집, 실측 스캔으로 갱신, 자동 마커."""
from __future__ import annotations

import json
import os
import sys
import tempfile
from pathlib import Path

from PyQt5.QtCore import QProcess, Qt
from PyQt5.QtGui import QBrush, QColor
from PyQt5.QtWidgets import (QAbstractItemView, QCheckBox, QComboBox, QDialog, QDialogButtonBox,
                             QDoubleSpinBox, QFormLayout, QGroupBox, QHBoxLayout, QHeaderView,
                             QInputDialog, QLabel, QLineEdit, QMessageBox, QPushButton, QSpinBox,
                             QTableWidget, QTableWidgetItem, QTreeWidget, QTreeWidgetItem,
                             QVBoxLayout, QWidget)

from ..core.catalog import AutoMarker, CatalogError, TopicSpec
from ..core.catalog_diff import KIND_LABELS, DiffItem, ScanEntry, apply_items, diff_catalog
from .common import fmt_kb, fmt_num
from .context import AppContext

COLUMNS = ['토픽', '타입', 'Hz', '크기 KB', '필수', 'heavy', 'latched', 'monitor_via', '설명']


def guess_group(name: str, groups: list[str]) -> str:
    rules = [('camera_info', 'camera_info'), ('/compressed', 'camera_compressed'),
             ('image', 'camera_raw'), ('velodyne_points', 'lidar_points'), ('scan', 'lidar'),
             ('velodyne', 'lidar'), ('imu', 'imu_gnss'), ('gps', 'imu_gnss'), ('fix', 'imu_gnss'),
             ('odom', 'localization'), ('path', 'planning'), ('costmap', 'planning'),
             ('behavior', 'planning'), ('cmd', 'control'), ('hunter', 'vehicle'), ('/tf', 'tf')]
    for key, group in rules:
        if key in name and group in groups:
            return group
    return groups[0] if groups else ''


class TopicDialog(QDialog):
    def __init__(self, parent, groups: list[str], spec: TopicSpec | None = None):
        super().__init__(parent)
        self.setWindowTitle('토픽 편집' if spec else '토픽 추가')
        form = QFormLayout(self)
        self.name = QLineEdit(spec.name if spec else '/')
        self.group = QComboBox()
        self.group.addItems(groups)
        if spec:
            self.group.setCurrentText(spec.group)
        self.type = QLineEdit(spec.type or '' if spec else '')
        self.type.setPlaceholderText('pkg/msg/Type (비워 두면 실행 중 그래프에서 확인)')
        self.hz = QDoubleSpinBox()
        self.hz.setRange(0, 10000)
        self.hz.setDecimals(1)
        self.hz.setSpecialValueText('미지정')
        self.hz.setValue(spec.hz or 0 if spec else 0)
        self.size = QDoubleSpinBox()
        self.size.setRange(0, 1e6)
        self.size.setDecimals(1)
        self.size.setSpecialValueText('미지정')
        self.size.setValue(spec.size_kb or 0 if spec else 0)
        self.required = QCheckBox('필수 (없으면 녹화 전 경고)')
        self.heavy = QCheckBox('heavy (녹화 시 best-effort)')
        self.latched = QCheckBox('latched (transient_local, 주기 판정 제외)')
        if spec:
            self.required.setChecked(spec.required)
            self.heavy.setChecked(spec.heavy)
            self.latched.setChecked(spec.latched)
        self.via = QLineEdit(spec.monitor_via or '' if spec else '')
        self.via.setPlaceholderText('주기를 대신 잴 가벼운 토픽 (예: .../camera_info)')
        self.desc = QLineEdit(spec.description if spec else '')
        for label, w in (('이름', self.name), ('그룹', self.group), ('타입', self.type), ('기준 Hz', self.hz),
                         ('평균 크기 KB', self.size), ('', self.required), ('', self.heavy),
                         ('', self.latched), ('monitor_via', self.via), ('설명', self.desc)):
            form.addRow(label, w)
        bb = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        bb.button(QDialogButtonBox.Ok).setText('확인')
        bb.button(QDialogButtonBox.Cancel).setText('취소')
        bb.accepted.connect(self.accept)
        bb.rejected.connect(self.reject)
        form.addRow(bb)

    def spec(self) -> TopicSpec:
        return TopicSpec(
            name=self.name.text().strip(), group=self.group.currentText(),
            type=self.type.text().strip() or None, hz=self.hz.value() or None,
            required=self.required.isChecked(), heavy=self.heavy.isChecked(),
            size_kb=self.size.value() or None, monitor_via=self.via.text().strip() or None,
            latched=self.latched.isChecked(), description=self.desc.text().strip())


class ScanDialog(QDialog):
    """스캔 결과와 카탈로그 차이 — 반영할 항목을 고른다."""

    def __init__(self, parent, ctx: AppContext, items: list[DiffItem]):
        super().__init__(parent)
        self.ctx = ctx
        self.setWindowTitle('카탈로그 스캔 결과')
        self.resize(1100, 600)
        lay = QVBoxLayout(self)
        same = sum(1 for i in items if i.kind == 'same')
        self.items = [i for i in items if i.kind != 'same']
        counts = {k: sum(1 for i in self.items if i.kind == k) for k in ('new', 'changed', 'missing')}
        lay.addWidget(QLabel(
            f'새 토픽 {counts["new"]} · 값 다름 {counts["changed"]} · 그래프에 없음 {counts["missing"]} · 같음 {same}\n'
            '체크한 항목만 반영합니다. 새 토픽은 넣을 그룹을 고르고, "그래프에 없음"을 체크하면 카탈로그에서 삭제합니다.'))
        groups = list(ctx.catalog.groups)
        self.table = QTableWidget(len(self.items), 7)
        self.table.setHorizontalHeaderLabels(['반영', '구분', '토픽', '실측 타입', '실측 Hz / KB', '그룹', '변경 내용'])
        self.table.verticalHeader().setVisible(False)
        self.table.horizontalHeader().setSectionResizeMode(2, QHeaderView.Stretch)
        self.table.horizontalHeader().setSectionResizeMode(6, QHeaderView.Stretch)
        self.checks: list[QCheckBox] = []
        self.group_boxes: dict[int, QComboBox] = {}
        for r, it in enumerate(self.items):
            cb = QCheckBox()
            cb.setChecked(it.kind == 'changed')
            self.checks.append(cb)
            self.table.setCellWidget(r, 0, cb)
            kind = QTableWidgetItem(KIND_LABELS[it.kind])
            kind.setBackground(QBrush(QColor({'new': '#d9ecff', 'changed': '#fff0b3', 'missing': '#eeeeee'}[it.kind])))
            self.table.setItem(r, 1, kind)
            self.table.setItem(r, 2, QTableWidgetItem(it.name))
            s = it.scan
            self.table.setItem(r, 3, QTableWidgetItem((s.type or '') + (f' ({s.error})' if s and s.error else '') if s else '-'))
            self.table.setItem(r, 4, QTableWidgetItem(f'{fmt_num(s.hz)} / {fmt_kb(s.size_kb)}' if s else '-'))
            if it.kind == 'new':
                box = QComboBox()
                box.addItems(groups)
                box.setCurrentText(guess_group(it.name, groups))
                self.group_boxes[r] = box
                self.table.setCellWidget(r, 5, box)
            else:
                self.table.setItem(r, 5, QTableWidgetItem(it.spec.group if it.spec else ''))
            desc = ', '.join(f'{k}: {fmt_num(a) if isinstance(a, float) else a} → {fmt_num(b) if isinstance(b, float) else b}'
                             for k, (a, b) in it.changes.items())
            if it.suggest_heavy:
                desc += (', ' if desc else '') + 'heavy 지정 제안'
            self.table.setItem(r, 6, QTableWidgetItem(desc))
        self.table.resizeColumnsToContents()
        lay.addWidget(self.table, 1)
        bb = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        bb.button(QDialogButtonBox.Ok).setText('선택 항목 반영')
        bb.button(QDialogButtonBox.Cancel).setText('취소')
        bb.accepted.connect(self.accept)
        bb.rejected.connect(self.reject)
        lay.addWidget(bb)

    def selection(self) -> list[tuple[DiffItem, str | None]]:
        out = []
        for r, it in enumerate(self.items):
            if self.checks[r].isChecked():
                box = self.group_boxes.get(r)
                out.append((it, box.currentText() if box else None))
        return out


class CatalogTab(QWidget):
    def __init__(self, ctx: AppContext):
        super().__init__()
        self.ctx = ctx
        self._scan: QProcess | None = None
        self._scan_out: Path | None = None
        root = QVBoxLayout(self)

        top = QHBoxLayout()
        self.path_label = QLabel(f'카탈로그: {ctx.catalog_path}')
        self.path_label.setStyleSheet('color:#555')
        top.addWidget(self.path_label, 1)
        top.addWidget(QLabel('스캔 시간(초)'))
        self.scan_secs = QSpinBox()
        self.scan_secs.setRange(2, 60)
        self.scan_secs.setValue(5)
        top.addWidget(self.scan_secs)
        self.scan_btn = QPushButton('카탈로그 스캔')
        self.scan_btn.setToolTip('지금 ROS 그래프의 토픽·타입·실측 주기·크기를 수집해 카탈로그와 비교합니다.\n'
                                 '큰 토픽도 잠깐 구독하므로 주행 중에는 쓰지 마세요.')
        self.scan_btn.clicked.connect(self._start_scan)
        top.addWidget(self.scan_btn)
        root.addLayout(top)

        self.tree = QTreeWidget()
        self.tree.setHeaderLabels(COLUMNS)
        self.tree.header().setSectionResizeMode(0, QHeaderView.ResizeToContents)
        self.tree.header().setSectionResizeMode(len(COLUMNS) - 1, QHeaderView.Stretch)
        self.tree.itemDoubleClicked.connect(lambda item, _c: self._edit(item))
        root.addWidget(self.tree, 1)

        btns = QHBoxLayout()
        for text, slot in (('그룹 추가', self._add_group), ('토픽 추가', self._add_topic),
                           ('편집', lambda: self._edit(self.tree.currentItem())), ('삭제', self._delete)):
            b = QPushButton(text)
            b.clicked.connect(slot)
            btns.addWidget(b)
        btns.addStretch()
        root.addLayout(btns)

        am_box = QGroupBox('자동 마커 — 값이 바뀌면 녹화 중 마커를 자동으로 찍을 토픽 (예: 수동/자율 전환)')
        am_lay = QVBoxLayout(am_box)
        self.am_table = QTableWidget(0, 3)
        self.am_table.setHorizontalHeaderLabels(['토픽', '라벨', '비교 필드 (비우면 header 제외 전체)'])
        self.am_table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.am_table.verticalHeader().setVisible(False)
        self.am_table.setMaximumHeight(140)
        self.am_table.setSelectionBehavior(QAbstractItemView.SelectRows)
        am_lay.addWidget(self.am_table)
        am_btns = QHBoxLayout()
        for text, slot in (('추가', self._am_add), ('삭제', self._am_remove), ('자동 마커 저장', self._am_save)):
            b = QPushButton(text)
            b.clicked.connect(slot)
            am_btns.addWidget(b)
        am_btns.addStretch()
        am_lay.addLayout(am_btns)
        root.addWidget(am_box)

        ctx.catalog_changed.connect(self.refresh)
        self.refresh()

    # ---- 표시 ----------------------------------------------------------
    def refresh(self) -> None:
        self.tree.clear()
        for g in self.ctx.catalog.groups.values():
            gi = QTreeWidgetItem([g.name, '', '', '', '', '', '', '', g.description])
            f = gi.font(0)
            f.setBold(True)
            gi.setFont(0, f)
            gi.setData(0, Qt.UserRole, ('group', g.name))
            for t in g.topics.values():
                ti = QTreeWidgetItem([t.name, t.type or '', fmt_num(t.hz), fmt_num(t.size_kb),
                                      '✓' if t.required else '', '✓' if t.heavy else '',
                                      '✓' if t.latched else '', t.monitor_via or '', t.description])
                ti.setData(0, Qt.UserRole, ('topic', t.name))
                gi.addChild(ti)
            self.tree.addTopLevelItem(gi)
        self.tree.expandAll()
        self.am_table.setRowCount(0)
        for m in self.ctx.catalog.auto_markers:
            self._am_add_row(m.topic, m.label, m.field or '')

    def _save(self) -> bool:
        try:
            self.ctx.save_catalog()
            return True
        except (CatalogError, OSError) as e:
            QMessageBox.warning(self, '카탈로그 저장 실패', str(e))
            self.ctx.reload_catalog()
            return False

    # ---- 편집 ----------------------------------------------------------
    def _add_group(self) -> None:
        name, ok = QInputDialog.getText(self, '그룹 추가', '그룹 이름 (영문 소문자·숫자·_):')
        if not ok or not name.strip():
            return
        desc, _ = QInputDialog.getText(self, '그룹 추가', '설명:')
        try:
            self.ctx.catalog.add_group(name.strip(), desc.strip())
        except CatalogError as e:
            QMessageBox.warning(self, '그룹 추가 실패', str(e))
            return
        self._save()

    def _add_topic(self) -> None:
        if not self.ctx.catalog.groups:
            QMessageBox.information(self, '토픽 추가', '먼저 그룹을 추가하세요.')
            return
        dlg = TopicDialog(self, list(self.ctx.catalog.groups))
        cur = self.tree.currentItem()
        if cur is not None:
            kind, name = cur.data(0, Qt.UserRole)
            dlg.group.setCurrentText(name if kind == 'group' else self.ctx.catalog.topic(name).group)
        if dlg.exec_() != QDialog.Accepted:
            return
        try:
            self.ctx.catalog.add_topic(dlg.spec())
        except CatalogError as e:
            QMessageBox.warning(self, '토픽 추가 실패', str(e))
            return
        self._save()

    def _edit(self, item) -> None:
        if item is None:
            return
        kind, name = item.data(0, Qt.UserRole)
        if kind == 'group':
            g = self.ctx.catalog.groups[name]
            desc, ok = QInputDialog.getText(self, '그룹 설명', f'{name} 설명:', text=g.description)
            if ok:
                g.description = desc.strip()
                self._save()
            return
        spec = self.ctx.catalog.topic(name)
        dlg = TopicDialog(self, list(self.ctx.catalog.groups), spec)
        if dlg.exec_() != QDialog.Accepted:
            return
        try:
            self.ctx.catalog.update_topic(name, dlg.spec())
        except CatalogError as e:
            QMessageBox.warning(self, '토픽 수정 실패', str(e))
            return
        self._save()

    def _delete(self) -> None:
        item = self.tree.currentItem()
        if item is None:
            return
        kind, name = item.data(0, Qt.UserRole)
        if kind == 'group':
            g = self.ctx.catalog.groups[name]
            users = self._profiles_using_group(name)
            msg = f'그룹 {name}과(와) 토픽 {len(g.topics)}개를 삭제할까요?'
            if users:
                msg += f'\n\n이 그룹을 쓰는 프로파일이 있어 저장이 거부될 수 있습니다: {", ".join(users)}'
            if QMessageBox.question(self, '그룹 삭제', msg) != QMessageBox.Yes:
                return
            del self.ctx.catalog.groups[name]
        else:
            if QMessageBox.question(self, '토픽 삭제', f'{name}을(를) 카탈로그에서 삭제할까요?') != QMessageBox.Yes:
                return
            self.ctx.catalog.remove_topic(name)
        self._save()

    def _profiles_using_group(self, group: str) -> list[str]:
        out = []
        for n in self.ctx.store.names():
            try:
                p = self.ctx.store.load(n)
            except ValueError:
                continue
            if group in (p.groups or []) + p.add_groups + p.exclude_groups:
                out.append(n)
        return out

    # ---- 자동 마커 -----------------------------------------------------
    def _am_add_row(self, topic: str = '/', label: str = '', field: str = '') -> None:
        r = self.am_table.rowCount()
        self.am_table.insertRow(r)
        for c, v in enumerate((topic, label, field)):
            self.am_table.setItem(r, c, QTableWidgetItem(v))

    def _am_add(self) -> None:
        self._am_add_row()

    def _am_remove(self) -> None:
        rows = sorted({i.row() for i in self.am_table.selectedIndexes()}, reverse=True)
        for r in rows:
            self.am_table.removeRow(r)

    def _am_save(self) -> None:
        markers = []
        for r in range(self.am_table.rowCount()):
            vals = [(self.am_table.item(r, c).text().strip() if self.am_table.item(r, c) else '') for c in range(3)]
            if vals[0] and vals[0] != '/':
                markers.append(AutoMarker(topic=vals[0], label=vals[1], field=vals[2] or None))
        old = self.ctx.catalog.auto_markers
        self.ctx.catalog.auto_markers = markers
        if not self._save():
            self.ctx.catalog.auto_markers = old

    # ---- 스캔 ----------------------------------------------------------
    def _start_scan(self) -> None:
        if self._scan is not None:
            return
        out = str(Path(tempfile.gettempdir()) / f'scv_logger_scan_{os.getpid()}.json')
        self._scan_out = Path(out)
        self._scan_out.unlink(missing_ok=True)
        self._scan = QProcess(self)
        self._scan.setProcessChannelMode(QProcess.MergedChannels)
        self._scan.finished.connect(self._scan_finished)
        secs = self.scan_secs.value()
        self._scan.start(sys.executable, ['-m', 'scv_logger.ros.scan', '--duration', str(secs), '--out', out])
        self.scan_btn.setEnabled(False)
        self.scan_btn.setText(f'스캔 중… ({secs + 2}초)')

    def _scan_finished(self, code: int, _status) -> None:
        log = bytes(self._scan.readAll()).decode(errors='replace')
        self._scan = None
        self.scan_btn.setEnabled(True)
        self.scan_btn.setText('카탈로그 스캔')
        try:
            data = json.loads(self._scan_out.read_text(encoding='utf-8'))
        except (OSError, ValueError):
            QMessageBox.warning(self, '스캔 실패', f'종료 코드 {code}\n{log[-2000:]}')
            return
        finally:
            self._scan_out.unlink(missing_ok=True)
        entries = [ScanEntry.from_dict(t) for t in data.get('topics', [])]
        if not entries:
            QMessageBox.information(self, '스캔 결과', '발행 중인 토픽이 없습니다. 주행 스택을 띄운 뒤 스캔하세요.\n'
                                    '(ROS_DOMAIN_ID가 같은지도 확인)')
            return
        items = diff_catalog(self.ctx.catalog, entries)
        dlg = ScanDialog(self, self.ctx, items)
        if dlg.exec_() != QDialog.Accepted:
            return
        sel = dlg.selection()
        try:
            n = apply_items(self.ctx.catalog, sel, remove_missing=True)
        except CatalogError as e:
            QMessageBox.warning(self, '반영 실패', str(e))
            self.ctx.reload_catalog()
            return
        if n and self._save():
            QMessageBox.information(self, '스캔 반영', f'{n}개 항목을 카탈로그에 반영했습니다.')

"""세션 탭 — 지난 녹화 목록, manifest·마커 보기, 메모 수정."""
from __future__ import annotations

import subprocess
from datetime import datetime

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QAbstractItemView, QApplication, QFormLayout, QGroupBox, QHBoxLayout,
                             QHeaderView, QLabel, QListWidget, QMessageBox, QPlainTextEdit,
                             QPushButton, QSplitter, QTableWidget, QTableWidgetItem, QVBoxLayout,
                             QWidget)

from ..core.session import STATUS_LABELS, Session, list_sessions
from ..core.yamlio import dump_yaml
from .common import fmt_bytes, fmt_duration
from .context import AppContext
from .controller import RecordingController

COLUMNS = ['시작', '프로파일', '라벨', '길이', '용량', '마커', '상태']


def _short_time(iso: str | None) -> str:
    try:
        return datetime.fromisoformat(iso).strftime('%Y-%m-%d %H:%M:%S')
    except (TypeError, ValueError):
        return iso or '-'


class SessionsTab(QWidget):
    def __init__(self, ctx: AppContext, controller: RecordingController):
        super().__init__()
        self.ctx = ctx
        self.ctl = controller
        self.sessions: list[Session] = []
        self.selected: Session | None = None

        root = QVBoxLayout(self)
        top = QHBoxLayout()
        self.root_label = QLabel()
        self.root_label.setStyleSheet('color:#555')
        top.addWidget(self.root_label, 1)
        refresh = QPushButton('새로고침')
        refresh.clicked.connect(self.refresh)
        top.addWidget(refresh)
        root.addLayout(top)

        split = QSplitter(Qt.Vertical)
        self.table = QTableWidget(0, len(COLUMNS))
        self.table.setHorizontalHeaderLabels(COLUMNS)
        self.table.verticalHeader().setVisible(False)
        self.table.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.table.setSelectionBehavior(QAbstractItemView.SelectRows)
        self.table.setSelectionMode(QAbstractItemView.SingleSelection)
        self.table.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeToContents)
        self.table.horizontalHeader().setSectionResizeMode(2, QHeaderView.Stretch)
        self.table.itemSelectionChanged.connect(self._on_select)
        split.addWidget(self.table)

        detail = QWidget()
        dlay = QHBoxLayout(detail)
        left = QVBoxLayout()
        info_box = QGroupBox('세션')
        self.info = QFormLayout(info_box)
        self.info_labels = {}
        for key in ('경로', '프로파일', '코드', '토픽'):
            lab = QLabel('-')
            lab.setWordWrap(True)
            lab.setTextInteractionFlags(Qt.TextSelectableByMouse)
            self.info_labels[key] = lab
            self.info.addRow(key, lab)
        left.addWidget(info_box)
        notes_box = QGroupBox('메모')
        nlay = QVBoxLayout(notes_box)
        self.notes = QPlainTextEdit()
        self.notes.setMaximumHeight(90)
        nlay.addWidget(self.notes)
        nb = QHBoxLayout()
        save = QPushButton('메모 저장')
        save.clicked.connect(self._save_notes)
        open_btn = QPushButton('폴더 열기')
        open_btn.clicked.connect(self._open_folder)
        copy_btn = QPushButton('경로 복사')
        copy_btn.clicked.connect(self._copy_path)
        for b in (save, open_btn, copy_btn):
            nb.addWidget(b)
        nlay.addLayout(nb)
        left.addWidget(notes_box)
        mk_box = QGroupBox('마커')
        mlay = QVBoxLayout(mk_box)
        self.markers = QListWidget()
        mlay.addWidget(self.markers)
        left.addWidget(mk_box, 1)
        dlay.addLayout(left, 2)
        man_box = QGroupBox('manifest.yaml')
        malay = QVBoxLayout(man_box)
        self.manifest = QPlainTextEdit()
        self.manifest.setReadOnly(True)
        self.manifest.setLineWrapMode(QPlainTextEdit.NoWrap)
        malay.addWidget(self.manifest)
        dlay.addWidget(man_box, 3)
        split.addWidget(detail)
        split.setStretchFactor(1, 2)
        root.addWidget(split, 1)

        controller.session_started.connect(lambda _: self.refresh())
        controller.session_finished.connect(lambda _: self.refresh())
        ctx.settings_changed.connect(self.refresh)
        self.refresh()

    def refresh(self) -> None:
        out = self.ctx.settings.output_path
        self.root_label.setText(f'저장 경로: {out}')
        keep = self.selected.id if self.selected else None
        self.sessions = list_sessions(out)
        self.table.setRowCount(len(self.sessions))
        for r, s in enumerate(self.sessions):
            m = s.read_manifest()
            status = m.get('status', '')
            recording = status == 'recording'
            size = s.bag_bytes() if recording else (m.get('bag') or {}).get('total_bytes')
            values = [_short_time(m.get('started_at')), (m.get('profile') or {}).get('name', '-'),
                      m.get('label') or '', fmt_duration(m.get('duration_sec')), fmt_bytes(size),
                      str(m.get('markers', s.marker_count() if recording else 0)),
                      STATUS_LABELS.get(status, status)]
            for c, v in enumerate(values):
                self.table.setItem(r, c, QTableWidgetItem(v))
            if keep == s.id:
                self.table.selectRow(r)
        if not self.sessions:
            self._show(None)
        elif not self.table.selectedIndexes():
            self.table.selectRow(0)

    def _on_select(self) -> None:
        rows = {i.row() for i in self.table.selectedIndexes()}
        self._show(self.sessions[rows.pop()] if rows else None)

    def _show(self, s: Session | None) -> None:
        self.selected = s
        self.markers.clear()
        if s is None:
            for lab in self.info_labels.values():
                lab.setText('-')
            self.notes.setPlainText('')
            self.manifest.setPlainText('')
            return
        m = s.read_manifest()
        prof = m.get('profile') or {}
        git = m.get('git') or {}
        top = git.get('superproject') or {}
        subs = git.get('submodules') or []
        dirty = [x['path'] for x in subs if x.get('dirty')]
        mismatch = [x['path'] for x in subs if x.get('matches_superproject') is False]
        code = f'{top.get("branch", "?")} @ {str(top.get("commit", ""))[:8]}' + (' (dirty)' if top.get('dirty') else '')
        if dirty:
            code += f'\n변경 있는 서브모듈: {", ".join(dirty)}'
        if mismatch:
            code += f'\n상위 레포 기록과 다른 서브모듈: {", ".join(mismatch)}'
        self.info_labels['경로'].setText(str(s.path))
        self.info_labels['프로파일'].setText(f'{prof.get("name", "-")} ({" → ".join(prof.get("chain", []))})')
        self.info_labels['코드'].setText(code)
        self.info_labels['토픽'].setText(f'{len(prof.get("topics", []))}개'
                                       + (f' + 카탈로그 밖 {len(prof["unknown_topics"])}개' if prof.get('unknown_topics') else ''))
        self.notes.setPlainText(m.get('notes') or '')
        for mk in s.markers():
            t = mk.get('t_rel')
            self.markers.addItem(f'{fmt_duration(t) if t is not None else "-"}  [{mk.get("kind")}] {mk.get("text", "")}')
        self.manifest.setPlainText(dump_yaml(m))

    def _save_notes(self) -> None:
        if self.selected is None:
            return
        self.selected.update_manifest(notes=self.notes.toPlainText().strip())
        self.refresh()

    def _open_folder(self) -> None:
        if self.selected is None:
            return
        try:
            subprocess.Popen(['xdg-open', str(self.selected.path)], stdout=subprocess.DEVNULL,
                             stderr=subprocess.DEVNULL)
        except OSError as e:
            QMessageBox.warning(self, '폴더 열기 실패', str(e))

    def _copy_path(self) -> None:
        if self.selected is not None:
            QApplication.clipboard().setText(str(self.selected.path))

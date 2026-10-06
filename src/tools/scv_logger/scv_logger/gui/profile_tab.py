"""프로파일 탭 — 녹화 프로파일 만들기·고치기 (상속 지원)."""
from __future__ import annotations

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QBrush, QColor
from PyQt5.QtWidgets import (QComboBox, QDoubleSpinBox, QFormLayout, QGroupBox, QHBoxLayout,
                             QHeaderView, QInputDialog, QLabel, QLineEdit, QListWidget,
                             QListWidgetItem, QMessageBox, QPushButton, QSpinBox, QSplitter,
                             QTreeWidget, QTreeWidgetItem, QVBoxLayout, QWidget)

from ..core.command import estimate_mb_per_min
from ..core.profile import (CHOICE_LABELS, OPTION_CHOICES, OPTION_LABELS, PROFILE_NAME_RE,
                            ProfileError, RecordOptions, ResolvedProfile, profile_from_selection)
from .common import fmt_num
from .context import AppContext

UNKNOWN_GROUP = '(카탈로그 밖)'
NO_PARENT = '(없음)'


class ProfileTab(QWidget):
    def __init__(self, ctx: AppContext):
        super().__init__()
        self.ctx = ctx
        self.current: str | None = None      # 편집 중인 프로파일 이름 (새로 만드는 중이면 그 이름)
        self.is_new = False
        self.abstract = False
        self.parent_resolved: ResolvedProfile | None = None
        self.dirty = False
        self._loading = False

        root = QHBoxLayout(self)
        split = QSplitter()
        root.addWidget(split)

        # ---- 왼쪽: 목록 --------------------------------------------------
        left = QWidget()
        llay = QVBoxLayout(left)
        self.list = QListWidget()
        self.list.currentItemChanged.connect(self._on_select)
        llay.addWidget(self.list)
        for text, slot in (('새로 만들기', self._new), ('복제', self._duplicate), ('삭제', self._delete)):
            b = QPushButton(text)
            b.clicked.connect(slot)
            llay.addWidget(b)
        split.addWidget(left)

        # ---- 오른쪽: 편집 ------------------------------------------------
        right = QWidget()
        rlay = QVBoxLayout(right)
        head = QFormLayout()
        self.name_edit = QLineEdit()
        self.name_edit.setReadOnly(True)
        self.desc_edit = QLineEdit()
        self.desc_edit.textEdited.connect(self._mark_dirty)
        self.parent_combo = QComboBox()
        self.parent_combo.currentTextChanged.connect(self._on_parent_changed)
        head.addRow('이름', self.name_edit)
        head.addRow('설명', self.desc_edit)
        head.addRow('상속', self.parent_combo)
        rlay.addLayout(head)

        body = QHBoxLayout()
        self.tree = QTreeWidget()
        self.tree.setHeaderLabels(['토픽', 'Hz', '크기 KB', '비고', '부모 대비'])
        self.tree.header().setSectionResizeMode(0, QHeaderView.Stretch)
        for i in range(1, 5):
            self.tree.header().setSectionResizeMode(i, QHeaderView.ResizeToContents)
        self.tree.itemChanged.connect(self._on_item_changed)
        body.addWidget(self.tree, 3)

        opt_box = QGroupBox('녹화 옵션')
        self.opt_form = QFormLayout(opt_box)
        self.opt_widgets: dict[str, QWidget] = {}
        defaults = RecordOptions()
        for key in RecordOptions.names():
            default = getattr(defaults, key)
            if key in OPTION_CHOICES:
                w = QComboBox()
                for v in OPTION_CHOICES[key]:
                    w.addItem(CHOICE_LABELS.get(v, v), v)
                w.currentIndexChanged.connect(self._on_option_changed)
            elif isinstance(default, float):
                w = QDoubleSpinBox()
                w.setRange(0, 10000)
                w.setDecimals(1)
                w.valueChanged.connect(self._on_option_changed)
            else:
                w = QSpinBox()
                w.setRange(0, 1000000)
                w.valueChanged.connect(self._on_option_changed)
            self.opt_widgets[key] = w
            self.opt_form.addRow(OPTION_LABELS.get(key, key), w)
        body.addWidget(opt_box, 2)
        rlay.addLayout(body, 1)

        self.estimate = QLabel()
        self.estimate.setWordWrap(True)
        rlay.addWidget(self.estimate)
        btns = QHBoxLayout()
        btns.addStretch()
        self.revert_btn = QPushButton('되돌리기')
        self.revert_btn.clicked.connect(lambda: self._load(self.current) if self.current and not self.is_new else None)
        self.save_btn = QPushButton('저장')
        self.save_btn.clicked.connect(self._save)
        btns.addWidget(self.revert_btn)
        btns.addWidget(self.save_btn)
        rlay.addLayout(btns)
        split.addWidget(right)
        split.setStretchFactor(1, 4)

        ctx.catalog_changed.connect(self._reload_current)
        ctx.profiles_changed.connect(self.reload_list)
        self.reload_list()

    # ---- 목록 ----------------------------------------------------------
    def reload_list(self) -> None:
        keep = self.current
        self.list.blockSignals(True)
        self.list.clear()
        for n in self.ctx.profile_names(include_abstract=True):
            label = n
            try:
                if self.ctx.store.load(n).abstract:
                    label = f'{n} (공통)'
            except ValueError:
                label = f'{n} (오류)'
            item = QListWidgetItem(label)
            item.setData(Qt.UserRole, n)
            self.list.addItem(item)
        self.list.blockSignals(False)
        names = [self.list.item(i).data(Qt.UserRole) for i in range(self.list.count())]
        if keep in names and not self.is_new:
            self.list.setCurrentRow(names.index(keep))
        elif names and self.current is None:
            self.list.setCurrentRow(0)

    def _on_select(self, item, prev) -> None:
        if item is None:
            return
        name = item.data(Qt.UserRole)
        if name == self.current and not self.is_new:
            return
        if self.dirty and not self._confirm_discard():
            self.list.blockSignals(True)
            self.list.setCurrentItem(prev)
            self.list.blockSignals(False)
            return
        self._load(name)

    def _confirm_discard(self) -> bool:
        return QMessageBox.question(self, '저장 안 된 변경', f'{self.current}의 변경을 버릴까요?') == QMessageBox.Yes

    # ---- 불러오기 ------------------------------------------------------
    def _load(self, name: str) -> None:
        try:
            prof = self.ctx.store.load(name)
            resolved = self.ctx.resolve(name)
        except (ProfileError, ValueError) as e:
            QMessageBox.warning(self, '프로파일 오류', str(e))
            return
        self.current, self.is_new, self.abstract = name, False, prof.abstract
        self._fill(name, prof.description, prof.extends, resolved.topics + resolved.unknown_topics,
                   resolved.options)

    def _reload_current(self) -> None:
        if self.current and not self.is_new and not self.dirty:
            self._load(self.current)
        else:
            self._update_marks()

    def _fill(self, name: str, desc: str, parent: str | None, selected: list[str],
              options: RecordOptions) -> None:
        self._loading = True
        self.name_edit.setText(name)
        self.desc_edit.setText(desc)
        self.parent_combo.blockSignals(True)
        self.parent_combo.clear()
        self.parent_combo.addItem(NO_PARENT)
        blocked = self._descendants(name) | {name}
        for n in self.ctx.profile_names(include_abstract=True):
            if n not in blocked:
                self.parent_combo.addItem(n)
        self.parent_combo.setCurrentText(parent or NO_PARENT)
        self.parent_combo.blockSignals(False)
        self._build_tree(set(selected))
        self._set_options(options)
        self._loading = False
        self._resolve_parent()
        self.dirty = False
        self._update_title()

    def _descendants(self, name: str) -> set[str]:
        out, frontier = set(), [name]
        while frontier:
            n = frontier.pop()
            for kid in self.ctx.store.children(n):
                if kid not in out:
                    out.add(kid)
                    frontier.append(kid)
        return out

    def _build_tree(self, selected: set[str]) -> None:
        self.tree.blockSignals(True)
        self.tree.clear()
        cat = self.ctx.catalog
        for g in cat.groups.values():
            gi = QTreeWidgetItem([f'{g.name}  — {g.description}' if g.description else g.name])
            gi.setFlags(gi.flags() | Qt.ItemIsUserCheckable | Qt.ItemIsAutoTristate)
            gi.setData(0, Qt.UserRole, None)
            for t in g.topics.values():
                notes = [w for w, on in (('필수', t.required), ('heavy', t.heavy), ('latched', t.latched)) if on]
                ti = QTreeWidgetItem([t.name, fmt_num(t.hz), fmt_num(t.size_kb), ' '.join(notes), ''])
                ti.setFlags(ti.flags() | Qt.ItemIsUserCheckable)
                ti.setData(0, Qt.UserRole, t.name)
                ti.setCheckState(0, Qt.Checked if t.name in selected else Qt.Unchecked)
                gi.addChild(ti)
            self.tree.addTopLevelItem(gi)
        extra = sorted(s for s in selected if cat.topic(s) is None)
        if extra:
            gi = QTreeWidgetItem([UNKNOWN_GROUP])
            gi.setFlags(gi.flags() | Qt.ItemIsUserCheckable | Qt.ItemIsAutoTristate)
            for name in extra:
                ti = QTreeWidgetItem([name, '-', '-', '카탈로그에 없음', ''])
                ti.setFlags(ti.flags() | Qt.ItemIsUserCheckable)
                ti.setData(0, Qt.UserRole, name)
                ti.setCheckState(0, Qt.Checked)
                gi.addChild(ti)
            self.tree.addTopLevelItem(gi)
        self.tree.expandAll()
        self.tree.blockSignals(False)

    def selected_topics(self) -> list[str]:
        out = []
        for i in range(self.tree.topLevelItemCount()):
            g = self.tree.topLevelItem(i)
            for j in range(g.childCount()):
                t = g.child(j)
                if t.checkState(0) == Qt.Checked:
                    out.append(t.data(0, Qt.UserRole))
        return out

    def options(self) -> RecordOptions:
        values = {}
        for key, w in self.opt_widgets.items():
            values[key] = w.currentData() if isinstance(w, QComboBox) else w.value()
        return RecordOptions.from_dict(values)

    # ---- 변경 반응 -----------------------------------------------------
    def _mark_dirty(self, *_) -> None:
        if not self._loading:
            self.dirty = True
            self._update_title()

    def _on_item_changed(self, *_) -> None:
        self._mark_dirty()
        self._update_marks()

    def _on_option_changed(self, *_) -> None:
        self._mark_dirty()
        self._update_marks()

    def _on_parent_changed(self, _text: str) -> None:
        self._mark_dirty()
        self._resolve_parent()
        if self.is_new and self.parent_resolved is not None:
            # 새 프로파일은 부모 옵션에서 출발 — 기본값이 '부모와 다른 옵션'으로 저장되지 않게
            self._set_options(self.parent_resolved.options)
            self._update_marks()

    def _set_options(self, options: RecordOptions) -> None:
        loading, self._loading = self._loading, True
        for key, w in self.opt_widgets.items():
            v = getattr(options, key)
            if isinstance(w, QComboBox):
                w.setCurrentIndex(max(0, w.findData(v)))
            else:
                w.setValue(v)
        self._loading = loading

    def _resolve_parent(self) -> None:
        name = self.parent_combo.currentText()
        self.parent_resolved = None
        if name and name != NO_PARENT:
            try:
                self.parent_resolved = self.ctx.resolve(name)
            except (ProfileError, ValueError) as e:
                QMessageBox.warning(self, '부모 프로파일 오류', str(e))
        self._update_marks()

    def _update_marks(self) -> None:
        if self._loading:
            return
        base = set()
        if self.parent_resolved:
            base = set(self.parent_resolved.topics) | set(self.parent_resolved.unknown_topics)
        self.tree.blockSignals(True)
        for i in range(self.tree.topLevelItemCount()):
            g = self.tree.topLevelItem(i)
            for j in range(g.childCount()):
                t = g.child(j)
                name = t.data(0, Qt.UserRole)
                on = t.checkState(0) == Qt.Checked
                mark = ''
                if self.parent_resolved is not None:
                    if on and name not in base:
                        mark = '+ 추가'
                    elif not on and name in base:
                        mark = '- 제외'
                t.setText(4, mark)
                t.setForeground(4, QBrush(QColor('#2e7d32' if mark.startswith('+') else '#c62828')))
        self.tree.blockSignals(False)
        try:
            opts = self.options()
            sel = self.selected_topics()
            fake = ResolvedProfile(self.current or '', '', [], [s for s in sel if self.ctx.catalog.topic(s)],
                                   opts, [s for s in sel if not self.ctx.catalog.topic(s)])
            mb, unknown = estimate_mb_per_min(fake, self.ctx.catalog)
            diff = ''
            if self.parent_resolved is not None:
                d = opts.diff(self.parent_resolved.options)
                diff = '  ·  부모와 다른 옵션: ' + (', '.join(f'{OPTION_LABELS.get(k, k)}={v}' for k, v in d.items()) or '없음')
            self.estimate.setText(f'선택 {len(sel)}개 · 예상 약 {mb:,.0f} MB/분 ({mb * 60 / 1024:,.1f} GB/시간)'
                                  + (f' — 크기 미상 {len(unknown)}개 제외' if unknown else '') + diff)
        except ProfileError as e:
            self.estimate.setText(f'<span style="color:#c62828">옵션 오류: {e}</span>')

    def _update_title(self) -> None:
        self.save_btn.setText('저장 *' if self.dirty else '저장')

    # ---- 저장·생성·삭제 ------------------------------------------------
    def _save(self) -> None:
        if not self.current:
            return
        try:
            opts = self.options()
            prof = profile_from_selection(self.current, self.desc_edit.text().strip(),
                                          self.selected_topics(), opts, self.ctx.catalog,
                                          self.parent_resolved)
            if self.abstract:
                prof.abstract = True
                if self.parent_resolved is None:
                    prof.options = opts.to_dict()     # 공통 프로파일은 옵션을 전부 적어 둔다
            self.ctx.store.save(prof, self.ctx.catalog)
        except (ProfileError, ValueError) as e:
            QMessageBox.warning(self, '저장 실패', str(e))
            return
        self.is_new = False
        self.dirty = False
        self._update_title()
        self.ctx.profiles_changed.emit()
        self._load(self.current)

    def _ask_name(self, title: str) -> str | None:
        name, ok = QInputDialog.getText(self, title, '이름 (영문 소문자·숫자·_):')
        name = name.strip()
        if not ok or not name:
            return None
        if not PROFILE_NAME_RE.match(name):
            QMessageBox.warning(self, '이름 오류', '영문 소문자·숫자·_ 만 쓸 수 있습니다.')
            return None
        if name in self.ctx.store.names():
            QMessageBox.warning(self, '이름 오류', f'이미 있는 프로파일: {name}')
            return None
        return name

    def _new(self) -> None:
        if self.dirty and not self._confirm_discard():
            return
        name = self._ask_name('새 프로파일')
        if not name:
            return
        parent = 'base' if 'base' in self.ctx.store.names() else None
        opts = self.ctx.resolve(parent).options if parent else RecordOptions()
        self.current, self.is_new, self.abstract = name, True, False
        self._fill(name, '', parent, [], opts)
        self.dirty = True
        self._update_title()

    def _duplicate(self) -> None:
        if not self.current:
            return
        src = self.current
        sel, opts, parent = self.selected_topics(), self.options(), self.parent_combo.currentText()
        name = self._ask_name(f'{src} 복제')
        if not name:
            return
        self.current, self.is_new, self.abstract = name, True, False
        self._fill(name, f'{self.desc_edit.text()} (복제: {src})', None if parent == NO_PARENT else parent,
                   sel, opts)
        self.dirty = True
        self._update_title()

    def _delete(self) -> None:
        if not self.current or self.is_new:
            return
        if QMessageBox.question(self, '삭제', f'프로파일 {self.current}을(를) 삭제할까요?\n'
                                f'({self.ctx.store.path(self.current)})') != QMessageBox.Yes:
            return
        try:
            self.ctx.store.delete(self.current)
        except (ProfileError, OSError) as e:
            QMessageBox.warning(self, '삭제 실패', str(e))
            return
        self.current = None
        self.dirty = False
        self.ctx.profiles_changed.emit()

"""설정 탭 — 저장 경로 등 차량별 설정 (~/.config/scv_logger/settings.yaml)."""
from __future__ import annotations

from dataclasses import replace

from PyQt5.QtWidgets import (QDoubleSpinBox, QFileDialog, QFormLayout, QGroupBox, QHBoxLayout,
                             QLabel, QLineEdit, QMessageBox, QPlainTextEdit, QPushButton,
                             QVBoxLayout, QWidget)

from ..paths import settings_path
from .context import AppContext


class SettingsTab(QWidget):
    def __init__(self, ctx: AppContext):
        super().__init__()
        self.ctx = ctx
        root = QVBoxLayout(self)

        box = QGroupBox(f'설정 ({settings_path()})')
        form = QFormLayout(box)
        out_row = QHBoxLayout()
        self.output = QLineEdit()
        browse = QPushButton('찾아보기')
        browse.clicked.connect(self._browse)
        out_row.addWidget(self.output, 1)
        out_row.addWidget(browse)
        form.addRow('저장 경로', out_row)
        self.tol = QDoubleSpinBox()
        self.tol.setRange(0.1, 1.0)
        self.tol.setSingleStep(0.05)
        self.tol.setDecimals(2)
        form.addRow('주기 낮음 기준 (기준 Hz의 비율)', self.tol)
        self.stop_timeout = QDoubleSpinBox()
        self.stop_timeout.setRange(3, 300)
        self.stop_timeout.setDecimals(0)
        form.addRow('정지 대기 한도 (초)', self.stop_timeout)
        self.copy_max = QDoubleSpinBox()
        self.copy_max.setRange(0, 1000)
        self.copy_max.setDecimals(1)
        form.addRow('파라미터 사본 최대 (MB)', self.copy_max)
        self.globs = QPlainTextEdit()
        self.globs.setPlaceholderText('워크스페이스 기준 glob, 한 줄에 하나')
        form.addRow('세션에 기록할 파라미터 파일', self.globs)
        root.addWidget(box)

        info = QGroupBox('경로 정보')
        ilay = QFormLayout(info)
        ilay.addRow('워크스페이스', QLabel(str(ctx.workspace)))
        cfg = QLabel(str(ctx.config_dir))
        if not ctx.config_in_source:
            cfg.setText(f'{ctx.config_dir}\n⚠ 소스 트리가 아님 — 여기서 고친 프로파일·카탈로그는 재빌드 시 덮어써짐')
            cfg.setStyleSheet('color:#b26a00')
        ilay.addRow('카탈로그·프로파일', cfg)
        root.addWidget(info)

        btns = QHBoxLayout()
        btns.addStretch()
        save = QPushButton('저장')
        save.clicked.connect(self._save)
        btns.addWidget(save)
        root.addLayout(btns)
        root.addStretch()
        self._load()

    def _load(self) -> None:
        s = self.ctx.settings
        self.output.setText(s.output_dir)
        self.tol.setValue(s.hz_tolerance)
        self.stop_timeout.setValue(s.stop_timeout_sec)
        self.copy_max.setValue(s.param_copy_max_mb)
        self.globs.setPlainText('\n'.join(s.param_globs))

    def _browse(self) -> None:
        d = QFileDialog.getExistingDirectory(self, '저장 경로', self.output.text())
        if d:
            self.output.setText(d)

    def _save(self) -> None:
        s = replace(self.ctx.settings,
                    output_dir=self.output.text().strip() or self.ctx.settings.output_dir,
                    hz_tolerance=self.tol.value(), stop_timeout_sec=self.stop_timeout.value(),
                    param_copy_max_mb=self.copy_max.value(),
                    param_globs=[g.strip() for g in self.globs.toPlainText().splitlines() if g.strip()])
        try:
            self.ctx.save_settings(s)
        except OSError as e:
            QMessageBox.warning(self, '저장 실패', str(e))
            return
        QMessageBox.information(self, '설정', '저장했습니다.')

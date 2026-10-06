"""메인 창."""
from __future__ import annotations

from PyQt5.QtWidgets import QLabel, QMainWindow, QMessageBox, QTabWidget

from .. import __version__
from .catalog_tab import CatalogTab
from .common import LEVEL_COLOR
from .context import AppContext
from .controller import RECORDING, STOPPING, RecordingController
from .profile_tab import ProfileTab
from .record_tab import RecordTab
from .ros_bridge import RosBridge
from .sessions_tab import SessionsTab
from .settings_tab import SettingsTab


class MainWindow(QMainWindow):
    def __init__(self, ctx: AppContext, bridge: RosBridge):
        super().__init__()
        self.ctx = ctx
        self.bridge = bridge
        self.setWindowTitle(f'SCV Logger {__version__}')
        self.resize(1150, 860)
        self.controller = RecordingController(ctx, bridge)

        self.tabs = QTabWidget()
        self.record_tab = RecordTab(ctx, self.controller, bridge)
        self.tabs.addTab(self.record_tab, '녹화')
        self.tabs.addTab(ProfileTab(ctx), '프로파일')
        self.tabs.addTab(CatalogTab(ctx), '카탈로그')
        self.tabs.addTab(SessionsTab(ctx, self.controller), '세션')
        self.tabs.addTab(SettingsTab(ctx), '설정')
        self.setCentralWidget(self.tabs)

        self.msg = QLabel()
        self.statusBar().addWidget(self.msg, 1)
        self.controller.message.connect(self._on_message)
        if not ctx.config_writable:
            self._on_message('warn', f'설정 디렉토리에 쓸 수 없음: {ctx.config_dir}')

        self.controller.attach_existing()

    def _on_message(self, level: str, text: str) -> None:
        first, _, rest = text.partition('\n')
        self.msg.setText(first)
        self.msg.setStyleSheet(f'color: {LEVEL_COLOR.get(level, "#000")}')
        if level == 'error':
            QMessageBox.warning(self, '오류', text)

    def closeEvent(self, event) -> None:
        if self.controller.state in (RECORDING, STOPPING):
            r = QMessageBox.question(
                self, '녹화 중',
                '녹화는 GUI와 별개로 계속됩니다.\nGUI를 다시 열면 실행 중인 녹화에 다시 연결됩니다.\n\n창을 닫을까요?')
            if r != QMessageBox.Yes:
                event.ignore()
                return
        self.controller.shutdown()
        event.accept()

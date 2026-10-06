"""진입점: ros2 run scv_logger scv_logger"""
from __future__ import annotations

import signal
import sys

import rclpy
from PyQt5.QtCore import QTimer
from PyQt5.QtWidgets import QApplication, QMessageBox

from ..core.catalog import CatalogError
from ..core.profile import ProfileError


def main(argv: list[str] | None = None) -> None:
    argv = list(sys.argv if argv is None else argv)
    rclpy.init(args=argv)
    app = QApplication(rclpy.utilities.remove_ros_args(argv))
    app.setApplicationName('SCV Logger')

    from .context import AppContext
    from .main_window import MainWindow
    from .ros_bridge import RosBridge
    try:
        ctx = AppContext()
    except (CatalogError, ProfileError, OSError) as e:
        QMessageBox.critical(None, 'SCV Logger', f'설정을 불러오지 못했습니다:\n{e}')
        rclpy.shutdown()
        sys.exit(1)

    bridge = RosBridge()
    win = MainWindow(ctx, bridge)
    win.show()

    # 터미널 Ctrl+C로도 닫히게 (Qt 이벤트 루프 중에도 파이썬 시그널 처리)
    signal.signal(signal.SIGINT, lambda *_: win.close())
    tick = QTimer()
    tick.start(300)
    tick.timeout.connect(lambda: None)

    rc = app.exec_()
    bridge.shutdown()
    if rclpy.ok():
        rclpy.shutdown()
    sys.exit(rc)


if __name__ == '__main__':
    main()

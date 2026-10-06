"""GUI 전체가 공유하는 설정 상태 (카탈로그·프로파일·사용자 설정)."""
from __future__ import annotations

import os

from PyQt5.QtCore import QObject, pyqtSignal

from ..core.catalog import Catalog
from ..core.profile import ProfileStore, ResolvedProfile
from ..core.settings import Settings
from ..paths import SOURCE_REL, find_config_dir, find_workspace_root


class AppContext(QObject):
    catalog_changed = pyqtSignal()
    profiles_changed = pyqtSignal()
    settings_changed = pyqtSignal()

    def __init__(self):
        super().__init__()
        self.workspace = find_workspace_root()
        self.config_dir = find_config_dir(self.workspace)
        self.catalog_path = self.config_dir / 'catalog.yaml'
        self.store = ProfileStore(self.config_dir / 'profiles')
        self.settings = Settings.load()
        self.catalog = Catalog.load(self.catalog_path)

    @property
    def config_in_source(self) -> bool:
        return SOURCE_REL.as_posix() in self.config_dir.as_posix()

    @property
    def config_writable(self) -> bool:
        return os.access(self.config_dir, os.W_OK)

    def save_catalog(self) -> None:
        self.catalog.save(self.catalog_path)
        self.catalog_changed.emit()

    def reload_catalog(self) -> None:
        self.catalog = Catalog.load(self.catalog_path)
        self.catalog_changed.emit()

    def save_settings(self, settings: Settings) -> None:
        settings.save()
        self.settings = settings
        self.settings_changed.emit()

    def profile_names(self, include_abstract: bool = False) -> list[str]:
        names = []
        for n in self.store.names():
            try:
                if include_abstract or not self.store.load(n).abstract:
                    names.append(n)
            except ValueError:
                names.append(n)          # 깨진 파일도 목록엔 보여서 고칠 수 있게
        return names

    def resolve(self, name: str) -> ResolvedProfile:
        return self.store.resolve(name, self.catalog)

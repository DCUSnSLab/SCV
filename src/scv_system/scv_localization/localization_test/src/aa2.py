import json
import matplotlib.pyplot as plt
from shapely.geometry import LineString
from pyproj import Transformer
import geopandas as gpd
import contextily as ctx

# —————————————————————————————————————————
# 설정
# —————————————————————————————————————————
map_file   = "/home/hanbaek2004/map/map1.json"
output_png = "/home/hanbaek2004/map/map_path_highres_xyz.png"

# UTM zone 52N → Web Mercator(EPSG:3857) 변환기
transformer = Transformer.from_crs("EPSG:32652", "EPSG:3857", always_xy=True)

# —————————————————————————————————————————
# 1) map1.json 에서 UTM 좌표 읽기
# —————————————————————————————————————————
with open(map_file, 'r') as f:
    data = json.load(f)

utm_pts = [
    (node["UtmInfo"]["Easting"], node["UtmInfo"]["Northing"])
    for node in data["Node"]
]

# —————————————————————————————————————————
# 2) Web Mercator 로 직접 변환
# —————————————————————————————————————————
eastings, northings = zip(*utm_pts)
xs_merc, ys_merc   = transformer.transform(eastings, northings)
line_merc = LineString(zip(xs_merc, ys_merc))

# GeoSeries 생성 (CRS = EPSG:3857)
gseries = gpd.GeoSeries([line_merc], crs="EPSG:3857")

# —————————————————————————————————————————
# 3) 배경 위성지도(XYZ) + 경로 그리기
# —————————————————————————————————————————
fig, ax = plt.subplots(figsize=(12, 12))

# 3-1) 경로 오버레이
gseries.plot(ax=ax, linewidth=4, edgecolor="red", alpha=0.8)

# 3-2) Esri World Imagery XYZ 타일 추가 (zoom 레벨 높여 고해상도)
ctx.add_basemap(
    ax,
    url="https://server.arcgisonline.com/ArcGIS/rest/services/World_Imagery/MapServer/tile/{z}/{y}/{x}",
    attribution="Esri World Imagery",
    zoom=19
)

# —————————————————————————————————————————
# 4) 마무리
# —————————————————————————————————————————
ax.set_axis_off()
plt.tight_layout()

# 300dpi 고해상도 PNG로 저장
plt.savefig(output_png, dpi=300, bbox_inches="tight")
plt.show()

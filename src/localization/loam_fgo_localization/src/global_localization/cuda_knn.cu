#include "loam_fgo_localization/global_localization/cuda_knn.hpp"

#include <cuda_runtime.h>

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <string>

namespace loam_fgo_localization
{
namespace
{
constexpr int kNearest = 5;
constexpr int kBlockSize = 256;
constexpr int kWarpSize = 32;
constexpr int kSurfQueriesPerBlock = kBlockSize / kWarpSize;

struct CudaAffine3x4
{
  float m[12];
};

void checkCuda(cudaError_t err, const char * context)
{
  if (err != cudaSuccess) {
    throw std::runtime_error(std::string(context) + ": " + cudaGetErrorString(err));
  }
}

__device__ void insertCandidate(
  float dist,
  int index,
  float best_dist[kNearest],
  int best_index[kNearest])
{
  if (dist >= best_dist[kNearest - 1]) {
    return;
  }
  int pos = kNearest - 1;
  while (pos > 0 && dist < best_dist[pos - 1]) {
    best_dist[pos] = best_dist[pos - 1];
    best_index[pos] = best_index[pos - 1];
    --pos;
  }
  best_dist[pos] = dist;
  best_index[pos] = index;
}

__global__ void knn5Kernel(
  const CudaPoint3 * map_points,
  int map_count,
  const CudaPoint3 * queries,
  int query_count,
  int * out_indices,
  float * out_distances)
{
  const int query_index = blockIdx.x;
  if (query_index >= query_count) {
    return;
  }

  float local_dist[kNearest];
  int local_index[kNearest];
  for (int i = 0; i < kNearest; ++i) {
    local_dist[i] = INFINITY;
    local_index[i] = -1;
  }

  const CudaPoint3 q = queries[query_index];
  for (int map_index = threadIdx.x; map_index < map_count; map_index += blockDim.x) {
    const CudaPoint3 p = map_points[map_index];
    const float dx = p.x - q.x;
    const float dy = p.y - q.y;
    const float dz = p.z - q.z;
    const float dist = dx * dx + dy * dy + dz * dz;
    insertCandidate(dist, map_index, local_dist, local_index);
  }

  __shared__ float shared_dist[kBlockSize * kNearest];
  __shared__ int shared_index[kBlockSize * kNearest];
  const int base = threadIdx.x * kNearest;
  for (int i = 0; i < kNearest; ++i) {
    shared_dist[base + i] = local_dist[i];
    shared_index[base + i] = local_index[i];
  }
  __syncthreads();

  if (threadIdx.x == 0) {
    float best_dist[kNearest];
    int best_index[kNearest];
    for (int i = 0; i < kNearest; ++i) {
      best_dist[i] = INFINITY;
      best_index[i] = -1;
    }
    for (int thread = 0; thread < blockDim.x; ++thread) {
      const int thread_base = thread * kNearest;
      for (int i = 0; i < kNearest; ++i) {
        insertCandidate(
          shared_dist[thread_base + i],
          shared_index[thread_base + i],
          best_dist,
          best_index);
      }
    }
    const int out_base = query_index * kNearest;
    for (int i = 0; i < kNearest; ++i) {
      out_indices[out_base + i] = best_index[i];
      out_distances[out_base + i] = best_dist[i];
    }
  }
}

__device__ CudaPoint3 transformPoint(const CudaAffine3x4 tf, const CudaPoint3 p)
{
  return {
    tf.m[0] * p.x + tf.m[1] * p.y + tf.m[2] * p.z + tf.m[3],
    tf.m[4] * p.x + tf.m[5] * p.y + tf.m[6] * p.z + tf.m[7],
    tf.m[8] * p.x + tf.m[9] * p.y + tf.m[10] * p.z + tf.m[11]};
}

__device__ bool solve3x3(float a[3][4], float x[3])
{
  for (int col = 0; col < 3; ++col) {
    int pivot = col;
    float pivot_abs = fabsf(a[col][col]);
    for (int row = col + 1; row < 3; ++row) {
      const float v = fabsf(a[row][col]);
      if (v > pivot_abs) {
        pivot = row;
        pivot_abs = v;
      }
    }
    if (pivot_abs < 1e-6f) {
      return false;
    }
    if (pivot != col) {
      for (int k = col; k < 4; ++k) {
        const float tmp = a[col][k];
        a[col][k] = a[pivot][k];
        a[pivot][k] = tmp;
      }
    }
    const float inv_pivot = 1.0f / a[col][col];
    for (int k = col; k < 4; ++k) {
      a[col][k] *= inv_pivot;
    }
    for (int row = 0; row < 3; ++row) {
      if (row == col) {
        continue;
      }
      const float factor = a[row][col];
      for (int k = col; k < 4; ++k) {
        a[row][k] -= factor * a[col][k];
      }
    }
  }
  x[0] = a[0][3];
  x[1] = a[1][3];
  x[2] = a[2][3];
  return isfinite(x[0]) && isfinite(x[1]) && isfinite(x[2]);
}

__device__ bool computeSurfCoeffDevice(
  const CudaPoint3 map_points[kNearest],
  const CudaPoint3 source_point,
  const CudaPoint3 point_sel,
  CudaPoint3 & coeff,
  float & intensity)
{
  float xx = 0.0f;
  float xy = 0.0f;
  float xz = 0.0f;
  float yy = 0.0f;
  float yz = 0.0f;
  float zz = 0.0f;
  float sx = 0.0f;
  float sy = 0.0f;
  float sz = 0.0f;
  for (int i = 0; i < kNearest; ++i) {
    const CudaPoint3 p = map_points[i];
    xx += p.x * p.x;
    xy += p.x * p.y;
    xz += p.x * p.z;
    yy += p.y * p.y;
    yz += p.y * p.z;
    zz += p.z * p.z;
    sx += p.x;
    sy += p.y;
    sz += p.z;
  }

  float augmented[3][4] = {
    {xx, xy, xz, -sx},
    {xy, yy, yz, -sy},
    {xz, yz, zz, -sz}};
  float plane[3];
  if (!solve3x3(augmented, plane)) {
    return false;
  }

  float pa = plane[0];
  float pb = plane[1];
  float pc = plane[2];
  float pd = 1.0f;
  const float norm = sqrtf(pa * pa + pb * pb + pc * pc);
  if (norm < 1e-6f) {
    return false;
  }
  pa /= norm;
  pb /= norm;
  pc /= norm;
  pd /= norm;

  for (int i = 0; i < kNearest; ++i) {
    const CudaPoint3 p = map_points[i];
    if (fabsf(pa * p.x + pb * p.y + pc * p.z + pd) > 0.2f) {
      return false;
    }
  }

  const float pd2 = pa * point_sel.x + pb * point_sel.y + pc * point_sel.z + pd;
  const float range = sqrtf(
    source_point.x * source_point.x +
    source_point.y * source_point.y +
    source_point.z * source_point.z);
  const float s = 1.0f - 0.9f * fabsf(pd2) / sqrtf(fmaxf(range, 1e-3f));
  if (s <= 0.1f) {
    return false;
  }

  coeff = {s * pa, s * pb, s * pc};
  intensity = s * pd2;
  return true;
}

__global__ void surfCoeffKernel(
  const CudaPoint3 * map_points,
  int map_count,
  const CudaPoint3 * source_points,
  int source_count,
  CudaAffine3x4 transform,
  CudaPoint3 * out_coefficients,
  float * out_intensities,
  unsigned char * out_valid)
{
  const int warp_id = threadIdx.x / kWarpSize;
  const int lane_id = threadIdx.x % kWarpSize;
  const int source_index = blockIdx.x * kSurfQueriesPerBlock + warp_id;
  float local_dist[kNearest];
  int local_index[kNearest];
  for (int i = 0; i < kNearest; ++i) {
    local_dist[i] = INFINITY;
    local_index[i] = -1;
  }

  __shared__ CudaPoint3 shared_map[kBlockSize];
  __shared__ float shared_dist[kBlockSize * kNearest];
  __shared__ int shared_index[kBlockSize * kNearest];

  CudaPoint3 source = {0.0f, 0.0f, 0.0f};
  CudaPoint3 query = {0.0f, 0.0f, 0.0f};
  const bool active_query = source_index < source_count;
  if (active_query) {
    source = source_points[source_index];
    query = transformPoint(transform, source);
  }

  for (int tile_start = 0; tile_start < map_count; tile_start += kBlockSize) {
    const int map_index = tile_start + threadIdx.x;
    const bool valid_map = map_index < map_count;
    shared_map[threadIdx.x] = valid_map ? map_points[map_index] : CudaPoint3{0.0f, 0.0f, 0.0f};
    __syncthreads();

    const int tile_count = min(kBlockSize, map_count - tile_start);
    if (active_query) {
      for (int tile_index = lane_id; tile_index < tile_count; tile_index += kWarpSize) {
        const CudaPoint3 p = shared_map[tile_index];
        const float dx = p.x - query.x;
        const float dy = p.y - query.y;
        const float dz = p.z - query.z;
        const float dist = dx * dx + dy * dy + dz * dz;
        insertCandidate(dist, tile_start + tile_index, local_dist, local_index);
      }
    }
    __syncthreads();
  }

  const int base = threadIdx.x * kNearest;
  for (int i = 0; i < kNearest; ++i) {
    shared_dist[base + i] = local_dist[i];
    shared_index[base + i] = local_index[i];
  }
  __syncthreads();

  if (active_query && lane_id == 0) {
    float best_dist[kNearest];
    int best_index[kNearest];
    for (int i = 0; i < kNearest; ++i) {
      best_dist[i] = INFINITY;
      best_index[i] = -1;
    }
    const int warp_thread_begin = warp_id * kWarpSize;
    for (int thread = warp_thread_begin; thread < warp_thread_begin + kWarpSize; ++thread) {
      const int thread_base = thread * kNearest;
      for (int i = 0; i < kNearest; ++i) {
        insertCandidate(
          shared_dist[thread_base + i],
          shared_index[thread_base + i],
          best_dist,
          best_index);
      }
    }

    out_valid[source_index] = 0;
    out_coefficients[source_index] = {0.0f, 0.0f, 0.0f};
    out_intensities[source_index] = 0.0f;
    if (best_index[kNearest - 1] < 0 || best_dist[kNearest - 1] >= 1.0f) {
      return;
    }

    CudaPoint3 neighbors[kNearest];
    for (int i = 0; i < kNearest; ++i) {
      neighbors[i] = map_points[best_index[i]];
    }
    CudaPoint3 coeff;
    float intensity = 0.0f;
    if (computeSurfCoeffDevice(neighbors, source, query, coeff, intensity)) {
      out_coefficients[source_index] = coeff;
      out_intensities[source_index] = intensity;
      out_valid[source_index] = 1;
    }
  }
}
}  // namespace

struct CudaKnnIndex::Impl
{
  bool available = false;
  CudaPoint3 * d_map = nullptr;
  CudaPoint3 * d_queries = nullptr;
  int * d_indices = nullptr;
  float * d_distances = nullptr;
  CudaPoint3 * d_coefficients = nullptr;
  float * d_intensities = nullptr;
  unsigned char * d_valid = nullptr;
  int map_count = 0;
  mutable int query_capacity = 0;

  Impl()
  {
    int device_count = 0;
    available = cudaGetDeviceCount(&device_count) == cudaSuccess && device_count > 0;
  }

  ~Impl()
  {
    cudaFree(d_map);
    cudaFree(d_queries);
    cudaFree(d_indices);
    cudaFree(d_distances);
    cudaFree(d_coefficients);
    cudaFree(d_intensities);
    cudaFree(d_valid);
  }

  void ensureAvailable() const
  {
    if (!available) {
      throw std::runtime_error("CUDA kNN backend requested, but no CUDA device is available");
    }
  }

  void ensureQueryCapacity(int query_count) const
  {
    if (query_count <= query_capacity) {
      return;
    }
    auto * self = const_cast<Impl *>(this);
    cudaFree(self->d_queries);
    cudaFree(self->d_indices);
    cudaFree(self->d_distances);
    cudaFree(self->d_coefficients);
    cudaFree(self->d_intensities);
    cudaFree(self->d_valid);
    checkCuda(
      cudaMalloc(&self->d_queries, sizeof(CudaPoint3) * query_count),
      "cudaMalloc queries");
    checkCuda(
      cudaMalloc(&self->d_indices, sizeof(int) * query_count * kNearest),
      "cudaMalloc indices");
    checkCuda(
      cudaMalloc(&self->d_distances, sizeof(float) * query_count * kNearest),
      "cudaMalloc distances");
    checkCuda(
      cudaMalloc(&self->d_coefficients, sizeof(CudaPoint3) * query_count),
      "cudaMalloc coefficients");
    checkCuda(
      cudaMalloc(&self->d_intensities, sizeof(float) * query_count),
      "cudaMalloc intensities");
    checkCuda(
      cudaMalloc(&self->d_valid, sizeof(unsigned char) * query_count),
      "cudaMalloc valid flags");
    self->query_capacity = query_count;
  }
};

CudaKnnIndex::CudaKnnIndex()
: impl_(std::make_unique<Impl>())
{
}

CudaKnnIndex::~CudaKnnIndex() = default;
CudaKnnIndex::CudaKnnIndex(CudaKnnIndex &&) noexcept = default;
CudaKnnIndex & CudaKnnIndex::operator=(CudaKnnIndex &&) noexcept = default;

bool CudaKnnIndex::available() const noexcept
{
  return impl_ && impl_->available;
}

std::size_t CudaKnnIndex::size() const noexcept
{
  return impl_ ? static_cast<std::size_t>(impl_->map_count) : 0U;
}

void CudaKnnIndex::setInputCloud(const std::vector<CudaPoint3> & points)
{
  impl_->ensureAvailable();
  cudaFree(impl_->d_map);
  impl_->d_map = nullptr;
  impl_->map_count = static_cast<int>(points.size());
  if (points.empty()) {
    return;
  }
  checkCuda(
    cudaMalloc(&impl_->d_map, sizeof(CudaPoint3) * points.size()),
    "cudaMalloc map");
  checkCuda(
    cudaMemcpy(
      impl_->d_map,
      points.data(),
      sizeof(CudaPoint3) * points.size(),
      cudaMemcpyHostToDevice),
    "cudaMemcpy map");
}

void CudaKnnIndex::nearestKSearch5(
  const std::vector<CudaPoint3> & queries,
  std::vector<int> & indices,
  std::vector<float> & squared_distances) const
{
  impl_->ensureAvailable();
  if (impl_->map_count < kNearest) {
    throw std::runtime_error("CUDA kNN backend needs at least five map points");
  }
  const int query_count = static_cast<int>(queries.size());
  indices.assign(queries.size() * kNearest, -1);
  squared_distances.assign(queries.size() * kNearest, std::numeric_limits<float>::infinity());
  if (queries.empty()) {
    return;
  }

  impl_->ensureQueryCapacity(query_count);
  checkCuda(
    cudaMemcpy(
      impl_->d_queries,
      queries.data(),
      sizeof(CudaPoint3) * queries.size(),
      cudaMemcpyHostToDevice),
    "cudaMemcpy queries");

  knn5Kernel<<<query_count, kBlockSize>>>(
    impl_->d_map,
    impl_->map_count,
    impl_->d_queries,
    query_count,
    impl_->d_indices,
    impl_->d_distances);
  checkCuda(cudaGetLastError(), "knn5Kernel launch");
  checkCuda(cudaDeviceSynchronize(), "knn5Kernel synchronize");
  checkCuda(
    cudaMemcpy(
      indices.data(),
      impl_->d_indices,
      sizeof(int) * indices.size(),
      cudaMemcpyDeviceToHost),
    "cudaMemcpy indices");
  checkCuda(
    cudaMemcpy(
      squared_distances.data(),
      impl_->d_distances,
      sizeof(float) * squared_distances.size(),
      cudaMemcpyDeviceToHost),
    "cudaMemcpy distances");
}

void CudaKnnIndex::computeSurfCoefficients(
  const std::vector<CudaPoint3> & source_points,
  const float transform_matrix[12],
  std::vector<CudaPoint3> & coefficients,
  std::vector<float> & coefficient_intensities,
  std::vector<unsigned char> & valid_flags) const
{
  impl_->ensureAvailable();
  if (impl_->map_count < kNearest) {
    throw std::runtime_error("CUDA surface coefficient backend needs at least five map points");
  }
  const int source_count = static_cast<int>(source_points.size());
  coefficients.assign(source_points.size(), {0.0f, 0.0f, 0.0f});
  coefficient_intensities.assign(source_points.size(), 0.0f);
  valid_flags.assign(source_points.size(), 0U);
  if (source_points.empty()) {
    return;
  }

  impl_->ensureQueryCapacity(source_count);
  checkCuda(
    cudaMemcpy(
      impl_->d_queries,
      source_points.data(),
      sizeof(CudaPoint3) * source_points.size(),
      cudaMemcpyHostToDevice),
    "cudaMemcpy surf source points");

  CudaAffine3x4 transform;
  std::copy(transform_matrix, transform_matrix + 12, transform.m);
  const int block_count = (source_count + kSurfQueriesPerBlock - 1) / kSurfQueriesPerBlock;
  surfCoeffKernel<<<block_count, kBlockSize>>>(
    impl_->d_map,
    impl_->map_count,
    impl_->d_queries,
    source_count,
    transform,
    impl_->d_coefficients,
    impl_->d_intensities,
    impl_->d_valid);
  checkCuda(cudaGetLastError(), "surfCoeffKernel launch");
  checkCuda(cudaDeviceSynchronize(), "surfCoeffKernel synchronize");
  checkCuda(
    cudaMemcpy(
      coefficients.data(),
      impl_->d_coefficients,
      sizeof(CudaPoint3) * coefficients.size(),
      cudaMemcpyDeviceToHost),
    "cudaMemcpy surf coefficients");
  checkCuda(
    cudaMemcpy(
      coefficient_intensities.data(),
      impl_->d_intensities,
      sizeof(float) * coefficient_intensities.size(),
      cudaMemcpyDeviceToHost),
    "cudaMemcpy surf intensities");
  checkCuda(
    cudaMemcpy(
      valid_flags.data(),
      impl_->d_valid,
      sizeof(unsigned char) * valid_flags.size(),
      cudaMemcpyDeviceToHost),
    "cudaMemcpy surf valid flags");
}

}  // namespace loam_fgo_localization

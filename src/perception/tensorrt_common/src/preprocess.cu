#include "preprocess.hpp"

#include <cuda_fp16.h>

#include <algorithm>

namespace tensorrt_common
{
namespace
{

__device__ float pixel(const PreprocessLaunch & p, int x, int y, int offset)
{
  return p.src[static_cast<std::size_t>(y) * p.src_pitch + x * p.channels + offset];
}

// cv::INTER_LINEAR of a uint8 image, bit for bit: weights rounded to 11-bit fixed point, the
// rows summed as integers, and the vertical step of the SIMD path (VResizeLinearVec_32s8u).
__device__ void linear_tap(double scale, int d, int size, int & i0, int & w0, int & w1)
{
  // As cv::resize: the scale in double, the coordinate rounded to float.
  float f = static_cast<float>((d + 0.5) * scale - 0.5);
  i0 = static_cast<int>(floorf(f));
  f -= i0;
  if (i0 < 0) {
    i0 = 0;
    f = 0.0F;
  }
  if (i0 >= size - 1) {
    i0 = size - 1;
    f = 0.0F;
  }
  w0 = __float2int_rn((1.0F - f) * 2048.0F);
  w1 = __float2int_rn(f * 2048.0F);
}

__device__ int linear_row(
  const PreprocessLaunch & p, int y, int x0, int x1, int w0, int w1, int offset)
{
  return static_cast<int>(pixel(p, x0, y, offset)) * w0 +
         static_cast<int>(pixel(p, x1, y, offset)) * w1;
}

__device__ float sample_linear(const PreprocessLaunch & p, int u, int v, int offset)
{
  // cv::resize turns an exact halving into INTER_AREA: the rounded mean of 2 x 2 pixels.
  if (p.src_width == 2 * p.place.width && p.src_height == 2 * p.place.height) {
    const int sum = static_cast<int>(pixel(p, 2 * u, 2 * v, offset)) +
                    pixel(p, 2 * u + 1, 2 * v, offset) + pixel(p, 2 * u, 2 * v + 1, offset) +
                    pixel(p, 2 * u + 1, 2 * v + 1, offset);
    return static_cast<float>((sum + 2) >> 2);
  }
  int x0;
  int y0;
  int a0;
  int a1;
  int b0;
  int b1;
  linear_tap(static_cast<double>(p.src_width) / p.place.width, u, p.src_width, x0, a0, a1);
  linear_tap(static_cast<double>(p.src_height) / p.place.height, v, p.src_height, y0, b0, b1);
  const int x1 = min(x0 + 1, p.src_width - 1);
  const int y1 = min(y0 + 1, p.src_height - 1);
  const int s0 = linear_row(p, y0, x0, x1, a0, a1, offset) >> 4;
  const int s1 = linear_row(p, y1, x0, x1, a0, a1, offset) >> 4;
  const int value = (((b0 * s0) >> 16) + ((b1 * s1) >> 16) + 2) >> 2;
  return static_cast<float>(min(max(value, 0), 255));
}

// cv::INTER_CUBIC: A = -0.75, edge pixels repeated.
__device__ void cubic_weights(float t, float * w)
{
  const float A = -0.75F;
  w[0] = ((A * (t + 1) - 5 * A) * (t + 1) + 8 * A) * (t + 1) - 4 * A;
  w[1] = ((A + 2) * t - (A + 3)) * t * t + 1;
  w[2] = ((A + 2) * (1 - t) - (A + 3)) * (1 - t) * (1 - t) + 1;
  w[3] = 1.0F - w[0] - w[1] - w[2];
}

// cv::INTER_CUBIC of a uint8 image: rows summed with 11-bit integer weights, columns in float
// as VResizeCubicVec_32s8u does, then rounded.
__device__ void cubic_tap(double scale, int d, int & i0, int * w)
{
  float f = static_cast<float>((d + 0.5) * scale - 0.5);
  i0 = static_cast<int>(floorf(f));
  float c[4];
  cubic_weights(f - i0, c);
  for (int k = 0; k < 4; ++k) {
    w[k] = __float2int_rn(c[k] * 2048.0F);
  }
}

__device__ float sample_cubic(const PreprocessLaunch & p, int u, int v, int offset)
{
  int x0;
  int y0;
  int wx[4];
  int wy[4];
  cubic_tap(static_cast<double>(p.src_width) / p.place.width, u, x0, wx);
  cubic_tap(static_cast<double>(p.src_height) / p.place.height, v, y0, wy);
  float rows[4];
  for (int j = 0; j < 4; ++j) {
    const int y = min(max(y0 - 1 + j, 0), p.src_height - 1);
    int row = 0;
    for (int i = 0; i < 4; ++i) {
      const int x = min(max(x0 - 1 + i, 0), p.src_width - 1);
      row += static_cast<int>(pixel(p, x, y, offset)) * wx[i];
    }
    rows[j] = static_cast<float>(row);
  }
  const float scale = 1.0F / (2048.0F * 2048.0F);
  const float sum = fmaf(
    rows[0], wy[0] * scale,
    fmaf(rows[1], wy[1] * scale, fmaf(rows[2], wy[2] * scale, rows[3] * (wy[3] * scale))));
  return fminf(fmaxf(rintf(sum), 0.0F), 255.0F);
}

// cv::INTER_AREA when shrinking: the mean over the source area under the destination pixel,
// partial pixels weighted by the covered fraction.
__device__ float sample_area(
  const PreprocessLaunch & p, int u, int v, float sx, float sy, int offset)
{
  const float x_begin = u * sx;
  const float x_end = fminf(x_begin + sx, static_cast<float>(p.src_width));
  const float y_begin = v * sy;
  const float y_end = fminf(y_begin + sy, static_cast<float>(p.src_height));
  float sum = 0.0F;
  for (int y = static_cast<int>(floorf(y_begin)); y < static_cast<int>(ceilf(y_end)); ++y) {
    const float wy = fminf(y + 1.0F, y_end) - fmaxf(static_cast<float>(y), y_begin);
    float row = 0.0F;
    for (int x = static_cast<int>(floorf(x_begin)); x < static_cast<int>(ceilf(x_end)); ++x) {
      const float wx = fminf(x + 1.0F, x_end) - fmaxf(static_cast<float>(x), x_begin);
      row += pixel(p, x, y, offset) * wx;
    }
    sum += row * wy;
  }
  return sum / ((x_end - x_begin) * (y_end - y_begin));
}

__device__ void store(float * dst, std::size_t i, float v)
{
  dst[i] = v;
}
__device__ void store(__half * dst, std::size_t i, float v)
{
  dst[i] = __float2half(v);
}

template <class T>
__global__ void preprocess(PreprocessLaunch p, T * dst)
{
  const int x = blockIdx.x * blockDim.x + threadIdx.x;
  const int y = blockIdx.y * blockDim.y + threadIdx.y;
  if (x >= p.dst_width || y >= p.dst_height) {
    return;
  }
  const int u = x - p.place.left;
  const int v = y - p.place.top;
  const bool inside = u >= 0 && v >= 0 && u < p.place.width && v < p.place.height;
  const float sx = static_cast<float>(p.src_width) / p.place.width;
  const float sy = static_cast<float>(p.src_height) / p.place.height;
  const int offsets[3] = {p.r, p.g, p.b};
  const std::size_t plane = static_cast<std::size_t>(p.dst_width) * p.dst_height;
  const std::size_t i = static_cast<std::size_t>(y) * p.dst_width + x;
  for (int c = 0; c < 3; ++c) {
    float value = p.place.pad;
    if (inside) {
      if (p.resize == Resize::Linear) {
        value = sample_linear(p, u, v, offsets[c]);
      } else if (p.resize == Resize::Cubic) {
        value = sample_cubic(p, u, v, offsets[c]);
      } else {
        value = sample_area(p, u, v, sx, sy, offsets[c]);
      }
      // cv::resize writes uint8 before the normalization of the CPU path.
      value = fminf(fmaxf(rintf(value), 0.0F), 255.0F);
    }
    store(dst, c * plane + i, (value / 255.0F - p.mean[c]) * p.inv_std[c]);
  }
}

dim3 grid_of(const PreprocessLaunch & p, dim3 block)
{
  return dim3((p.dst_width + block.x - 1) / block.x, (p.dst_height + block.y - 1) / block.y);
}

}  // namespace

void launch_preprocess(const PreprocessLaunch & p, float * dst, cudaStream_t stream)
{
  const dim3 block(32, 8);
  preprocess<<<grid_of(p, block), block, 0, stream>>>(p, dst);
}

void launch_preprocess(const PreprocessLaunch & p, void * dst_half, cudaStream_t stream)
{
  const dim3 block(32, 8);
  preprocess<<<grid_of(p, block), block, 0, stream>>>(p, static_cast<__half *>(dst_half));
}

}  // namespace tensorrt_common

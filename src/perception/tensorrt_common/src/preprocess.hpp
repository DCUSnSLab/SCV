#ifndef PREPROCESS_HPP_
#define PREPROCESS_HPP_

#include "tensorrt_common/engine.hpp"

#include <cuda_runtime_api.h>

#include <cstddef>
#include <cstdint>

namespace tensorrt_common
{

// One image, already on the device, into one CHW plane set of a network input.
struct PreprocessLaunch
{
  const std::uint8_t * src = nullptr;
  int src_width = 0;
  int src_height = 0;
  std::size_t src_pitch = 0;
  int channels = 0;
  // Byte offsets of R, G and B inside a source pixel.
  int r = 0;
  int g = 0;
  int b = 0;
  int dst_width = 0;
  int dst_height = 0;
  Placement place;
  Resize resize = Resize::Linear;
  float mean[3] = {0.0F, 0.0F, 0.0F};
  float inv_std[3] = {1.0F, 1.0F, 1.0F};
};

void launch_preprocess(const PreprocessLaunch & p, float * dst, cudaStream_t stream);
void launch_preprocess(const PreprocessLaunch & p, void * dst_half, cudaStream_t stream);

}  // namespace tensorrt_common

#endif  // PREPROCESS_HPP_

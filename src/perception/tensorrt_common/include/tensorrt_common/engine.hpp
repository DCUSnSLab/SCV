#ifndef TENSORRT_COMMON__ENGINE_HPP_
#define TENSORRT_COMMON__ENGINE_HPP_

#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace tensorrt_common
{

enum class TensorType { Float32, Float16, Int32, Int64, UInt8, Bool, Other };

struct TensorInfo
{
  std::vector<std::int64_t> shape;
  TensorType type = TensorType::Other;
  std::size_t elements = 0;
  std::size_t bytes = 0;
};

struct EngineOptions
{
  // The precision is the one of this file (FP32, FP16 or INT8 Q/DQ): the build is strongly typed.
  std::string onnx_path;
  // Built from onnx_path and written here when the file does not exist yet.
  std::string engine_path;
  std::size_t workspace_bytes = 0;
  // false rounds no float32 product to TF32, closer to ONNX Runtime and slower on Ampere.
  bool tf32 = true;
  int optimization_level = 3;
  std::string timing_cache_path;
  // A DLA core of Jetson, with the layers it cannot run left on the GPU. -1: the GPU only.
  int dla_core = -1;
};

enum class Resize { Linear, Cubic, Area };

// The rest of the input is `pad`, 0 to 255.
struct Placement
{
  int left = 0;
  int top = 0;
  int width = 0;
  int height = 0;
  float pad = 0.0F;
};

// `data` is host memory, or device memory when `on_device`. A device image belongs to a CUDA
// `stream` (a cudaStream_t) that must not finish before the work queued on the image is done.
struct ImageView
{
  std::string_view encoding;
  const std::uint8_t * data = nullptr;
  int width = 0;
  int height = 0;
  std::size_t step = 0;
  bool on_device = false;
  void * stream = nullptr;
};

// `image` itself when it is in host memory; else a copy in `buffer`, waited for.
auto host_copy(const ImageView & image, std::vector<std::uint8_t> & buffer) -> ImageView;

// Builds onnx_path and writes engine_path, also when engine_path exists.
void build_engine_file(const EngineOptions & options);

// Static shapes only.
class Engine
{
public:
  explicit Engine(const EngineOptions & options);
  ~Engine();
  Engine(const Engine &) = delete;
  Engine & operator=(const Engine &) = delete;

  [[nodiscard]] auto input_names() const -> const std::vector<std::string> &;
  [[nodiscard]] auto output_names() const -> const std::vector<std::string> &;
  [[nodiscard]] auto info(const std::string & name) const -> const TensorInfo &;

  // The float calls copy info(name).elements values, converted from or to the tensor type
  // (Float32 or Float16). Uploads and infer() are queued on one stream; downloads wait for it.
  void upload_float(const std::string & name, const float * host);
  // Resize as cv::resize, then (v / 255 - mean) / stddev into the CHW planes of image `index`.
  // Area is for shrinking only. A device image is read in place, with no copy.
  void upload_image(
    const std::string & name, std::size_t index, const ImageView & image, const Placement & place,
    Resize resize, const std::array<float, 3> & mean, const std::array<float, 3> & stddev);
  void infer();
  void download_float(const std::string & name, float * host);
  void download_raw(const std::string & name, void * host);

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace tensorrt_common

#endif  // TENSORRT_COMMON__ENGINE_HPP_

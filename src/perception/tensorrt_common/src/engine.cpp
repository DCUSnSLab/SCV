#include "tensorrt_common/engine.hpp"

#include "preprocess.hpp"
#include "tensorrt_common/image.hpp"

#include <NvInfer.h>
#include <NvOnnxParser.h>
#include <cuda_fp16.h>
#include <cuda_runtime_api.h>

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace tensorrt_common
{
namespace
{

class Logger : public nvinfer1::ILogger
{
public:
  void log(Severity severity, const char * msg) noexcept override
  {
    if (severity <= Severity::kWARNING) {
      std::fprintf(stderr, "[tensorrt] %s\n", msg);
    }
  }
};

Logger & logger()
{
  static Logger instance;
  return instance;
}

void check(cudaError_t err, const char * what)
{
  if (err != cudaSuccess) {
    throw std::runtime_error(std::string(what) + ": " + cudaGetErrorString(err));
  }
}

TensorType to_type(nvinfer1::DataType t)
{
  switch (t) {
    case nvinfer1::DataType::kFLOAT:
      return TensorType::Float32;
    case nvinfer1::DataType::kHALF:
      return TensorType::Float16;
    case nvinfer1::DataType::kINT32:
      return TensorType::Int32;
    case nvinfer1::DataType::kINT64:
      return TensorType::Int64;
    case nvinfer1::DataType::kUINT8:
      return TensorType::UInt8;
    case nvinfer1::DataType::kBOOL:
      return TensorType::Bool;
    default:
      return TensorType::Other;
  }
}

std::size_t element_size(TensorType t)
{
  switch (t) {
    case TensorType::Float32:
    case TensorType::Int32:
      return 4;
    case TensorType::Float16:
      return 2;
    case TensorType::Int64:
      return 8;
    case TensorType::UInt8:
    case TensorType::Bool:
      return 1;
    default:
      throw std::runtime_error("unsupported tensor type");
  }
}

std::vector<char> read_file(const std::string & path)
{
  std::ifstream in(path, std::ios::binary);
  return {std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
}

void write_file(const std::string & path, const void * data, std::size_t size)
{
  std::ofstream out(path, std::ios::binary);
  out.write(static_cast<const char *>(data), static_cast<std::streamsize>(size));
  if (!out) {
    throw std::runtime_error("cannot write " + path);
  }
}

void configure(
  nvinfer1::IBuilder & builder, nvinfer1::IBuilderConfig & config, const EngineOptions & options,
  std::unique_ptr<nvinfer1::ITimingCache> & cache)
{
  config.setMemoryPoolLimit(nvinfer1::MemoryPoolType::kWORKSPACE, options.workspace_bytes);
  config.setBuilderOptimizationLevel(options.optimization_level);
  if (!options.tf32) {
    config.clearFlag(nvinfer1::BuilderFlag::kTF32);
  }
  if (options.dla_core >= 0) {
    if (options.dla_core >= builder.getNbDLACores()) {
      throw std::runtime_error("this device has no DLA core " + std::to_string(options.dla_core));
    }
    config.setDefaultDeviceType(nvinfer1::DeviceType::kDLA);
    config.setDLACore(options.dla_core);
    config.setFlag(nvinfer1::BuilderFlag::kGPU_FALLBACK);
  }
  if (!options.timing_cache_path.empty()) {
    const auto blob = std::filesystem::exists(options.timing_cache_path)
                        ? read_file(options.timing_cache_path)
                        : std::vector<char>();
    cache.reset(config.createTimingCache(blob.data(), blob.size()));
    config.setTimingCache(*cache, false);
  }
}

std::vector<char> build_engine(const EngineOptions & options)
{
  std::unique_ptr<nvinfer1::IBuilder> builder(nvinfer1::createInferBuilder(logger()));
  const auto flags =
    1U << static_cast<std::uint32_t>(nvinfer1::NetworkDefinitionCreationFlag::kSTRONGLY_TYPED);
  std::unique_ptr<nvinfer1::INetworkDefinition> network(builder->createNetworkV2(flags));
  std::unique_ptr<nvonnxparser::IParser> parser(nvonnxparser::createParser(*network, logger()));
  if (!parser->parseFromFile(
        options.onnx_path.c_str(), static_cast<int>(nvinfer1::ILogger::Severity::kWARNING))) {
    throw std::runtime_error("cannot parse " + options.onnx_path);
  }
  std::unique_ptr<nvinfer1::IBuilderConfig> config(builder->createBuilderConfig());
  std::unique_ptr<nvinfer1::ITimingCache> cache;
  configure(*builder, *config, options, cache);
  std::unique_ptr<nvinfer1::IHostMemory> plan(builder->buildSerializedNetwork(*network, *config));
  if (!plan) {
    throw std::runtime_error("cannot build an engine from " + options.onnx_path);
  }
  if (cache) {
    std::unique_ptr<nvinfer1::IHostMemory> blob(config->getTimingCache()->serialize());
    write_file(options.timing_cache_path, blob->data(), blob->size());
  }
  const auto * begin = static_cast<const char *>(plan->data());
  return {begin, begin + plan->size()};
}

std::vector<char> load_or_build(const EngineOptions & options)
{
  if (std::filesystem::exists(options.engine_path)) {
    return read_file(options.engine_path);
  }
  std::fprintf(
    stderr, "[tensorrt] building %s from %s; this takes minutes\n", options.engine_path.c_str(),
    options.onnx_path.c_str());
  auto plan = build_engine(options);
  write_file(options.engine_path, plan.data(), plan.size());
  return plan;
}

}  // namespace

void build_engine_file(const EngineOptions & options)
{
  const auto plan = build_engine(options);
  write_file(options.engine_path, plan.data(), plan.size());
}

struct Engine::Impl
{
  std::unique_ptr<nvinfer1::IRuntime> runtime;
  std::unique_ptr<nvinfer1::ICudaEngine> engine;
  std::unique_ptr<nvinfer1::IExecutionContext> context;
  cudaStream_t stream = nullptr;
  std::vector<std::string> inputs;
  std::vector<std::string> outputs;
  std::map<std::string, TensorInfo> infos;
  std::map<std::string, void *> buffers;
  // Host staging for Float16 tensors, kept until the stream has used it.
  std::map<std::string, std::vector<__half>> half_staging;
  // The raw image of upload_image, grown to the largest image seen.
  std::uint8_t * image = nullptr;
  std::size_t image_bytes = 0;
  // Recorded after a device image is read, for the stream of that image to wait on.
  cudaEvent_t image_read = nullptr;

  auto buffer(const std::string & name) -> void *
  {
    const auto it = buffers.find(name);
    if (it == buffers.end()) {
      throw std::out_of_range("no tensor named " + name);
    }
    return it->second;
  }
};

Engine::Engine(const EngineOptions & options) : impl_(std::make_unique<Impl>())
{
  const auto plan = load_or_build(options);
  impl_->runtime.reset(nvinfer1::createInferRuntime(logger()));
  if (options.dla_core >= 0) {
    impl_->runtime->setDLACore(options.dla_core);
  }
  impl_->engine.reset(impl_->runtime->deserializeCudaEngine(plan.data(), plan.size()));
  if (!impl_->engine) {
    throw std::runtime_error(
      "cannot load " + options.engine_path + "; delete it to rebuild for this TensorRT and GPU");
  }
  impl_->context.reset(impl_->engine->createExecutionContext());
  check(cudaStreamCreate(&impl_->stream), "cudaStreamCreate");
  check(cudaEventCreateWithFlags(&impl_->image_read, cudaEventDisableTiming), "cudaEventCreate");

  for (int i = 0; i < impl_->engine->getNbIOTensors(); ++i) {
    const std::string name = impl_->engine->getIOTensorName(i);
    const auto dims = impl_->engine->getTensorShape(name.c_str());
    TensorInfo info;
    info.type = to_type(impl_->engine->getTensorDataType(name.c_str()));
    info.elements = 1;
    for (int d = 0; d < dims.nbDims; ++d) {
      if (dims.d[d] < 0) {
        throw std::runtime_error("tensor " + name + " has a dynamic shape; export it static");
      }
      info.shape.push_back(dims.d[d]);
      info.elements *= static_cast<std::size_t>(dims.d[d]);
    }
    info.bytes = info.elements * element_size(info.type);
    void * buffer = nullptr;
    check(cudaMalloc(&buffer, info.bytes), "cudaMalloc");
    impl_->context->setTensorAddress(name.c_str(), buffer);
    impl_->buffers[name] = buffer;
    impl_->infos[name] = info;
    const bool input =
      impl_->engine->getTensorIOMode(name.c_str()) == nvinfer1::TensorIOMode::kINPUT;
    (input ? impl_->inputs : impl_->outputs).push_back(name);
  }
}

Engine::~Engine()
{
  if (impl_->stream != nullptr) {
    cudaStreamSynchronize(impl_->stream);
    cudaStreamDestroy(impl_->stream);
  }
  for (auto & [name, buffer] : impl_->buffers) {
    cudaFree(buffer);
  }
  cudaFree(impl_->image);
  if (impl_->image_read != nullptr) {
    cudaEventDestroy(impl_->image_read);
  }
}

auto Engine::input_names() const -> const std::vector<std::string> &
{
  return impl_->inputs;
}

auto Engine::output_names() const -> const std::vector<std::string> &
{
  return impl_->outputs;
}

auto Engine::info(const std::string & name) const -> const TensorInfo &
{
  const auto it = impl_->infos.find(name);
  if (it == impl_->infos.end()) {
    throw std::out_of_range("no tensor named " + name);
  }
  return it->second;
}

void Engine::upload_float(const std::string & name, const float * host)
{
  const auto & i = info(name);
  void * device = impl_->buffer(name);
  if (i.type == TensorType::Float32) {
    check(
      cudaMemcpyAsync(device, host, i.bytes, cudaMemcpyHostToDevice, impl_->stream),
      "cudaMemcpyAsync");
    return;
  }
  if (i.type != TensorType::Float16) {
    throw std::runtime_error("tensor " + name + " is not a float tensor");
  }
  auto & staging = impl_->half_staging[name];
  staging.resize(i.elements);
  for (std::size_t k = 0; k < i.elements; ++k) {
    staging[k] = __float2half(host[k]);
  }
  check(
    cudaMemcpyAsync(device, staging.data(), i.bytes, cudaMemcpyHostToDevice, impl_->stream),
    "cudaMemcpyAsync");
}

void Engine::upload_image(
  const std::string & name, std::size_t index, const ImageView & image, const Placement & place,
  Resize resize, const std::array<float, 3> & mean, const std::array<float, 3> & stddev)
{
  const auto & i = info(name);
  const auto layout = channel_layout(image.encoding);
  PreprocessLaunch p;
  if (image.on_device) {
    p.src = image.data;
    p.src_pitch = image.step;
  } else {
    const std::size_t row = static_cast<std::size_t>(image.width) * layout.bytes;
    const std::size_t bytes = row * image.height;
    if (bytes > impl_->image_bytes) {
      check(cudaFree(impl_->image), "cudaFree");
      check(cudaMalloc(reinterpret_cast<void **>(&impl_->image), bytes), "cudaMalloc");
      impl_->image_bytes = bytes;
    }
    check(
      cudaMemcpy2DAsync(
        impl_->image, row, image.data, image.step, row, image.height, cudaMemcpyHostToDevice,
        impl_->stream),
      "cudaMemcpy2DAsync");
    p.src = impl_->image;
    p.src_pitch = row;
  }
  p.src_width = image.width;
  p.src_height = image.height;
  p.r = layout.r;
  p.g = layout.g;
  p.b = layout.b;
  p.channels = layout.bytes;
  p.dst_height = static_cast<int>(i.shape.at(i.shape.size() - 2));
  p.dst_width = static_cast<int>(i.shape.back());
  p.place = place;
  p.resize = resize;
  for (int c = 0; c < 3; ++c) {
    p.mean[c] = mean[c];
    p.inv_std[c] = 1.0F / stddev[c];
  }
  const std::size_t offset = index * 3 * static_cast<std::size_t>(p.dst_width) * p.dst_height;
  if (offset + 3 * static_cast<std::size_t>(p.dst_width) * p.dst_height > i.elements) {
    throw std::out_of_range("image index past tensor " + name);
  }
  if (i.type == TensorType::Float32) {
    launch_preprocess(p, static_cast<float *>(impl_->buffer(name)) + offset, impl_->stream);
  } else if (i.type == TensorType::Float16) {
    launch_preprocess(p, static_cast<__half *>(impl_->buffer(name)) + offset, impl_->stream);
  } else {
    throw std::runtime_error("tensor " + name + " is not a float tensor");
  }
  check(cudaGetLastError(), "preprocess kernel");
  // The publisher gets the image back once its stream has passed this point. The kernel may
  // still be queued when the subscription callback returns (several views, one inference).
  if (image.on_device && image.stream != nullptr) {
    check(cudaEventRecord(impl_->image_read, impl_->stream), "cudaEventRecord");
    check(
      cudaStreamWaitEvent(static_cast<cudaStream_t>(image.stream), impl_->image_read, 0),
      "cudaStreamWaitEvent");
  }
}

auto host_copy(const ImageView & image, std::vector<std::uint8_t> & buffer) -> ImageView
{
  if (!image.on_device) {
    return image;
  }
  const std::size_t row =
    static_cast<std::size_t>(image.width) * channel_layout(image.encoding).bytes;
  buffer.resize(row * image.height);
  const auto stream = static_cast<cudaStream_t>(image.stream);
  check(
    cudaMemcpy2DAsync(
      buffer.data(), row, image.data, image.step, row, image.height, cudaMemcpyDeviceToHost,
      stream),
    "cudaMemcpy2DAsync");
  check(cudaStreamSynchronize(stream), "cudaStreamSynchronize");
  return {image.encoding, buffer.data(), image.width, image.height, row};
}

void Engine::infer()
{
  if (!impl_->context->enqueueV3(impl_->stream)) {
    throw std::runtime_error("TensorRT enqueue failed");
  }
}

void Engine::download_float(const std::string & name, float * host)
{
  const auto & i = info(name);
  if (i.type == TensorType::Float32) {
    download_raw(name, host);
    return;
  }
  if (i.type != TensorType::Float16) {
    throw std::runtime_error("tensor " + name + " is not a float tensor");
  }
  std::vector<__half> half(i.elements);
  download_raw(name, half.data());
  for (std::size_t k = 0; k < i.elements; ++k) {
    host[k] = __half2float(half[k]);
  }
}

void Engine::download_raw(const std::string & name, void * host)
{
  const auto & i = info(name);
  check(
    cudaMemcpyAsync(host, impl_->buffer(name), i.bytes, cudaMemcpyDeviceToHost, impl_->stream),
    "cudaMemcpyAsync");
  check(cudaStreamSynchronize(impl_->stream), "cudaStreamSynchronize");
}

}  // namespace tensorrt_common

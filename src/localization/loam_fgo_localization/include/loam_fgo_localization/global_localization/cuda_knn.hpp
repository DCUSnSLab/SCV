#pragma once

#include <cstddef>
#include <memory>
#include <vector>

namespace loam_fgo_localization
{

struct CudaPoint3
{
  float x;
  float y;
  float z;
};

class CudaKnnIndex
{
public:
  CudaKnnIndex();
  ~CudaKnnIndex();

  CudaKnnIndex(const CudaKnnIndex &) = delete;
  CudaKnnIndex & operator=(const CudaKnnIndex &) = delete;
  CudaKnnIndex(CudaKnnIndex &&) noexcept;
  CudaKnnIndex & operator=(CudaKnnIndex &&) noexcept;

  bool available() const noexcept;
  std::size_t size() const noexcept;
  void setInputCloud(const std::vector<CudaPoint3> & points);
  void nearestKSearch5(
    const std::vector<CudaPoint3> & queries,
    std::vector<int> & indices,
    std::vector<float> & squared_distances) const;
  void computeSurfCoefficients(
    const std::vector<CudaPoint3> & source_points,
    const float transform_matrix[12],
    std::vector<CudaPoint3> & coefficients,
    std::vector<float> & coefficient_intensities,
    std::vector<unsigned char> & valid_flags) const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace loam_fgo_localization

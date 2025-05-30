// Copyright 2021 Tier IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef AUTOWARE__PROBABILISTIC_OCCUPANCY_GRID_MAP__UPDATER__BINARY_BAYES_FILTER_UPDATER_KERNEL_HPP_
#define AUTOWARE__PROBABILISTIC_OCCUPANCY_GRID_MAP__UPDATER__BINARY_BAYES_FILTER_UPDATER_KERNEL_HPP_

#include <cuda_runtime.h>

#include <cstdint>

namespace autoware::occupancy_grid_map
{
namespace costmap_2d
{

void applyBBFLaunch(
  const std::uint8_t * z_costmap, const float * probability_matrix, const int num_states,
  const int free_index, const int occupied_index, const std::uint8_t free_space_value,
  const std::uint8_t lethal_obstacle_value, const std::uint8_t no_information_value,
  const double v_ratio_, const int num_elements, std::uint8_t * o_costmap, cudaStream_t stream);

}  // namespace costmap_2d
}  // namespace autoware::occupancy_grid_map

#endif  // AUTOWARE__PROBABILISTIC_OCCUPANCY_GRID_MAP__UPDATER__BINARY_BAYES_FILTER_UPDATER_KERNEL_HPP_

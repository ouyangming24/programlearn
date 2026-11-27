#pragma once

#include <cstdint>

// 与阶段 2 相同的数据契约：一帧测量。
struct Frame {
  std::uint64_t sequence = 0;
  double timestamp_s = 0.0;
  double value = 0.0;
};

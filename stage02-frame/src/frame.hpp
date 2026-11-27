#pragma once

#include <cstdint>

// 一帧 = 管线里流动的最小数据包（模拟「仪器采到的一次测量」）。
// 用 struct：像 C 的结构体，把相关字段捆在一起；后面 source/process/sink 都认这一份约定。
struct Frame {
  std::uint64_t sequence = 0;  // 第几帧，从 0 起
  double timestamp_s = 0.0;    // 相对时间，单位秒
  double value = 0.0;          // 测量值（先当一个标量通道）
};

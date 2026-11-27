#pragma once

#include "frame.hpp"

// 模拟传感器：按固定采样间隔产出 Frame。
// class：把「相关数据 + 操作」捆在一起；默认成员是 private（外面不能直接改内部计数）。
class SimulatedSource {
 public:
  // 构造时约定：一共采多少帧、采样间隔（秒）。
  SimulatedSource(std::uint64_t total_frames, double sample_period_s);

  // 还有下一帧吗？
  bool has_next() const;

  // 取出下一帧；若已采完，行为未定义——调用前先 has_next()。
  Frame next_frame();

 private:
  std::uint64_t total_frames_;
  std::uint64_t next_index_;
  double sample_period_s_;
};

#include "source.hpp"

#include <cmath>

SimulatedSource::SimulatedSource(std::uint64_t total_frames, double sample_period_s)
    : total_frames_(total_frames),
      next_index_(0),
      sample_period_s_(sample_period_s) {}

bool SimulatedSource::has_next() const {
  return next_index_ < total_frames_;
}

Frame SimulatedSource::next_frame() {
  Frame frame;
  frame.sequence = next_index_;
  frame.timestamp_s = static_cast<double>(next_index_) * sample_period_s_;
  // 模拟信号：正弦 + 一点点「噪声感」的偏移，方便后面做滤波对照。
  frame.value = std::sin(frame.timestamp_s * 2.0) + 0.1 * static_cast<double>(next_index_ % 5);
  ++next_index_;
  return frame;
}

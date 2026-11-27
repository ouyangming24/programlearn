#include <iostream>

#include "source.hpp"

int main() {
  // 阶段 3：用模拟源拉若干帧并打印（尚未处理/落盘）。
  SimulatedSource source(/*total_frames=*/5, /*sample_period_s=*/0.1);

  while (source.has_next()) {
    const Frame frame = source.next_frame();
    std::cout << "frame #" << frame.sequence
              << " t=" << frame.timestamp_s << "s"
              << " value=" << frame.value << '\n';
  }
  return 0;
}

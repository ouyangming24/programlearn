#include <iostream>

#include "frame.hpp"

int main() {
  // 阶段 2：还没有真源/处理，先手工造一帧，确认「契约」能被 main 使用。
  Frame demo;
  demo.sequence = 0;
  demo.timestamp_s = 0.0;
  demo.value = 1.23;

  std::cout << "frame #" << demo.sequence
            << " t=" << demo.timestamp_s << "s"
            << " value=" << demo.value << '\n';
  return 0;
}

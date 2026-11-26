# sensor-pipeline

采集处理管线教学工程（阶段 1：骨架）。

## 编译与运行

```bash
cmake -S . -B build
cmake --build build
./build/sensor_pipeline
```

期望输出：

```text
Hello, sensor-pipeline
```

## 当前阶段

- 阶段 1：CMake + Hello
- 阶段 2：`src/frame.hpp` 定义一帧；`main` 打印演示帧
- 后续：`source` / `process` / `sink`

## 阶段 2 期望输出

```text
frame #0 t=0s value=1.23
```

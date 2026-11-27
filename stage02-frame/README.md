# 阶段 2：数据契约 Frame

本目录在阶段 1 骨架上增加 `src/frame.hpp`，`main` 手工构造并打印一帧。

## CLion

**File → Open** 选本目录（`stage02-frame`，根上有 `CMakeLists.txt`），运行目标 `sensor_pipeline`。

## 命令行

```bash
cmake -S . -B build
cmake --build build
./build/sensor_pipeline
```

期望输出：

```text
frame #0 t=0s value=1.23
```

对应课笔记：仓库根 `docs/lessons/02-frame-and-struct.md`。

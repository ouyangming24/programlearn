# 阶段 1：工程骨架（CMake + Hello）

本目录是独立可打开的 CMake 工程，只做「能配置、能编译、能跑」。

## CLion

**File → Open** 选本目录（`stage01-skeleton`，根上有 `CMakeLists.txt`），运行目标 `sensor_pipeline`。

## 命令行

```bash
cmake -S . -B build
cmake --build build
./build/sensor_pipeline
```

期望输出：

```text
Hello, sensor-pipeline
```

对应课笔记：仓库根 `docs/lessons/01-cmake-and-project-layout.md`。

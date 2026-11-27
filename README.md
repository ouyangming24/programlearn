# programlearn

采集处理管线教学仓库。每个阶段是**独立子目录工程**，请分别 Open，不要打开仓库根当 CMake 工程。

## 目录

| 目录 | 阶段 | 内容 |
|------|------|------|
| `stage01-skeleton/` | 1 | CMake + Hello |
| `stage02-frame/` | 2 | `Frame` 契约 + 打印演示帧 |
| `docs/lessons/` | — | 课笔记（含自测参考答案） |

后续阶段会继续新增 `stage03-*` 等目录，互不覆盖。

## 用 CLion

1. **File → Open**
2. 选某一个阶段目录，例如 `…/programlearn/stage02-frame`（该目录内必须能看到 `CMakeLists.txt`）
3. 等 CMake 加载完成，运行配置选 `sensor_pipeline`

不要 Open 仓库根目录：根上没有面向整仓的 `CMakeLists.txt`。

## 命令行示例（阶段 2）

```bash
cd stage02-frame
cmake -S . -B build
cmake --build build
./build/sensor_pipeline
```

可执行文件目标名均为 `sensor_pipeline`（CMake ≥ 3.16，C++17）。

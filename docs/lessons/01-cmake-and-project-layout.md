# 课 01：工程骨架与 CMake（对应阶段 1）

> 用 C 的直觉对照：以前可能是 `gcc main.c -o app`；项目变大后用 **CMake** 描述「有哪些源文件、怎么编译」，再生成真正的构建命令。

## 本步目标

- 有一个叫 `sensor-pipeline` 的目录
- 能配置、编译，跑出 `Hello, sensor-pipeline`
- 知道 `CMakeLists.txt`、`src/main.cpp` 各自干什么

## 目录在干什么

| 路径 | 作用 |
|------|------|
| `CMakeLists.txt` | 告诉 CMake：项目名、C++ 标准、可执行文件由哪些 `.cpp` 组成 |
| `src/main.cpp` | 程序入口（类似 C 的 `main`） |
| `README.md` | 给人看的：怎么编译、怎么跑 |
| `build/` | **生成目录**，不要手改；编译产物放这里 |

## CMake 最少要会的几行

- `cmake_minimum_required`：最低 CMake 版本
- `project(...)`：项目名
- `set(CMAKE_CXX_STANDARD 17)`：用 C++17（后面会用到更现代的写法，但我们会逐个讲）
- `add_executable(名字 源文件...)`：生成可执行文件

## 本地怎么编译（你机器上）

命令行：

```bash
cd sensor-pipeline
cmake -S . -B build
cmake --build build
./build/sensor_pipeline
```

**CLion**：File → Open，选带根 `CMakeLists.txt` 的 `sensor-pipeline` 目录 → 等右下角 CMake 加载完成 → 运行配置选 `sensor_pipeline` → 运行。输出应在下方 Run 窗口。

期望输出：`Hello, sensor-pipeline`

## 和「从 main.cpp 硬写」的差别

- `main` 只是入口；后面源、处理、输出会拆成多个文件
- 构建规则集中在 CMake，而不是记一长串 gcc 命令

## 自测

1. 改一句打印文字，重新 `cmake --build build`，能看到新输出吗？
2. 不用清掉整个 `build/`，改源码后一般只需再 build。

### 参考答案

1. **能。** 改的是源码，重新 build 会重编并链出新可执行文件，再运行就能看到新文字。CLion 里点运行通常也会先自动 build。
2. **对。** `build/` 是生成目录；改 `.cpp` 后增量编译即可。只有大改 CMake、换工具链或配置坏了时，才需要清 `build/` 或 Reload CMake。

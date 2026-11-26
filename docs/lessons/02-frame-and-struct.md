# 课 02：数据契约与 `struct`（对应阶段 2）

## 为什么先定「一帧」

管线里各模块要说同一种话。先约定 **Frame**（一帧），再写 source / process / sink，避免每人字段各写一套。

仪器软件里这叫 **数据契约**（data contract）：字段含义、单位、编号规则写清楚。

## `struct` 和 C 的关系

- C 里：`struct Frame { ... };`
- C++ 里几乎一样；默认成员是 `public`（外面可以直接读写字段）
- 后面学 `class` 时再对比：`class` 默认是 `private`

本课用 `struct Frame`，先当「一捆字段」。

## 头文件要点

| 写法 | 含义 |
|------|------|
| `#pragma once` | 同一编译单元里这个头只包含一次（防重复定义） |
| `#include <cstdint>` | 固定宽度整数，如 `std::uint64_t` |
| `frame.hpp` 无 `.cpp` | 只有类型定义、无函数实现时，常只放头文件 |

## 本步字段

- `sequence`：帧序号
- `timestamp_s`：时间（秒）
- `value`：一个标量测量值（以后可扩成数组/多通道）

刻意保持简单；FPGA 联调时往往再加通道号、状态位、校验等。

## CLion 操作

1. 在 `src/` 新建 `frame.hpp`（内容见骨架）
2. 改 `src/main.cpp`：`#include "frame.hpp"`，构造并打印一帧
3. **CMake 不用改**：头文件不进 `add_executable`；只有 `.cpp` 要列进去
4. 若提示找不到 `frame.hpp`：确认文件在 `src/`，且 `main.cpp` 也在 `src/`（同目录用 `"frame.hpp"` 即可）
5. Reload CMake（若需要）→ 运行，应看到类似：`frame #0 t=0s value=1.23`

## 自测

1. 改 `value` 再运行，输出是否变？
2. 能否用一句话说清：为什么 source 和 sink 都要依赖同一份 `Frame`？

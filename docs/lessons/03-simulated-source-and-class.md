# 课 03：模拟源与 `class`（对应阶段 3）

## 本步目标

- 有一个 `SimulatedSource`，能连续产出多帧 `Frame`
- 理解：**头文件声明 / `.cpp` 实现 / CMake 把两者链进可执行文件**
- 初识 `class`、构造函数、`public` / `private`

## 和 C 对照

| C 里常见写法 | 本步 C++ |
|--------------|----------|
| 一堆全局变量 + 函数 | 成员变量藏在对象里，用成员函数操作 |
| `struct` 只有数据 | `class` 默认 private，强调「外面别乱摸内部状态」 |

`Frame` 仍用 `struct`（纯数据）；`SimulatedSource` 用 `class`（有状态：下一帧下标）。

## 关键语法（先够用）

- `SimulatedSource::next_frame`：`::` 表示「属于这个类的函数」在 `.cpp` 里实现
- 构造函数与类同名，创建对象时自动调用
- `const` 写在 `has_next() const`：承诺不修改对象状态
- `return frame;`：按值返回一帧（简单清楚；以后再谈引用/移动）

## 文件怎么连起来

1. `main.cpp` → `#include "source.hpp"`（只要声明）
2. `source.cpp` → 写实现，并 `#include "source.hpp"`
3. `CMakeLists.txt` → `add_executable(... src/main.cpp src/source.cpp)`

漏掉 `source.cpp` 会链接失败：找不到 `SimulatedSource` 的函数定义。

## CLion

Open `stage03-source/` → Reload CMake → 运行 `stage03_source` → 应看到 5 行帧输出。

## 自测

1. 若 CMake 只写了 `src/main.cpp`、漏了 `source.cpp`，会在哪一步失败？编译还是链接？
2. 为什么 `next_index_` 放在 `private`？

### 参考答案

1. **链接阶段失败**（有的 IDE 统称 build failed）。`main` 能通过编译（看见了声明），但链接器找不到实现。
2. **防止外部随便改内部进度**；只通过 `has_next` / `next_frame` 推进，状态不容易被用乱。

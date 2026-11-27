# 课 03：模拟源（先语法，再代码）

> 约定：本课出现的新语法都会先讲清楚，再对照工程文件。

## 0. 本步要做成什么

用软件假装一台传感器：连续产出多帧 `Frame`，在 `main` 里打印出来。  
硬件以后再换；现在先学会「源」这个模块怎么拆文件。

---

## 1. 语法：为什么需要比 `struct` 更多一点的东西

阶段 2 的 `Frame` 只是**一捆数据**（序号、时间、数值），用 `struct` 很合适。

模拟源除了数据，还有**会变化的状态**（下一帧是第几帧）和**操作**（还有没有下一帧、取出下一帧）。  
可以把状态和操作捆成一个「对象」。C++ 里常用 `class` 来写这种对象。

用 C 的直觉对照：

| 你在 C 里可能怎么做 | 本课对应 |
|---------------------|----------|
| 几个全局变量 + 一组函数 | 成员变量 + 成员函数，装在一个类型里 |
| 靠注释约定「别乱改某个变量」 | 用 `private` 从语法上挡住乱改 |

---

## 2. 语法：`class`、`public`、`private`

最小样子：

```cpp
class SimulatedSource {
 public:
  // 外面（例如 main）可以调用的部分 = 接口
  bool has_next() const;
  Frame next_frame();

 private:
  // 只有类自己的函数能碰 = 内部状态
  std::uint64_t next_index_;
};
```

- **`public:`** 下面的名字，类外面能用。  
- **`private:`** 下面的名字，类外面不能写 `source.next_index_ = 99;` 这种。  
- 名字末尾的 `_`：团队习惯，提醒「这是私有成员」（不是语法强制）。

`struct` 默认是 public；`class` 默认是 private。我们写 `Frame` 用 struct、写源用 class，是习惯上的分工，不是绝对法令。

---

## 3. 语法：构造函数

```cpp
SimulatedSource source(5, 0.1);
```

这里会调用与类同名的函数，叫**构造函数**：创建对象时自动执行，用来把 `total_frames_`、`sample_period_s_` 设好。  
在 `.cpp` 里常见写法：

```cpp
SimulatedSource::SimulatedSource(std::uint64_t total_frames, double sample_period_s)
    : total_frames_(total_frames),
      next_index_(0),
      sample_period_s_(sample_period_s) {}
```

- 第一个 `SimulatedSource`：类名  
- `::`：属于这个类  
- 第二个 `SimulatedSource`：构造函数名（与类同名）  
- 冒号后面：给成员变量赋初值（成员初始化列表）

---

## 4. 语法：声明在 `.hpp`，实现在 `.cpp`

- **声明**：告诉编译器「有这个函数、参数和返回类型是什么」（头文件）  
- **实现**：函数体真正干活（源文件）

`main.cpp` 只 `#include "source.hpp"`，编译 `main` 时够用。  
链接时还要把编译好的 `source.cpp` 凑进来，所以 CMake 要写：

```cmake
add_executable(stage03_source
  src/main.cpp
  src/source.cpp
)
```

漏掉 `source.cpp` → 往往在**链接**时报「找不到定义」。

---

## 5. 语法：`has_next() const`

末尾的 `const` 表示：这个成员函数**保证不修改**对象内部状态，只读。  
有助于读代码的人放心：问「还有没有下一帧」不会偷偷把计数器改掉。

---

## 6. 对照工程（CLion）

Open 仓库里的 `stage03-source/`（不要 Open 仓库根）：

| 文件 | 角色 |
|------|------|
| `src/frame.hpp` | 数据契约（阶段 2 原样） |
| `src/source.hpp` | `SimulatedSource` 的声明（接口） |
| `src/source.cpp` | 构造、`has_next`、`next_frame` 的实现 |
| `src/main.cpp` | 创建源，循环取帧并打印 |
| `CMakeLists.txt` | 把 `main.cpp` + `source.cpp` 链成程序 |

期望：运行后打印 5 行 `frame #...`。

---

## 7. 自测

1. `public` 和 `private` 各管什么？  
2. 若 CMake 只写了 `src/main.cpp`、漏了 `source.cpp`，多半在哪一步失败？  
3. 构造函数什么时候被调用？

### 参考答案

1. `public`：外面能用的接口；`private`：内部状态，外面不能直接改。  
2. **链接**阶段（声明看得到，实现找不到）。  
3. **创建对象时**，例如 `SimulatedSource source(5, 0.1);`。

# Course-Paper-for-Introduction-to-Computer

《计算机引论》结课论文《怎么判断一段程序好不好——基于三组对比实验的分析》的附录代码。

## 环境
AMD Ryzen 7 H 260 · GCC 16.1.0 (MinGW) · 编译不开启优化（-O0）

## 编译与运行
gcc -O0 A1-insertion.c -o A1 && ./A1

## 文件与论文对应关系
| 文件 | 实验 | 对应数据 |
|---|---|---|
| A1-insertion.c | 插入排序（计时+比较/搬移计数） | 表 1 左三列 |
| A2-qsort.c | 库函数 qsort（比较计数） | 表 1 右两列 |
| B1-sequential_stack_block5.c | 顺序栈，每次扩容 +5 | 正文 2.1005 s |
| B2-sequential_stack_double.c | 顺序栈，扩容 cap*=2 | 正文 0.0106 s |
| B3-linked_stack.c | 链栈 | 正文 21.6014 s |
| C1-binary_search_sentinel.c | 哨兵二分查找（比较计数） | 表 2 二分列 |
| C2-sequential_search.c | 顺序查找（比较计数） | 表 2 顺序列 |

## 可复现性说明
A 组计数由固定随机种子 srand(42) 保证确定；计时为单次运行结果，毫秒级抖动正常。
B 组为 10 次取平均。B 组结论依赖 realloc/malloc 的实现：本仓库数据基于 Windows/MinGW。

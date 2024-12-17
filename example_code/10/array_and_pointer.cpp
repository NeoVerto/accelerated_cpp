#include <algorithm>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::copy;

using std::vector;

int main()
{
  const int NDim = 3;
  double coord[NDim];
  /**
   * 数组与指针
   * - 若 p 指向数组的第 m 个元素, 则 (p + n) 指向第 (m + n) 个元素, (p - n) 指
   *   向第 (m - n) 个元素.
   * - 对数组前面的地址计算被视为非法. 只有 a + i (0 <= i <= n) 是有效的, 且
   *   i = n 时指向数组最后一个元素的后一个位置.
   */

  /**
   * 指针之差
   * - (p - q) 表示 p 和 q 所指向的元素在数组中的间距.
   * - 类型为 ptrdiff_t, 定义在 <cstddef> 中, 为有符号整数.
   */

  // 复制进 vector
  vector<int> dotA;
  copy(coord, coord + NDim, back_inserter(dotA));

  // 初始化 vector
  vector<int> dotB(coord, coord + NDim);

  // 数组支持索引
  coord[1] = 1.5; // 等价于 *(coord + 1) = 1.5;

  // 数组初始化
  const int month_lengths[] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
  };
  /**
   * 通过 = {} 初始化, 由编译器确定元素个数.
   */

  return 0;
}
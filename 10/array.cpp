#include <cstddef>

using std::size_t;

int main()
{
  const size_t NDim = 3;
  double coords[NDim];
  /**
   * 数组
   * - 核心语言的一部分.
   * - 一种容器, 类似 vector.
   * - C++ 要求数组元素的个数必须在编译时确定.
   *   - PS: int arr[n]; 的写法属于非标准扩展, 依赖于编译器 (如 GCC 和 Clang 支
   *     持 VLA), 但这不是标准 C++ 的特性.
   */
  *coords = 1.5;
  /**
   * 数组与指针
   * - 数组名表示指向数组首元素的指针.
   */

  return 0;
}
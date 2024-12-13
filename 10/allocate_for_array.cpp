#include <algorithm>
#include <cstring>

using std::copy;
using std::strlen;

char *duplicate_chars(const char *p)
{
  // 分配足够的内存空间 (记住要为空字符预留空间)
  size_t length = strlen(p) + 1;
  char *result = new char[length];
  /**
   * new 关键字
   * - 语法: 类型 *指针名 = new 类型[长度]
   * - 为一个 n 个 T 类型对象的数组分配内存, 并返回一个指向数组首元素的指针.
   * - 每个对象都将默认初始化. 对自定义类型, 若不允许默认初始化, 编译器将终止程
   *   序.
   * - 若 n = 0, new 无法返回一个指向首元素的指针, 此时返回一个有效但无意义的
   *   off-the-end 指针. 该值可作为 delete[] 的参数使用.
   *   - off-the-end 指针存在的目的是为了下列类似情况, 程序仍能继续执行:
   *     T *p = new T[n];
   *     vector<T> v(p, p + n);
   *     delete[] p;
   */

  /**
   * delete[] 关键字
   * - 语法: delete[] 指针名;
   * - 用于释放掉整个数组所占用的内存.
   */

  // 复制进新分配的内存空间并返回指向首元素的指针
  copy(p, p + length, result);

  return result;
}
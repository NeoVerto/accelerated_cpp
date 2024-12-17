#include "median.h"

#include <stdexcept>
#include <vector>

using std::domain_error;
using std::vector;

template <class T>
/**
 * template <class T> 模板头
 * - 告知系统环境定义的是模板函数, 且该函数有一类型参数 T.
 */
T median(vector<T> v)
/**
 * 类型参数 T
 * - 类型参数的操作类似其他函数参数, 但其表示类型. 无论其出现在函数的任何地方,
 * 系统环境认为其命名了一个类型.
 * - 调用函数时, 系统环境在编译期间将其判定的一个类型赋给 T.
 */

/**
 * 模板实例化
 * - 对那些沿用了传统的编辑--编译--链接模式的系统环境, 实例化动作经常在链接期间
 * 发生.
 * - 为了对模板实例化, 当前大多数系统环境都要求这个模板的定义必须是系统环境可以
 * 访问的.
 */
{
  typedef typename vector<T>::size_type vec_sz;
  /**
   * typename
   * - 告知系统后续参数为一个类型名
   */
  vec_sz = v.size();
  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(v.begin(), v.end());
  vec_sz mid = size / 2;

  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}
#include "median.h"

#include <algorithm>
#include <stdexcept>
/**
 * stdexcept 定义了 domain_error 对象.
 * 常用异常类:
 * - logic_error    - domain_error    - invalid_argument
 * - length_error   - out_of_range    _ runtime_error
 * - range_error    - overflow_error  - underflow_error
 */
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

// 计算一个 vector<double> 类型的变量的中值.
// 调用函数时整个 vec 参数都会被复制.
double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_sz;
  
  vec_sz size = vec.size();
  if (size == 0)
    throw domain_error("median of an empty vector");
  /**
   * 抛出异常
   * - 由于并不知道何种函数 / 程序使用该函数以及出于何种目的使用该函数, 为发出更
   * 为通用的错误提示, 抛出异常.
   * - 语法: throw 异常类型(异常说明字符串);
   */

  /**
   * domain_error 类型
   * - 函数参数的取值是函数所不能接受的.
   */

  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
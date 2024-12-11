#include "palindrome.h"

#include <algorithm>
/**
 * algorithm 定义了 equal 函数
 */
#include <string>

using std::equal;
using std::string;

bool is_palindrome(const string& s)
{
  return equal(s.begin(), s.end(), s.rbegin());
  /**
   * equal 函数
   * - 语法: equal(s1.b, s1.e, s2.b);
   * - 判断两个序列是否包含相等的值.
   * - equal 假定两个序列的长度相等, 故第二个序列无需传入一个结尾迭代器.
   */
}
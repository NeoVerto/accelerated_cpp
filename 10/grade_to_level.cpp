#include "grade_to_leve.h"

#include <cstddef>
#include <string>

using std::size_t;
using std::string;

string letter_grade(double grade)
{
  // 分数成绩的界限
  static const double numbers[] = {
    97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
  };

  // 字母成绩表示
  static const char* const letters[] = {
    "A+", "A", "A-", "B+", "B-", "C+", "C", "C-", "D", "F"
  };

  // 根据数组的大小计算成绩的个数和单个元素的大小
  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
  /**
   * sizeof 运算符
   * - 语法: sizeof(对象名) 或 sizeof(类型名)
   * - 返回一个 size_t 值, 告知该类型的对象占用多少内存.
   * - sizeof 返回的数值以字节为单位, 一个字节包含 8 位, 一个字符变量正好占用一
   *   个字节的空间.
   */

  // 根据分数成绩得到相应的字母成绩
  for (size_t i = 0; i < ngrades; ++i)
    if (grade >= numbers[i])
      return letters[i];

  return "?\?\?";
  /**
   * C++ 程序不允许存在连续的多个问号, 因此需要转义.
   */
}
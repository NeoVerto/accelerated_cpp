#include "Student_info.h"

#include <iostream>
#include <vector>

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
  /**
   * 运算符重载
   * - < 运算符按照字典序比较字符串.
   */
}

istream& read(istream& is, Student_info& s)
{
  // 读入并存储学生的姓名以及期中, 期末考试成绩
  is >> s.name >> s.midterm >> s.final;

  // 读入并存储学生的所有家庭作业成绩
  read_hw(is, s.homework);

  return is;
}

istream& read_hw(istream& in, vector<double>& hw)
/**
 * 左值
 * - 用于指示非临时对象的值.
 */

/**
 * 返回引用
 * - 返回时不复制对象
 * - 返回的不是函数中创建的局部引用.
 */
{
  if (in)
  {
    // 清除原先的内容
    hw.clear();
    /**
     * vector 的成员函数 clear()
     * - 清除向量内容.
     */

    // 读家庭作业成绩
    double x;
    while (in >> x)
      hw.push_back(x);

    // 清除流以使输入动作对下一个学生有效
    in.clear();
    /**
     * istream 的成员函数 clear()
     * - 清除 istream 类型对象的内部错误状态.
     */
  }

  return in;
}
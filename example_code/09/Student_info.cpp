#include "Student_info.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::domain_error;
using std::istream;
using std::string;
using std::vector;

using std::sort;

istream& read_hw(istream& in, vector<double>& hw)
{
  if (in)
  {
    //清除原先的内容
    hw.clear();

    // 读入家庭作业成绩
    double x;
    while (in >> x)
      hw.push_back(x);

    // 清除以使输入动作对下一个学生有效
    in.clear();
  }

  return in;
}

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec)
{
  typedef vector<double>::size_type vec_size;

  vec_size size = vec.size();
  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_size mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name() < y.name();
}
/**
 * 非成员函数
 */

// class Student_info
Student_info::Student_info(): midterm(0), final(0) {}
/**
 * 初始化列表
 * - 语法: 构造函数(参数列表): 初始化器1, 初始化器2, ... ,初始化器n {}
 * - 用于初始化成员属性.
 */

/**
 * 初始化过程
 * - 分配内存保存对象.
 * - 按照初始化列表对对象初始化.
 * - 实行构造函数的函数体.
 */

Student_info::Student_info(istream& is)
{
  read(is);
}

istream& Student_info::read(istream& in)
/**
 * 类作用域
 * - 语法: 类名::类中名称
 * - 定义类中函数 / 访问 static 对象
 */
{
  in >> n >> midterm >> final;
  /**
   * 成员函数可直接访问其所在类的成员属性.
   */
  read_hw(in, homework);
  return in;
}

double Student_info::grade() const
{
  return ::grade(midterm, final, homework);
  /**
   * 全局作用域
   * - 访问语法: ::全局对象名称
   * - 访问全局对象
   */
}

string Student_info::name() const
{
  return n;
}

bool Student_info::valid() const
{
  return !homework.empty();
}
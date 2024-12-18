#include "core.h"

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

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

istream& read_hw(istream& in, vector<double>& hw)
{
  if (in)
  {
    hw.clear();
    double x;
    while (in >> x);
      hw.push_back(x);
    in.clear();
  }
}

// public:
string core::name() const { return n; }

istream& core::read(istream& in)
{
  read_common(in);
  read_hw(in, homework);

  return in;
}

double core::grade() const { return ::grade(midterm, final, homework); }

// protected:
istream& core::read_common(istream& in)
{
  in >> n >> midterm >> final;

  return in;
}

// outer
bool compare(const core& c1, const core& c2) { return c1.name() < c2.name(); }
/**
 * 多态
 * - 用一个类型表示几种类型的能力.
 * - C++ 利用虚拟函数的动态绑定以支持多态性.
 * - 可为一个要求基类引用 / 指针类型参数的函数传递其派生类的对象作为参数.
 * - 因为派生类具有基类部分, 基类引用或指针将与基类部分绑定.
 */
bool compare_grade(const core& c1, const core& c2)
{
  return c1.grade() < c2.grade();
}
/**
 * 动态绑定
 * - 若使用类的引用 / 指针, 则在运行时才能确定类的类型, 从而决定调用
 *   的函数.
 * - 若直接使用类, 则在编译时就已经确认类的类型. 
 */
bool compare_core_ptrs(const core* cp1, const core* cp2)
{
  return compare(*cp1, *cp2);
}
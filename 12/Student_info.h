#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
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

double median(std::vector<double> vec)
{
  typedef std::vector<double>::size_type vec_size;

  vec_size size = vec.size();
  if (size == 0)
    throw std::domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_size mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

class Student_info
{
public:
  Student_info(): midterm(0), final(0) {}
  Student_info(std::istream& is) { read(is); }

  // 类型转换操作函数
  operator double() const { return grade(); }
  /**
   * 类型转换操作函数
   * - 定义将自定义对象转换为对应类型的对象.
   */

  std::istream& read(std::istream& in)
  {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
  }
  double grade() const { return ::grade(midterm, final, homework); }
  bool valid() const { return !homework.empty(); }

  std::string name() const { return n; }
private:
  std::string n;
  double midterm, final;
  std::vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name() < y.name();
}

#endif  // GUARD_Student_info
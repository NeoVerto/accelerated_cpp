#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h
#include <iostream>
#include <string>
#include <vector>

struct Student_info
{
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};
/**
 * struct 自定义数据结构类型
 * - struct 自定义数据结构类型的成员默认 public.
 * - 常用于定义简单的数据结构.
 */

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif  // GUARD_Student_info

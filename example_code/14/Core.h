#ifndef GUARD_student_h
#define GUARD_student_h

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Handle.h"

double median(std::vector<double> vec)
{
  typedef std::vector<double>::size_type vector_size;

  vector_size size = vec.size();
  if (size == 0)
    throw std::domain_error("median of an empty vector");

  std::sort(vec.begin(), vec.end());

  vector_size mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
  if (in)
  {
    hw.clear();
    double x;
    while (in >> x)
      hw.push_back(x);
    in.clear();
  }

  return in;
}

class Core
{
public:
  Core(): midterm(0), final(0) {}
  Core(std::istream& is) { read(is); }

  virtual ~Core() {}

  std::string name() const { return n; }

  virtual std::istream& read(std::istream& in)
  {
    read_common(in);
    read_hw(in, homework);

    return in;
  }

  virtual double grade() const { return ::grade(midterm, final, homework); }

protected:
  virtual Core* clone() const { return new Core(*this); }
  std::istream& read_common(std::istream& in)
  {
    in >> n >> midterm >> final;

    return in;
  }

  double midterm, final;
  std::vector<double> homework;

private:
  std::string n;
};

class Grad : public Core
{
public:
  Grad(): thesis(0) {}
  Grad(std::istream& is) { read(is); }

  std::istream& read(std::istream& in)
  {
    read_common(in);
    in >> thesis;
    read_hw(in, homework);

    return in;
  }

  double grade() const { return std::min(Core::grade(), thesis); }

protected:
  Grad* clone() const { return new Grad(*this); }

private:
  double thesis;
};

bool compare(const Core& c1, const Core& c2) { return c1.name() < c2.name(); }

bool compare_grade(const Core& c1, const Core& c2)
{
  return c1.grade() < c2.grade();
}

bool compare_Core_handles(const Handle<Core>& hc1, const Handle<Core>& hc2)
{
  return hc1->name() < hc2->name();
}

#endif  // GUARD_student_h
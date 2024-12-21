#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <stdexcept>
#include "Handle.h"
#include "Core.h"
class StudentInfo
{
public:
  StudentInfo() {}
  StudentInfo(std::istream& is) { read(is); }

  std::istream& read(std::istream& is)
  {
    char ch;
    is >> ch;

    if (ch == 'U')
      cp = new Core(is);
    else
      cp = new Grad(is);

    return is;
  }

  double grade() const
  {
    if (cp)
      return cp->grade();
    else
      throw std::runtime_error("uninitialized Student");
  }

  std::string name() const
  {
    if (cp)
      return cp->name();
    else
      throw std::runtime_error("uninitialized Student");
  }

  static bool compare(const StudentInfo& s1, const StudentInfo& s2)
  {
    return s1.name() < s2.name();
  }

private:
  Handle<Core> cp;
};

#endif  // GUARD_student_info_h
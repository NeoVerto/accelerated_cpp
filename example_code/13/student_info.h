#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <stdexcept>
#include <string>
#include "core.h"
#include "grad.h"
class student_info
{
public:
  // 构造函数与复制控制
  student_info(): cp(nullptr) {}
  student_info(std::istream& is): cp(nullptr) { read(is); }
  student_info(const student_info& s): cp(0)
  {
    if (s.cp)
      cp = s.cp->clone();
  }

  ~student_info() {delete cp;}
  
  student_info& operator=(const student_info& s)
  {
    if (&s != this)
    {
      delete cp;
      if (s.cp)
        cp = s.cp->clone();
      else
        cp = nullptr;
    }

    return *this;
  }

  // 操作
  std::istream& read(std::istream& is)
  {
    delete cp;  // 删除以前所指的对象
    /**
     * C++ 中, 删除 nullptr 是无害的
     */

    char ch;
    is >> ch;   // 得到记录的类型

    if (ch == 'U')
      cp = new core(is);
    else
      cp = new grad(is);

    return is;
  }

  std::string name() const
  {
    if (cp)
      return cp->name();
    else
      throw std::runtime_error("uninitialized student");
  }

  double grade() const
  {
    if (cp)
      return cp->grade();
    else
      throw std::runtime_error("uninitialized student");
  }

  static bool compare(const student_info& s1, const student_info& s2)
  {
    return s1.name() < s2.name();
  }
  /**
   * 静态成员函数
   * - 语法: static 函数声明
   * - 静态成员函数与类关联， 而非与该类的对象关联
   * - 不能访问类型对象的非静态成员
   * - 不能对类的对象进行操作
   */

private:
  core* cp;
};
/**
 * 句柄类
 * - 如同指针一样
 * - 不用担心为其对应的对象进行类型分配

 */
#endif  // GUARD_student_info_h
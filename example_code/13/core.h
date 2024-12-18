#ifndef GUARD_core_h
#define GUARD_core_h

#include <iostream>
#include <string>
#include <vector>
class core
{
  friend class student_info;
  /**
   * 友元类
   * - 使友元类的所有成员函数为该类的友元函数
   */
  /**
   * 友元关系不会继承.
   */
public:
  core(): midterm(0), final(0) {}
  core(std::istream& is) { read(is); }

  virtual ~core() {}
  /**
   * 系统会自动删除对象的成员属性
   */

  std::string name() const;

  virtual std::istream& read(std::istream&);
  virtual double grade() const;
  /**
   * 虚拟函数
   * - 语法: virtual 函数声明
   * - 只能在类的定义中使用.
   * - 若函数是虚拟的, 则派生类中其虚拟特性也会被继承, 因此在派生类中不需要重复
   *   virtual 关键字.
   */
protected:
/**
 * 保护类型
 * - public: 任何类都能访问
 * - private: 只有该类本身和其友元函数可访问
 * - protected: 只有该类本身和其友元函数及其派生类可访问.
 */
  virtual core* clone() const { return new core(*this); }

  std::istream& read_common(std::istream&);
  double midterm, final;
  std::vector<double> homework;
private:
  std::string n;
};

bool compare(const core&, const core&);
bool compare_grade(const core&, const core&);
bool compare_core_ptrs(const core*, const core*);
#endif  // GUARD_core_h
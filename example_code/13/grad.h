#ifndef GUARD_grad_h
#define GUARD_grad_h

#include <iostream>
#include "core.h"
class grad : public core
/**
 * 继承
 * - 语法 class A : 保护类型 B
 * - 基类中的每个成员 (除构造函数, 赋值运算符和析构函数外) 均是派生类的成员.
 * - 派生类不可删除基类的成员.
 */
{
public:
  grad(): thesis(0) {}
  grad(std::istream& is) { read(is); }
  /**
   * 派生类类型构造对象的过程
   * - 为整个对象分配内存空间.
   * - 使用基类的构造函数以便初始化对象中的基类部分数据.
   *   - 编译器根据参数的个数和类型选择调用基类中的构造函数.
   *   - 若初始化时没有指定调用基类的构造函数, 则调用基类默认构造函数以构造对象
   *     的基类部分.
   * - 使用构造初始化器对对象的派生类部分数据进行初始化.
   * - 执行派生类构造函数的构造体.
   */

  std::istream& read(std::istream&);
  double grade() const;
  /**
   * 继承
   * - 派生类可重定义自己的成员.
   */
protected:
  grad* clone() const { return new grad(*this); }
private:
  double thesis;
  /**
   * 继承
   * - 派生类可加入自己的成员.
   */
};

#endif  // GUARD_grad_h
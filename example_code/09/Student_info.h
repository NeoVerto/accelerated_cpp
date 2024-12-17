#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

class Student_info
/**
 * class 与 struct
 * - class 默认 private
 * - struct 默认 public
 */
{
public:
// 构造函数: 初始化对象
  Student_info();
  Student_info(std::istream&);
  /**
   * 默认初始化与数值初始化
   * - 若对象是一个局部变量, 其成员属性将被默认初始化.
   * - 若以下三种情况, 对象的成员属性将被数值初始化.
   *   - 对象被用于初始化一个容器元素.
   *   - 为映射表添加一个新元素, 而对象是该添加动作的副作用.
   *   - 定义一个有特定长度的容器, 对象是这个容器的元素.
   */

  /**
   * 对象初始化
   * - 自定义类型且有构造函数, 由构造函数初始化.
   * - 内部类型, 数值初始化设为 0, 默认初始化未定义.
   * - 自定义类型且无构造函数, 由各成员属性分别默认初始化或数值初始化.
   */

// 成员函数: 接口
  std::istream& read(std::istream&);
  double grade() const;
  /**
   * 常量成员函数
   * - const 修饰调用成员函数的对象.
   * - 无法修改对象的成员属性.
   * - 无法调用对象的非常量成员函数.
   */
  std::string name() const;
  /**
   * 存取器函数
   * - 用于直接读 / 写成员属性的接口.
   */
  bool valid() const;
  /**
   * 成员函数
   * - 调用语法: c.func();
   * - 改变 / 返回调用者对象的状态.
   */
private:
  std::string n;
  double midterm, final;
  std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

#endif  // GUARD_Student_info
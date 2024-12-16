#ifndef GUARD_str_h
#define GUARD_str_h

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iterator>
#include "../11/vec.h"
class str
{
  friend std::ostream& operator<<(std::ostream& os, const str& s)
  {
    for (size_type i = 0; i != s.size(); ++i)
      os << s[i];
    return os;
  }

  friend std::istream& operator>>(std::istream& is, str& s)
  /**
   * 友元函数
   * - 语法: friend 函数声明
   * - 赋予该函数与类的成员函数一样的对类私有成员属性的读写权力
   * - 可加在类定义的任何地方, 故将友元函数的声明放在 public 接口前, 作为一个相
   *   对独立的组.
   */
  {
    // 抹去存在的值 (s)
    s.data.clear();

    // 按顺序读字符并忽略前面的空格字符
    char c;
    while (is.get(c) && isspace(c))
      ;

    // 若读到非空格字符
    if (is)
    {
      do
        s.data.push_back(c);
      while (is.get(c) && !isspace(c));

      // 若遇到一个空格字符, 将其放在输入流的后面
      if (is)
        is.unget();
    }

    return is;
  }
public:
  // 类型定义
  typedef vec<char>::size_type size_type;

  // 构造函数
  str() {}  // 默认构造函数
  str(size_type n, char c): data(n, c) {}
  str(const char *cp)
  {
    std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
  }
  /**
   * 对赋值语句 s = "hello"
   * - 首先调用该构造函数, 将 "hello" 转为 str 类型对象.
   * - 然后调用默认赋值函数, 将该局部的, 没名称的, 临时的 str 类型对象赋值给 s.
   */

  /**
   * 自定义的类型转换
   * - 该定义包含两个方面:
   *   - 将其他类型转换为该类类型
   *   - 将该类类型转换为其他类型
   */
  template <class In>
  str(In b, In e)
  {
    std::copy(b, e, std::back_inserter(data));
  }

  // size 函数
  size_type size() const { return data.size(); }

  // 重载运算符
  char& operator[](size_type i) { return data[i]; }
  const char& operator[](size_type i) const { return data[i]; }
private:
  vec<char> data;
};

#endif  // GUARD_str_h
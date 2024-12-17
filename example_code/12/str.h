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
    /**
     * void* 指针
     * - 可以指向任何类型对象的指针.
     * - 无法对这类指针间接引用.
     */
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
   * 若实现了某类型为参数的构造函数, 也就同时定义了一个从某类型到该类型的类型转
   * 换操作.
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

  str& operator+=(const str& s)
  {
    std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));

    return *this;
  }

  // 类型转换操作函数
  // operator char*();
  // operator const char&() const;
  /**
   * 类型转换操作函数
   * - 定义将自定义对象转换为对应类型的对象.
   */
  
  /**
   * 标准库 string 类的处理方法
   * - 提供三个成员函数从 string 类型对象中获得一个字符数组
   *   - c_str()
   *     将 string 类型对象的内容复制到一个空字符结尾的字符数组中.
   *     用户不能删除指向该数组的指针.
   *     该数组的数据是临时的, 在下次调用可改变 string 的成员函数时它就会失效.
   *   - data()
   *     返回一个非空字符结尾的字符数组.
   *     其余同 c_str().
   *   - copy(char*, int)
   *     将 int 类型参数指定个数的字符复制到 char* 类型参数的内存中.
   *     该内存由用户分配和释放空间.
   *   c_str() 和 data() 都具有隐式地向 const char* 类型转换的缺陷.
   */
private:
  vec<char> data;
};

std::ostream& operator<<(std::ostream& os, const str& s)
{
  for (str::size_type i = 0; i != s.size(); ++i)
    os << s[i];
  return os;
}

str operator+(const str& a, const str& b)
{
  str tmp = a;
  tmp += b;
  return tmp;
}
/**
 * 设计二元运算符
 * - 若类支持转换, 将其定义为非成员函数.
 * - 若运算符函数是类的成员函数, 那么这个运算符的左操作数不能是自动转换得到的结
 *   果.
 * - 对赋值操作符与复合赋值操作符, 必须是类的成员函数.
 */
#endif  // GUARD_str_h
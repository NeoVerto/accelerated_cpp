#ifndef GUARD_handle_h
#define GUARD_handle_h

#include <stdexcept>
/**
 * 全部的对 T 类型对象的访问都通过 Handle 类型对象实现.
 * 
 */
template <class T>
class Handle
{
public:
  // 构造函数
  // 默认构造函数
  Handle(): p(0) {}
  // 数值构造函数
  Handle(T* t): p(t) {}
  // 复制构造函数
  Handle(const Handle& s): p(0)
  {
    if (s.p)
      p = s.p->clone();
  }

  // 析构函数
  ~Handle() { delete p; }

  // 重载运算符
  // 赋值运算符
  Handle& operator=(const Handle& rhs)
  {
    if (&rhs == this)
    {
      delete p;
      p == rhs.p ? rhs.p->clone() : 0;
    }

    return *this;
  }
  // * 运算符
  T& operator*() const
  {
    if (p)
      return *p;
    throw std::runtime_error("unbound Handle");
  }
  // -> 运算符
  T* operator->() const
  {
    if (p)
      return p;
    throw std::runtime_error("unbound Handle");
  }
  // bool 类型转换
  operator bool() const { return p; }
private:
  T* p;
};

#endif  // GUARD_handle_h
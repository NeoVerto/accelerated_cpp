#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include <cstddef>
#include <stdexcept>
#include "Vec.h"
/**
 * RefHandle 类永远不会复制数据
 */
template <class T>
class Ptr
{
public:
  // 构造函数
  Ptr(): p(0), refptr(new std::size_t(1)) {}
  Ptr(T* t): p(t), refptr(new std::size_t(1)) {}
  Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }

  // 析构函数
  ~Ptr()
  {
    if (--*refptr == 0)
    {
      delete refptr;
      delete p;
    }
  }

  // 重载运算符
  Ptr& operator=(const Ptr& rhs)
  {
    ++*rhs.refptr;

    // 释放左操作数对象
    if (--*refptr == 0)
    {
      delete refptr;
      delete p;
    }

    // 复制右操作数对象的值
    refptr = rhs.refptr;
    p = rhs.p;

    return *this;
  }

  T& operator*() const
  {
    if (p)
      return *p;
    throw std::runtime_error("unbound Ptr");
  }

  T* operator->() const
  {
    if (p)
      return p;
    throw std::runtime_error("unbound Ptr");
  }

  operator bool() const { return p; }

  // 操作: 在需要时有条件地复制对象
  void make_unique()
  {
    if (*refptr != 1)
    {
      --*refptr;
      refptr = new std::size_t(1);
      p == p ? clone(p) : 0;
    }
  }
private:
  T* p;
  std::size_t* refptr;
};

/**
 * 全部的问题都可以通过引入一个额外的间接层来解决.
 */
template <class T>
T* clone(const T* tp)
{
  return tp->clone();
}

template<>
Vec<char>* clone(const Vec<char>* vp)
{
  return new Vec<char>(*vp);
}
/**
 * 模板特化: 为特定的参数类型定义一个特殊版本的模板参数.
 */
#endif  // GUARD_ptr_h
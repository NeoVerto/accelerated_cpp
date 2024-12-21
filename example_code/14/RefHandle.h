#ifndef GUARD_ref_handle_h
#define GUARD_ref_handle_h

#include <cstddef>
#include <stdexcept>
/**
 * Handle 类总是会复制 Handle 类型对象指向的对象.
 * 
 * 通常情况下, 我们希望亲自决定是否对对象进行复制.
 * - 我们可能希望一个对象为另一个对象的副本, 但其值共用同一块内存 (Java 内存池). 
 */
template <class T>
class RefHandle
{
public:
  // 构造函数
  RefHandle(): p(0), refptr(new std::size_t(1)) {}
  RefHandle(T* t): p(t), refptr(new std::size_t(1)) {}
  RefHandle(const RefHandle& h): p(h.p), refptr(h.refptr) { ++*refptr; }

  // 析构函数
  ~RefHandle()
  {
    if (--*refptr == 0)
    {
      delete refptr;
      delete p;
    }
  }

  // 重载运算符
  RefHandle& operator=(const RefHandle& rhs)
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
    throw std::runtime_error("unbound RefHandle");
  }

  T* operator->() const
  {
    if (p)
      return p;
    throw std::runtime_error("unbound RefHandle");
  }

  operator bool() const { return p; }

private:
  T* p;
  std::size_t* refptr;    // 记录指向底层对象的对象个数
};

#endif  // GUARD_ref_handle_h
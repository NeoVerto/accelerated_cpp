#ifndef GUARD_vec_h
#define GUARD_vec_h

#include <algorithm>
#include <cstddef>
#include <memory>

template<class T>
class Vec
{
public:
  // 类型定义
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef std::size_t size_type;          // 表示 vec 的大小的类型
  typedef T value_type;                   // 容器中存储的每个对象的类型
  typedef std::ptrdiff_t difference_type; 
  typedef T& reference;                   // value_type&
  typedef const T& const_reference;        // const value_type&

  // 构造函数
  Vec() { create(); }
  explicit Vec(std::size_t n, const T& val = T()) { create(n, val); }
  Vec(const Vec& v) { create(v.begin(), v.end()); }

  // 析构函数
  ~Vec() { uncreate(); }

  // 重载运算符
  Vec& operator=(const Vec& rhs)
  {
    if (&rhs != this)
    {
      uncreate();
      create(rhs.begin(), rhs.end());
    }
  }

  T& operator[](size_type i) { return data[i]; }
  const T& operator[](size_type i) const { return data[i]; }

  // 操作
  size_type size() const { return (avail - data); }

  iterator begin() { return data; }
  const_iterator begin() const { return data; }

  iterator end() { return avail; }
  const_iterator end() const { return avail; }
  
  void push_back(const T& val)
  {
    if (avail == limit)
      grow();
    unchecked_append(val);
  }

  iterator erase(iterator pos)
  {
    if (pos < avail)
    {
      alloc.destroy(pos);
      iterator new_pos = std::move(pos + 1, avail, pos);
      --avail;

      return new_pos;
    }

    return avail;
  }

  iterator erase(iterator first, iterator last)
  {
    if (first == last)
      return first;

    iterator new_avail = std::move(last, avail, first);

    for (iterator it = first; it != last; ++it)
      alloc.destroy(it);

    avail = new_avail;

    return first;
  }

  void clear()
  {
    for (iterator it = data; it != avail; ++it)
      alloc.destroy(it);
    avail = data;
  }

private:
  iterator data;
  iterator avail;
  iterator limit;

  std::allocator<T> alloc;

  void create() { data = avail = limit = nullptr; }

  void create(size_type n, const T& val)
  {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
  }

  void create(const_iterator first, const_iterator last)
  {
    data = alloc.allocate(last - first);
    limit = avail = std::uninitialized_copy(first, last, data);
  }

  void uncreate()
  {
    if (data)
    {
      iterator it = avail;
      while (it != data)
        alloc.destroy(--it);

      alloc.deallocate(data, limit - data);
    }

    data = limit = avail = nullptr;
  }

  void grow()
  {
    size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
  }

  void unchecked_append(const T& val)
  {
    alloc.construct(avail++, val);
  }
};

#endif  // GUARD_vec_h
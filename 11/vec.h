#ifndef GUARD_vec_h
#define GUARD_vec_h

#include <algorithm>
#include <cstddef>
#include <memory>

/**
 * 类不变式: 
 * - 若构造了一个类的对象, 则其类的公有成员函数不可打破这一不变式.
 * - vec 类的不变式
 *   - 若对象中存在数据元素, data 指向对象数组的首元素, 否则为 nullptr
 *   - data <= avail <= limit
 *   - 在 [data, avail) 区间内的元素被初始化
 *   - 在 [avail, limit) 区间内的函数不会被初始化
 */
template <class T>
class vec
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
  vec() { create(); };  // 默认构造函数
  explicit vec(std::size_t n, const T& val = T()) { create(n, val); }
  /**
   * explicit 关键字
   * - 若一个构造函数是 explicit 的, 则只有在用户显式地调用构造函数时才会调用它,
   *   否则不会调用.
   */
  vec(const vec& v) { create(v.begin(), v.end()); }  // 复制构造函数
  /**
   * 复制构造函数
   * - 无论对于显式还是隐式的复制, 都由复制构造函数进行.
   */

  /**
   * 若无构造函数, 根据上下文, 编译器生成不带任何参数的构造函数, 从而实现默认初
   * 始化或值初始化.
   */

  // 析构函数
  ~vec() { uncreate(); }
  /**
   * 析构函数
   * - 语法: ~类名() {语句}
   * - 用于自动删除生命周期结束的对象.
   */

  /**
   * 三位一体规则
   * - 若类需要一个析构函数, 则它同时可能也需要一个复制构造函数与一个赋值运算符
   *   函数
   * - 为控制 T 类型对象的每个副本, 需要
   *   T::T()
   *   T::~T()
   *   T::T(const T&)
   *   T::operator=(const T&)
   */

  // 大小与索引
  size_type size() const { return (avail - data); }

  T& operator[](size_type i) { return data[i]; }
  const T& operator[](size_type i) const { return data[i]; }
  /**
   * const 修饰符亦可作为函数重载的标志
   */

  // 赋值运算符
  vec& operator=(const vec&);
  /**
   * 赋值不是初始化
   * - 在使用 = 为变量赋初始值时, 程序自动调用复制构造函数.
   * - 在使用 = 为变量赋值时, 程序自动调用 operator= 赋值操作函数.
   * - 区别在于, 赋值总是删去旧的值, 而初始化并没有这步操作.
   * - 发生初始化行为的情况:
   *   - 声明一个变量时
   *   - 在函数的入口处用到函数参数时
   *   - 函数返回中使用函数返回值时
   *   - 构造初始化时
   */

  // 返回迭代器的函数
  iterator begin() { return data; }
  const_iterator begin() const { return data; }

  iterator end() { return avail; }
  const_iterator end() const { return avail; }

  // push_back 函数
  void push_back(const T& val)
  {
    if (avail == limit)     // 获得所需要的空间
      grow();
    unchecked_append(val);  // 将新增元素放到对象末端

    /**
     * 为何不使用 new 和 delete?
     * - 使用了 new 与 delete 运算符, 将使得 vec 类收到诸多限制.
     * - new 运算符可能为程序带来过多的资源开销.
     */
  }

private:
  iterator data;    // vec 中的首元素
  iterator avail;   // vec 构造元素后面的一个元素
  iterator limit;   // vec 可获得元素后的一个元素.

  // 内存分配工具
  std::allocator<T> alloc;  // 控制内存分配的对象
  /**
   * allocator<T> 类
   * - 可分配一块预备用于储存 T 类型对象但尚未被初始化的内存块, 并返回一个指向该
   *   内存块的头元素的指针.
   * - 成员函数
   *   - T* allocate(size_t);
   *     用于分配一块被指定了类型但未被初始化的内存块. 足以储存相应类型对象的元
   *     素.
   *   - void deallocate(T*, size_t);
   *     用于释放未被初始化的内存.
   *   - void construct(T* const T&);
   *     在尚未被初始化的内存区域中构造单个对象.
   *   - void destroy(T*);
   *     删除它的参数所指的类型 T 的对象.
   * - 相关非成员函数
   *   - template<class In, class For>
   *     For uninitialized_copy(In b, In e, For d);
   *     将 [b, e) 中的值复制到 d 所指向的内存空间中.
   *   - template<class For, class T>
   *     void uninitialized_fill(For b, For e, const T& val);
   *     将 [b, e) 中的元素初始化为 val.
   *   用于在 allocate 分配的内存块中构造并初始化新的对象. 
   */

  // 为底层的数组分配空间并对其初始化
  void create();
  void create(size_type, const T&);
  void create(const_iterator, const_iterator);

  // 删除数组中的元素并释放其占用的内存
  void uncreate();

  // 支持 push_back 的函数
  void grow();
  void unchecked_append(const T&);
};

template <class T>
vec<T>& vec<T>::operator=(const vec& rhs)
/**
 * 由于在模板文件的范围外, 必须声明返回类型, 因此要在必要的地方显式地写出模板参
 * 数.
 */
{
  // 判断是否自我赋值
  if (&rhs != this)
  /**
   * 对引用取地址得到的是该引用绑定对象的地址 (即指针)
   */
  /**
   * this 关键词
   * - 代表指向函数操作的对象的指针. 
   */
  {
    // 删除运算符左侧的数组
    uncreate();
    // 从右侧复制元素到左侧
    create(rhs.begin(), rhs.end());
  }

  return *this; 
}

template <class T>
void vec<T>::create() { data = avail = limit = nullptr; }

template <class T>
void vec<T>::create(size_type n, const T& val)
{
  data = alloc.allocate(n);
  limit = avail = data + n;
  std::uninitialized_fill(data, limit, val);
}

template <class T>
void vec<T>::create(const_iterator i, const_iterator j)
{
  data = alloc.allocate(j - i);
  limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void vec<T>::uncreate()
{
  if (data)
  {
    // 以相反的顺序删除构造函数生成的元素
    iterator it = avail;
    while (it != data)
      alloc.destroy(--it);

    // 返回占用的所有内存空间
    alloc.deallocate(data, limit - data); // 需要一个非零指针作为参数
  }

  // 重置指针表明 vec 类型对象为空
  data = limit = avail = nullptr;
}

template <class T>
void vec<T>::grow()
{
  // 在扩展对象大小时, 为对象分配实际使用的两倍大小的内存空间
  size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

  // 分配新的内存空间
  iterator new_data = alloc.allocate(new_size);
  // 并将已存在的对象元素复制到新内存中
  iterator new_avail = std::uninitialized_copy(data, avail, new_data);

  // 返回原来的内存空间
  uncreate();

  // 重置指针, 使其指向新分配的内存空间
  data = new_data;
  avail = new_avail;
  limit = data + new_size;
}

// 假设 avail 指向一片新分配但尚未被初始化的内存空间
template <class T>
void vec<T>::unchecked_append(const T& val)
{
  alloc.construct(avail++, val);
}
#endif  // GUARD_vec_h
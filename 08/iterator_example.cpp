template <class In, class X>
In find(In begin, In end, const X& x)
{
  // 迭代实现：
  while (begin != end && *begin != x)
    ++begin;
  return begin;
  // 递归实现
  if (begin == end || *begin == x)
    return begin;
  begin++;
  return find(begin, end, x);
}
/**
 * 顺序只读访问与输入迭代器
 * - 对一个序列的元素提供了顺序只读访问操作的迭代器应该支持 ++, ==, != 以及一元
 * 运算符 * (及*().的简写 ->).
 */

template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
  while (begin != end)
    *dest++ = *begin++;
  return dest;
}
/**
 * 顺序只写访问与输出迭代器
 * - 对一个序列的元素提供了顺序只写访问操作的迭代器应该支持 ++, *()=, 且保证不能
 * 在两次赋值运算之间执行超过一次的 ++ 操作, 保证不能在递增前对其多次赋值.
 * - 一次写入 (保证不能在两次赋值运算之间执行超过一次的 ++ 操作, 保证不能在递增
 * 前对其多次赋值) 同时针对了调用这类迭代器的函数 / 程序.
 */

template<class For, class X>
void replace(For begin, For end, const X& x, const X& y)
{
  while (begin != end)
  {
    if (*begin == x)
      *begin = y;
    ++begin;
  }
}
/**
 * replace 函数
 * - 定义在 <algorithm> 头文件中
 * - 将区间 [begin, end) 中等于 x 的元素替换为 y.
 */

/**
 * 顺序读写访问与正向迭代器
 * - 支持 *it 读写操作, ++ 操作 (无需支持 -- 操作), ==, != 操作 及* 操作 (同时支
 * 持了 *(). 和 ->).
 * - 无需满足输出迭代器的一次操作要求.
 * - 所有标准库容器都满足正向迭代器的要求.
 */

template <class Bi>
void reverse(Bi begin, Bi end)
{
  while (begin != end)
  {
    --end;
    if (begin != end)
      swap(*begin++, *end);
  }
}

/**
 * reverse 函数
 * - 定义在 <algorithm> 头文件中
 * - 将整个容器元素反转排列.
 */

/**
 * 可逆访问与双向迭代器
 * - 支持 -- 操作且满足正向迭代器的所有要求的迭代器.
 */

template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
  while (begin < end)
  {
    // 查找区间中点
    Ran mid = begin + (end - begin) / 2;
    // 看区间的哪部分含有 x, 只往下查找该部分:
    if (x < *mid)
      end = mid;
    else if (*mid < x)
      begin = mid;
    // 找到了待查的值, 完成查找
    else
      return true;
  }

  return false;
}

/**
 * 随机访问与随机访问迭代器
 * - 支持双向迭代器及 +, -, [] (等价于 *( + )), <, >, <=, >= 操作.
 */

/**
 * 指向区间最后元素后面位置的迭代器被使用的原因:
 * - 若用一个迭代器指向区间末端, 且该迭代器指向区间最后一个元素, 则该元素的处理
 * 是相对特殊的, 必须当作特例.
 * - 若区间没有元素, 无法找到一个最后的元素以标记终点. 若引入一个表示空区间的迭
 * 代器, 则必须将其当作特例.
 * - 若采用该方法设计迭代器, 就可以通过 != == 两种操作比较迭代器, 而无需实现 <,
 * >, <=, >= 的具体意义. 同时, 容易判断容器是否为空 (begin == end 即为空).
 * - 若采用该方法设计迭代器, 可以自然地表示 "区间之外" 的概念 (即返回 end).
 */

/**
 * 输出迭代器和输入迭代器的必要性
 * - 迭代器并非关联于容器.
 * - 迭代器有很好的适应性.
 */
#include "cat.h"

#include <algorithm>
/**
 * algorithm 定义了 copy 函数
 */
#include <iterator>
/**
 * iterator 定义了迭代器适配器, 如 back_inserter
 */
#include <vector>
#include <string>
#include "../05/frame.h"

using std::back_inserter;
using std::copy;
using std::string;
using std::vector;

vector<string>
vcat(const vector<string>& top, const vector<string>& bottom)
{
  // 复制顶部图案
  vector<string> ret = top;
  // 复制整个底部图案
  // for (vector<string>::const_iterator it = bottom.begin(); 
  //      it != bottom.end(); ++it)
  //   ret.push_back(*it);
  // ret.insert(ret.end(), bottom.begin(), bottom.end());
  copy(bottom.begin(), bottom.end(), back_inserter(ret));
  /**
   * copy 函数
   * - 语法: copy(b, e, d);
   * - 将 [b, e) 范围内的元素复制到一连串从 d 开头的元素中, 并覆盖他们
   * - 在必要时, 对 d 所属的容器进行扩展.
   */

  /**
   * 泛型算法
   * - 不属于任何特定类别容器的算法.
   * - 从参数类型获得关于如何访问它所使用数据的提示.
   * - 标准库的泛型算法通常采用迭代器作为参数, 用于处理基本容器的元素.
   */

  /**
   * 迭代器适配器
   * - 产生与其参数相关的属性的迭代器.
   */

  /**
   * back_inserter()
   * - 语法: back_inserter(容器名);
   * - 产生给定容器的插入迭代器.
   * - 在插入迭代器用作一个目的地时, 向容器末端添加数值.
   * - 不等价 容器名.end(), 因 容器名.end() 并不指向一个元素.
   */

  /**
   * front_inserter()
   * - 语法: front_inserter(容器名);
   * - 产生给定容器的插入迭代器.
   * - 在插入迭代器用作一个目的地时, 向容器头部添加元素.
   * - 需要容器实现 push_front() 方法.
   */

  /**
   * inserter()
   * - 语法: inserter(容器名, 迭代器);
   * - 产生给定容器的插入迭代器.
   * - 迭代器指出了插入位置, 在插入迭代器用作一个目的地时, 向给定迭代器前端插入
   * 元素.
   */

  return ret;
}

std::vector<std::string> hcat(const std::vector<std::string>& left, 
                              const std::vector<std::string>& right)
{
  vector<string> ret;

  // 对 width(left) + 1, 在两幅图案之间留一个空格
  string::size_type widthl = width(left) + 1;

  // 用于遍历 left, right 的索引
  vector<string>::size_type i = 0, j = 0;
  // 循环操作直至我们查看完了两幅图案的全部行
  while (i != left.size() || j != right.size())
  {
    // 构造新字符串来保存字符, 这些字符来自两幅图案
    string s;
    // 若左侧图案有待复制的行, 复制一行
    if (i != left.size())
      s = left[i++];
    // 填充至适当的长度
    s += string(widthl - s.size(), ' ');
    // 若右侧图案有待复制的行, 复制一行
    if (j != right.size())
      s += right[j++];

    // 将 s 添加到我们正创建的图案中
    ret.push_back(s);
  }
}
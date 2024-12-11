#include "cat.h"

#include <vector>
#include <string>
#include "frame.h"

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
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  /**
   * vector 类型对象的成员函数 insert
   * - 语法: v.insert(插入的位置迭代器, 插入元素的起始位置迭代器, 插入元素的结束
   * 位置迭代器)
   * - 将容器 B 中的一段元素按顺序插入到 vector 容器 A 中的某处.
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
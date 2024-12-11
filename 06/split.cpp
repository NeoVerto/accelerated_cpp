#include "split.h"

#include <algorithm>
/**
 * algorithm 定义了 find_if 函数
 */
#include <cctype>
#include <string>
#include <vector>

using std::find_if;
using std::isspace;
using std::string;
using std::vector;

bool space(char c) {return isspace(c);}
bool not_space(char c) {return !isspace(c);}
/**
 * 封装 isspace 的原因
 * - 指定 isspace 的版本.
 */

vector<string> split(const string& str)
{
  typedef string::const_iterator iter;
  vector<string> ret;

  iter i = str.begin();
  while (i != str.end())
  {
    // 忽略前端空白
    i = find_if(i, str.end(), not_space);
    /**
     * find_if 函数
     * - 语法: find_if(b, e, v)
     * - 对序列 [b, e) 中的每个元素调用该谓词.
     * - 找到该谓词产生 true 的元素后, 停止调用并返回该位置.
     */

    /**
     * 标准库算法适度处理传入空区间的调用.
     */
    // 找出下一个单词的结尾
    iter j = find_if(i, str.end(), space);
    // 复制在 [i, j) 中的字符
    if (i != str.end())
      ret.push_back(string(i, j));
    i = j;
  }

  return ret;
}
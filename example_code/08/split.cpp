#include "split.h"

#include <algorithm>
#include <cctype>
#include <string>

using std::find_if;
using std::isspace;

using std::string;

bool not_space(char x) {return !isspace(x);}
bool space(char x) {return isspace(x);}

template <class Out>
void split(const string& str, Out os)
{
  typedef string::const_iterator iter;
  iter i = str.begin();
  while (i != str.end())
  {
    // 忽略前端空白
    i = find_if(i, str.end(), not_space);

    // 找出下一个单词的结尾
    iter j = find_if(i, str.end(), space);

    // 复制在 [i, j) 中的字符
    if (i != str.end())
      *os++ = string(i, j);
      /**
       * 这样, 就能将 split 函数用于任何非输入迭代器.
       */

      /**
       * istream_iterator<T>(istream)
       * - 从 istream 中读入 T 类型的值.
       * - istream 留空则产生默认 istream_iterator<T>, 用于文件末尾或错误状态.
       */

      /**
       * ostream_iterator<T>(ostream, dim)
       * - 向 ostream 输出, 以 dim 分割.
       */
    i = j;
  }
}
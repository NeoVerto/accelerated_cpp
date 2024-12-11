#include "split.h"

#include <cctype>
/**
 * cctype 定义了 isspace 函数
 */

/**
 * 常用 cctype 谓词函数
 * - isspace(c)  - isalpha(c)  - isdigit(c)
 * - isalnum(c)  - ispunct(c)  - isupper(c)
 * - islower(c)  - toupper(c)  - tolower(c)
 */
#include <vector>
#include <string>

using std::isspace;
using std::string;
using std::vector;

vector<string> split(const string& s)
{
  vector<string> ret;

  typedef string::size_type string_size;
  string_size i = 0;
  // 不变式: 我们已经处理了在索引域中的字符.
  while (i != s.size())
  {
    // 忽略前端空白
    // 不变式: 索引域中的全部字符都是空格
    while (i != s.size() && isspace(s[i]))
    /**
     * s[i]
     * - 视 string 类型对象为容器, 取其中第 i 个字符.
     */

    /**
     * isspace 函数
     * - 语法: isspace(字符)
     * - 检查传入字符是否为空白字符.
     */
      ++i;

    // 找出下一个单词的终结点
    string_size j = i;
    // 不变式: 索引域中的任何字符都不是空格
    while (j != s.size() && !isspace(s[j]))
      ++j;

    // 如果找到了一些非空白字符
    if (i != j)
    {
      // 从 i 开始复制 s 的 j - i 个字符
      ret.push_back(s.substr(i, j - i));
      /**
       * string 类型对象的成员函数 substr
       * - 语法: substr(开始索引, 字符个数)
       * - 在源字符串上切出一个新字符串返回.
       */
      i = j;
    }
  }

  return ret;
}
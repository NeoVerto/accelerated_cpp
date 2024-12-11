#include "find_urls.h"

#include <algorithm>
/**
 * algorithm 定义了 find 函数
 * algorithm 定义了 search 函数
 */
#include <cctype>
#include <string>
#include <vector>

using std::find_if;
using std::isalnum;
using std::search;
using std::string;
using std::vector;

bool not_url_char(char c)
{
  // 除字母数字外, 其他可能出现在一个 URL 中的字符.
  static const string url_ch = "~;/?:@=&$-_.+!*'(),";
  /**
   * static 存储类别说明符
   * - 被声明为 static 的局部变量具有全局寿命, 即其生存期贯穿了整个函数调用过程.
   * - 第一次调用时被构造并被初始化.
   */

  // 看 c 是否出现在一个 URL 中并返回求反的结果
  return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
  /**
   * isalnum 函数
   * - 语法: isalnum(c);
   * - 检验其参数是否为一个字母 / 数字字符.
   */

  /**
   * find 函数
   * - 语法: find(b, e, target)
   * - 在 [b, e) 中查找 target 值.
   * - 若找到 target 值, 返回迭代器, 指向第一次出现该值的位置.
   * - 若未找到 target 值, 返回传入的第二个参数.
   */
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
  return find_if(b, e, not_url_char);
}

string::const_iterator
url_begin(string::const_iterator b, string::const_iterator e)
{
  static const string sep = "://";

  typedef string::const_iterator iter;
  // i 标记了查找到的分隔符的位置:
  iter i = b;
  while ((i = search(i, e, sep.begin(), sep.end())) != e)
  /**
   * search 函数
   * - 语法: search(str.b, str.e, substr.b, substr.e)
   * - 若 search 失败, 返回 str.e
   * - 若 search 成功, 返回一个迭代器, 指向所搜索的序列出现的第一个位置
   */
  {
    // 确保分隔符不是本行中唯一的一个符号
    if (i != b && i + sep.size() != e)
    {
      // begin 标记协议名称的开头
      iter begin = i;
      while (begin != b && isalpha(begin[-1]))
      /**
       * 若容器支持索引, 则迭代器也支持索引.
       * - begin[-1] <=> *(begin-1)
       */

      /**
       * isalpha 函数
       * - 语法: isalpha(c);
       * - 检验参数是否为一个字母.
       */
        --begin;

      // 是否在分隔符前及后至少有一个字符?
      if (begin != i && !not_url_char(i[sep.size()]))
        return begin;
    }
    // 我们找到的分隔符不是 URL 的一部分
    i += sep.size();
  }

  return e;
}

vector<string> find_urls(const string& s)
{
  vector<string> ret;
  typedef string::const_iterator iter;
  iter b = s.begin(), e = s.end();

  // 检查整个输入
  while (b != e)
  {
    // 查找一个或多个紧跟着 :// 的字母
    b = url_begin(b, e);
    // 如果查找成功
    if (b != e)
    {
      iter after = url_end(b, e);
      ret.push_back(string(b, after));
      b = after;
    }
  }

  return ret;
}
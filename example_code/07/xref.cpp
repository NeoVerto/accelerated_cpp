#include "xref.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "06/split.h"

using std::getline;

using std::istream;
using std::map;
using std::string;
using std::vector;

map<string, vector<int>>
xref(istream& in, vector<string> find_words(const string&) = split)
/**
 * 定义默认参数
 * - 语法 p = x
 * - 若为参数指定了一个默认参数, 在不传递该参数时, 以默认参数代入该参数调用.
 */
{
  string line;
  int line_number = 0;
  map<string, vector<int>> ret;
  /**
   * 自 C++ 11 后, 可写作 contain<T1, T2<T3>> 而非 contain<T1, T2<T3> >
   */

  // 读下一行
  while (getline(in, line))
  {
    ++line_number;
    // 将输入行分割为单词
    vector<string> words = find_words(line);
    // 记住出现在当前行的每个单词
    for (vector<string>::const_iterator it = words.begin();
         it != words.end(); ++it)
      ret[*it].push_back(line_number);
  }

  return ret;
}
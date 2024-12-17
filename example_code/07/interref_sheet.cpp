#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "xref.h"

using std::cin;
using std::cout;
using std::endl;

using std::map;
using std::string;
using std::vector;

int main()
{
  // 默认使用 split 调用 xref
  map<string, vector<int>> ret = xref(cin);
  // 输出结果
  for (map<string, vector<int>>::const_iterator it = ret.begin();
       it != ret.end(); ++it)
  {
    // 输出单词
    cout << it->first << " occurs on line(s): ";
    // 后面跟随一个或多个行编号
    vector<int>::const_iterator line_it = it->second.begin();
    cout << *line_it;
    ++line_it;
    // 若有则输出其余行编号
    while (line_it != it->second.end())
    {
      cout << ", " << *line_it;
      ++line_it;
    }
    // 换一个新行以便将每个单词与下一个分隔开.
    cout << endl;
  }
  return 0;
}
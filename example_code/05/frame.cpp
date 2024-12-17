#include "frame.h"

#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

string::size_type width(const vector<string>& v)
{
  string::size_type maxlen = 0;
  for (vector<string>::size_type i = 0; i != v.size(); ++i)
    maxlen = max(maxlen, v[i].size());

  return maxlen;
}

vector<string> frame(const vector<string>& v)
{
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');

  // 输入顶部的边框
  ret.push_back(border);
  for (vector<string>::size_type i = 0; i != v.size(); ++i)
    ret.push_back("*" + v[i] + string(maxlen - v[i].size(), ' ') + "*");
    /**
     * string(次数, 字符) 构造了一个未命名的临时字符串.
     */
  // 输入底部的边框
  ret.push_back(border);
}
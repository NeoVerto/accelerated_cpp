#include "grammar.h"

#include <iostream>
#include <string>
#include <vector>
#include "../06/split.h"

using std::getline;

using std::istream;
using std::string;
using std::vector;

Grammar read_grammar(istream& in)
{
  Grammar ret;
  string line;

  // 读输入
  while (getline(in, line))
  {
    // 将输入分割为单词
    vector<string> entry = split(line); // entry = Rule_name + Rule
    
    if (!entry.empty())
      // 用种类存储相关联的规则
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
  }

  return ret;
}
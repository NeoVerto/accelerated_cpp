#include <iostream>
#include <string>
#include <vector>
#include "grammar.h"
#include "sentence.h"

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;

int main()
{
  // 生成语句
  vector<string> sentence = gen_sentence(read_grammar(cin));

  // 输出第一个单词, 如果存在
  vector<string>::const_iterator it = sentence.begin();
  if (!sentence.empty())
  {
    cout << *it;
    ++it;
  }

  // 输出其余的单词, 每个单词之前都有空格
  while (it != sentence.end())
  {
    cout << " " << *it;
    ++it;
  }
  cout << endl;

  return 0;
}
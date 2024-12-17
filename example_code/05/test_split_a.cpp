#include <iostream>
#include <string>
#include <vector>
#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline; 
using std::string;
using std::vector;

int main()
{
  string s;
  // 读并分割每一行输入
  while (getline(cin, s))
  /**
   * getline 函数
   * - 语法: getline(输入流, 字符串)
   * - 读输入直到行尾
   */
  {
    vector<string> v = split(s);

    // 输出 v 中的每一个单词
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
      cout << v[i] << endl;

    return 0;
  }
}
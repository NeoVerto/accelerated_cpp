#include <iostream>
#include <fstream>
/**
 * fstream 定义了 istream, ostream
 */
#include <string>

using std::cerr;
using std::cout;
using std::endl;

using std::ifstream;
using std::string;

using std::getline;

int main(int argc, char **argv)
{
  int fail_count = 0;
  // 对每个要输出的文件
  for (int i = 1; i < argc; ++i)
  {
    ifstream in(argv[i]);
    /**
     * 定义一个 ifstream / ofstream 对象
     * - 语法: ifstream 对象名(文件名)
     * - 文件名为字符数组 (以 '\0' 结尾). 对 string 类型的参数, 应通过 c_str 成
     *   员函数转化为字符数组 (以 '\0' 结尾).
     */

    if (in)
    {
      string s;
      while (getline(in, s))
        cout << s << endl;
    }
    else
    {
      cerr << "cannot open file " << argv[i] << endl;
      /**
       * 标准错误流
       * - cerr 即时输出错误信息. 只要一发生异常, 就会及时显示错误信息.
       * - clog 生成日志, 存储错误信息, 在系统认为适当时将其输出.
       */
      ++fail_count;
    }
  }

  return fail_count;
}
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
/**
 * main 函数参数
 * - argc: argv 指向的数组中的指针个数.
 * - argv: 指向一个指针数组首元素的指针.
 */
{
  // 若由命令行参数, 将它们显示出来
  if (argc > 1)
  /**
   * argv 数组的首元素总是 main 函数编译后的程序名, 因此 argc 的值至少是 1.
   */
  {
    cout << argv[1];                // 显示第一个参数
    for (int i = 2; i != argc; ++i)
      cout << " " << argv[i];       // argv[i] 是一个 char*, 字符串字面量.
  }
  cout << endl;

  return 0;
}
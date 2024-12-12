#include <cstring>
#include <string>

using std::strlen;

using std::string;

int main()
{
  const char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  /**
   * 字符串字面量
   * - 字符串字面量实质上是一个字符字面量数组, 该数组以 '\0' 结尾. 故该数组的大
   *   小是字符串长度 + 1.
   * - '\0' 作为字符串的终止符.
   * - strlen 函数 (定义在 <cstring> 中) 可计算字符串字面量的大小 ('\0' 不计入).
   */

  // 三者是等价的
  string s1(hello);
  string s2("Hello");
  string s3(hello, hello + strlen(hello));

  return 0;
}
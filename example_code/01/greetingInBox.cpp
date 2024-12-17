// 请求用户输入姓名, 然后产生一个带框架的问候语句
#include <iostream>
#include <string>

int main()
{
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;

  // 构造我们将要输出的信息
  const std::string greeting = "Hello, " + name + "!";
  /**
   * 拷贝初始化
   * - 语法: 修饰符 变量类型 变量名 = 初始值
   * - 若变量和初始值具有不同的类型, 则系统环境会将初始值的类型转换为变量的类.
   * 型.
   */

  /**
   * 运算符重载
   * - 若一个运算符对不同类型的操作数有不同的含义, 则称此运算符被重载了.
   * - 可利用 + 将两个字符串或一个字符串与字符串字面量连接起来 (不能连接两个字符
   * 串字面量).
   * - 重载运算符不改变运算符的结合性.
   */

  /**
   * const 修饰符
   * - 指明在变量的生存期内不允许修改的值.
   * - 必须在定义时初始化.
   */

  // 构建输出的第 2 行和第 4 行
  const std::string spaces(greeting.size(), ' ');
  /**
   * 调用成员
   * - 名为 greeting 的对象有一个称为 size 的成员. 该成员是一个函数, 因此可调用
   * 其获得关于 greeting 这个对象的字符个数.
   */

  /**
   * 字符字面量
   * - 由一对单引号 '' 括起, 表示单个字符.
   * - 类型为 char
   * - 跟在 \ 后的字符具有特殊含义.
   */

  /**
   * 字符类型
   * - char 类型用于保存 ascii 码字符.
   * - wchar_t 类型用于保存 Unicode 字符.
   * - 在 Unicode 下, 字符 '0-9', 'a-z', 'A-Z' 的相对顺序同 ASCII.
   */

  /**
   * 直接初始化
   * - 使用构造函数的参数直接创建对象.
   * - 对 std::string 而言, 一种直接初始化的方式为 obj(size, char) 来创建一个多
   * 个重复字符构成的字符串.
   */
  const std::string second = "*" + spaces + "*";

  // 构建输出的第 1 行和第 5 行
  const std::string first(second.size(), '*');

  // 输出全部内容
  std::cout << std::endl;
  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first << std::endl;

  return 0;
}
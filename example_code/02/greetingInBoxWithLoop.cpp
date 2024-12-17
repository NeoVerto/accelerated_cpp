#include <iostream>
#include <string>

using std::cin;
/**
 * using 声明
 * - 用于声明特定的名称来自特定的命名空间.
 * - using 声明的名称的特性同其他名称.
 */
using std::cout;
using std::endl;
using std::string;

int main()
{
  // 请求用户输入姓名
  cout << "Please enter your first name: ";

  // 读取用户的姓名
  string name;
  cin >> name;

  // 构造输出的信息
  const string greeting = "Hello, " + name + "!";

  // 围住问候语的空白个数
  const int pad = 1;

  // 待输入的行数与列数
  const int rows = pad * 2 + 3;
  const string::size_type cols = greeting.size() + pad * 2 + 2;
  /**
   * 类作用域
   * - 与名称空间和块语句一样, 类定义了它们自己的作用域.
   * - 类作用域中的名称也可用 :: 访问.
   */

  /**
   * std::string::size_type
   * - 用于保存字符串中的字符个数.
   * - 是一个无符号类型
   */

  /**
    * 其他类型
    * - unsigned 只包含非负数的整数类型
    * - short    16 位整数类型
    * - long     32 位整数类型
    * - size_t   无符号整数类型 (<csddef>), 保存对象长度.
    */
  // 输出一个空白行, 将输出和输入分隔开
  cout << endl;

  // 输出 rows 行
  // 不变式: 到目前为止, 我们已经输出了 r 行
  for (int r = 0; r != rows; ++r)
  {
  /**
   * for 语句
   * - 语法形式: for (初始化; 条件; 表达式)
   *               语句
   * - 首先执行初始化语句. 该语句只在 for 开始前执行一次.
   * - 在每次的循环过程中, 对条件计算. 只要条件满足, 执行语句.
   * - 每一轮语句执行完后, 执行表达式.
   * - 通常情况下, for 语句的意义相当于: {
   *                                        init-statement
   *                                        while (condition) {
   *                                          statement
   *                                          expression;
   *                                        }
   *                                     }
   */

  /**
   * 从 0 计数的原因
   * - 可使用不对称的区间表示间隔: [0, end)
   * - 在一个形式为 [m, n) 的区间内包含有 n - m 个元素.
   * - 空区间的表示: [n, n)
   * - 可使得循环不变式容易表达: 目前为止, 已经做了 x 次.
   * - 可使得条件用 != 比较, 从而确定结束状态.
   */
    string::size_type c = 0;
    // 不变式: 到目前为止, 我们已在当前行中输出了 c 个字符
    while (c != cols)
    {
    /**
     * while 语句
     * - 语法形式: while (条件)
     *               语句
     * - 只要条件满足, 反复执行语句直至条件不满足.
     */

    /**
     * 块语句: 由 {} 括起的语句集.
     */

    /**
     * 布尔类型 bool
     * - 用于表示真值的内建类型.
     * - 取值为 {true, false}
     */

    /**
     * 设计 loop 语句
     * - 当 loop 语句结束时, 条件必须为假.
     * - 循环不变式: 当 loop 语句要测试其条件时, 我们可断言该特性为真.
     *   - 在 loop 语句第一次测试它的条件之前, 不变式应当为真.
     *   - 到达了 loop 循环体结尾并即将开始下一次循环之前, 不变式应当为真.
     */
      // 是否应该输出问候语?
      if (r == pad + 1 && c == pad + 1)
      {
      /**
       * if 语句
       * - 语法: if (条件)
       *           语句
       *         或
       *         if (条件)
       *           语句
       *         else
       *           语句
       * - 条件为真, 执行 if 后的块语句; 条件为假, 执行 else 后的块语句.
       */

      /**
       * 关系运算符
       * - == 相等, != 不等, < 小于, > 大于, <= 不大于, >= 不小于
       * - 优先级低于算术运算符.
       */

      /**
       * 逻辑运算符
       * - || 或 (左结合)
       * - && 与 (左结合)
       * - !  非 (右结合)
       * - 逻辑运算符遵循短路求值的特性: 左操作数已经能确定整个表达式的值时, 不
       * 再计算右操作数.
       * - 优先级低于关系运算符.
       */
        cout << greeting;
        c += greeting.size();
      }
      // 是否在边界上?
      else
      {
        if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
          cout << "*";
        else
          cout << " ";
        ++c;
        /**
         * 自增运算符 ++
         * - 副作用是将对象的值变为直接后继.
         * - 前置自增 ++r 计算结果为 r + 1.
         * - 后置自增 r++ 计算结果为 r.
         */
      }
    }
    cout << endl;
  }

  return 0;
}
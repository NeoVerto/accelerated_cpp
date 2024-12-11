#include <iomanip>
/**
 * iomanip 定义了控制器, 如 setprecision.
 * - endl 控制器定义在 iostream 中.
 */
#include <ios>
/**
 * ios 定义了 streamsize 类型.
 */
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::string;

int main()
{
  // 请求并读入学生的姓名
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // 请求输入并读入期中期末成绩
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  /**
   * 类型 double, float
   * - double 用于存储双精度浮点数 (至少 10 个有效位).
   * - float 用于存储单精度浮点数 (最多 6 个有效位).
   */
  cin >> midterm >> final;

  // 请求输入家庭作业成绩
  cout << "Enter all your homework grades, "
       << "followed by end-of-file: ";
  
  // 到目前为止, 读到的家庭作业成绩的个数及总和
  int count = 0;
  double sum = 0;
  /**
   * 隐式数据类型转换
   * - 0 的类型是 int, 系统环境将其转换为 double 类型并赋值给 sum.
   */

  /**
   * 默认初始化
   * - 若未指定初始化器, 对自定义类型的对象, 类会自己指定一个.
   * - 对内部类型的局部变量, 不存在默认初始化.
   */

  /**
   * 未定义
   * - 若不明确初始化内部类型的局部变量, 则这些变量未定义.
   * - 创建变量时所分配的内存单元内的随机信息即为未定义变量的值.
   * - 在对未定义变量赋值前, 一切其他操作, 从逻辑上而言是不合法的.
   */

  // 将家庭作业成绩读到变量 x 中
  double x;

  // 不变式
  // 到目前为止, 我们已读入 count 个家庭作业成绩,
  // 而且 sum 等于头 count 个成绩的总和
  while (cin >> x) {
  /**
   * 发送文件结束标志
   * - Windows: Ctrl + Z
   * - Unix-like: Ctrl + D
   */

  /**
   * 隐式数据类型转换
   * - 非零值转为 true, 零值转为 false
   */

  /**
   * 将 istream 类型对象作为条件 <=> 检测最近一次从 istream 类型对象读数据是否
   * 成功
   * - 失败情况
   *   - 可能已经到达了输入文件的结尾.
   *   - 碰到的输入有可能跟我们试图读取的变量的类型不一致.
   *   - 系统可能在输入装置中检测到一个硬件问题.
   * - 如果不能成功地从流中读得数据, 则接下来所有从流读数据的方式都会失败, 除非
   * 重置流.
   */
    ++count;
    sum += x;
  }

  // 输出结果
  streamsize prec = cout.precision();
  /**
   * streamsize 类型
   * - 用于表示流的大小 (如字节数, 输出数据精度)
   * - 使用例子
   *   - 设置和获取流的精度
   *   - 控制流的宽度
   *   - 指定缓冲区大小
   */

  /**
   * cout.precision()
   * - 返回之前流在进行浮点数输出时所使用的精度.
   * - 可设置当前流在进行浮点数输出时所使用的精度: cout.precision(有效位数)
   */

  cout << "Your final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
       << setprecision(prec) << endl;
  /**
   * setprecision 控制器
   * - 允许我们指明输出所包含的有效位数.
   * - 语法: setprecision(有效位数)
   */

  return 0;
}
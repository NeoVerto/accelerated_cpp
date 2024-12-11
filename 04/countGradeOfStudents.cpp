/**
 * C++ 提供了两种基本的方法以便组织大型的程序
 * - 函数 (子程序)
 * - 数据结构
 */
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;   // 最长姓名的长度

  // 读入并存储所有学生的数据
  // 不变式: students 包含所有学生记录
  //         maxlen 包含 students 中最长的姓名
  while (read(cin, record))
  {
    // 找出最长姓名的长度
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // 按字母顺序排列学生记录
  sort(students.begin(), students.end(), compare);
  /**
   * sort 函数
   * - 语法: sort(b, e, 谓词)
   * - 谓词是一个函数, 它产生一个真值. 若有谓词, sort 用其比较元素, 而非采用 <
   * 运算符.
   *   - 谓词参数可以是谓词函数名.
   * - 非递增: b < e; 非递减: b > e;
   */

  // 输出姓名与成绩
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
  {
    // 输出姓名, 将姓名填充至 maxlen + 1 个字符的长度
    cout << students[i].name
         << string(maxlen + 1 - students[i].name.size(), ' ');

    // 计算并输出成绩
    try
    {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      /**
       * istream, ostream 类型的成员函数 width()
       * - 语法: s.width(宽度)
       * - 返回值: 当前宽度.
       * - 副作用: 将下一次的输入 / 输出操作的宽度设置为 n.
       * - 标准输出运算符在输出后会调用 width(0) 来重置宽度.
       */
      /**
       * 控制器 setw()
       * - 语法: setw(宽度)
       * - 作用于输出流效果等同于 s.width(n).
       */
      cout << setprecision(3) << final_grade
           << setprecision(prec);
    }
    catch (domain_error exception)
    {
      cout << exception.what();
      /**
       * 异常类型的成员函数 what()
       * - 返回值, 报告了问题所在.
       */
    }
    /**
     * 抛出异常
     * - 若程序抛出了一个异常, 则其会在抛出异常的地方终止程序并转移到程序的另一部
     * 分, 并向这部分提供一个异常对象.
     * - 异常对象中含有调用程序, 可用于处理异常的信息.
     */

    /**
     * try-catch 语句
     * - 语法: try {语句} catch (异常类型 异常变量名) {处理异常语句}
     * - 尝试执行 try 后块语句, 若语句中的任何地方发生了 catch 中的异常类型异常,
     * 则停止执行语句, 转而执行 catch 后块语句; 若未引发异常, 则跳过 catch 及后
     * 的块语句.
     * - 一个在时间上本来是跟在异常后执行的运算, 在程序正文中是没有必要位于异常
     * 发送点之后的.
     * - 应当保证一条语句的副作用个数不超过 1 个.
     */
    cout << endl;
  }

  return 0;
}
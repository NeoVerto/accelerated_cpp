#include <algorithm>
/**
 * algorithm 定义了 sort 函数
 * algorithm 定义了 max 函数
 */
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
/**
 * vector 定义了 vector 类型
 */

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

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
  cin >> midterm >> final;

  // 请求输入家庭作业成绩
  cout << "Enter all your homework grades, "
       << "followed by end-of-file: ";
  
  vector<double> homework;
  /**
   * vector<T> 类型
   * - 保存一系列具有特定类型 T 的数值 (模板类).
   * - 大小可根据需要增长以容纳添加的数值.
   * - 可随机访问每一个独立的数值.
   */
  double x;

  // 不变式: homework 包含所有的家庭作业成绩
  while (cin >> x)
    homework.push_back(x);
    /**
     * vector 的成员函数 push_back(T 类型的对象)
     * - 返回值: 传递给它的参数.
     * - 功能: 添加一个新的元素到向量的末尾.
     * - 副作用: 将向量的长度加 1.
     */

  // 检查 homework 是否为空
  typedef vector<double>::size_type vec_sz;
  /**
   * typedef 语言工具
   * - 语法: typedef type name;
   * - 为特定类型设定一个替代名.
   * - 通过 typedef 定义的名称, 同其他所有名称一样, 具有作用域.
   */
  vec_sz size = homework.size();
  /**
   * vector<T>::size_type 类型
   * - 一个 unsigned 类型, 用于保存向量可能容纳的最大长度.
   */
  
  /**
   * vector 的成员函数 size()
   * - 返回值: 向量中的元素个数, vector<T>::size_type 类型的值.
   */
  if (size == 0)
  {
    cout << endl << "You must enter your grades. "
                    "Please try again." << endl;
    return 1;
  }

  // 对成绩进行排序
  sort(homework.begin(), homework.end());
  /**
   * sort 函数
   * - 语法: sort(b, e)
   * - 默认将区间 [b, e) 中定义的元素重新排序为非递减序列
   */

  /**
   * max 函数
   * - 语法: max(e1, e2)
   * - 比较两个相同类型的表达式, 返回其中较大者.
   */

  /**
   * vector 的成员函数 begin(), end()
   * - begin() 指向 vector 内的第一个元素
   * - end() 指向 vector 内的最后一个元素之后的位置.
   */

  // 计算家庭作业成绩的中值
  vec_sz mid = size / 2;
  double median;
  median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
                         : homework[mid];
  /**
   * % 取模运算符
   * - 返回一个由其左操作数除以右操作数而得到的余数.
   */

  /**
   * ? : 条件运算符
   * - 简单的 if-then-else 表达式的简写: 条件 ? 真则表达式 : 假则表达式.
   * - 返回的值或为真则表达式的值, 或为假则表达式的值.
   */

  /**
   * 通过索引访问 vector 中的数
   * - 语法: vec[索引值]
   * - 索引值 = 0 为第一个元素, 索引值 = size - 1 为最后一个元素.
   */

  // 计算并输出总成绩
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final + 0.4 * median
       << setprecision(prec) << endl;

  return 0;
}
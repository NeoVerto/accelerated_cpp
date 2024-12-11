#include "analysis.h"

#include <algorithm>
/**
 * algorithm 定义了 transform 函数
 * algorithm 定义了 remove_copy 函数
 */
#include <iostream>
#include <iterator>
#include <numeric>
/**
 * numeric 定义了 accumulate 函数
 */
#include <stdexcept>
#include <string>
#include <vector>
#include "../04/grade.h"
#include "../04/median.h"
#include "../04/Student_info.h"

using std::accumulate;
using std::back_inserter;
using std::domain_error;
using std::endl;
using std::ostream;
using std::remove_copy;
using std::string;
using std::transform;
using std::vector;

double grade_aux(const Student_info& s)
{
  try
  {
    return grade(s);
  }
  catch (domain_error)
  {
    return grade(s.midterm, s.final, 0);
  }
}

double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  /**
   * transform 函数
   * - 语法: transform(b, e, d, f)
   * - 将 [b, e) 中的元素经 f 处理后复制到 d 处.
   * - 需保证目的地有足够的空间以保存值.
   */

  return median(grades);
}

double average(const std::vector<double>& v)
{
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
  /**
   * accumulate 函数
   * - 语法: accumulate(b, e, 初始值)
   * - 对 [b, e) 的所有元素求和, 并加上初始值.
   * - 初始值的类型为求和的类型.
   */
}

double average_grade(const Student_info& s)
{
  return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), average_grade);

  return median(grades);
}

double optimistic_median(const Student_info& s)
{
  vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
  /**
   * remove_copy 函数
   * - 语法: remove_copy(b, e, d, value)
   * - 将 [b, e) 中非 value 的值复制到 d 中.
   */

  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else
    return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);

  return median(grades);
}

void write_analysis(ostream& out, const string& name,
/**
 * void 返回类型
 * - 意义: 不返回值
 * - return; 可退出这种函数
 * - 不使用 return 语句, 执行到函数的末尾自动退出.
 */
                    double analysis(const vector<Student_info>&),
                    /**
                     * 传入函数作为参数
                     * - 语法: 类似一个函数声明
                     * - 事实上, 这样的形式会由编译器自动转化为函数指针形式:
                     *   double (*analysis)(const vector<Student_info>&)
                     */
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
  out << name << ":median(did) = " << analysis(did)
              << ":median(didnt) = " << analysis(didnt)
              << endl;
}
#include "grade.h"
/**
 * #include "用户定义的头文件名称"
 */

/**
 * 包含所实现的头文件冗余
 * - 为编译器提供机会检查声明与定义是否一致.
 */

#include <stdexcept>
#include <vector>
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

double grade(double midterm, double final, double homework)
/**
 * 按值调用参数
 * - 作为函数的局部变量使用, 调用函数时创建, 在函数返回时被销毁.
 * - 是相应参数值的复制.
 */

/**
 * 参数初始化
 * - 通过提供对应的对象, 在调用函数时初始化函数参数列表内的参数.
 * - 定义函数时定义参数并不会创建参数.
 */

{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
/**
 * 函数的作用
 * - 每当我们要在多个地方进行同一个计算时, 应当考虑将该部分计算放在同一个函数里.
 *   - 减轻程序工作量.
 *   - 方便改变运算过程.
 * - 函数具有名称, 使得我们能考虑其用途而不关心其实现.
 */

double grade(double midterm, double final, const vector<double>& hw)
/**
 * 重载
 * - 使几个函数具有同样函数.
 * - 参数列表不同
 */

/**
 * 引用
 * - 参数名称是一个特定对象的另一个名称.
 * - 对引用所做的任何动作等价于对原对象所做的同样动作, 反之亦然.
 * - 不存在 "引用的引用", 定义一个 "引用的引用" 与定义原来对象的引用的效果是一致
 * 的.
 */
{
  if (hw.size() == 0)
    throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
  return grade(s.midterm, s.final, s.homework);
}
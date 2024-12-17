#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include "Student_info.h"
inline double grade(double, double, double);
/**
 * inline 限定符
 * - 在适当条件下使编译器将调用扩展为内联子过程, 即复制替换为函数体而非调用函数.
 * - 避免函数调用的额外开销.
 */

double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif  // GUARD_grade_h
/**
 * #ifndef - #endif 指令
 * - 用于包含保护
 * - #ifndef label 检测 label 是否被定义, 若未定义, 包含后续代码.
 * - #endif 作为其结束符.
 */
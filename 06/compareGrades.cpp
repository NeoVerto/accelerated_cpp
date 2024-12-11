#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../04/Student_info.h"
#include "analysis.h"
#include "did_all_hw.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  vector<Student_info> did, didnt;
  Student_info student;

  // 读记录, 根据是否做了全部的家庭作业对其进行分类.
  while (read(cin, student))
  {
    if (did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }

  // 检查两个向量是否有包含数据
  if (did.empty())
  /**
   * vector 类型对象成员函数 empty
   * - 语法: v.empty()
   * - 若容器为空, 返回 true; 否则返回 false.
   */
  {
    cout << "No student did all the homework!" << endl;
    return 1;
  }
  if (didnt.empty())
  {
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  // 分析
  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);
  write_analysis(cout, "median of homework turned in", 
                 optimistic_median_analysis, did ,didnt);

  return 0;
}
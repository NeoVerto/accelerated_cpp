
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "core.h"
#include "grad.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

using std::domain_error;
using std::streamsize;
using std::string;
using std::vector;

using std::max;
using std::sort;

int main()
{
  vector<core*> students;
  core* record;
  char ch;
  string::size_type maxlen = 0;

  // 读入并存储数据
  while (cin >> ch)
  {
    if (ch == 'U')
      record = new core;
    else
      record = new grad;
    record->read(cin);
    maxlen = max(maxlen, record->name().size());
    students.push_back(record);
  }

  // 将学生记录按字母排序
  sort(students.begin(), students.end(), compare_core_ptrs);

  // 输出学生姓名与成绩
  for (vector<core*>::size_type i = 0; i != students.size(); ++i)
  {
    cout << students[i]->name()
         << string(maxlen + 1 - students[i]->name().size(), ' ');
    try
    {
      double final_grade = students[i]->grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
           << setprecision(prec) << endl;
    }
    catch(domain_error exception)
    {
      cout << exception.what() << endl;
    }
    delete students[i]; // 释放读文件时生成的临时变量
    /**
     * 调用 delete 所发生的
     * - 调用了指针 / 引用所指 / 绑定对象的析构函数.
     * - 对象所占用的内存空间被释放回系统.
     */
  }

  return 0;
}
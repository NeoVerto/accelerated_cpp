#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"

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
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // 读并存储数据
  while (record.read(cin))
  {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  // 按字典序排列学生记录
  sort(students.begin(), students.end(), compare);

  // 写姓名和成绩
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
  {
    cout << students[i].name()
         << string(maxlen + 1 - students[i].name().size(), ' ');

    try
    {
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
           << setprecision(prec) << endl;
    }
    catch (domain_error exception)
    {
      cout << exception.what() << endl;
    }
  }
  return 0;
}
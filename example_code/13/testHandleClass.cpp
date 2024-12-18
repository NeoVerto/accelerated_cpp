
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;

using std::domain_error;
using std::string;
using std::streamsize;
using std::vector;

using std::max;
using std::sort;

int main()
{
  vector<student_info> students;
  student_info record;
  string::size_type maxlen = 0;

  while (record.read(cin))
  {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), student_info::compare);

  for (vector<student_info>::size_type i = 0; i != students.size(); ++i)
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
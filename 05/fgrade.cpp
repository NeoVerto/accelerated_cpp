#include "fgrade.h"

#include "../04/grade.h"
#include "../04/Student_info.h"

bool fgrade(const Student_info& s)
{
  return grade(s) < 60;
}
#ifndef GUARD_extract_fails_h
#define GUARD_extract_fails_h

#include <list>
#include <vector>
#include "../04/Student_info.h"
std::vector<Student_info>
extract_fails_VectorByIndex(std::vector<Student_info>&);
std::vector<Student_info>
extract_fails_VectorByIterator(std::vector<Student_info>&);
std::list<Student_info>
extract_fails_List(std::list<Student_info>&);
#endif  // GUARD_extract_fails_h
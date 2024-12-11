#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <iostream>
#include <string>
#include <vector>
#include "../04/Student_info.h"
double grade_aux(const Student_info&);
double average(const std::vector<double>&);
double average_grade(const Student_info&);
double optimistic_median(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&,
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);

#endif  // GUARD_analysis_h
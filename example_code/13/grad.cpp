#include "grad.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::istream;
using std::vector;

using std::min;

istream& read_hw(istream& in, vector<double>& hw)
{
  if (in)
  {
    hw.clear();
    double x;
    while (in >> x);
      hw.push_back(x);
    in.clear();
  }
}

// public:
istream& grad::read(istream& in)
{
  read_common(in);
  in >> thesis;
  read_hw(in, homework);

  return in;
}

double grad::grade() const { return min(core::grade(), thesis); }
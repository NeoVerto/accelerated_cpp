#ifndef GUARD_str_h
#define GUARD_str_h

#include <cctype>
#include <cstring>
#include <iostream>
#include <iterator>
#include "Ptr.h"
#include "Vec.h"

class Str
{
  friend std::istream& operator>>(std::istream& is, Str& s)
  {
    s.data->clear();

    char c;
    while (is.get(c) && std::isspace(c))
      ;

    if (is)
    {
      do
        s.data->push_back(c);
      while (is.get(c) && !isspace(c));

      if (is)
        is.unget();
    }

    return is;
  }

public:
  typedef Vec<char>::size_type size_type;

  Str(): data(new Vec<char>) {}

  Str(size_type n, char c): data(new Vec<char>(n, c)) {}

  Str(const char* cp): data(new Vec<char>)
  {
    std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data));
  }

  template <class In>
  Str(In b, In e): data(new Vec<char>)
  {
    std::copy(b, e, std::back_inserter(*data));
  }

  char& operator[](size_type i)
  {
    data.make_unique();
    return (*data)[i];
  }
  const char& operator[](size_type i) const { return (*data)[i]; }

  Str& operator+=(const Str& s)
  {
    std::copy(s.data->begin(), s.data->end(), std::back_inserter(*data));

    return *this;
  }

  size_type size() const { return data->size(); }

private:
  Ptr<Vec<char>> data;
};

std::ostream& operator<<(std::ostream& os, const Str& s)
{
  for (Str::size_type i = 0; i != s.size(); ++i)
    os << s[i];
  return os;
}

Str operator+(const Str& a, const Str& b)
{
  Str tmp = a;
  tmp += b;
  return tmp;
}

#endif  // GUARD_str_h
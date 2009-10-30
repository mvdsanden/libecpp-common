#include "string.ih"

#include <algorithm>
#include <ctype.h>

char down(char x) { return tolower(x); }

std::string String::lower(std::string const &str)
{
  string res = str;
  transform(res.begin(),res.end(),res.begin(),down);
  return res;
}

#include "string.ih"

#include <algorithm>
#include <cctype>

char up(char x) { return toupper(x); }

std::string String::upper(std::string const &str)
{
  string res = str;
  transform(res.begin(),res.end(),res.begin(),up);
  return res;
}

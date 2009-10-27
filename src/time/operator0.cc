#include "time.ih"

#include <iostream>

std::ostream &ecpp::operator<<(std::ostream &stream, Time const &t)
{
  char buffer[26];
  asctime_r(t,buffer);
  for (char *i = buffer; i < buffer+26; ++i)
    if (*i == '\n') { (*i) = 0; break; }
  return stream << buffer;
}

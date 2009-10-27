#include "time.ih"

string Time::monthName() const
{
  char buf[64];

  size_t len = strftime(buf, sizeof(buf), "%B", &d_tm);

  string res(buf,len);

  return res;
}

#include "time.ih"

string Time::dayOfWeekName() const
{
  char buf[64];

  size_t len = strftime(buf, sizeof(buf), "%A", &d_tm);

  string res(buf,len);

  return res;
}

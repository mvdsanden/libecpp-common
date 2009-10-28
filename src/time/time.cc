#include "time.ih"

#include <cstring>

Time::Time(struct tm *t)
{
  memcpy(reinterpret_cast<char *>(&d_tm),
	 reinterpret_cast<char const*>(&t),
	 sizeof(tm));
}

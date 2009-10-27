#include "time.ih"

#include <cstring>

void Time::copy(Time const &other)
{
  memcpy(reinterpret_cast<char *>(&d_tm),
	 reinterpret_cast<char const*>(&other.d_tm),
	 sizeof(tm));
}

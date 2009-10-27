#include "time.ih"

Time Time::localNow()
{
  return Time();
}

Time Time::utcNow()
{
  time_t t;
  time(&t);

  return Time(gmtime(&t));
}


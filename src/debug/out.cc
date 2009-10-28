#include "debug.ih"

#include "../Time/time.hh"

std::ostream &Debug::out()
{
  return d_stream << Time::localNow() << " ";
}

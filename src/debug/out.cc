#include "debug.ih"

std::ostream &Debug::out()
{
  return d_stream << Time::localNow() << " ";
}

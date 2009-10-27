#include "debug.ih"

Debug *Debug::s_instance = 0;

Debug &Debug::instance()
{
  return *(s_instance?s_instance:s_instance = new Debug);
}

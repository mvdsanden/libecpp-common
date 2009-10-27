#include "debug.ih"

#include <iostream>

Debug::Debug()
  : d_stream(cerr.rdbuf())
{

}

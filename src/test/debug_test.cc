#include <iostream>

#define DEBUGLEVEL 2
#include "../Debug/debug.hh"

using namespace ecpp;

int main()
{
  __debug(1,"Should not be visible");
  __debug(3,"Should be visible");

  return 0;
}

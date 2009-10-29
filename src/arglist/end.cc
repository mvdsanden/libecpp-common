#include "arglist.ih"

#include "iterator.hh"

ArgList::iterator ArgList::end()
{
  return iterator(d_argv + d_argc);
}

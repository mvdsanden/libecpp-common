#include "arglist.ih"

#include "iterator.hh"

ArgList::iterator ArgList::begin()
{
  return iterator(d_argv);
}

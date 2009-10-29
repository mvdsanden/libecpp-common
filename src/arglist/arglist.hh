/*
  This file is part of libecpp-module_name.
  libecpp-module_name is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  libecpp-mofule_name is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __INC_ECPP_ARGLIST_HH__
#define __INC_ECPP_ARGLIST_HH__

namespace ecpp
{

  class ArgList {
  public:

    class iterator;

    ArgList(int argc, char *argv[]);

    iterator begin();

    iterator end();

  private:

    int d_argc;
    char **d_argv;

  };

  inline ArgList::ArgList(int argc, char *argv[])
    : d_argc(argc),
      d_argv(argv)
  {
  }


};

// This is pretty bad I guess??
#include "iterator.hh"

#endif // __INC_ECPP_ARGLIST_HH__

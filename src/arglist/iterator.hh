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

#ifndef __INC_ECPP_ARGLIST_ITERATOR_HH__
#define __INC_ECPP_ARGLIST_ITERATOR_HH__

#include <iterator>

#include "arglist.hh"

namespace ecpp
{

  class ArgList::iterator {
    friend class ArgList;

    iterator(char **argv)
      : d_argv(argv)
    {
    }

  public:

    // Iterator traits
    typedef std::forward_iterator_tag iterator_category; // could be random I guess!
    typedef std::string value_type;
    typedef ptrdiff_t difference_type;
    typedef iterator *pointer;
    typedef iterator &reference;

    iterator &operator++()
    {
      d_argv++;
      return *this;
    }

    iterator &operator++(int)
    {
      ++d_argv;
      return *this;
    }

    iterator &operator+(size_t index)
    {
      iterator i(*this);
      return i += index;
    }

    iterator &operator+=(size_t index)
    {
      d_argv += index;
      return *this;
    }

    iterator &operator-(size_t index)
    {
      iterator i(*this);
      return i -= index;
    }

    iterator &operator-=(size_t index)
    {
      d_argv -= index;
      return *this;
    }

    std::string operator*() const
    {
      return *d_argv;
    }

    bool operator==(iterator const &other)
    {
      return (d_argv == other.d_argv);
    }

    bool operator!=(iterator const &other)
    {
      return (d_argv != other.d_argv);
    }


  private:

    char **d_argv;

  };

};

#endif // __INC_ECPP_ARGLIST_ITERATOR_HH__

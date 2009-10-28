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

#ifndef __INC_ECPP_STRING_HH__
#define __INC_ECPP_STRING_HH__

#include <string>
#include <vector>

namespace ecpp
{

  class String {
  public:

    class Splitter;

    /**
     *  Split a string using delimmitter delim.
     */
    static std::vector<std::string> split(std::string const &str, std::string const &delim);

  };

  class String::Splitter {
  public:

    class iterator  {

      std::string const &d_str;
      std::string const &d_delim;
      size_t d_pos, d_del;

      void next()
      {
	d_del = d_str.find(d_delim,d_pos);
	d_del = (d_del == std::string::npos?d_str.length():d_del+1);
      }

    public:

      iterator(std::string const &str, std::string const &delim, size_t pos = 0)
	: d_str(str), d_delim(delim), d_pos(pos)
      {
	next();
      }

      iterator(iterator const &other)
	: d_str(other.d_str),
	  d_delim(other.d_delim),
	  d_pos(other.d_pos),
	  d_del(other.d_del)
      {
      }

      iterator &operator++()
      {
	d_pos = d_del;
	next();
	return *this;
      }

      std::string operator*() const
      {
	return d_str.substr(d_pos,d_del-d_pos-1);
      }

      bool operator==(iterator const &other)
      {
	return (d_pos == other.d_pos);
      }

      bool operator!=(iterator const &other)
      {
	return (d_pos != other.d_pos);
      }

    };

    Splitter(std::string const &str, std::string const &delim);

    iterator begin();
    iterator end();

  private:

    std::string d_str;
    std::string d_delim;
  };

  inline String::Splitter::Splitter(std::string const &str, std::string const &delim)
    : d_str(str),
      d_delim(delim)
  {
  }

  inline String::Splitter::iterator String::Splitter::begin()
  {
    return iterator(d_str,d_delim);
  }

  inline String::Splitter::iterator String::Splitter::end()
  {
    return iterator(d_str,d_delim,d_str.length());
  }

};

#endif // __INC_ECPP_STRING_HH__

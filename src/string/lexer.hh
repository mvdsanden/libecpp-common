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

#ifndef __INC_ECPP_STRING_LEXER_HH__
#define __INC_ECPP_STRING_LEXER_HH__

#include "string.hh"

namespace ecpp
{

  class String::Lexer {
  public:

    class iterator {

      friend class String::Lexer;

      std::string const &d_str;
      std::string const &d_delims;
      size_t d_pos, d_del;

      void next()
      {
	d_del = d_str.find_first_of(d_delims,d_pos);
	d_del = (d_del == std::string::npos?d_str.length():(d_del == d_pos?d_del+1:d_del));
      }

      iterator(std::string const &str, std::string const &delims, size_t pos = 0)
	: d_str(str), d_delims(delims), d_pos(pos)
      {
	next();
      }

    public:

      // Iterator traits
      typedef std::forward_iterator_tag iterator_category;
      typedef std::string value_type;
      typedef ptrdiff_t difference_type;
      typedef iterator *pointer;
      typedef iterator &reference;

      iterator(iterator const &other)
	: d_str(other.d_str),
	  d_delims(other.d_delims),
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

      iterator &operator++(int)
      {
	d_pos = d_del;
	next();
	return *this;
      }

      std::string operator*() const
      {
	return d_str.substr(d_pos,d_del-d_pos);
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

    /**
     *  Create a Lexer with string str and delimitter delim.
     */
    Lexer(std::string const &str, std::string const &delim);

    /**
     *  @returns an iterator to the first element of the split pieces.
     */
    iterator begin();

    /**
     *  @returns an iterator to the element after the last element of the split pieces.
     */
    iterator end();

  private:
    std::string d_str;
    std::string d_delim;
  };

  inline String::Lexer::Lexer(std::string const &str, std::string const &delim)
    : d_str(str),
      d_delim(delim)
  {
  }

  inline String::Lexer::iterator String::Lexer::begin()
  {
    return iterator(d_str,d_delim);
  }

  inline String::Lexer::iterator String::Lexer::end()
  {
    return iterator(d_str,d_delim,d_str.length());
  }

}

#endif // __INC_ECPP_STRING_LEXER_HH__

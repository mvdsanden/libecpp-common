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
#include <map>

namespace ecpp
{

  class String {
  public:

    class Splitter; // include "string/splitter.hh"
    class Lexer;    // include "string/lexer.hh"

    /**
     *  Split a string using delimmitter delim.
     */
    static std::vector<std::string> split(std::string const &str, std::string const &delim);

    /**
     *  Combine a list of string, adding delim between the elements.
     */
    static std::string combine(std::vector<std::string> const &lst, std::string const &delim);

    /**
     *  Lex a string using delimmitters in delims.
     *
     *  This creates a vector of tokens of the spring split by one of the
     *  delimitters in delims and also contains the delimitters them selfs.
     */
    static std::vector<std::string> lex(std::string const &str, std::string const &delims);

    /**
     *  Substitute all keys in substs with their values.
     *
     *  @returns the substituted result.
     */
    static std::string substitute(std::string const &str, std::map<std::string,std::string> const &substs);

    /**
     *  @return the lowercase version of str.
     */
    static std::string lower(std::string const &str);

    /**
     *  @return the uppercase version of str.
     */
    static std::string upper(std::string const &str);

  };



};

#endif // __INC_ECPP_STRING_HH__

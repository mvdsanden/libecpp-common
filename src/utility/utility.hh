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

#ifndef __INC_ECPP_UTILITY_HH__
#define __INC_ECPP_UTILITY_HH__

#include <vector>
#include <ostream>

namespace ecpp
{

  template <class T>
  std::vector<T> operator+(std::vector<T> const &a, std::vector<T> const &b)
  {
    std::vector<T> res = a;
    res.insert(res.end(),b.begin(),b.end());
    return res;
  }

  template <class T>
  std::ostream &operator<<(std::ostream &stream, std::vector<T> const &vect)
  {
    stream << "[";
    for (typename std::vector<T>::const_iterator i = vect.begin();
	 i != vect.end(); ++i)
      stream << (i != vect.begin()?",":"") << *i;
    return stream << "]";
  }


};

#endif // __INC_ECPP_UTILITY_HH__

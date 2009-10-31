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

#ifndef __INC_ECPP_CHARACTER_HH__
#define __INC_ECPP_CHARACTER_HH__

#include <cctype>

namespace ecpp
{

  class Character {
  public:

    /**
     *  @returns true if ch is a digit.
     */
    static bool isDigit(int ch);

    /**
     *  @returns true if ch is a letter (equivalent to isAlpha()).
     */
    static bool isLetter(int ch);

    /**
     *  @returns true if ch is an alphabet value.
     */
    static bool isAlpha(int ch);

    /**
     *  @returns true if ch is a blank character.
     */
    static bool isBlank(int ch);

    /**
     *  @returns true if ch is an upper case letter.
     */
    static bool isUpper(int ch);

    /**
     *  @returns true if ch is a lower case letter.
     */
    static bool isLower(int ch);

    /**
     *  @returns true if ch is in [r0,r1].
     */
    template <int r0, int r1>
    static bool isInRange(int ch);

    /**
     *  @returns the upper case variant of ch.
     */
    static int toUpper(int ch);

    /**
     *  @returns the lower case variant of ch.
     */
    static int toLower(int ch);

  };

  inline bool Character::isDigit(int ch)
  {
    return isdigit(ch);
  }

  inline bool Character::isLetter(int ch)
  {
    return isAlpha(ch);
  }

  inline bool Character::isAlpha(int ch)
  {
    return isalpha(ch);
  }

  inline bool Character::isBlank(int ch)
  {
    return isblank(ch);
  }

  inline bool Character::isUpper(int ch)
  {
    return isupper(ch);
  }

  inline bool Character::isLower(int ch)
  {
    return islower(ch);
  }

  template <int r0, int r1>
  inline bool Character::isInRange(int ch)
  {
    return (r0 <= ch && ch <= r1);
  }

  inline int Character::toUpper(int ch)
  {
    return toupper(ch);
  }

  inline int Character::toLower(int ch)
  {
    return tolower(ch);
  }



};

#endif // __INC_ECPP_CHARACTER_HH__

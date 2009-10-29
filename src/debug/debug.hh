/* This file is part of libecpp-module_name.
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

#ifndef __INC_ECPP_DEBUG_HH__
#define __INC_ECPP_DEBUG_HH__

#include <ostream>

//Default debuglevel is 0
#ifndef DEBUGLEVEL
  #define DEBUGLEVEL 0
#endif

#define __debug(level, x) if (level < DEBUGLEVEL) { Debug::instance().out() << "[D" << level << "] " << __FILE__ << ":" << __LINE__ << ":" << x << std::endl; }

namespace ecpp
{

  /** The Debug Helper Class
   *
   *  Use __debug(level,msg) for inserting debug information.
   *
   *  This class implements some methods to change how debug is generated,
   *  currently only redirecting the output.
   */
  class Debug
  {
  public:

    static Debug &instance();

    /**
     *  @returns the debug output stream.
     */
    std::ostream &out();

    /**
     *  Redirect the debug output to stream.
     */
    void redirect(std::ostream &stream);

  private:

    Debug();

    static Debug *s_instance;

    std::ostream d_stream;

  };

} //end of namespace cpp

#endif // __INC_ECPP_DEBUG_HH__

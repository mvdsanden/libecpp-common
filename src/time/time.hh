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

#ifndef __INC_ECPP_TIME_HH__
#define __INC_ECPP_TIME_HH__

#include <ctime>
#include <iosfwd>
#include <string>

namespace ecpp {

  /** The Time Class
   *
   *  This class implements the time_t constructs.
   *
   *  It represents a time accurate to the second (internally
   *  it is represented as seconds since the Epoch (00:00:00 UTC,
   *  January 1, 1970).
   */
  class Time {
    friend std::ostream &operator<<(std::ostream &, Time const &);
  public:

    /**
     *  @returns the current local time.
     */
    static Time localNow();

    /**
     *  @returns the current time in UTC.
     */
    static Time utcNow();

    /**
     *  Constructs a time of 00:00:00 UTC,
     *  January 1, 1970.
     */
    Time();

    Time(Time const &other);

    /**
     *  Constructs a time object initialized by the time represented by t.
     */
    Time(time_t t);

    /**
     *  Constructs a time object initialized by the time represented by tm.
     */
    Time(struct tm *t);

    Time &operator=(Time const &other);

    /**
     *  @returns true if this time is before the other.
     */
    bool operator<(Time const &other);

    /**
     *  @returns true if this time is after the other.
     */
    bool operator>(Time const &other);

    /**
     *  @returns true if this time is before or equal to the other.
     */
    bool operator<=(Time const &other);

    /**
     *  @returns true if this time is after or equal to the other.
     */
    bool operator>=(Time const &other);

    /**
     *  Substracts the other time from this time and returns the result.
     */
    Time operator-(Time const &other);

    /**
     *  Substracts adds the two times and returns the result.
     */
    Time operator+(Time const &other);

    /**
     *  @returns a time_t representation of this time.
     */
    operator time_t () const;

    /**
     *  @returns a tm* representation of this time.
     */
    operator struct tm* () const;

    /**
     *  @returns the seconds of the hour.
     */
    int sec() const;

    /**
     *  @returns the minutes of the hour.
     */
    int min() const;

    /**
     *  @returns the hour.
     */
    int hour() const;

    /**
     *  @returns the day of the month.
     */
    int dayOfMonth() const;

    /**
     *  @returns the number of the month.
     */
    int month() const;

    /**
     *  @returns a string representation of the month.
     */
    std::string monthName() const;

    /**
     *  @returns the number of the year.
     */
    int year() const;

    /**
     *  @returns the day of the week.
     */
    int dayOfWeek() const;

    /**
     *  @returns a string representation of the day of the week.
     */
    std::string dayOfWeekName() const;

    /**
     *  @returns the day of the year.
     */
    int dayOfYear() const;

    /**
     *  @returns true if it is day light savings time.
     */
    bool daylightSavingsTime() const;

  private:

    void copy(Time const &other);
    void destroy();

    // I know, it's realy bad!
    mutable struct tm d_tm;

  };


  inline void Time::destroy()
  {
  }

  inline Time::Time()
  {
    // Use local time.
    time_t t = time(0);
    localtime_r(&t,&d_tm);
  }

  inline Time::Time(Time const &other)
  {
    copy(other);
  }

  inline Time::Time(time_t t)
  {
    localtime_r(&t,&d_tm);
  }

  inline Time &Time::operator=(Time const &other)
  {
    if (this != &other) {
      destroy();
      copy(other);
    }
    return *this;
  }

  inline bool Time::operator<(Time const &other)
  {
    return
      static_cast<time_t>(*this) <
      static_cast<time_t>(other);
  }

  inline bool Time::operator>(Time const &other)
  {
    return
      static_cast<time_t>(*this) >
      static_cast<time_t>(other);
  }

  inline bool Time::operator<=(Time const &other)
  {
    return
      static_cast<time_t>(*this) <=
      static_cast<time_t>(other);
  }

  inline bool Time::operator>=(Time const &other)
  {
    return
      static_cast<time_t>(*this) >=
      static_cast<time_t>(other);
  }

  inline Time Time::operator-(Time const &other)
  {
    return
      static_cast<time_t>(*this) -
      static_cast<time_t>(other);
  }

  inline Time Time::operator+(Time const &other)
  {
    return
      static_cast<time_t>(*this) +
      static_cast<time_t>(other);
  }

  inline Time::operator time_t () const
  {
    return mktime(&d_tm);
  }

  inline Time::operator struct tm* () const
  {
    return &d_tm;
  }

  inline int Time::sec() const
  {
    return d_tm.tm_sec;
  }

  inline int Time::min() const
  {
    return d_tm.tm_min;
  }

  inline int Time::hour() const
  {
    return d_tm.tm_hour;
  }

  inline int Time::dayOfMonth() const
  {
    return d_tm.tm_mday;
  }

  inline int Time::month() const
  {
    return d_tm.tm_mon;
  }

  inline int Time::year() const
  {
    return d_tm.tm_year;
  }

  inline int Time::dayOfWeek() const
  {
    return d_tm.tm_wday;
  }

  inline int Time::dayOfYear() const
  {
    return d_tm.tm_yday;
  }

  inline bool Time::daylightSavingsTime() const
  {
    return d_tm.tm_isdst;
  }

  std::ostream &operator<<(std::ostream &stream, Time const &t);

};

#endif // __INC_ECPP_TIME_HH__

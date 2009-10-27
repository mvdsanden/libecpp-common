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

#include <time.h>
#include <iostream>
#include <cstring>

namespace ecpp {

  class Time {

	friend std::ostream &operator<<(std::ostream &, Time const &);

  public:

	static Time localNow();
	static Time utcNow();

	Time();

	Time(Time const &other);

	Time(time_t t);

	Time(struct tm *t);

	Time &operator=(Time const &other);

	bool operator<(Time const &other);
	bool operator>(Time const &other);
	bool operator<=(Time const &other);
	bool operator>=(Time const &other);

	Time operator-(Time const &other);
	Time operator+(Time const &other);

	operator time_t () const;
	operator struct tm* () const;

	int sec() const;
	int min() const;
	int hour() const;
	int dayOfMonth() const;
	int month() const;
	int year() const;
	int dayOfWeek() const;
	int dayOfYear() const;

	bool daylightSavingsTime() const;

  private:

	void copy(Time const &other);
	void destroy();

	// I know, it's realy bad!
	mutable struct tm d_tm;

  };

  inline void Time::copy(Time const &other)
  {
	memcpy(reinterpret_cast<char *>(&d_tm),
		   reinterpret_cast<char const*>(&other.d_tm),
		   sizeof(tm));
  }

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

  inline Time::Time(struct tm *t)
  {
	memcpy(reinterpret_cast<char *>(&d_tm),
		   reinterpret_cast<char const*>(&t),
		   sizeof(tm));
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

  inline std::ostream &operator<<(std::ostream &stream, Time const &t)
  {
	char buffer[26];
	asctime_r(t,buffer);
	for (char *i = buffer; i < buffer+26; ++i)
	  if (*i == '\n') { (*i) = 0; break; }
	return stream << buffer;
  }

};

#endif // __INC_ECPP_TIME_HH__

#include <iostream>

#include "../time/time.hh"

using namespace std;
using namespace ecpp;

int main()
{

  Time t = Time::localNow();

  cout << "t = " << t << endl;
  cout << "Month: " << t.monthName() << endl;
  cout << "Day: " << t.dayOfWeekName() << endl;

  return 0;
}

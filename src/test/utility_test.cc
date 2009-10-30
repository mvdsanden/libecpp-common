#include <iostream>

#include "../string/string.hh"
#include "../utility/utility.hh"

using namespace std;
using namespace ecpp;

int main()
{
  vector<string> a = String::split("1,2,3,4,5",",");
  vector<string> b = String::split("6,7,8,9,0",",");
  vector<string> c = a + b;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a + b = " << c << endl;

  return 0;
}

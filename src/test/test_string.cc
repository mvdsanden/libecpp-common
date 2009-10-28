#include <iostream>

#include "../String/string.hh"

using namespace std;
using namespace ecpp;


int main()
{
  string a = "Hallo/dit/is/een/test/hahaha/dit/hoeft helemaal niet met slashes!";

  String::Splitter split(a,"/");
  for (String::Splitter::iterator i = split.begin();
       i != split.end(); ++i)
    cout << "- '" << (*i) << "'." << endl;

  vector<string> s = String::split(a,"/");
  for (vector<string>::iterator i = s.begin();
       i != s.end(); ++i)
    cout << "- '" << (*i) << "'." << endl;

  return 0;
}

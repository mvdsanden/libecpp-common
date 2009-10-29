#include <iostream>

#include "../string/string.hh"
#include "../string/splitter.hh"
#include "../string/lexer.hh"
#include "../misc/foreach.hh"

using namespace std;
using namespace ecpp;

int main()
{
  string a = "Hallo/dit/is/een/test/hahaha/dit/ /hoeft helemaal niet met slashes!";

  String::Splitter split(a,"/");
  for (String::Splitter::iterator i = split.begin();
       i != split.end(); ++i)
    cout << "- '" << (*i) << "'." << endl;

  vector<string> s = String::split(a,"/");
  for (vector<string>::iterator i = s.begin();
       i != s.end(); ++i)
    cout << "- '" << (*i) << "'." << endl;

  __foreach(j,split)
    cout << "- '" << (*j) << "'." << endl;

  String::Lexer lex(a,"/ ");
  for (String::Lexer::iterator i = lex.begin();
       i != lex.end(); ++i)
    cout << "- '" << (*i) << "'." << endl;

  vector<string> l = String::lex(a,"/ !");
  for (vector<string>::iterator i = l.begin();
       i != l.end(); ++i)
    cout << "- '" << (*i) << "'." << endl;

  cout << String::combine(s,":") << endl;

  return 0;
}

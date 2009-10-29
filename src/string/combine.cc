#include "string.ih"

string String::combine(vector<string> const &lst,
		       string const &delim)
{
  string res;

  for (vector<string>::const_iterator i = lst.begin();
       i != lst.end(); ++i)
    res += (i != lst.begin()?delim:"") + *i;

  return res;
}

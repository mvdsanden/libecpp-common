#include "string.ih"

std::string String::substitute(std::string const &str,
			       std::map<std::string,std::string> const &substs)
{
  string res = str;

  size_t count = 1;

  while (count) {
    count = 0;

    for (map<string,string>::const_iterator i = substs.begin();
	 i != substs.end(); ++i) {

      size_t pos = res.find((*i).first);

      if (pos != string::npos) {
	++count;

	res.replace(res.begin() + pos,
		    res.begin() + pos + (*i).first.length(),
		    (*i).second);
      }

    }
  }

  return res;
}

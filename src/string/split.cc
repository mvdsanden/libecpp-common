#include "string.ih"
#include "splitter.hh"

vector<string> String::split(std::string const &str, std::string const &delim)
{
  Splitter split(str,delim);
  return vector<string>(split.begin(),split.end());
}


#include "string.ih"
#include "lexer.hh"

vector<string> String::lex(std::string const &str, std::string const &delims)
{
  Lexer lex(str,delims);
  return vector<string>(lex.begin(),lex.end());
}


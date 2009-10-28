#include "debug.ih"

void Debug::redirect(std::ostream &stream)
{
  d_stream.rdbuf(stream.rdbuf()); // ?
  //  throw runtime_error("Debug redirection not yet implemented");
}

#include <iostream>

#include "../arglist/arglist.hh"
//#include "../arglist/iterator.hh"

using namespace std;
using namespace ecpp;

int main(int argc, char *argv[])
{
  ArgList args(argc,argv);

  for (ArgList::iterator i = args.begin() + 1;
       i != args.end(); ++i)
    cout << "- " << *i << endl;

  return 0;
}

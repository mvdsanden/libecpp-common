#include <iostream>

#include "../character/character.hh"

using namespace std;
using namespace ecpp;

void show(char c)
{
  cout << c << "\t"
       << Character::isDigit(c) << "\t"
       << Character::isLetter(c) << "\t"
       << Character::isBlank(c) << "\t"
       << Character::isUpper(c) << "\t"
       << Character::isLower(c) << "\t"
       << Character::isInRange<'e','l'>(c) << endl;
}

int main()
{

  cout << "Char\tDigit\tLetter\tBlank\tUpper\tLower\t['e','l']" << endl;
  show('a');
  show('5');
  show('A');
  show('c');
  show('d');
  show(' ');
  show('\t');
  show('f');
  show('l');
  show('e');

  return 0;
}

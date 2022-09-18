// set::rbegin/rend
#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  int myints[] = {21,64,17,78,49};
  CT::set<int> myset (myints,myints+5);

  CT::set<int>::reverse_iterator rit;

  std::cout << "myset contains:";
  for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}
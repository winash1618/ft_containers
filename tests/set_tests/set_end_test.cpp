// set::begin/end
#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  int myints[] = {75,23,65,42,13};
  CT::set<int> myset (myints,myints+5);

  std::cout << "myset contains:";
  for (CT::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
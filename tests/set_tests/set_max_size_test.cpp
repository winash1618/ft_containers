// set::max_size
#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  int i;
  CT::set<int> myset;

  if (myset.max_size()>1000)
  {
    for (i=0; i<1000; i++) myset.insert(i);
    std::cout << "The set contains 1000 elements.\n";
  }
  else std::cout << "The set could not hold 1000 elements.\n";

  return 0;
}
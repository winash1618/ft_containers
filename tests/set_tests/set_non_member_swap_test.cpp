// swap (set overload)
#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  int myints[]={12,75,10,32,20,25};
  CT::set<int> first (myints,myints+3);     // 10,12,75
  CT::set<int> second (myints+3,myints+6);  // 20,25,32

  swap(first,second);

  std::cout << "first contains:";
  for (CT::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (CT::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
// assignment operator with sets
#include <iostream>
#include <set>
#include "set.hpp"

int main ()
{
  int myints[]={ 12,82,37,64,15 };
  CT::set<int> first (myints,myints+5);   // set with 5 ints
  CT::set<int> second;                    // empty set

  second = first;                          // now second contains the 5 ints
  first = CT::set<int>();                 // and first is empty

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}
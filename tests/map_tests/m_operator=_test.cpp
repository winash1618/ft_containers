// assignment operator with maps
#include <iostream>
#include <string>
#include <map>
#include "map.hpp"

int main ()
{
  CT::map<char,int> first;
  CT::map<char,int> second;

  first['x']=8;
  first['y']=16;
  first['z']=32;

  second=first;                // second now contains 3 ints
  first=CT::map<char,int>();  // and first is now empty

  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
  return 0;
}
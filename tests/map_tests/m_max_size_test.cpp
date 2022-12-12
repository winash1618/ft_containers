// map::max_size
#include <iostream>
#include <string>
#include <map>
#include "map.hpp"
int main ()
{
  int i;
  CT::map<int,int> mymap;

  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";
  std::cout << mymap.max_size() << std::endl;

  return 0;
}
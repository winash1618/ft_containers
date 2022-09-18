// map::size
#include <iostream>
#include <string>
#include <map>
#include "pair.hpp"
#include "map.hpp"

int main ()
{
  CT::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';

  return 0;
}
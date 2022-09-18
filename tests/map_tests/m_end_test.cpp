// map::begin/end
#include <iostream>
#include <string>
#include <map>
#include "pair.hpp"
#include "map.hpp"

int main ()
{
  CT::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (CT::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
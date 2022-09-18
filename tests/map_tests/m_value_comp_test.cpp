 // map::value_comp
#include <iostream>
#include <string>
#include <map>
#include "pair.hpp"
#include "map.hpp"

int main ()
{
  CT::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  CT::pair<char,int> highest = *mymap.rbegin();          // last element

  CT::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

  return 0;
}
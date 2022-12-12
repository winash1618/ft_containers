#include <iostream>
#include <map>
#include "map.hpp"
#include <iostream>
#include <string>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  CT::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  CT::map<char,int> second (first.begin(),first.end());

  CT::map<char,int> third (second);

  CT::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  CT::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
  CT::map<char,int>::iterator itlow,itup;
itlow=first.lower_bound ('b');  // itlow points to b
  itup=first.upper_bound ('d');   // itup points to e (not d!)
std::cout << itlow->first <<std::endl;
//   first.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (CT::map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}
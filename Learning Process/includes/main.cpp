#include "pair.hpp"
#include "map.hpp"
#include <iostream>
#include <string>
#include <map>
#include <iterator>





// int main ()
// {
//   std::map<int,int> mymap;

//   mymap[54] = 1005;
//   mymap[12] = 2003;
//   mymap[17] = 3002;
//   mymap[15] = 1001;
//   mymap[18] = 2006;
//   mymap[11] = 3002;
//   mymap[69] = 1006;
//   mymap[55] = 2003;
//   mymap[89] = 3001;
//   mymap[88] = 2003;
//   mymap[150] = 3001;

//   // show content:
//   for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }


// map::insert (C++98)
#include <iostream>
#include <map>

int main ()
{
  ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
//   mymap.insert ( std::pair<char,int>('z',200) );

//   std::pair<std::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( std::pair<char,int>('z',500) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already existed";
//     std::cout << " with a value of " << ret.first->second << '\n';
  }

//   // second insert function version (with hint position):
//   std::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

//   // third insert function version (range insertion):
//   std::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
//   std::cout << "mymap contains:\n";
//   ft::map<char, int>::iterator it=mymap.begin(); 
//   ft::map<char, int>::iterator it1=mymap.end(); 
//   for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    // std::cout << mymap->first << " => " << mymap->second << '\n';
    // std::cout << it1->first << " => " << it1->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }





// #include "pair.hpp"      // std::pair, std::make_pair
// #include <string>       // std::string
// #include <iostream>     // std::cout

// int main () {
//   ft::pair <std::string,int> planet;
//   ft::pair <std::string,int> homeplanet;
  

//   planet = ft::make_pair("Earth",6371);

//   homeplanet = planet;
// 	ft::pair <std::string,int> exoplanet(homeplanet);
//   std::cout << "Home planet: " << exoplanet.first << '\n';
//   std::cout << "Planet size: " << exoplanet.second << '\n';
//   return 0;
// }
// #include "pair.hpp"
// #include <utility>      // std::pair
// #include <iostream>     // std::cout

// int main ()
// {
//   ft::pair<int,char> foo (10,'z');
//   ft::pair<int,char> bar (90,'a');

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }
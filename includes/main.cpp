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
//   ft::map<char,int> mymap;
//   std::map<char,int> mymap1;

  // first insert function version (single parameter):
//   mymap.insert ( ft::pair<char,int>('a',100) );
//   mymap.insert ( ft::pair<char,int>('a',100) );

	// mymap.insert ( ft::pair<char,int>('z',203) );
	// mymap1.insert ( std::pair<char,int>('z',200) );
	// mymap.insert ( ft::pair<char,int>('k',200) );
	// mymap1.insert ( std::pair<char,int>('k',200) );
	// mymap.insert ( ft::pair<char,int>('r',200) );
	// mymap1.insert ( std::pair<char,int>('r',200) );
	// mymap.insert ( ft::pair<char,int>('l',200) );
	// mymap1.insert ( std::pair<char,int>('l',200) );
	// mymap.insert ( ft::pair<char,int>('e',200) );
	// mymap1.insert ( std::pair<char,int>('e',200) );
	// std::cout << "size : " << mymap.size() << std::endl;
	
	
	// ft::map<char, int> my = mymap;
	// std::cout << mymap['h'] << std::endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	// ft::pair<ft::map<char,int>::iterator,bool> ret;
	// std::pair<std::map<char,int>::iterator,bool> ret1;
	
	//  ret = mymap.insert (ft::pair<char,int>('e',500));
	// ret1 = mymap1.insert (std::pair<char,int>('e',500));

	// std::cout << "element 'z' already existed";
	// std::cout << " with a value of " << ret.first->first << " " << ret.first->second << '\n';

	// std::cout << "element 'z' already existed";
	// std::cout << " with a value of " << ret1.first->first << " " << ret1.first->second << '\n';

	// std::cout << "HELKO" << std::endl;
	// for(ft::map<char,int>::reverse_iterator it = my.rbegin(); it != my.rend(); it++)
	// {std::cout << it->first << "->" << it->second << std::endl;}
	// for (ft::map<char, int>::iterator it=my.begin(); it!=my.end(); ++it)
   	// 	 std::cout << it->first << " => " << it->second << '\n';
	// std::map<char,int>::iterator it = mymap1.begin();
	// it++;
	// mymap1.insert(it, mymap1.end());

	// for(ft::map<char,int>::reverse_iterator it1 = mymap.rend(); it1 != mymap.rbegin(); it1--)
	// {std::cout << it1->first << "->" << it1->second << std::endl;}
	// ft::map<char,int>::iterator it = mymap.end();
	// it-- ;

	// std::cout << it->first << "->" << it->second << std::endl;
	// std::cout<< "--------------------------------------------------------" << std::endl;

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
//   for (std::map<char, int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
    // std::cout << it1->first << " => " << it1->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  mymap['t']=44;
  mymap['*']=63;
  mymap['@']=82;
  mymap['-']=120;
  for(ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
{
	std::cout << it->first << "->" << it->second << std::endl;
}
  itlow=mymap.lower_bound ('a');  // itlow points to b
  itup=mymap.upper_bound ('t');   // itup points to e (not d!)

	std::cout << itlow->first << "<->" << itup->first << std::endl;
std::map<char,int> mymap1;
  std::map<char,int>::iterator itlow1,itup1;

  mymap1['a']=20;
  mymap1['b']=40;
  mymap1['c']=60;
  mymap1['d']=80;
  mymap1['e']=100;
  mymap1['t']=44;
  mymap1['*']=63;
  mymap1['@']=82;
  mymap1['-']=120;
 for(std::map<char, int>::iterator it = mymap1.begin(); it != mymap1.end(); it++)
{
	std::cout << it->first << "->" << it->second << std::endl;
}
  itlow1=mymap1.lower_bound ('a');  // itlow points to b
  itup1=mymap1.upper_bound ('t');   // itup points to e (not d!)

	std::cout << itlow1->first << "<->" << itup1->first << std::endl;
// ft::map<std::string,int> mymap;
//   ft::map<std::string,int>::iterator itlow,itup;

//   mymap["fa"]=20;
//   mymap["fb"]=40;
//   mymap["fd"]=60;
//   mymap["fs"]=80;
//   mymap["fw"]=100;
//   mymap["fq"]=44;
//   mymap["fe"]=63;
//   mymap["fq"]=82;
//   mymap["ft"]=120;
//   for(ft::map<std::string, int>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); it++)
// {
// 	std::cout << it->first << "->" << it->second << std::endl;
// }
//   itlow=mymap.lower_bound ("fs");  // itlow points to b
//   itup=mymap.upper_bound ("fq");   // itup points to e (not d!)

// 	std::cout << itlow->first << "<->" << itup->first << std::endl;
// std::map<std::string,int> mymap1;
//   std::map<std::string,int>::iterator itlow1,itup1;

//   mymap1["fa"]=20;
//   mymap1["fb"]=40;
//   mymap1["fd"]=60;
//   mymap1["fs"]=80;
//   mymap1["fw"]=100;
//   mymap1["fq"]=44;
//   mymap1["fe"]=63;
//   mymap1["fq"]=82;
//   mymap1["ft"]=120;
//  for(std::map<std::string, int>::reverse_iterator it = mymap1.rbegin(); it != mymap1.rend(); it++)
// 	{std::cout << it->first << "->" << it->second << std::endl;}
//   itlow1=mymap1.lower_bound ("fs");  // itlow points to b
//   itup1=mymap1.upper_bound ("fq");   // itup points to e (not d!)

// 	std::cout << itlow1->first << "<->" << itup1->first << std::endl;
  return 0;
}





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
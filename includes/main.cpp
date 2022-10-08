#include "pair.hpp"
#include "map.hpp"
#include "stack.hpp"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include "set.hpp"



struct ft_more {
	bool	operator()(const int &first, const int &second) const {
		return (first > second);
	}
};


int main ()
{
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
// #include <iostream>
// #include <map>

// int main ()
// {
//   ft::map<char,int> mymap;
//   std::map<char,int> mymap1;

//   first insert function version (single parameter):
//   mymap.insert ( ft::pair<char,int>('a',100) );
//   mymap.insert ( ft::pair<char,int>('a',100) );

// 	mymap.insert ( ft::pair<char,int>('z',203) );
// 	mymap1.insert ( std::pair<char,int>('z',200) );
// 	mymap.insert ( ft::pair<char,int>('k',200) );
// 	mymap1.insert ( std::pair<char,int>('k',200) );
// 	mymap.insert ( ft::pair<char,int>('r',200) );
// 	mymap1.insert ( std::pair<char,int>('r',200) );
// 	mymap.insert ( ft::pair<char,int>('l',200) );
// 	mymap1.insert ( std::pair<char,int>('l',200) );
// 	mymap.insert ( ft::pair<char,int>('e',200) );
// 	mymap1.insert ( std::pair<char,int>('e',200) );
// 	std::cout << "size : " << mymap.size() << std::endl;
	
	
// 	ft::map<char, int> my = mymap;
// 	std::cout << mymap['h'] << std::endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
// 	ft::pair<ft::map<char,int>::iterator,bool> ret;
// 	std::pair<std::map<char,int>::iterator,bool> ret1;
	
// 	 ret = mymap.insert (ft::pair<char,int>('e',500));
// 	ret1 = mymap1.insert (std::pair<char,int>('e',500));

// 	std::cout << "element 'z' already existed";
// 	std::cout << " with a value of " << ret.first->first << " " << ret.first->second << '\n';

// 	std::cout << "element 'z' already existed";
// 	std::cout << " with a value of " << ret1.first->first << " " << ret1.first->second << '\n';

// 	std::cout << "HELKO" << std::endl;
// 	for(ft::map<char,int>::reverse_iterator it = my.rbegin(); it != my.rend(); it++)
// 	{std::cout << it->first << "->" << it->second << std::endl;}
// 	for (ft::map<char, int>::iterator it=my.begin(); it!=my.end(); ++it)
//    		 std::cout << it->first << " => " << it->second << '\n';
// 	std::map<char,int>::iterator it = mymap1.begin();
// 	it++;
// 	mymap1.insert(it, mymap1.end());

// 	for(ft::map<char,int>::reverse_iterator it1 = mymap.rend(); it1 != mymap.rbegin(); it1--)
// 	{std::cout << it1->first << "->" << it1->second << std::endl;}
// 	ft::map<char,int>::iterator it = mymap.end();
// 	it-- ;

// 	std::cout << it->first << "->" << it->second << std::endl;
// 	std::cout<< "--------------------------------------------------------" << std::endl;

//   // second insert function version (with hint position):
//   std::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

//   // third insert function version (range insertion):
//   std::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

//   showing contents:
//   std::cout << "mymap contains:\n";
//   ft::map<char, int>::iterator it=mymap.begin(); 
//   ft::map<char, int>::iterator it1=mymap.end(); 
//   for (std::map<char, int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
//     std::cout << it1->first << " => " << it1->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
// ft::map<char,int> mymap;
//   ft::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   mymap['b']=40;
//   mymap['c']=60;
//   mymap['d']=80;
//   mymap['e']=100;
//   mymap['t']=44;
//   for(ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
// {
// 	std::cout << it->first << "->" << it->second << std::endl;
// }
//   itlow=mymap.lower_bound ('d');  // itlow points to b
//   itup=mymap.upper_bound ('c');   // itup points to e (not d!)

// 	std::cout << itlow->first << "<->" << itup->first << std::endl;
// std::map<char,int> mymap1;
//   std::map<char,int>::iterator itlow1,itup1;

//   mymap1['a']=20;
//   mymap1['b']=40;
//   mymap1['c']=60;
//   mymap1['d']=80;
//   mymap1['e']=100;
//   mymap1['t']=44;
//  for(std::map<char, int>::iterator it = mymap1.begin(); it != mymap1.end(); it++)
// {
// 	std::cout << it->first << "->" << it->second << std::endl;
// }
//   itlow1=mymap1.lower_bound ('d');  // itlow points to b
//   itup1=mymap1.upper_bound ('c');   // itup points to e (not d!)

// 	std::cout << itlow1->first << "<->" << itup1->first << std::endl;
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

// erase test
// 	ft::map<std::string,int> mymap;
// 	mymap["fa"]=0;
// 	mymap["fb"]=0;
// 	mymap["fd"]=0;

// 	mymap.at("fa") = 10;
// 	mymap.at("fb") = 20;
// 	mymap.at("fd") = 30;

// 	for(ft::map<std::string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
// 	{
// 		std::cout << it->first << "->" << it->second << std::endl;
// 	}
// 	std::map<std::string,int> mymap1;
// 	mymap1["fa"]=0;
// 	mymap1["fb"]=0;
// 	mymap1["fd"]=0;

// 	mymap1.at("f") = 10;
// 	mymap1.at("fb") = 20;
// 	mymap1.at("fd") = 30;

// 	for(std::map<std::string, int>::iterator it = mymap1.begin(); it != mymap1.end(); it++)
// 	{
// 		std::cout << it->first << "->" << it->second << std::endl;
// 	}

// {
// 	ft::map<char,int> mymap;
// 	ft::map<char,int>::iterator it;

// 	// insert some values:
// 	mymap['a']=10;
// 	mymap['b']=20;
// 	mymap['c']=30;
// 	mymap['d']=40;
// 	mymap['e']=50;
// 	mymap['f']=60;
// 	mymap['g']=10;
// 	mymap['h']=20;
// 	mymap['i']=30;
// 	mymap['j']=40;
// 	mymap['k']=50;
// 	mymap['l']=60;

// 	it=mymap.find('d');
// 	mymap.erase (it, mymap.end()); 
// 	for (it=mymap.begin(); it!=mymap.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';
// }
// std::cout << "-----------------------------------------" << std::endl;
// std::map<char,int> mymap;
//   std::map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;
//   mymap['g']=10;
//   mymap['h']=20;
//   mymap['i']=30;
//   mymap['j']=40;
//   mymap['k']=50;
//   mymap['l']=60;

//   it=mymap.find('d');
//   mymap.erase (it, mymap.end()); 
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

// {
// std::map<char,int> mymap;
//   std::map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');                  // erasing by key

//   it=mymap.find ('e');
//   mymap.erase ( it, mymap.end() );    // erasing by range

//   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
// }
// std::cout << "=================================================" << std::endl;
// {
// ft::map<char,int> mymap;
//   ft::map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

//   mymap.erase ('c');                  // erasing by key

//   it=mymap.find ('e');
//   mymap.erase ( it, mymap.end() );    // erasing by range

//   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
// }
{
ft::map<int, std::string> mp;
//   ft::map<int, int>::iterator it;

//   // insert some values:
//   mymap[40]=10;
//   mymap[55]=20;
//   mymap[65]=30;
//   mymap[60]=40;
//   mymap[57]=50;
//   mymap[75]=60;

//   it=mymap.find(40);
//   mymap.erase (it);                   // erasing by iterator

// //   mymap.erase ('c');                  // erasing by key

// //   it=mymap.find ('e');
// //   mymap.erase ( it, mymap.end() );    // erasing by range

//   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

// ft_mp mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	// std::cout << "hi" << std::endl;
	mp[12] = "no";
	// std::cout << mp[12] << std::endl;
	mp[27] = "bee";
	mp[90] = "8";
}

// {
// 	std::map<char,int> foo,bar;
// 	foo['a']=100;
// 	foo['b']=200;
// 	bar['a']=10;
// 	bar['z']=1000;

// 	if (foo==bar) std::cout << "foo and bar are equal\n";
// 	if (foo!=bar) std::cout << "foo and bar are not equal\n";
// 	if (foo< bar) std::cout << "foo is less than bar\n";
// 	if (foo> bar) std::cout << "foo is greater than bar\n";
// 	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// 	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// }
// std::cout << "=================================================" << std::endl;
// {
// 	ft::map<char,int> foo,bar;
// 	foo['a']=100;
// 	foo['b']=200;
// 	bar['a']=10;
// 	bar['z']=1000;

// 	if (foo==bar) std::cout << "foo and bar are equal\n";
// 	if (foo!=bar) std::cout << "foo and bar are not equal\n";
// 	if (foo< bar) std::cout << "foo is less than bar\n";
// 	if (foo> bar) std::cout << "foo is greater than bar\n";
// 	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// 	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// }
// {
// 	std::map<char,int> mymap;

// 	mymap['a']=10;
// 	mymap['b']=20;
// 	mymap['c']=30;

// 	while (!mymap.empty())
// 	{
// 		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
// 		mymap.erase(mymap.begin());
// 	}

// }

// std::cout << "=================================================" << std::endl;
// {
// 	ft::map<char,int> mymap;

// 	mymap['a']=10;
// 	mymap['b']=20;
// 	mymap['c']=30;

// 	while (!mymap.empty())
// 	{
// 		std::cout << "BI" << std::endl;
// 		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
// 		mymap.erase(mymap.begin());
// 	}
// }

  return 0;
}

// {
//   int myints[] = {75,23,65,42,13};
//   ft::set<int> myset (myints,myints+5);

//   std::cout << "myset contains:";
//   for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

// //   return 0;
// }
// std::cout << "=================================================" << std::endl;

// {
//   int myints[] = {75,23,65,42,13};
//   std::set<int> myset (myints,myints+5);

//   std::cout << "myset contains:";
//   for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
//     std::cout << ' ' << *it;

//   std::cout << '\n';

// //   return 0;
// }

// {
// 	 std::set<int> myset;
// 	std::set<int>::iterator it;

// 	// insert some values:
// 	for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

// 	it = myset.begin();
// 	++it;                                         // "it" points now to 20

// 	myset.erase (it);

// 	myset.erase (40);

// 	it = myset.find (60);
// 	myset.erase (it, myset.end());

// 	std::cout << "myset contains:";
// 	for (it=myset.begin(); it!=myset.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// }
// std::cout << "=================================================" << std::endl;
// {
// 	 ft::set<int> myset;
// 	ft::set<int>::iterator it;

// 	// insert some values:
// 	for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

// 	it = myset.begin();
// 	++it;                                         // "it" points now to 20

// 	myset.erase (it);

// 	myset.erase (40);

// 	it = myset.find (60);
// 	myset.erase (it, myset.end());

// 	std::cout << "myset contains:";
// 	for (it=myset.begin(); it!=myset.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
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
// 	ft::stack<int> mystack;
// 		for (int i=0; i<5; ++i) mystack.push(i);
// 	std::cout << mystack.top() << std::endl;
//   return 0;
// }

// #include "stack.hpp"
// #include <iostream>

// int main()
// {
// 	ft::stack<int> mystack;
// 		for (int i=0; i<5; ++i) mystack.push(i);
// 	std::cout << mystack.top() << std::endl;
// 	return (0);
// }

// #include <iostream>
// #include <string>
// #include <deque>
// // #if 1 //CREATE A REAL STL EXAMPLE
// // 	#include <map>
// // 	#include <stack>
// // 	#include <vector>
// // 	namespace ft = std;
// // #else
// #include "map.hpp"
// #include "stack.hpp"
// #include "vector.hpp"
// // #endif
// #include <unistd.h>
// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };

// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	// ft::stack<int> mystack;
// 	// 	for (int i=0; i<5; ++i) mystack.push(i);
// 	// std::cout << mystack.top() << std::endl;
// 	sleep(1);
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}
// 	// std::cout << map_int.size() << std::endl;
// 	// for(ft::map<int, int>::iterator it = map_int.begin(); it != map_int.end(); it++)
// 	// {
// 	// 	std::cout << it->first << "->" << it->second << std::endl;
// 	// }
// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;
// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
	
// 	MutantStack<char> iterable_stack;
// 	// std::cout << "hi" << std::endl;
// 	// iterable_stack.push('a');
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 	{
// 		iterable_stack.push(letter);
// 	}
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }
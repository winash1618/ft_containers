// erasing from set
#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  CT::set<int> myset;
  CT::set<int>::iterator it;
//   CT::set<int>::iterator ite;

  // insert some values:
  for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

  it = myset.begin();
  ++it;                                         // "it" points now to 20

  myset.erase (it);

  myset.erase (40);

  it = myset.find (60);
//   try
//   {
// 	std::cout << "myset contains:";
// 	std::cout << ' ' << *it;
// 	std::cout << '\n';
//   }
//   catch(const std::exception& e)
//   {
// 	std::cerr << e.what() << '\n';
//   }
//   ite = myset.end();
//   std::cout << "myset contains:";
// std::cout << ' ' << *it << ' ' << *ite << '\n';
// 	ite = it;
// 	myset.erase (it);
// 	std::cout << *ite++ << std::endl;
// 	it = ite;
// 	ite++;
// 	std::cout << *it << std::endl;
// 	myset.erase (it);
// 	it = ite;
// 	ite++;
// 	std::cout << *it << std::endl;
// 	myset.erase (it);
// 	it = ite;
// 	ite++;
// 	std::cout << *it << std::endl;
// 	myset.erase (it);
// 	it = ite;
// 	ite++;
	// std::cout << *it << std::endl;
	// myset.erase (it);
	// it++;
	// myset.erase (it);
	// it++;
	// myset.erase (it);
	// for (; it!=myset.end(); ++it)
    // std::cout << ' ' << *it;
  myset.erase (it, myset.end());

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
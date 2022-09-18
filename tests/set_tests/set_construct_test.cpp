// constructing sets
#include <iostream>
#include <set>
#include "set.hpp"
#include <string>


bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main ()
{
	CT::set<int> first;                           // empty set of ints
	CT::set<int>::iterator it;
	int myints[]= {10,20,30,40,50};
	CT::set<int> second (myints,myints+5);        // range
	for (it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	CT::set<int> third (second);                  // a copy of second

	// std::cout << "========== " << std::endl;
	CT::set<int> fourth (second.begin(), second.end());  // iterator ctor.
	for (it=fourth.begin(); it!=fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	CT::set<int,classcomp> fifth;                 // class as Compare

	bool(*fn_pt)(int,int) = fncomp;
	CT::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare

	return 0;
}
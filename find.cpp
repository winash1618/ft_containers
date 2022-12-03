#include "./includes/map.hpp"

int main()
{
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	std::cout << mymap.find('a')->second;
}
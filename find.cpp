#include <map>
#include "includes/map.hpp"

int main() {
	NS::map<int, int> m;
	NS::map<int, int>::iterator it = m.end();

	m.insert(NS::make_pair(3,3));
	m.insert(NS::make_pair(1,1));
	m.insert(NS::make_pair(2,2));

	std::cout << std::boolalpha << (m.find(12345678) == m.end()) << std::endl;
	std::cout << std::boolalpha << (m.find(12345678) == it) << std::endl;
}
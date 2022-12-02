#include "includes/map.hpp"

int main() {
	ft::map<int, int> m;

	m.insert(ft::pair<int,int>(1, 10));
	m.insert(ft::pair<int,int>(2, 20));
	m.insert(ft::pair<int,int>(3, 30));

	// std::cout << m.find(123)->first << std::endl;
	std::cout << m.find(1123) << std::endl;
	// m.end() == m.find(doesnt exist);
	return 0;
}
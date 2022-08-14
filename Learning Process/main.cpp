#include "vector.hpp"
#include "iterator.hpp"
#include <iterator>
#include <vector>
using namespace std;
// int main()
// {
// 	// ft::vector<int> a(5, 4);
// 	vector<int> v1;
// 	 v1.assign (7,100);
// 	 v1.push_back(200);  
//     // Declaring an iterator
//     vector<int>::iterator i1;
// 	ft::vector<int> a(v1.begin(), v1.end());
// 	ft::vector<int> b(a);
// 	std::cout << "try to run operator[] : " << b[7] << std::endl;
// 	b.pop_back();
// 	std::cout << "size = " << b.size() << std::endl;
// 	// std::cout << b.size();
// 	// a.say();
// 	// container::vector<int> a();

// }

// int main() for iterator
int main()
{
		// ft::vector<int> a(5, 4);
		vector<int> v1;
		 v1.assign (7,100);
		 v1.push_back(200);  
	    // Declaring an iterator
	    vector<int>::iterator i1;
		ft::vector<int> a(v1.begin(), v1.end());
		ft::vector<int> b(a);
		std::cout << "try to run operator[] : " << b[7] << std::endl;
		b.pop_back();
		std::cout << "size = " << b.size() << std::endl;
		// std::cout << b.size();
		// a.say();
		// container::vector<int> a();
		ft::vector<int>::iterator a1;
		a1 = a.begin();
		std::cout << a1[7];
}
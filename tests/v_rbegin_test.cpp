#include "vector.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
//   CT::vector<int> myvector (5);  // 5 default-constructed ints

//   int i=0;

//   CT::vector<int>::reverse_iterator rit = myvector.rbegin();
//   for (; rit!= myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (CT::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
// 	std::cout << "size: " << (int) myvector.size() << '\n';
//   std::cout << "capacity: " << (int) myvector.capacity() << '\n';

// CT::vector<std::string> myvector2;
// myvector2.push_back("42");
// myvector2.push_back("Abu");
// myvector2.push_back("Dhabi");
// myvector2.push_back("Hello");
// myvector2.push_back("World");
// myvector2.push_back("!");

// // for (CT::vector<std::string>::reverse_iterator ib = myvector2.rend() - 1 ; ib != myvector2.rbegin(); ib--) {
// 	CT::vector<std::string>::reverse_iterator ib = myvector2.rend() ;
//     std::cout << ' ' << *--ib;
//     std::cout << ' ' << *--ib;
//     std::cout << ' ' << *--ib;
//     std::cout << ' ' << *--ib;
//     std::cout << ' ' << *--ib;
//     std::cout << ' ' << *--ib;
// 	CT::vector<std::string>::reverse_iterator ib1 = myvector2.rbegin() - 1 ;
//     std::cout << ' ' << *++ib1;
//     std::cout << ' ' << *++ib1;
//     std::cout << ' ' << *++ib1;
//     std::cout << ' ' << *++ib1;
//     std::cout << ' ' << *++ib1;
//     std::cout << ' ' << *++ib1;
//     // std::cout << ' ' << *--ib;
// // }
//   std::cout << '\n';
// 	std::cout << "size: " << myvector2.size() << '\n';
//   std::cout << "capacity: " << myvector2.capacity() << '\n';
	// CT::vector<std::string> vec2;
	// 	vec2.push_back("Hello");
	// 	vec2.push_back("World");
	// 	vec2.push_back("!");
	// 	vec2.push_back("Hello");
	// 	vec2.push_back("World");
	// 	vec2.push_back("!");
	// 	CT::vector<std::string>::reverse_iterator ib3 = vec2.rend() - 1;
	// 	std::cout << "hi " << *(ib3 - 5) << std::endl;
	// 	std::cout << "hi " << *(vec2.rbegin()) << std::endl;
	// 	std::cout << ((vec2.rend()-6) == (vec2.rbegin())) <<std::endl;
	// 	// for (CT::vector<std::string>::iterator ib4 = vec2.begin(); ib4 != vec2.end(); ib4++) {
			
	// 	// 	std::cout << *ib4 << " ";
	// 	// 	// if (ib4 == vec2.end())
	// 	// 	// 	break ;
	// 	// 	// ib3 = vec2.rbegin();
	// 	// }
	// 	for (CT::vector<std::string>::reverse_iterator ib3 = vec2.rend(); ib3 != vec2.rbegin() - 3; ib3--) {
			
	// 		std::cout << *ib3 << " ";
	// 		// ib3 = vec2.rbegin();
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << vec2.size() << std::endl;
	// 	std::cout << vec2.capacity() << std::endl;
	CT::vector<int> vec3;
		vec3.push_back(1);
		vec3.push_back(3);
		vec3.push_back(5);
		vec3.push_back(7);
		vec3.push_back(9);
		vec3.push_back(11);
		// CT::vector<int>::reverse_iterator ib5 = vec3.rend() - 1;
		// std::cout << "hi " << *(ib5 - 5) << std::endl;
		// std::cout << "hi " << *(vec3.rbegin()) << std::endl;
		// std::cout << ((vec3.rend()-6) == (vec3.rbegin())) <<std::endl;
		// for (CT::vector<std::string>::iterator ib4 = vec2.begin(); ib4 != vec2.end(); ib4++) {
			
		// 	std::cout << *ib4 << " ";
		// 	// if (ib4 == vec2.end())
		// 	// 	break ;
		// 	// ib3 = vec2.rbegin();
		// }
		int iff = 0;
		for (CT::vector<int>::reverse_iterator ib5 = vec3.rend(); ib5 != vec3.rbegin() - 1; ib5--) {
			
			std::cout << *ib5 << " ";
			iff++;
			if (iff > 18)
				break;
			// ib3 = vec2.rbegin();
		}
		std::cout << std::endl;
		std::cout << vec3.size() << std::endl;
		std::cout << vec3.capacity() << std::endl;
  return 0;
}
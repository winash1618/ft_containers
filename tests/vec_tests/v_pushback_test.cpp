#include "vector.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
  CT::vector<int> myvector;
//   int myint;

//   std::cout << "Please enter some integers (enter 0 to end):\n";

//   do {
//     std::cin >> myint;
//     myvector.push_back (myint);
//   } while (myint);
	myvector.push_back(2);  
	myvector.push_back(20);  
	myvector.push_back(10);  
	myvector.push_back(201);  
	myvector.push_back(203);  
	myvector.push_back(204);  
	myvector.push_back(202);  
	myvector.push_back(208);  
	myvector.push_back(209);  
	myvector.push_back(206);  
	myvector.push_back(207);  
	myvector.push_back(10);  
	myvector.push_back(201);  
	myvector.push_back(203);  
	myvector.push_back(204);  
	myvector.push_back(202);  
	myvector.push_back(208);  
	myvector.push_back(209);  
	myvector.push_back(206);  
	myvector.push_back(207);  

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	return 0;
}
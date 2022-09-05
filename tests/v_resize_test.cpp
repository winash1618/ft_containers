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

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  	std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';



	{
		CT::vector<std::string> vec;

		vec.resize(7, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque euismod auctor odio, sed fermentum libero varius quis. Curabitur sed faucibus tortor.");
		for (size_t i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << std::endl;
		}
	}


  return 0;
}
#include "vector.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
  // constructors used in the same order as described above:
  CT::vector<int> first;                                // empty vector of ints
  CT::vector<int> second (4,100);                       // four ints with value 100
  CT::vector<int> third (second.begin(),second.end());  // iterating through second
  CT::vector<int> fourth (second);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   CT::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
  for (CT::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
	  std::cout << "size of first: " << (int) first.size() << '\n';
  std::cout << "capacity of first: " << (int) first.capacity() << '\n';
	  std::cout << "size of second: " << (int) second.size() << '\n';
  std::cout << "capacity of second: " << (int) second.capacity() << '\n';
	  std::cout << "size of fourth: " << (int) fourth.size() << '\n';
  std::cout << "capacity of fourth: " << (int) fourth.capacity() << '\n';
  return 0;
}
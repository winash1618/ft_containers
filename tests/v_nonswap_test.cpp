#include "vector.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
  CT::vector<int> foo (3,100);   // three ints with a value of 100
  CT::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (CT::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (CT::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
std::cout << "size of foo: " << (int) foo.size() << '\n';
  std::cout << "capacity of foo: " << (int) foo.capacity() << '\n';
std::cout << "size of bar: " << (int) bar.size() << '\n';
  std::cout << "capacity of bar: " << (int) bar.capacity() << '\n';
  return 0;
}
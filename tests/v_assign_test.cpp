#include "vector.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
  CT::vector<int> first;
  CT::vector<int> second;
  CT::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  CT::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';

  std::cout << "Capacity of first: " << int (first.capacity()) << '\n';
  std::cout << "Capacity of second: " << int (second.capacity()) << '\n';
  std::cout << "Capacity of third: " << int (third.capacity()) << '\n';

  return 0;
}
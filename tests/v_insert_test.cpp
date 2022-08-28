#include "vector.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
  CT::vector<int> myvector (3,100);
  CT::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,13,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
    std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';

  return 0;
}
// stack::top
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "vector.hpp"
#include "stack.hpp"

int main ()
{
  std::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}
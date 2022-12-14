/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_reserve_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:54:24 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:54:25 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
  CT::vector<int>::size_type sz;

  CT::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
      sz = foo.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  CT::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }
  std::cout << "size of foo: " << (int) foo.size() << '\n';
  std::cout << "capacity of foo: " << (int) foo.capacity() << '\n';
std::cout << "size of bar: " << (int) bar.size() << '\n';
  std::cout << "capacity of bar: " << (int) bar.capacity() << '\n';
  return 0;
}
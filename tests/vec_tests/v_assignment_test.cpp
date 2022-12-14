/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_assignment_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:50:50 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:51:39 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
  CT::vector<int> foo (3,0);
  CT::vector<int> bar (5,0);

  bar = foo;
  foo = CT::vector<int>();

  std::cout << "size of foo: " << (int) foo.size() << '\n';
  std::cout << "capacity of foo: " << (int) foo.capacity() << '\n';
std::cout << "size of bar: " << (int) bar.size() << '\n';
  std::cout << "capacity of bar: " << (int) bar.capacity() << '\n';
  return 0;
}
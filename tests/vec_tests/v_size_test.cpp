/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_size_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:55:42 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:55:43 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>


int main ()
{
  CT::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';
 std::cout << "capacity: " << (int) myints.capacity() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';
 std::cout << "capacity: " << (int) myints.capacity() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';
 std::cout << "capacity: " << (int) myints.capacity() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
 std::cout << "capacity: " << (int) myints.capacity() << '\n';
  return 0;
}
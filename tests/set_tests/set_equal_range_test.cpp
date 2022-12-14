/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_equal_range_test.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:48:14 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:48:15 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  CT::set<int> myset;

  for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

  CT::pair<CT::set<int>::const_iterator,CT::set<int>::const_iterator> ret;
  ret = myset.equal_range(30);

  std::cout << "the lower bound points to: " << *ret.first << '\n';
  std::cout << "the upper bound points to: " << *ret.second << '\n';

  return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_empty_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:48:01 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:48:02 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  CT::set<int> myset;

  myset.insert(20);
  myset.insert(30);
  myset.insert(10);

  std::cout << "myset contains:";
  while (!myset.empty())
  {
     std::cout << ' ' << *myset.begin();
     myset.erase(myset.begin());
  }
  std::cout << '\n';

  return 0;
}
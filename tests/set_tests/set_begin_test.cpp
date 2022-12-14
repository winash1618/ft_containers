/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_begin_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:47:39 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:47:40 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  int myints[] = {75,23,65,42,13};
  CT::set<int> myset (myints,myints+5);

  std::cout << "myset contains:";
  for (CT::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
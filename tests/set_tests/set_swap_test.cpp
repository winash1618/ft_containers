/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_swap_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:49:43 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:49:47 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  int myints[]={12,75,10,32,20,25};
  CT::set<int> first (myints,myints+3);     // 10,12,75
  CT::set<int> second (myints+3,myints+6);  // 20,25,32

  first.swap(second);

  std::cout << "first contains:";
  for (CT::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (CT::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rend_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:49:29 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:49:30 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  int myints[] = {21,64,17,78,49};
  CT::set<int> myset (myints,myints+5);

  CT::set<int>::reverse_iterator rit;

  std::cout << "myset contains:";
  for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
    std::cout << ' ' << *rit;

  std::cout << '\n';

  return 0;
}
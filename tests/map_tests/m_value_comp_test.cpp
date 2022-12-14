/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_value_comp_test.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:47:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:47:34 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include "utils/pair.hpp"
#include "map.hpp"

int main ()
{
  CT::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  CT::pair<char,int> highest = *mymap.rbegin();          // last element

  CT::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

  return 0;
}
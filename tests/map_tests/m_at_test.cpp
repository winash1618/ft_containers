/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_at_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:43:25 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:43:26 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// map::at
#include <iostream>
#include <string>
#include <map>
#include "map.hpp"

int main ()
{
	CT::map<std::string,int> mymap;
	mymap["alpha"]=0;
	mymap["beta"]=0;
	mymap["gamma"]=0;

  mymap.at("alpha") = 10;
  mymap.at("beta") = 20;
  mymap.at("gamma") = 30;

	for(CT::map<std::string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
			std::cout << it->first << "->" << it->second << std::endl;
	}
  return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_insert_test copy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:45:13 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 10:29:41 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include "map.hpp"

int main ()
{
	CT::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( CT::pair<char,int>('a',100) );
	mymap.insert ( CT::pair<char,int>('z',200) );

	CT::pair<CT::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( CT::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	CT::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, CT::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, CT::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	CT::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_erase_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:48:22 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 10:34:37 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
	CT::set<int> myset;
	CT::set<int>::iterator it;
	for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

	it = myset.begin();
	
	++it;                                         // "it" points now to 20

	myset.erase (it);

	myset.erase (40);

	it = myset.find (60);
	
	myset.erase (it, myset.end());

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
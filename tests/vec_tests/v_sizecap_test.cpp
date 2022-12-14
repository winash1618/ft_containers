/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_sizecap_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:55:47 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:55:48 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>

int main ()
{
	{
		CT::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
	{ 
		CT::vector<double> myvector;

		// set some content in the vector:
		myvector.push_back(10.2);
		myvector.push_back(53.2);
		myvector.push_back(85.6);
		std::cout << "myvector contains:";
		for (size_t i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
  return 0;
}

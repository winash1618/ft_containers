/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_resize_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:54:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/15 18:13:39 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <utility>
#include <climits>

int main ()
{
	
	CT::vector<int>  myvector(5, 42);


  for (int i=1;i<10;i++) myvector.push_back(i);
  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);
  myvector.resize(SCHAR_MAX);
  myvector.resize(SHRT_MAX);
  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  	std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';



	{
		CT::vector<std::string> vec;

		vec.resize(7, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque euismod auctor odio, sed fermentum libero varius quis. Curabitur sed faucibus tortor.");
		for (size_t i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << std::endl;
		}
		vec.resize(12, "Proin tellus sem, facilisis vel faucibus nec, convallis in ex");
		for (size_t i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << std::endl;
		}
	}

	std::cout << "size = " << myvector.size() << std::endl;
	

  return 0;
}
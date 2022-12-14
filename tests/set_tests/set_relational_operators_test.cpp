/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_relational_operators_test.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:49:23 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:49:24 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include "set.hpp"
#include <string>

int main ()
{
  CT::set<int> foo,bar;
  foo.insert(10);
  bar.insert(20);
  bar.insert(30);
  foo.insert(40);

  // foo ({10,40}) vs bar ({20,30}):
  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  return 0;
}
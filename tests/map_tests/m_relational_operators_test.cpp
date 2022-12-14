/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_relational_operators_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:46:57 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:47:03 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <map>
#include "map.hpp"
int main ()
{
  CT::map<char,int> foo,bar;
  foo['a']=100;
  foo['b']=200;
  bar['a']=10;
  bar['z']=1000;

  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  return 0;
}
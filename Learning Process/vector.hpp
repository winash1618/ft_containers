/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/06 19:47:42 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>
#include <string>
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			explicit vector (const allocator_type& alloc = allocator_type());	// empty container constructor
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()); // fill constructor
			template <class InputIterator> vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()); // range constructor
			ector (const vector& x);
	} ;
#include "vector.cpp" // include separate implementation file inside namespace
}
#endif
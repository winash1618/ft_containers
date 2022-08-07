/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/07 14:38:55 by mkaruvan         ###   ########.fr       */
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
			void say(void)
			{
				std::cout << "hello world" << std::endl;
			}
			// /*--------------------------------------------------------------------*/
			// /*-------------------------member type--------------------------------*/
			// /*--------------------------------------------------------------------*/
			// typedef T											value_type;
			// typedef Allocator									allocator_type;
			// typedef typename allocator_type::reference			reference;
			// typedef typename allocator_type::const_reference	const_reference;
			// // typedef implementation-defined						iterator;
			// // typedef implementation-defined						const_iterator;
			// typedef typename allocator_type::size_type			size_type;
			// typedef typename allocator_type::difference_type	difference_type;
			// typedef typename allocator_type::pointer			pointer;
			// typedef typename allocator_type::const_pointer		const_pointer;
			// typedef std::reverse_iterator<iterator>				reverse_iterator;
    		// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
			// /*--------------------------------------------------------------------*/
			// /*-------------------------member functions---------------------------*/
			// /*--------------------------------------------------------------------*/
			// // Constructor
			// explicit vector (const allocator_type& alloc = allocator_type());	// empty container constructor
			// explicit vector (size_type n, const value_type& val = value_type(),
			// 	const allocator_type& alloc = allocator_type()); // fill constructor
			// template <class InputIterator> 
			// vector (InputIterator first, InputIterator last,
			// 	const allocator_type& alloc = allocator_type()); // range constructor
			// vector (const vector& x);
			// // Destructor
			// ~vector ();
			// // Iterators
			// iterator               begin() noexcept;
			// const_iterator         begin()   const noexcept;
			// iterator               end() noexcept;
			// const_iterator         end()     const noexcept;
			
			// reverse_iterator       rbegin() noexcept;
			// const_reverse_iterator rbegin()  const noexcept;
			// reverse_iterator       rend() noexcept;
			// const_reverse_iterator rend()    const noexcept;
			
			// // Capacity
			// size_type size() const noexcept;
			// size_type max_size() const noexcept;
			// size_type capacity() const noexcept;
			// bool empty() const noexcept;
			// void reserve(size_type n);

			// // Modifiers
			// reference       operator[](size_type n);
			// const_reference operator[](size_type n) const;
			// reference       at(size_type n);
			// const_reference at(size_type n) const;

			// reference       front();
			// const_reference front() const;
			// reference       back();
			// const_reference back() const;

			
	} ;
#include "vector.cpp" // include separate implementation file inside namespace
}
#endif
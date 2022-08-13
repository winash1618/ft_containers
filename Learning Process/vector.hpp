/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/13 09:04:35 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
# include <exception>
# include <stdexcept>
# include <algorithm>
# include <cassert>
# include <initializer_list>
# include <iterator>
# include <limits>
# include <memory>
# include <type_traits>
# include <utility>

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
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			// typedef ft::iterator										iterator;
			// typedef ft::iterator										const_iterator;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			// /*--------------------------------------------------------------------*/
			// /*-------------------------member functions---------------------------*/
			// /*--------------------------------------------------------------------*/
			// // Constructor
			
			// explicit vector (const allocator_type& alloc = allocator_type())  : _alloc(alloc), _vec(nullptr) // empty container constructor
			// {
			// 	// say();
			// }
			
			explicit vector (size_type len, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			 : _alloc(alloc) // fill constructor
			{
				say();
				allocate_and_copy_construct(len, len, val);
				for (std::size_t index = 0; index < _size; ++index)
				{
					std::cout << this->_vec[index];
				}
				// std::cout << typeid(allocator_type).name();
			}
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last,
			// 		const allocator_type& alloc = allocator_type()) // range constructor
			// {
			// 	say();
			// }
			// vector (const vector& x)
			// {
				
			// }
			
			// Destructor
			~vector (){}
			// Iterators
			// iterator	begin() noexcept
			// {
			// 	return (*_vec);
			// }
			// const_iterator         begin()   const noexcept
			// {
			// 	return (*_vec);
			// }
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
			
		private:
			T* _vec; // 
			std::size_t _cap;// Capacity 
			std::size_t _size;
			Allocator _alloc; // std::allocator
			void allocate(std::size_t capacity)
			{
				_cap = capacity;
				_vec = _alloc.allocate(capacity, 0);
			}

			void deallocate(std::size_t capacity)
			{
				_alloc.deallocate(_vec, capacity);
				_cap = 0;
				_size = 0;
			}

			void reallocate(std::size_t old_cap, std::size_t new_cap) {
				deallocate(old_cap);
				allocate(new_cap);
			}

			void construct(std::size_t size, const value_type& value)
			{
				_size = size;
				for (std::size_t index = 0; index < size; ++index)
					_alloc.construct(_vec, value);
			}

			void destruct(std::size_t size)
			{
				for (std::size_t index = 0; index < size; ++index)
					_alloc.destroy(_vec + index);
				_size = 0;
			}
			void allocate_and_copy_construct(std::size_t capacity, std::size_t size, const value_type& value = value_type())
			{
				allocate(capacity);
				construct(size, value);
			}
			void deallocate_and_destruct(std::size_t capacity, std::size_t size)
			{
				destruct(size);
				deallocate(capacity);
			}
	} ;
// #include "vector.cpp" // include separate implementation file inside namespace
}
#endif

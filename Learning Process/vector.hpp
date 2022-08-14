/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/14 14:53:12 by mkaruvan         ###   ########.fr       */
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

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
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
			typedef ft::My_iterator<value_type>							iterator;
			typedef ft::My_iterator<value_type>							const_iterator;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			// /*--------------------------------------------------------------------*/
			// /*-------------------------member functions---------------------------*/
			// /*--------------------------------------------------------------------*/
			// // Constructor
			
			explicit vector (const allocator_type& alloc = allocator_type())  : _alloc(alloc), _vec(nullptr), _size(0), _cap(0) // empty container constructor
			{
				// say();
			}
			
			explicit vector (size_type len, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			 : _alloc(alloc) // fill constructor
			{
				say();
				allocate_and_copy_construct(len, len, val);
				for (std::size_t index = 0; index < _size; ++index)
				{
					std::cout << this->_vec[index] << std::endl;
				}
				// std::cout << typeid(allocator_type).name();
			}
			
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()) : _size(0), _cap(0)// range constructor
			{
				say();
				std::size_t size = std::distance(first, last);
				std::cout << size << std::endl;
				allocate(size);
				for (size_type index = 0; index < size; ++index)
				{
					_alloc.construct(_vec + index, *(first + index));
					std::cout << this->_vec[index] << std::endl;
					++_size;
				}
				std::cout << _size << std::endl;
			}
			
			vector (const vector& x) : _size(0)  // Copy constructor
			{
				std::cout << "I am in copy constructor" << std::endl;
				// *this = x;
				_alloc = x.get_allocator();
				copy(x);
				std::cout << "I am back in copy again" << std::endl;
				for (std::size_t index = 0; index < _size; ++index)
				{
					std::cout << this->_vec[index] << std::endl;
				}
				std::cout << "End of copy constructor" << std::endl;
			}
			
			// Destructor
			~vector ()
			{
				deallocate_and_destruct(_cap, _size);
			}

			// Assignment operator
			vector& operator=(const vector& x)
			{
				if (this == &x) 
				{
					return *this;
				}
				destruct(size());
				
				if (x._vec)
				{
					
					// if ()
					// {
					// 	this->_alloc = x.get_allocator();
					// }
					this->_alloc = x.get_allocator();
					if (x.size() > this->capacity())
					{
						reallocate(this->capacity(), x.size());
					}
					std::cout << x.size() << " " << _size << std::endl;
					uninitialized_alloc_copy(x);
				}
				else
				{
					_vec = nullptr;
					_size = 0;
				}
				// for (std::size_t index = 0; index < _size; ++index)
				// {
				// 	std::cout << this->_vec[index] << std::endl;
				// }
				return *this;
			}
			
			// Allocator based function
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}
			
			// Iterators
			iterator	begin()
			{
				return (_vec);
			}
			const_iterator         begin()   const
			{
				return (_vec);
			}
			iterator               end()
			{
				return (_vec + size()); 
			}
			const_iterator         end()     const
			{
				return (_vec + size()); 
			}
			
			// reverse_iterator       rbegin()
			// {
				
			// }
			// const_reverse_iterator rbegin()  const
			// {
				
			// }
			// reverse_iterator       rend()
			// {
				
			// }
			// const_reverse_iterator rend()    const
			// {
				
			// }
			
			// Capacity based functions
			size_type size() const
			{
				return (this->_size); 
			}
			size_type capacity() const
			{
				return (this->_cap);
			}
			size_type max_size() const
			{
				return (std::numeric_limits<difference_type>::max()); 
			}
			bool empty() const
			{
				if (_size)
					return (false);
				return (true);
			}
			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("Capacity allocated exceeds max_size()");
				else if (n > _cap)
					reallocate(_cap, n);
			}

			// Modifiers functions
			reference       operator[](size_type index)
			{
				assert(index < size() && "Index out of range");
				return _vec[index]; 
			}
			const_reference operator[](size_type index) const
			{
				assert(index < size() && "Index out of range");
				return _vec[index]; 
			}
			reference       at(size_type n)
			{
				return (index < size() ? _vec[index] : throw std::out_of_range("Index out of range"));
			}
			const_reference at(size_type n) const
			{
				return (index < size() ? _vec[index] : throw std::out_of_range("Index out of range"));
			}
			void clear()
			{
				 destruct(_size); 
			}

			// // assign functions:
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last)
			// {
				
			// }
			// void assign (size_type n, const value_type& val)
			// {
				
			// }

			// // insert functions
			// iterator insert (iterator position, const value_type& val) // single element insert
			// {
				
			// }
			// void insert (iterator position, size_type n, const value_type& val) // fill n index starting from iterator position
			// {
				
			// }
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last)
			// {
				
			// }
			// popback and pushback
			void pop_back()
			{
				_alloc.destroy(_vec + size() - 1);
				_size -= 1;
			}
			// void push_back (const value_type& val);
			// {
			// 	if(_size + 1 > _cap)
			// 	{
			// 		T* temp;
			// 		temp = 
			// 	}
			// }
			// reference       front();
			// const_reference front() const;
			// reference       back();
			// const_reference back() const;



			
			// Non-member function overloads
			// template <class T, class Alloc>
			// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
			// {
				
			// }
			// template <class T, class Alloc>
			// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			// {
				
			// }
			// template <class T, class Alloc>
			// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			// {
				
			// }
			// template <class T, class Alloc>
			// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			// {
				
			// }
			// template <class T, class Alloc>
			// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			// {
				
			// }
			// template <class T, class Alloc>
			// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			// {
				
			// }
			// template <class T, class Alloc>
			// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
			// {
				
			// }
			
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
					_alloc.construct(_vec + index, value);
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
			void uninitialized_alloc_copy(const vector& other)
			{
				_size = other.size();
				std::cout << _size << "i am in unin"  << std::endl;
				for (size_type index=0; index < _size; ++index)
				{
					std::cout << *(other._vec + index)  << std::endl;
					this->_alloc.construct(this->_vec + index, *(other._vec + index));
				}
				std::cout << "i am going out" << std::endl;
			}
			void copy(const vector& other)
			{
				if (other._vec) {
					allocate(other._size);
					uninitialized_alloc_copy(other);
				}
				else
					_vec = nullptr;
			}
		} ;
		
// #include "vector.cpp" // include separate implementation file inside namespace
}
#endif

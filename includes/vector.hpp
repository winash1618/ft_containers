/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/09/10 15:03:57 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <limits>
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
namespace ft
{
	//https://stackoverflow.com/questions/44517556/how-to-define-our-own-nullptr-in-c98
	// const                         /* this is a const object...     */
	// class nullptr_t
	// {
	// public:
	// template<class T>          /* convertible to any type       */
	// operator T*() const        /* of null non-member            */
	// 	{ return 0; }           /* pointer...                    */

	// template<class C, class T> /* or any type of null           */
	// 	operator T C::*() const /* member pointer...             */
	// 	{ return 0; }   

	// private:
	// void operator&() const;    /* Can't take address of nullptr */

	// } nullptr = {};   

/*---------------std::is_integral----------------------------------------*/

template<class T, T v>
  	struct integral_constant {
      const static T value = v;
      typedef T value_type;
      typedef integral_constant type;
      operator value_type() const { return value; }
      value_type operator()() const { return value; } //since c++14
  };

	typedef integral_constant<bool, true> true_type1;
	typedef integral_constant<bool, false> false_type1;

	template <class T>
	struct is_integral : public false_type1{};

	template <>
	struct is_integral<bool> : public true_type1{};

	template <>
	struct is_integral<char> : public true_type1{};

	template <>
	struct is_integral<signed char> : public true_type1{};

	template <>
	struct is_integral<unsigned char> : public true_type1{};

	template <>
	struct is_integral<wchar_t> : public true_type1{};

	template <>
	struct is_integral<short> : public true_type1{};

	template <>
	struct is_integral<int> : public true_type1{};

	template <>
	struct is_integral<long> : public true_type1{};

	template <>
	struct is_integral<long long> : public true_type1{};

	template <>
	struct is_integral<unsigned short> : public true_type1{};

	template <>
	struct is_integral<unsigned int> : public true_type1{};

	template <>
	struct is_integral<unsigned long> : public true_type1{};

	template <>
	struct is_integral<unsigned long long> : public true_type1{};




/*--------------implementation 1 of enable if-----------------------------*/
	/* enable_if definitions */
	template<bool B, class T>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {typedef T type;};

	/* True type and False type*/
	struct true_type {
		static const bool value = true;
	};

	struct false_type {
		static const bool value = false;
	};

	template<typename T>
	int is_int() {
	return false;
	}

	template<>
	int is_int<int>() {
	return true;
}

	
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			/*--------------------------------------------------------------------*/
			/*-------------------------member type--------------------------------*/
			/*--------------------------------------------------------------------*/
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef ft::iterator<value_type>							iterator;
			typedef ft::iterator<const value_type>							const_iterator;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			
			/*--------------------------------------------------------------------*/
			/*-------------------------member functions---------------------------*/
			/*--------------------------------------------------------------------*/
			// Constructor
			// empty container constructor
			explicit vector (const allocator_type& alloc = allocator_type())  :  _vec(nullptr_f), _alloc(alloc), _cap(0), _size(0) {}
			
			// fill constructor
			explicit vector (size_type len, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			 : _alloc(alloc)
			{
				allocate(len);
				construct_at_end(len, val);
			}
			
			// range constructor
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : 
					_alloc(alloc), _cap(0), _size(0)
			{
				if (first > last)
					throw std::length_error("vector");
				size_type size = ft::distance(first, last);
				allocate(size);
				for (size_type index = 0; index < size; ++index)
				{
					_alloc.construct(_vec + index, *(first + index));
					++_size;
				}
			}
			
			// Copy constructor
			vector (const vector& x) : _size(0)
			{
				_alloc = x.get_allocator();
				copy(x);
			}
			
			// Destructor
			~vector () {deallocate_and_destruct(_cap, _size);}

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
					this->_alloc = x.get_allocator();
					if (x.size() > this->capacity())
					{
						reallocate(this->capacity(), x.size());
					}
					uninitialized_alloc_copy(x);
				}
				else
				{
					_vec = nullptr_f;
					_size = 0;
				}
				return *this;
			}
			
			// Allocator based function
			allocator_type get_allocator() const {return (this->_alloc);}
			
			// erase
			iterator erase (iterator position)
			{
				_alloc.destroy(_vec + (begin() - position));
				for(size_type index = begin() - position; index < _size - 1; index++)
				{
					_alloc.construct(_vec + index, *(_vec + index + 1));
				}
				_size--;
				// _vec[_size] = 0;
				return (position);
			}
			iterator erase (iterator first, iterator last)
			{
				// size_type j = 0;
				// size_type old_size = _size;
				// iterator t_end = end();
				// _size = begin() - first;
				// // std::cout << " size : " << _size << std::endl;
				// // std::cout << " end : " << *t_end << std::endl;
				// for (iterator i = first; i != t_end ; i++)
				// {
				// 	// std::cout << "f " << *(last + j) << std::endl;
				// 	*i = *(last + j);
				// 	j++;
				// 	_size++;
				// 	if (last + j == t_end)
				// 		break;
				// }
				// for (size_type i = _size; i < old_size; i++)
				// {
				// 	_vec[i] = 0;
				// }
				// // _size = 10;
				// // std::cout << "d " << old_size << " " << _size << std::endl;
				// return (first);
				
	
				size_type siz = begin() - first;
				size_type len = begin() - end();
				// (void)last;
				// (void)index;
				// std::cout << " size : " << siz << std::endl;
				if (len > 0)
				{
					size_type index = 0;
					iterator t_end = end();
					for (iterator it = first; it != last; it++)
					{
						_alloc.destroy(_vec + siz + index);
						index++;
						_size--;
					}
					index = 0;
					for (iterator it = first; it != last; it++)
					{
						if (last + index == t_end)
							break;
						_alloc.construct(_vec  + siz + index, *(last + index));
						_alloc.destroy(_vec + siz + index);
						index++;
					}
					if (last + index != t_end)
					{
						while (index < len)
						{
							if (last + index == t_end)
							break;
							_alloc.construct(_vec  + siz + index, *(last + index));
							_alloc.destroy(_vec + siz + index);
							index++;
						}
					}
				}
				return first;
			}

			// push_back
			void push_back (const value_type& val)
			{
				if (!_cap)
				{
					_vec = _alloc.allocate(1, 0);
					_alloc.construct(_vec, val);
					_cap = 1;
					_size = 1;
				}
				else
				{
					if (_size + 1 > _cap)
					{
						Allocator t_alloc1 ;
						pointer t_vec = t_alloc1.allocate(_size * 2);
						for (size_type index = 0; index < _size; ++index)
						{
							t_alloc1.construct(t_vec + index, _vec[index]);
						}
						t_alloc1.construct(t_vec + _size, val);
						for (size_type index= 0; index < _size; ++index)
							_alloc.destroy(_vec + index);
						_alloc.deallocate(_vec, _cap);
						_alloc = t_alloc1;
						_vec = t_vec;
						_cap = _size * 2;
						_size++;
					}
					else
					{
						_alloc.construct(_vec + _size, val);
						_size += 1;
					}
				}
			}
			
			// Iterators
			iterator	begin() {return iterator(_vec);}
			const_iterator         begin()   const {return const_iterator(_vec);}
			iterator               end() {return iterator(_vec + size());}
			const_iterator         end()     const {return const_iterator(_vec + size()); }
			
			//reverse Iterators
			reverse_iterator       rbegin() {return reverse_iterator(this->end());}
			const_reverse_iterator rbegin() const {return const_reverse_iterator(this->end());}
			reverse_iterator       rend() {return reverse_iterator(this->begin());}
			const_reverse_iterator rend() const {return const_reverse_iterator(this->begin());}
			
			// Capacity based functions
			size_type size() const {return (this->_size);}
			size_type capacity() const {return (this->_cap);}
			size_type max_size() const {return (_alloc.max_size());}
			bool empty() const {return (_size == 0);}
			
			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("Capacity allocated exceeds max_size()");
				else if (n > _cap)
				{
						temp = t_alloc.allocate(n, 0);
						for (_index = 0; _index < _size; ++_index)
						{
							t_alloc.construct(temp + _index, _vec[_index]);
						}
						_alloc.deallocate(_vec, _cap);
						for (_index = 0; _index < _size; ++_index)
							_alloc.destroy(_vec + _index);
						_alloc = t_alloc;
						_vec = temp;
						_cap = n;
				}	
					
			}

			// Modifiers functions
			reference       operator[](size_type index)
			{
				assert(index < size() && "Index out of range1");
				return _vec[index]; 
			}
			const_reference operator[](size_type index) const
			{
				assert(index < size() && "Index out of range2");
				return _vec[index]; 
			}
			reference       at(size_type n)
			{
				if (n < size() && n >= 0)
				{
					return (_vec[n]);
				}
				else
					throw std::out_of_range("Index out of range");
				// return (n < size() ? _vec[n] : throw std::out_of_range("Index out of range"));
			}
			
			const_reference at(size_type n) const {return (n < size() ? _vec[n] : throw std::out_of_range("Index out of range"));}
			void clear() {destruct(_size);}

			// assign functions:
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				if (first > last)
					throw std::length_error("vector");
				size_type size = ft::distance(first, last);
				allocate(size);
				for (size_type index = 0; index < size; ++index)
				{
					_alloc.construct(_vec + index, *(first + index));
					++_size;
				}
			}
			void assign (size_type n, const value_type& val)
			{
				allocate(n);
				for (size_type index = 0; index < n; ++index)
				{
					_alloc.construct(_vec + index, val);
					//std::cout << _vec[index] << std::endl;
					++_size;
				}
			}

			// resize
			void resize (size_type n, value_type val = value_type())
			{

				if (n > max_size())
				{
					throw std::length_error("vector");
				}
				if (n < _size)
				{
					for(size_type index = n; index < _size; index++)
					{
						_alloc.destroy(_vec + index);
					}
					_size = n;
				}
				else if (n >= _size && n < _cap )
				{
					// std::cout << "i am inside else if" << std::endl;
					// if (!val)
					// 	val = 0;
					for(size_type index = _size; index < n; index++)
					{
						_alloc.construct(_vec + index, val);
					}
					_size = n;
				}
				else
				{
					// if (!val)
					// 	val = 0;
					if (n > max_size())
						throw std::length_error("Capacity allocated exceeds max_size()");

					temp = t_alloc.allocate(n);
					for (size_type index = 0; index < _size; ++index)
					{
						t_alloc.construct(temp + index, _vec[index]);
					}
					for (size_type index = _size; index < n; ++index)
					{
						t_alloc.construct(temp + index, val);
					}
					
					for (size_type index = 0; index < _size; ++index)
						_alloc.destroy(_vec + index);
					_alloc.deallocate(_vec, _cap);
					_alloc = t_alloc;
					_vec = temp;
					_cap = recommend(n);
					_size = n;

				}
			}
			
			// // insert functions
			iterator insert (iterator position, const value_type& val) // single element insert
			{
				if (_size + 1 <= _cap)
				{
					_alloc.construct(_vec + _size, val);
					_cap = _size + 1;
					_size++;
					for (iterator it = position; it < end(); it++)
					{
						value_type temp1 = back();
						*(end() - 1) = *it;
						*it = temp1;
					}
				}
				else
				{
					size_type i = begin() - position;
					temp = t_alloc.allocate(_size * 2, 0);
					for (size_type index1 = 0; index1 < _size; ++index1)
					{
						t_alloc.construct(temp + index1, _vec[index1]);
					}
					t_alloc.construct(temp + _size, val);
					_alloc.deallocate(_vec, _cap);
					for (size_type index1 = 0; index1 < _size; ++index1)
						_alloc.destroy(_vec + index1);
					_alloc = t_alloc;
					_vec = temp;
					_cap = _size * 2;
					_size++;
					position = begin() + i;
					for (iterator it = position; it < end(); it++)
					{
						value_type temp1 = back();
						*(end() - 1) = *it;
						*it = temp1;
					}
				}
				return (position);
			}
			void insert (iterator position, size_type n, const value_type& val) // fill n index starting from iterator position
			{
				size_type t_cap;
				if (_size + n > _cap)
				{
					temp = t_alloc.allocate(recommend(_size + n), 0);
					t_cap = recommend(_size + n);
				}
				else
				{
					temp = t_alloc.allocate(_cap, 0);
					t_cap = _cap;
				}
				size_type index = 0;
				size_type t_size = 0;
				for (iterator it = begin(); it != position; it++)
				{
					t_alloc.construct(temp + index, *it);
					t_size++;
					index++;
				}
				for (index = 0; index < n; index++)
				{
					t_alloc.construct(temp + t_size + index, val);
				}
				t_size = t_size + index;
				index = 0;
				for (iterator it = position; it != end(); it++)
				{
					t_alloc.construct(temp + t_size + index, *it);
					index++;
				}
				for (size_type index1 = 0; index1 < _size; ++index1)
					_alloc.destroy(_vec + index1);
				_alloc.deallocate(_vec, _cap);
				t_size = t_size + index;
				_alloc = t_alloc;
				_vec = temp;
				_size = t_size;
				_cap = t_cap;
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				if (first > last)
					throw std::length_error("vector");
				size_type t_cap;
				if (_size + (size_type)(last - first) > _cap)
				{
					temp = t_alloc.allocate(recommend(_size + (size_type)(last - first)), 0);
					t_cap = recommend(_size + (size_type)(last - first));
				}
				else
				{
					temp = t_alloc.allocate(_cap, 0);
					t_cap = _cap;
				}
				size_type index = 0;
				size_type t_size = 0;
				for (iterator it = begin(); it != position; it++)
				{
					t_alloc.construct(temp + index, *it);
					t_size++;
					index++;
				}
				index = 0;
				for (InputIterator it = first; it != last; it++)
				{
					t_alloc.construct(temp + t_size + index,*it);
					index++;
				}
				t_size = t_size + index;
				index = 0;
				for (iterator it = position; it != end(); it++)
				{
					t_alloc.construct(temp + t_size + index, *it);
					index++;
				}
				t_size = t_size + index;
				_alloc = t_alloc;
				_vec = temp;
				_size = t_size;
				_cap = t_cap;
			}
			// popback and pushback
			void pop_back()
			{
				if (_size  == 0)
					throw std::out_of_range("can");
				_alloc.destroy(&_vec[_size-- - 1]);
			}
			reference       front()
			{
				assert(!empty() && "front() called for empty vector");
				return *this->begin();
			}
			const_reference front() const
			{
				assert(!empty() && "front() called for empty vector");
				return *this->begin();
			}
			reference       back()
			{
				assert(!empty() && "back() called for empty vector");
				return *(_vec + size() - 1);
			}
			const_reference back() const
			{
				assert(!empty() && "back() called for empty vector");
				return *(_vec + size() - 1);
			}
			void swap (vector& x)
			{
				temp = x._vec;
				t_alloc = x._alloc;
				size_type t_size = x._size;
				size_type t_cap = x._cap;
				x._vec = _vec;
				x._alloc = _alloc;
				x._size = _size;
				x._cap = _cap;
				_vec = temp;
				_alloc = t_alloc;
				_size = t_size;
				_cap = t_cap;
			}
		private:
			pointer temp;
			pointer _vec; // 
			Allocator t_alloc;
			Allocator 	_alloc; // std::allocator
			value_type t_val;
			size_type _index;
			size_type _cap;// Capacity 
			size_type _size;
			void print(void)
			{
				size_type i = 0;
				std::cout << "Printing starts" << std::endl;
				while (i < _size)
				{
					std::cout << i << " th element = " << _vec[i] << std::endl;
					i++;
				}
				std::cout << "Printing ends" << std::endl;
			}
			void allocate(size_type capacity)
			{
				if (capacity > max_size())
					throw std::length_error("new size to allocate exceeds max_size()");
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

			void construct_at_end(size_type size, const value_type& value)
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
				for (size_type index=0; index < _size; ++index)
				{
					this->_alloc.construct(this->_vec + index, *(other._vec + index));
				}
			}
			void copy(const vector& other)
			{
				if (other._vec) {
					allocate(other._size);
					uninitialized_alloc_copy(other);
				}
				else
					_vec = nullptr_f;
			}
			size_type recommend(size_type new_size) const
			{
				const size_type ms = max_size();
				if (new_size > ms)
					throw std::length_error("new size to allocate exceeds max_size()");
				const size_type cap = capacity();
				if (cap >= ms / 2)
					return ms;
				return std::max<size_type>(2*cap, new_size);
			}
			// destruct_at_end(pointer __new_last)
			// {
			// 	pointer __soon_to_be_end = end();
			// 	while (__new_last != __soon_to_be_end)
			// 		__alloc_traits::destroy(__alloc(), _VSTD::__to_address(--__soon_to_be_end));
			// }
		} ;
		// Non-member function overloads
		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs.size() == rhs.size())
			{
				for (size_t index = 0; index < lhs.size(); index++)
				{
					if (lhs[index] != rhs[index])
						return (false);
				}
				return (true);
			}
			return (false);
		}
		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs == rhs);
		}
		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			//src https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
			for ( ; (lhs.begin() != lhs.end()) && (rhs.begin() != rhs.end()); ++(lhs.begin()), (void) ++(rhs.begin()) ) 
			{
				if (*(lhs.begin()) < *(rhs.begin())) return true;
				if (*(rhs.begin()) < *(lhs.begin())) return false;
			}
			return (lhs.begin() == lhs.end()) && (rhs.begin() != rhs.end());
		}
		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(rhs < lhs);
		}
		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}
		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs);
		}
		// #include "vector.cpp" // include separate implementation file inside namespace
}
#endif

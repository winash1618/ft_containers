/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/11/12 12:43:46 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <vector>
// #include <iterator>
#include <cassert>
#include <cstddef>
#include <limits>
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "vec_utils.hpp"
namespace ft
{
	// https://stackoverflow.com/questions/4307271/how-to-check-that-the-passed-iterator-is-a-random-access-iterator
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::random_access_iterator_tag)
	{
		if (first > last )
					throw std::length_error("vector");
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::input_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::output_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::forward_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::bidirectional_iterator_tag)
	{
		(void)first;
		(void)last;

	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::random_access_iterator_tag)
	{
		if (first > last )
					throw std::length_error("vector");
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::input_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::output_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::forward_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::bidirectional_iterator_tag)
	{
		(void)first;
		(void)last;

	}
	template <class InputIter>
	void
	check_valid(InputIter first, InputIter last)
	{
		__check_valid(first, last, typename ft::iterator_traits<InputIter>::iterator_category());
	}
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef ft::iterator<pointer>								iterator;
			typedef ft::iterator<const_pointer>							const_iterator;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type len, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			vector(const vector& x);
			~vector();
			
			vector&									operator=(const vector& x);
			value_type*								data();
			const value_type*						data() const;
			allocator_type							get_allocator() const;
			iterator								erase(iterator position);
			iterator								erase(iterator first, iterator last);
			void									push_back (const value_type& val);
			iterator								begin();
			const_iterator							begin()   const;
			iterator								end();
			const_iterator							end() const;
			reverse_iterator						rbegin();
			const_reverse_iterator					rbegin() const;
			reverse_iterator						rend();
			const_reverse_iterator					rend() const;
			size_type								size() const;
			size_type								capacity() const;
			size_type								max_size() const;
			bool									empty() const;
			void									reserve(size_type n);
			reference								operator[](size_type index);
			const_reference							operator[](size_type index) const;
			reference								at(size_type n);
			const_reference							at(size_type n) const;
			void									clear();
			template <class InputIterator>
			void 									assign(InputIterator first, InputIterator last , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			void 									assign(size_type n, const value_type& val);
			void 									resize(size_type n, value_type val = value_type());
			iterator								insert(iterator position, const value_type& val);
			void									insert(iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void									insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			void									pop_back();
			reference								front();
			const_reference							front() const;
			reference								back();
			const_reference							back() const;
			void									swap(vector& x);
		private:
			pointer temp;
			pointer _vec; // 
			Allocator t_alloc;
			Allocator 	_alloc; // std::allocator
			value_type t_val;
			size_type _index;
			size_type _cap;// Capacity 
			size_type _size;
			void print(void);
			// {
			// 	size_type i = 0;
			// 	std::cout << "Printing starts" << std::endl;
			// 	while (i < _size)
			// 	{
			// 		std::cout << i << " th element = " << _vec[i] << std::endl;
			// 		i++;
			// 	}
			// 	std::cout << "Printing ends" << std::endl;
			// }
			void allocate(size_type capacity);
			// {
			// 	if (capacity > max_size())
			// 		throw std::length_error("new size to allocate exceeds max_size()");
			// 	_cap = capacity;
			// 	_vec = _alloc.allocate(capacity, 0);
			// }

			void deallocate(std::size_t capacity);
			// {
			// 	_alloc.deallocate(_vec, capacity);
			// 	_cap = 0;
			// 	_size = 0;
			// }

			void reallocate(std::size_t old_cap, std::size_t new_cap);
			// {
			// 	deallocate(old_cap);
			// 	allocate(new_cap);
			// }

			void construct(std::size_t size, const value_type& value);
			// {
			// 	_size = size;
			// 	for (std::size_t index = 0; index < size; ++index)
			// 		_alloc.construct(_vec + index, value);
			// }

			void construct_at_end(size_type size, const value_type& value);
			// {
			// 	_size = size;
			// 	for (std::size_t index = 0; index < size; ++index)
			// 		_alloc.construct(_vec + index, value);
			// }
			void destruct(std::size_t size);
			// {
			// 	for (std::size_t index = 0; index < size; ++index)
			// 		_alloc.destroy(_vec + index);
			// 	_size = 0;
			// }
			void allocate_and_copy_construct(std::size_t capacity, std::size_t size, const value_type& value = value_type());
			// {
			// 	allocate(capacity);
			// 	construct(size, value);
			// }
			void deallocate_and_destruct(std::size_t capacity, std::size_t size);
			// {
			// 	destruct(size);
			// 	deallocate(capacity);
			// }
			void uninitialized_alloc_copy(const vector& other);
			// {
			// 	_size = other.size();
			// 	for (size_type index=0; index < _size; ++index)
			// 		this->_alloc.construct(this->_vec + index, *(other._vec + index));
			// }
			void copy(const vector& other);
			// {
			// 	if (other._vec)
			// 	{
			// 		allocate(other._size);
			// 		uninitialized_alloc_copy(other);
			// 	}
			// 	else
			// 		_vec = nullptr_f;
			// }
			size_type recommend(size_type new_size) const;
			// {
			// 	const size_type ms = max_size();
			// 	if (new_size > ms)
			// 		throw std::length_error("new size to allocate exceeds max_size()");
			// 	const size_type cap = capacity();
			// 	if (cap >= ms / 2)
			// 		return ms;
			// 	return std::max<size_type>(2*cap, new_size);
			// }
		} ;
		// Non-member function overloads
		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
		template <class T, class Alloc>
		bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs == rhs);
		}
		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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
}
#include "vector.tpp"
#endif

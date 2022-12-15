/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/15 18:30:35 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <cstddef>
#include <limits>
#include "iterators/iterator.hpp"
#include "iterators/iterator_traits.hpp"
#include "iterators/reverse_iterator.hpp"
#include "utils/pair.hpp"
#include "utils/vec_utils.hpp"
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::iterator<pointer>						iterator;
			typedef ft::iterator<const_pointer>					const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;

			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type len, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			vector(const vector& x);
			~vector();
			vector&									operator=(const vector& x);

			iterator								begin();
			const_iterator							begin()   const;
			iterator								end();
			const_iterator							end() const;
			reverse_iterator						rbegin();
			const_reverse_iterator					rbegin() const;
			reverse_iterator						rend();
			const_reverse_iterator					rend() const;

			size_type								size() const;
			size_type								max_size() const;
			void 									resize(size_type n, value_type val = value_type());
			size_type								capacity() const;
			bool									empty() const;
			void									reserve(size_type n);

			reference								operator[](size_type index);
			const_reference							operator[](size_type index) const;
			reference								at(size_type n);
			const_reference							at(size_type n) const;
			reference								front();
			const_reference							front() const;
			reference								back();
			const_reference							back() const;
			value_type*								data();
			const value_type*						data() const;

			void 									assign(size_type n, const value_type& val);
			template <class InputIterator>
			void 									assign(InputIterator first, InputIterator last , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			void									push_back (const value_type& val);
			void									pop_back();
			iterator								insert(iterator position, const value_type& val);
			void									insert(iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void									insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0);
			iterator								erase(iterator position);
			iterator								erase(iterator first, iterator last);
			void									swap(vector& x);
			void									clear();

			allocator_type							get_allocator() const;
		private:
			pointer									temp;
			pointer									_vec;
			Allocator								t_alloc;
			Allocator								_alloc;
			value_type								t_val;
			size_type								_index;
			size_type								_cap;
			size_type								_size;
			void									print(void);
			void									allocate(size_type capacity);
			void									deallocate(std::size_t capacity);
			void									reallocate(std::size_t old_cap, std::size_t new_cap);
			void									construct(std::size_t size, const value_type& value);
			void									construct_at_end(size_type size, const value_type& value);
			void									destruct(std::size_t size);
			void									allocate_and_copy_construct(std::size_t capacity, std::size_t size, const value_type& value = value_type());
			void									deallocate_and_destruct(std::size_t capacity, std::size_t size);
			void									uninitialized_alloc_copy(const vector& other);
			void									copy(const vector& other);
			size_type								recommend(size_type new_size) const;
		} ;
		template <class T, class Allocator> bool operator==(const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y);
		template <class T, class Allocator> bool operator< (const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y);
		template <class T, class Allocator> bool operator!=(const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y);
		template <class T, class Allocator> bool operator> (const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y);
		template <class T, class Allocator> bool operator>=(const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y);
		template <class T, class Allocator> bool operator<=(const ft::vector<T,Allocator>& x, const ft::vector<T,Allocator>& y);
		template <class T, class Allocator>
		void swap(ft::vector<T,Allocator>& x, ft::vector<T,Allocator>& y);
		
}
#include "../srcs/vector/vector_capacity.tpp"
#include "../srcs/vector/vector_element_access.tpp"
#include "../srcs/vector/vector_init.tpp"
#include "../srcs/vector/vector_iterators.tpp"
#include "../srcs/vector/vector_modifiers.tpp"
#include "../srcs/vector/vector_non_member.tpp"
#include "../srcs/vector/vector_utils.tpp"
#endif

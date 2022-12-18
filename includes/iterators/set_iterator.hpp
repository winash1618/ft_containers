/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:57:00 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 08:58:32 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP
# include "reverse_iterator.hpp"
# include "../utils/utils.hpp"
namespace ft
{
	template <class _V, class Alloc>
	class set_iterator
	{
		public:
			typedef Alloc																allocator_type;
			typedef _V																	value_type;
			typedef value_type&															reference;
			typedef value_type*															pointer;
			typedef ft::bidirectional_iterator_tag										iterator_category;
			typedef std::ptrdiff_t														difference_type;
			typedef RBTreeNode<value_type>												Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr															__node_pointer;
			__node_pointer																__ptr_;
			__node_pointer																__end_;
			__node_pointer																__nil_;

			set_iterator();
			~set_iterator();
			set_iterator(__node_pointer ptr);
			set_iterator(__node_pointer end, __node_pointer ptr);
			set_iterator(__node_pointer end, __node_pointer ptr, __node_pointer nil);

			reference																	operator*() const;
			pointer																		operator->() const;
			set_iterator&																operator++();
			set_iterator																operator++(int);
			set_iterator&																operator--();
			set_iterator																operator--(int);

			template <class _V1, class Alloc1>
			friend bool operator==(const ft::set_iterator<_V1, Alloc1>& __x, const ft::set_iterator<_V1, Alloc1>& __y);
			template <class _V1, class Alloc1>
			friend bool operator!=(const ft::set_iterator<_V1, Alloc1>& __x, const ft::set_iterator<_V1, Alloc1>& __y);

	};

	template <class _V, class Alloc>
	class __const_set_iterator
	{
		public:
			typedef Alloc																allocator_type;
			typedef _V							 										value_type;
			typedef const value_type&													reference;
			typedef const value_type*													pointer;
			typedef std::bidirectional_iterator_tag										iterator_category;
			typedef std::ptrdiff_t														difference_type;
			typedef ft::RBTreeNode<value_type>											Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr															__node_pointer;
			typedef ft::set_iterator<_V, allocator_type> 								iterator;
			iterator																	__iter;
			__node_pointer																__ptr_;
			__node_pointer																__end_;
			__node_pointer																__nil_;

			__const_set_iterator();
			~__const_set_iterator();
			__const_set_iterator(__node_pointer ptr);
			__const_set_iterator(__node_pointer end, __node_pointer ptr);
			__const_set_iterator(__node_pointer end, __node_pointer ptr, __node_pointer nil);
			__const_set_iterator(iterator  iter);

			reference																	operator*() const;
			pointer																		operator->() const;
			__const_set_iterator&														operator++();
			__const_set_iterator														operator++(int);
			__const_set_iterator&														operator--();
			__const_set_iterator														operator--(int);

			template <class _V1, class Alloc1>
			friend bool operator==(const ft::__const_set_iterator<_V1, Alloc1>& __x, const ft::__const_set_iterator<_V1, Alloc1>& __y);
			template <class _V1, class Alloc1>
			friend bool operator!=(const ft::__const_set_iterator<_V1, Alloc1>& __x, const ft::__const_set_iterator<_V1, Alloc1>& __y);
	};
	template <class _V1, class Alloc1>
	bool operator==(const ft::set_iterator<_V1, Alloc1>& __x, const ft::set_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator==(const ft::__const_set_iterator<_V1, Alloc1>& __x, const ft::__const_set_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator==(const ft::set_iterator<_V1, Alloc1>& __x, const ft::__const_set_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator==(const ft::__const_set_iterator<_V1, Alloc1>& __x, const ft::set_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const ft::set_iterator<_V1, Alloc1>& __x, const ft::set_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const ft::__const_set_iterator<_V1, Alloc1>& __x, const ft::__const_set_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const __const_set_iterator<_V1, Alloc1>& __x, const set_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const set_iterator<_V1, Alloc1>& __x, const __const_set_iterator<_V1, Alloc1>& __y);
	#include "./../../srcs/extras/set_iterator.tpp"
	#include "./../../srcs/extras/const_set_iterator.tpp"
	#include "./../../srcs/extras/set_iter_non_members.tpp"
}
#endif
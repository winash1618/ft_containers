/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:57:06 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 21:53:23 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "../utils/utils.hpp"

namespace ft
{
	template <class _V, class Alloc>
	class __tree_iterator
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

			__tree_iterator();
			~__tree_iterator();
			__tree_iterator(const __tree_iterator& x);
			__tree_iterator(__node_pointer ptr);
			__tree_iterator(__node_pointer end, __node_pointer ptr);
			__tree_iterator(__node_pointer end, __node_pointer ptr, __node_pointer nil);

			__tree_iterator&															operator=(const __tree_iterator& x);

			reference																	operator*() const;
			pointer																		operator->() const;
			__tree_iterator&															operator++();
			__tree_iterator																operator++(int);
			__tree_iterator&															operator--();
			__tree_iterator																operator--(int);

			template <class _V1, class Alloc1>
			friend bool operator==(const ft::__tree_iterator<_V1, Alloc1>& __x, const ft::__tree_iterator<_V1, Alloc1>& __y);
			template <class _V1, class Alloc1>
			friend bool operator!=(const ft::__tree_iterator<_V1, Alloc1>& __x, const ft::__tree_iterator<_V1, Alloc1>& __y);
	};

	template <class _V, class Alloc>
	class __const_tree_iterator 
	{
		public:
			typedef Alloc																allocator_type;
			typedef typename allocator_type::value_type 								value_type;
			typedef const value_type&													reference;
			typedef const value_type*													pointer;
			typedef ft::bidirectional_iterator_tag										iterator_category;
			typedef std::ptrdiff_t														difference_type;
			typedef ft::RBTreeNode<value_type>											Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr															__node_pointer;
			typedef ft::__tree_iterator<_V, allocator_type> 							iterator;
			iterator																	__iter;
			__node_pointer																__ptr_;
			__node_pointer																__end_;
			__node_pointer																__nil_;

			__const_tree_iterator();
			~__const_tree_iterator();
			__const_tree_iterator(const __const_tree_iterator& x);
			__const_tree_iterator(__node_pointer ptr);
			__const_tree_iterator(__node_pointer end, __node_pointer ptr);
			__const_tree_iterator(__node_pointer end, __node_pointer ptr, __node_pointer nil);
			__const_tree_iterator(iterator  iter);

			__const_tree_iterator&														operator=(const __const_tree_iterator& x);

			reference																	operator*() const;
			pointer																		operator->() const;
			__const_tree_iterator&														operator++();
			__const_tree_iterator														operator++(int);
			__const_tree_iterator&														operator--();
			__const_tree_iterator														operator--(int);

			template <class _V1, class Alloc1>
			friend bool operator==(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y);
			template <class _V1, class Alloc1>
			friend bool operator!=(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y);
	};
	template <class _V1, class Alloc1>
	bool operator==(const ft::__tree_iterator<_V1, Alloc1>& __x, const ft::__tree_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator==(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator==(const ft::__tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator==(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__tree_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const ft::__tree_iterator<_V1, Alloc1>& __x, const ft::__tree_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const __const_tree_iterator<_V1, Alloc1>& __x, const __tree_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const __tree_iterator<_V1, Alloc1>& __x, const __tree_iterator<_V1, Alloc1>& __y);
	template <class _V1, class Alloc1>
	bool operator!=(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y);

	#include "./../../srcs/extras/tree_iterator.tpp"
	#include "./../../srcs/extras/const_tree_iterator.tpp"
	#include "./../../srcs/extras/map_iter_non_members.tpp"
}
#endif
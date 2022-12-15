/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_set_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:56:37 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/15 18:06:31 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_SET_ITERATOR_HPP
# define CONST_SET_ITERATOR_HPP


#include "reverse_iterator.hpp"
#include "set_iterator.hpp"
#include "../utils/utils.hpp"
namespace ft
{
	template <class _V, class Alloc>
	class __const_set_iterator
	{
		public:
			typedef Alloc																allocator_type;
			typedef _V							 										value_type;
			typedef ft::RBTreeNode<value_type>											Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr															__node_pointer;
			__node_pointer																__ptr_;
			__node_pointer																__end_;
			__node_pointer																__nil_;
			typedef const value_type&															reference;
			typedef const value_type*															pointer;
			typedef std::bidirectional_iterator_tag										iterator_category;
			typedef std::ptrdiff_t														difference_type;
			typedef ft::set_iterator<_V, allocator_type> 								iterator;
			iterator																	__iter;
			__const_set_iterator() {}
			__const_set_iterator(__node_pointer ptr): __ptr_(ptr) {}
			__const_set_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			__const_set_iterator(__node_pointer end, __node_pointer ptr, __node_pointer nil):__ptr_(ptr), __end_(end), __nil_(nil) {}
			__const_set_iterator(iterator  iter):__iter(iter)
			{
				__ptr_ = __iter.__ptr_;
				__end_ = __iter.__end_;
				__nil_ = __iter.__nil_;
			}
			reference operator*() const
			{
				if (__ptr_ == NULL)
					return __nil_->_data;
				return __ptr_->_data;
			}
			pointer operator->() const
			{
				if (__ptr_ == NULL)
					return &__nil_->_data;
				return &__ptr_->_data;
			}

			__const_set_iterator& operator++()
			{
				__node_pointer current_node = __ptr_;
				if (current_node == NULL || current_node == __end_)
					__ptr_ = __nil_;
				else if (current_node->_right != __nil_)
					__ptr_ = tree_min(current_node->_right, __nil_);
				else
				{
					while (!tree_is_left_child(current_node, __nil_) && current_node->_parent)
						current_node = current_node->_parent;
					__ptr_ = current_node->_parent;
				}
				return *this;
			}
			__const_set_iterator operator++(int)
			{
				__const_set_iterator __t(*this);
				++(*this);
				return __t;
			}
			__const_set_iterator& operator--()
			{
				if (__ptr_ == __nil_ || __ptr_ == NULL)
				{
					__ptr_ = __end_;
					return *this;
				}
				__node_pointer current_node = __ptr_;
				if (current_node == __nil_)
					__ptr_ = __nil_;
				else if (current_node->_left != __nil_)
					__ptr_ = tree_max(current_node->_left, __nil_);
				else
				{
					while (tree_is_left_child(current_node, __nil_))
					current_node = current_node->_parent;
					__ptr_ =  current_node->_parent;
				}
				return *this;
			}
			__const_set_iterator operator--(int)
			{
				
				__const_set_iterator __t(*this);
				--(*this); 
				return __t;
			}
			friend bool operator==(const __const_set_iterator& __x, const __const_set_iterator& __y)
			{return __x.__ptr_ == __y.__ptr_;}
			friend bool operator!=(const __const_set_iterator& __x, const __const_set_iterator& __y)
			{return !(__x == __y);}
	};
}
#endif
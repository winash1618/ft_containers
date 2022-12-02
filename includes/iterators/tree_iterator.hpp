#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "../utils/utils.hpp"
namespace ft
{

	
	template <class _V, class Alloc>
	class __tree_iterator
	{
		public:
			typedef Alloc allocator_type;
			typedef  _V value_type;
			typedef RBTreeNode<value_type>												Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr				__node_pointer;
			__node_pointer					__ptr_;
			__node_pointer					__end_;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;

			__tree_iterator() {}
			__tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
			__tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			reference operator*() const
			{
				return __ptr_->_data;
			}
			pointer operator->() const
			{
				return &__ptr_->_data;
			}

			__tree_iterator& operator++()
			{
				__ptr_ = tree_next(__ptr_, __end_);
				return *this;
			}
			__tree_iterator operator++(int)
			{
				__tree_iterator __t(*this);
				++(*this);
				return __t;
			}

			__tree_iterator& operator--()
			{
				if (__ptr_ == __end_)
				{
					__ptr_ = __end_;
					return *this;
				}
				__ptr_ = tree_prev(__ptr_, __end_);
				return *this;
			}
			__tree_iterator operator--(int)
			{
				
				__tree_iterator __t(*this);
				--(*this); 
				return __t;
			}
			
			friend bool operator==(const __tree_iterator& __x, const __tree_iterator& __y)
				{return __x.__ptr_ == __y.__ptr_;}
			friend bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y)
				{return !(__x == __y);}
	};


	template <class _V, class Alloc>
	class __const_tree_iterator 
	{
		public:
			typedef Alloc																allocator_type;
			typedef typename allocator_type::value_type 								value_type;
			typedef ft::RBTreeNode<value_type>											Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr															__node_pointer;
			// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
			__node_pointer																__ptr_;
			__node_pointer																__end_;
			typedef const value_type&															reference;
			typedef const value_type*															pointer;
			typedef ft::bidirectional_iterator_tag										iterator_category;
			typedef std::ptrdiff_t														difference_type;
			typedef ft::__tree_iterator<_V, allocator_type> 							iterator;
			iterator																__iter;
			__const_tree_iterator() {}
			__const_tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
			__const_tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			__const_tree_iterator(iterator  iter):__iter(iter)
			{
				__ptr_ = __iter.__ptr_;
				__end_ = __iter.__end_;
			}
			// __const_tree_iterator(iterator const iter):__iter1(iter)
			// {
			// 	__ptr_ = __iter1.__ptr_;
			// 	__end_ = __iter1.__end_;
			// }
			// __const_tree_iterator& operator=(const __const_tree_iterator<Alloc>& __u) // commented for linux working fine in mac
			// { 
			// 	if (this != &__u) 
			// 	{
			// 		__ptr_ = static_cast<__const_tree_iterator<Alloc> >(__u.__ptr_);
			// 		__end_ = static_cast<__const_tree_iterator<Alloc> >(__u.__end_);
			// 	}
			// 	return *this;
			// }
			reference operator*() const
			{
				return __ptr_->_data;
			}
			pointer operator->() const
			{
				return &__ptr_->_data;
			}

			__const_tree_iterator& operator++()
			{
				__ptr_ = tree_next(__ptr_, __end_);
				return *this;
			}
			__const_tree_iterator operator++(int)
			{
				__const_tree_iterator __t(*this);
				++(*this);
				return __t;
			}

			__const_tree_iterator& operator--()
			{
				if (__ptr_ == __end_)
				{
					__ptr_ = __end_;
					return *this;
				}
				__ptr_ = tree_prev(__ptr_, __end_);
				return *this;
			}
			__const_tree_iterator operator--(int)
			{
				
				__const_tree_iterator __t(*this);
				--(*this); 
				return __t;
			}

			friend bool operator==(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
				{return __x.__ptr_ == __y.__ptr_;}
			friend bool operator!=(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
				{return !(__x == __y);}
	};
}
#endif
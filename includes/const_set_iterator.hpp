#ifndef CONST_SET_ITERATOR_HPP
# define CONST_SET_ITERATOR_HPP


#include "reverse_iterator.hpp"
#include "set_iterator.hpp"
#include "utils.hpp"
namespace ft
{
	template <class _V, class Alloc>
	class __const_set_iterator
	{
		public:
			typedef Alloc																allocator_type;
			typedef typename allocator_type::value_type 								value_type;
			typedef ft::RBTreeNode<value_type>											Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr															__node_pointer;
			__node_pointer																__ptr_;
			__node_pointer																__end_;
			typedef value_type&															reference;
			typedef value_type*															pointer;
			typedef std::bidirectional_iterator_tag										iterator_category;
			typedef std::ptrdiff_t														difference_type;
			typedef ft::set_iterator<_V, allocator_type> 								iterator;
			iterator																	__iter;
			__const_set_iterator() {}
			__const_set_iterator(__node_pointer ptr): __ptr_(ptr) {}
			__const_set_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			__const_set_iterator(iterator  iter):__iter(iter)
			{
				__ptr_ = __iter.__ptr_;
				__end_ = __iter.__end_;
			}
			reference operator*() const
			{
				
				return __ptr_->_data;
			}
			pointer operator->() const
			{
				
				return &__ptr_->_data;
			}

			__const_set_iterator& operator++()
			{
				__ptr_ = tree_next(__ptr_);
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
				if (__ptr_ == nullptr_f)
				{
					__ptr_ = __end_;
					return *this;
				}
				__ptr_ = tree_prev(__ptr_);
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
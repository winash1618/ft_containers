#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

#include "reverse_iterator.hpp"
#include "utils.hpp"
namespace ft
{
	template <class _V, class Alloc>
	class set_iterator
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
			set_iterator() {}
			set_iterator(__node_pointer ptr): __ptr_(ptr) {}
			set_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			reference operator*() const
			{

				return __ptr_->_data;
			}
			pointer operator->() const
			{
				return &__ptr_->_data;
			}

			set_iterator& operator++()
			{
				__ptr_ = tree_next(__ptr_);
				return *this;
			}
			set_iterator operator++(int)
			{
				set_iterator __t(*this);
				++(*this);
				return __t;
			}

			set_iterator& operator--()
			{
				if (__ptr_ == nullptr_f)
				{
					__ptr_ = __end_;
					return *this;
				}
				__ptr_ = tree_prev(__ptr_);
				return *this;
			}
			set_iterator operator--(int)
			{
				
				set_iterator __t(*this);
				--(*this); 
				return __t;
			}
			
			friend bool operator==(const set_iterator& __x, const set_iterator& __y)
				{return __x.__ptr_ == __y.__ptr_;}
			friend bool operator!=(const set_iterator& __x, const set_iterator& __y)
				{return !(__x == __y);}
	};
}
#endif
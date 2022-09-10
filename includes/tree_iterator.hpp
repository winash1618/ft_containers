#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "map.hpp"
namespace ft
{
	// Returns:  true if __x is a left child of its parent, else false
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	inline
	bool
	__tree_is_left_child(_NodePtr __x)
	{
		if (__x != nullptr )
			if (__x->_parent != nullptr)
				return __x == __x->_parent->_left;
		return 0;
	}

	// Returns:  pointer to the left-most node under __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	inline
	_NodePtr
	__tree_min(_NodePtr __x)
	{
		while (__x->_left != nullptr)
			__x = __x->_left;
		return __x;
	}

	// Returns:  pointer to the right-most node under __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	inline
	_NodePtr
	__tree_max(_NodePtr __x)
	{
		while (__x->_right != nullptr)
			__x = __x->_right;
		return __x;
	}

	// Returns:  pointer to the next in-order node after __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	_NodePtr
	__tree_next(_NodePtr __x)
	{
		if (__x->_right != nullptr)
			return __tree_min(__x->_right);
		while (!__tree_is_left_child(__x) && __x->_parent)
		{
			__x = __x->_parent;
		}
		return __x->_parent;
	}

	// Returns:  pointer to the previous in-order node before __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	_NodePtr
	__tree_prev(_NodePtr __x)
	{
		if (__x->_left != nullptr)
			return __tree_max(__x->_left);
		while (__tree_is_left_child(__x))
			__x = __x->_parent;
		return __x->_parent;
	}

	template <class _V, class _NodePtr>
	class __tree_iterator
	{
		public:
			typedef _V value_type;
		private:
			typedef _NodePtr				__node_pointer;
			// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
			__node_pointer					__ptr_;
			__node_pointer					__end_;
		public:
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;

			__tree_iterator() {}
			__tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
			__tree_iterator(__node_pointer end, __node_pointer ptr):__end_(end), __ptr_(ptr) {}

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
				__ptr_ = __tree_next(__ptr_);
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
				if (__ptr_ == nullptr)
				{
					__ptr_ = __end_;
					return *this;
				}
				__ptr_ = __tree_prev(__ptr_);
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
	
}
#endif
#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "map.hpp"
namespace ft
{


	// Returns:  pointer to the next in-order node after __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	_NodePtr
	__tree_next(_NodePtr __x)
	{
		if (__x->_right != nullptr)
			return __tree_min(__x->_right);
		while (!__tree_is_left_child(__x))
			__x = __x->_parent;
		return __x->_parent;
	}

	// Returns:  pointer to the previous in-order node before __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	_NodePtr
	__tree_prev(_NodePtr __x)
	{
		if (__x->__left_ != nullptr)
			return __tree_max(__x->__left_);
		while (__tree_is_left_child(__x))
			__x = __x->__parent_;
		return __x->__parent_;
	}

	template <class _V, class _NodePtr>
	class __tree_iterator
	{
	private:
		typedef _NodePtr				__node_pointer;
		typedef _V value_type;
		// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
		__node_pointer					__ptr_;
	public:
		typedef value_type& reference;
		typedef value_type* pointer;
		typedef ft::bidirectional_iterator_tag	iterator_category;

		__tree_iterator() {}
		__tree_iterator(value_type val, __node_pointer ptr):  __ptr_(ptr) {}

		reference operator*() const
		{
			return __ptr_->_data;
		}
		pointer operator->() const
		{
			return &__ptr_->_data;
		}

		// __tree_iterator& operator++()
		// {
		// 	__ptr_ = __tree_next(__ptr_);
		// 	return *this;
		// }
		// __tree_iterator operator++(int)
		// {
		// 	__tree_iterator __t(*this);
		// 	++(*this);
		// 	return __t;
		// }

		// __tree_iterator& operator--()
		// {
		// 	__ptr_ = __tree_prev(__ptr_);
		// 	return *this;
		// }
		// __tree_iterator operator--(int)
		// {
		// 	__tree_iterator __t(*this);
		// 	--(*this); 
		// 	return __t;
		// }

		// friend bool operator==(const __tree_iterator& __x, const __tree_iterator& __y)
		// 	{return __x.__ptr_ == __y.__ptr_;}
		// friend bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y)
		// 	{return !(__x == __y);}

	};
	
}
#endif
#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{


	// Returns:  pointer to the next in-order node after __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	_NodePtr
	__tree_next(_NodePtr __x)
	{
		if (__x->__right_ != nullptr)
			return __tree_min(__x->__right_);
		while (!__tree_is_left_child(__x))
			__x = __x->__parent_;
		return __x->__parent_;
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

	template <class _NodePtr>
	class __tree_iterator
	{
	private:
		typedef _NodePtr				__node_pointer;
		__node_pointer					__ptr_;

	public:
		typedef ft::bidirectional_iterator_tag iterator_category;
		typedef _Tp                        value_type;

		__tree_iterator() {}
		__tree_iterator(__node_pointer ptr): __ptr_(ptr) {}

		reference operator*() const {return __ptr_->__value_;}
		pointer operator->() const {return &__ptr_->__value_;}

		__tree_iterator& operator++()
			{__ptr_ = __tree_next(__ptr_);
			return *this;}
		__tree_iterator operator++(int)
			{__tree_iterator __t(*this); ++(*this); return __t;}

		__tree_iterator& operator--()
			{__ptr_ = __tree_prev(__ptr_);
			return *this;}
		__tree_iterator operator--(int)
			{__tree_iterator __t(*this); --(*this); return __t;}

		friend bool operator==(const __tree_iterator& __x, const __tree_iterator& __y)
			{return __x.__ptr_ == __y.__ptr_;}
		friend bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y)
			{return !(__x == __y);}

	};
	
}
#endif
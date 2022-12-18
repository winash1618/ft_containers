#ifndef TREE_ITERATOR_TPP
# define TREE_ITERATOR_TPP

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>::__tree_iterator() {}

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>::~__tree_iterator() {}

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>::__tree_iterator(__node_pointer ptr): __ptr_(ptr) {}

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>::__tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>::__tree_iterator(__node_pointer end, __node_pointer ptr, __node_pointer nil):__ptr_(ptr), __end_(end), __nil_(nil) {}

template <class _V, class Alloc>
typename ft::__tree_iterator<_V, Alloc>::reference
ft::__tree_iterator<_V, Alloc>::operator*() const
{
	if (__ptr_ == NULL)
		return __nil_->_data;
	return __ptr_->_data;
}

template <class _V, class Alloc>
typename ft::__tree_iterator<_V, Alloc>::pointer
ft::__tree_iterator<_V, Alloc>::operator->() const
{
	if (__ptr_ == NULL)
		return &__nil_->_data;
	return &__ptr_->_data;
}

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>&
ft::__tree_iterator<_V, Alloc>::operator++()
{
	__node_pointer current_node = __ptr_;
	if (current_node == NULL || current_node == __end_)
		__ptr_ = __nil_;
	else if (current_node->_right != __nil_)
		__ptr_ = tree_min(current_node->_right, __nil_);
	else
	{
		while (!tree_is_left_child(current_node, __nil_) && current_node->_parent != __nil_)
			current_node = current_node->_parent;
		__ptr_ = current_node->_parent;
	}
	return *this;
}

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>
ft::__tree_iterator<_V, Alloc>::operator++(int)
{
	__tree_iterator __t(*this);
	++(*this);
	return __t;
}

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>&
ft::__tree_iterator<_V, Alloc>::operator--()
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

template <class _V, class Alloc>
ft::__tree_iterator<_V, Alloc>
ft::__tree_iterator<_V, Alloc>::operator--(int)
{
	__tree_iterator __t(*this);
	--(*this); 
	return __t;
}
#endif
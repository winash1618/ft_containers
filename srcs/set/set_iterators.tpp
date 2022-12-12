#ifndef SET_ITERATORS_TPP
# define SET_ITERATORS_TPP
template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::begin()
{
	if (_root == NULL)
		return iterator(_nil, _nil, _nil);
	return iterator(begin_right(), begin_left(), _nil);
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator
ft::set<T, Compare, Alloc>::begin() const
{
	if (_root == NULL)
		return const_iterator(_nil, _nil, _nil);
	return const_iterator(begin_right(), begin_left(), _nil);
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::end()
{
	node_pointer right = _root;
	if (right == NULL)
		return iterator(_nil, _nil, _nil);
	
	while (right != _nil && right->_right != _nil)
	{
		right = right->_right;
	}
	// std::cout << "right: " << right->_data << std::endl;
	return iterator(right, _nil, _nil);
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator
ft::set<T, Compare, Alloc>::end() const
{
	node_pointer right = _root;
	if (right == NULL)
		return const_iterator(_nil, _nil, _nil);
	while (right != _nil && right->_right != _nil)
	{
		right = right->_right;
	}
	return const_iterator(right, _nil, _nil);
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator
ft::set<T, Compare, Alloc>::rbegin()
{
	return reverse_iterator(this->end());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::reverse_iterator
ft::set<T, Compare, Alloc>::rend()
{
	return reverse_iterator(this->begin());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator
ft::set<T, Compare, Alloc>::rbegin() const
{
	return const_reverse_iterator(this->end());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_reverse_iterator
ft::set<T, Compare, Alloc>::rend() const
{
	return const_reverse_iterator(this->begin());
};
#endif

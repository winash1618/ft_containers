#ifndef SET_ITERATORS_TPP
# define SET_ITERATORS_TPP
template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::begin()
{
	return iterator(begin_right(), begin_left());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator
ft::set<T, Compare, Alloc>::begin() const
{
	return const_iterator(begin_right(), begin_left());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::end()
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return iterator(right, nullptr_f);
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator
ft::set<T, Compare, Alloc>::end() const
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return const_iterator(right, nullptr_f);
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

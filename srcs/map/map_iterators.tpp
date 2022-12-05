#ifndef MAP_ITERATORS_TPP
# define MAP_ITERATORS_TPP
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::begin()
{
	return iterator(begin_right(), begin_left());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::begin() const
{
	return const_iterator(begin_right(), begin_left());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::end()
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return iterator(right, nullptr_f,_nil);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::end() const
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return const_iterator(right, nullptr_f, _nil);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator
ft::map<Key, T, Compare, Alloc>::rbegin()
{
	return reverse_iterator(this->end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator
ft::map<Key, T, Compare, Alloc>::rend()
{
	return reverse_iterator(this->begin());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator
ft::map<Key, T, Compare, Alloc>::rbegin() const
{
	return const_reverse_iterator(this->end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator
ft::map<Key, T, Compare, Alloc>::rend() const
{
	return const_reverse_iterator(this->begin());
};
#endif
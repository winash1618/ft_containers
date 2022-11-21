#ifndef MAP_INIT_TPP
# define MAP_INIT_TPP

template <class Key, class T, class Compare, class Alloc>
bool
ft::map<Key, T, Compare, Alloc>::empty() const
{
	if (this->_size == 0)
		return true;
	return false;
}

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
#endif
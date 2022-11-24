#ifndef MAP_CAPACITY_TPP
# define MAP_CAPACITY_TPP

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type
ft::map<Key, T, Compare, Alloc>::size() const
{
	return (this->_size);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type
ft::map<Key, T, Compare, Alloc>::max_size() const
{
	return (this->n_alloc.max_size());
}
template <class Key, class T, class Compare, class Alloc>
bool
ft::map<Key, T, Compare, Alloc>::empty() const
{
	if (this->_size == 0)
		return true;
	return false;
}
#endif
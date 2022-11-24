#ifndef MAP_OBSERVERS_TPP
# define MAP_OBSERVERS_TPP
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::key_compare
ft::map<Key, T, Compare, Alloc>::key_comp() const
{
	return (this->_comp);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::value_compare
ft::map<Key, T, Compare, Alloc>::value_comp() const
{
	return ft::map<Key, T, Compare, Alloc>::value_compare(this->_comp);
}
#endif
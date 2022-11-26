#ifndef SET_OBSERVERS_TPP
# define SET_OBSERVERS_TPP
template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::key_compare
ft::set<T, Compare, Alloc>::key_comp() const
{
	return (this->_comp);
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::value_compare
ft::set<T, Compare, Alloc>::value_comp() const
{
	return ft::set<T, Compare, Alloc>::value_compare(this->_comp);
}
#endif
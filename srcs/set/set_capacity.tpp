#ifndef SET_CAPACITY_TPP
# define SET_CAPACITY_TPP
template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type
ft::set<T, Compare, Alloc>::size() const
{
	return (_size);
}

template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type
ft::set<T, Compare, Alloc>::max_size() const
{
	return (n_alloc.max_size());
}

template < class T, class Compare, class Alloc>
bool
ft::set<T, Compare, Alloc>::empty() const
{
	if (_size == 0)
		return true;
	return false;
}
#endif
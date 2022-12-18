#ifndef MAP_ITER_NON_MEMBERS_TPP
# define MAP_ITER_NON_MEMBERS_TPP


template <class _V, class Alloc>
bool operator==(const ft::__tree_iterator<_V, Alloc>& __x, const ft::__tree_iterator<_V, Alloc>& __y)
{
	return __x.__ptr_ == __y.__ptr_;
}

template <class _V, class Alloc>
bool operator!=(const ft::__tree_iterator<_V, Alloc>& __x, const ft::__tree_iterator<_V, Alloc>& __y)
{
	return !(__x == __y);
}

template <class _V1, class Alloc1>
bool operator==(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y)
{
	return __x.__ptr_ == __y.__ptr_;
}

template <class _V1, class Alloc1>
bool operator!=(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y)
{
	return !(__x == __y);
}
template <class _V1, class Alloc1>
bool operator==(const ft::__tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y)
{
	return __x.__ptr_ == __y.__ptr_;
}

template <class _V1, class Alloc1>
bool operator!=(const ft::__tree_iterator<_V1, Alloc1>& __x, const ft::__const_tree_iterator<_V1, Alloc1>& __y)
{
	return !(__x == __y);
}
template <class _V1, class Alloc1>
bool operator==(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__tree_iterator<_V1, Alloc1>& __y)
{
	return __x.__ptr_ == __y.__ptr_;
}

template <class _V1, class Alloc1>
bool operator!=(const ft::__const_tree_iterator<_V1, Alloc1>& __x, const ft::__tree_iterator<_V1, Alloc1>& __y)
{
	return !(__x == __y);
}
#endif
#ifndef REVERSE_NON_MEMBERS_TPP
# define REVERSE_NON_MEMBERS_TPP

template <class _Iter1, class _Iter2>
bool operator==(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
{
	return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
bool operator<(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
{
	return __x.base() > __y.base();
}

template <class _Iter1, class _Iter2>
bool operator!=(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
{
	return !(__x.base() == __y.base());
}

template <class _Iter1, class _Iter2>
bool operator>(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
{
	return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
bool operator>=(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
{
	return __x.base() <= __y.base();
}

template <class _Iter1, class _Iter2>
bool operator<=(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y)
{
	return __x.base() >= __y.base();
}

template <class _Iter1, class _Iter2>
typename ft::reverse_iterator<_Iter1>::difference_type operator-(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y) 
{
	return __y.base() - __x.base();
}

template <class _Iter1, class _Iter2>
typename ft::reverse_iterator<_Iter1>::difference_type operator+(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y) 
{
	return __x.base() + __y.base();
}

template <class _Iter1, class _Iter2>
bool operator==(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y)
{
	return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
bool operator<(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y)
{
	return __x.base() > __y.base();
}

template <class _Iter1, class _Iter2>
bool operator!=(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y)
{
	return !(__x.base() == __y.base());
}

template <class _Iter1, class _Iter2>
bool operator>(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y)
{
	return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
bool operator>=(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y)
{
	return __x.base() <= __y.base();
}

template <class _Iter1, class _Iter2>
bool operator<=(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y)
{
	return __x.base() >= __y.base();
}

template <class _Iter1, class _Iter2>
typename ft::reverse_const_iterator<_Iter1>::difference_type operator-(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y) 
{
	return __y.base() - __x.base();
}

template <class _Iter1, class _Iter2>
typename ft::reverse_const_iterator<_Iter1>::difference_type operator+(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y) 
{
	return __x.base() + __y.base();
}
#endif
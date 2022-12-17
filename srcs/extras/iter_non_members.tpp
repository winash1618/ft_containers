#ifndef ITER_NON_MEMBERS_TPP
# define ITER_NON_MEMBERS_TPP

template <class _Iter1, class _Iter2>
bool operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
{
	return x.base() == y.base();
}

template <class _Iter1, class _Iter2>
bool operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
{
	return !(x == y);
}

template <class _Iter1, class _Iter2>
bool operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
{
	return x.base() < y.base();
}

template <class _Iter1, class _Iter2>
bool operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
{
	return y < x;
}

template <class _Iter1, class _Iter2>
bool operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
{
	return !(x.base() < y.base());
}

template <class _Iter1, class _Iter2>
bool operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
{
	return !(y.base() < x.base());
}

template <class _Iter1>
bool operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
{
	return x.base() == y.base();
}

template <class _Iter1>
bool operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
{
	return !(x == y);
}

template <class _Iter1>
bool operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
{
	return (x.base() < y.base());
}

template <class _Iter1>
bool operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
{
	return (y < x);
}

template <class _Iter1>
bool operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
{
	return !(x.base() < y.base());
}

template <class _Iter1>
bool operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
{
	return !(y.base() < x.base());
}

template <class _Iter1, class _Iter2>
typename ft::iterator<_Iter1>::difference_type
operator-(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
{
	return x.base() - y.base();
}

template <class _Iterator>
_Iterator operator+(_Iterator n, std::size_t x) 
{
	n += x;
	return n;
}

template <class _Iterator>
_Iterator
operator+(std::size_t x, _Iterator n) 
{
	n += x;
	return n;
}
template <class _Iterator>
_Iterator operator-(_Iterator n, std::size_t x) 
{
	n -= x;
	return n;
}
#endif
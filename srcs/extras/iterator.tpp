#ifndef ITERATOR_TPP
# define ITERATOR_TPP

template<class _Iter>
ft::iterator<_Iter>::iterator() {}

template<class _Iter>
ft::iterator<_Iter>::~iterator() {}

template<class _Iter>
ft::iterator<_Iter>::iterator(typename ft::iterator<_Iter>::iterator_type iter) : __i( iter ) {}

template<class _Iter>
ft::iterator<_Iter>::iterator(const ft::iterator<_Iter>& x) : __i(x.base()) {}

template<class _Iter>
ft::iterator<_Iter>&
ft::iterator<_Iter>::operator=(const ft::iterator<_Iter>& x)
{
	if (this != &x)
		__i = x.base();
	return *this;
}

template<class _Iter>
template<class X>
ft::iterator<_Iter>::iterator(const iterator<X>& u):__i(u.base()) {}

template<class _Iter>
typename ft::iterator<_Iter>::reference
ft::iterator<_Iter>::operator*() const 
{
	return *__i;
}

template<class _Iter>
typename ft::iterator<_Iter>::pointer
ft::iterator<_Iter>::operator->() const
{
	return __i;
}

template<class _Iter>
ft::iterator<_Iter>&
ft::iterator<_Iter>::operator++()
{
	++__i;
	return *this;
}

template<class _Iter>
ft::iterator<_Iter>
ft::iterator<_Iter>::operator++(int)
{
	iterator __tmp(*this);
	++(*this);
	return __tmp;
}

template<class _Iter>
ft::iterator<_Iter>&
ft::iterator<_Iter>::operator--()
{
	--__i;
	return *this;
}

template<class _Iter>
ft::iterator<_Iter>
ft::iterator<_Iter>::operator--(int)
{
	iterator __tmp(*this);
	--(*this);
	return __tmp;
}

template<class _Iter>
ft::iterator<_Iter>
ft::iterator<_Iter>::operator+ (typename ft::iterator<_Iter>::difference_type __n) const
{
	iterator __w(*this);
	__w += __n;
	return __w;
}

template<class _Iter>
ft::iterator<_Iter>&
ft::iterator<_Iter>::operator+=(typename ft::iterator<_Iter>::difference_type __n)
{
	__i += __n;
	return *this;
}

template<class _Iter>
ft::iterator<_Iter>
ft::iterator<_Iter>::operator- (typename ft::iterator<_Iter>::difference_type __n) const
{
	return *this + (-__n);
}

template<class _Iter>
ft::iterator<_Iter>&
ft::iterator<_Iter>::operator-=(typename ft::iterator<_Iter>::difference_type __n)
{
	*this += -__n;
	return *this;
}

template<class _Iter>
typename ft::iterator<_Iter>::reference
ft::iterator<_Iter>::operator[](typename ft::iterator<_Iter>::difference_type __n) const
{
	return __i[__n];
}

template<class _Iter>
typename ft::iterator<_Iter>::iterator_type ft::iterator<_Iter>::base() const
{
	return __i;
}
#endif
#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(): _iter(), current(){}

template <class Iterator>
ft::reverse_iterator<Iterator>::~reverse_iterator(){}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(Iterator x) : _iter(x), current(x) {}

template <class Iterator>
template <class U> 
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<U>& u):_iter(u.base()), current(u.base()) {}

template <class Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator& x)
{
	*this = x;
}

template <class Iterator>
ft::reverse_iterator<Iterator>&
ft::reverse_iterator<Iterator>::operator=(const reverse_iterator<Iterator>& __u)
{ 
	if (this != &__u) 
	{
		_iter = current = __u.base();
	}
	return *this;
}

template <class Iterator>
Iterator ft::reverse_iterator<Iterator>::base() const
{
	return current;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference
ft::reverse_iterator<Iterator>::operator*() const
{
	Iterator tmp = current;
	return *--tmp;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::pointer
ft::reverse_iterator<Iterator>::operator->() const
{
	return &(operator*());
}

template <class Iterator>
ft::reverse_iterator<Iterator>&
ft::reverse_iterator<Iterator>::operator++()
{
	--current; return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>
ft::reverse_iterator<Iterator>::operator++(int)
{
	reverse_iterator tmp(*this); --current; return tmp;
}

template <class Iterator>
ft::reverse_iterator<Iterator>&
ft::reverse_iterator<Iterator>::operator--()
{
	++current; return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>
ft::reverse_iterator<Iterator>::operator--(int)
{
	reverse_iterator tmp(*this); ++current; return tmp;
}

template <class Iterator>
ft::reverse_iterator<Iterator>
ft::reverse_iterator<Iterator>::operator+ (typename ft::reverse_iterator<Iterator>::difference_type n) const
{
	return reverse_iterator(current - n);
}

template <class Iterator>
ft::reverse_iterator<Iterator>&
ft::reverse_iterator<Iterator>::operator+=(typename ft::reverse_iterator<Iterator>::difference_type n)
{
	current -= n; return *this;
}

template <class Iterator>
ft::reverse_iterator<Iterator>
ft::reverse_iterator<Iterator>::operator- (typename ft::reverse_iterator<Iterator>::difference_type n) const
{
	return reverse_iterator(current + n);
}

template <class Iterator>
ft::reverse_iterator<Iterator>&
ft::reverse_iterator<Iterator>::operator-=(typename ft::reverse_iterator<Iterator>::difference_type n)
{
	current += n; return *this;
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::reference
ft::reverse_iterator<Iterator>::operator[](typename ft::reverse_iterator<Iterator>::difference_type n) const
{
	return *(*this + n);
}
#endif
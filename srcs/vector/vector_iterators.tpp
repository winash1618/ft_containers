#ifndef VECTOR_ITERATORS_TPP
# define VECTOR_ITERATORS_TPP
// Iterators
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::begin()
{
	return iterator(_vec);
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_iterator
ft::vector<Tp, Allocator>::begin() const
{
	return const_iterator(_vec);
}


template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::end()
{
	return iterator(_vec + size());
}


template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_iterator
ft::vector<Tp, Allocator>::end() const
{
	return const_iterator(_vec + size());
}

//reverse Iterators
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reverse_iterator
ft::vector<Tp, Allocator>::rbegin()
{
	return reverse_iterator(this->end());
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reverse_iterator
ft::vector<Tp, Allocator>::rbegin() const
{
	return const_reverse_iterator(this->end());
}


template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reverse_iterator
ft::vector<Tp, Allocator>::rend()
{
	return reverse_iterator(this->begin());
}
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reverse_iterator
ft::vector<Tp, Allocator>::rend() const
{
	return const_reverse_iterator(this->begin());
}

#endif
#ifndef VECTOR_CAPACITY_TPP
# define VECTOR_CAPACITY_TPP

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::size_type 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::size_type
ft::vector<Tp, Allocator>::size() const
{
	return (this->_size);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::size_type 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::size_type
ft::vector<Tp, Allocator>::max_size() const
{
	return (_alloc.max_size());
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param n 
 * @param val 
 */
template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::resize
(
	typename ft::vector<Tp, Allocator>::size_type n,
	typename ft::vector<Tp, Allocator>::value_type val
)
{
	if (n > max_size())
		throw std::length_error("vector");
	if (n < _size)
	{
		for(size_type index = n; index < _size; index++)
			_alloc.destroy(_vec + index);
		_size = n;
	}
	else if (n >= _size && n < _cap )
	{
		for(size_type index = _size; index < n; index++)
			_alloc.construct(_vec + index, val);
		_size = n;
	}
	else
	{
		if (n > max_size())
			throw std::length_error("Capacity allocated exceeds max_size()");
		temp = t_alloc.allocate(n);
		for (size_type index = 0; index < _size; ++index)
			t_alloc.construct(temp + index, _vec[index]);
		for (size_type index = _size; index < n; ++index)
			t_alloc.construct(temp + index, val);
		for (size_type index = 0; index < _size; ++index)
			_alloc.destroy(_vec + index);
		_alloc.deallocate(_vec, _cap);
		_alloc = t_alloc;
		_vec = temp;
		_cap = recommend(n);
		_size = n;
	}
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::size_type 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::size_type
ft::vector<Tp, Allocator>::capacity() const
{
	return (this->_cap);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return true 
 * @return false 
 */
template<class Tp, class Allocator>
bool
ft::vector<Tp, Allocator>::empty() const
{
	return (_size == 0);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param n 
 */
template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::reserve(typename ft::vector<Tp, Allocator>::size_type n)
{
	if (n > max_size())
		throw std::length_error("Capacity allocated exceeds max_size()");
	else if (n > _cap)
	{
		pointer t_vec = t_alloc.allocate(n);
		for (_index = 0; _index < _size; ++_index)
			t_alloc.construct(t_vec + _index, _vec[_index]);
		for (_index = 0; _index < _size; ++_index)
			_alloc.destroy(_vec + _index);
		_alloc.deallocate(_vec, _cap);
		_alloc = t_alloc;
		_vec = t_vec;
		_cap = n;
	}
}

#endif
#ifndef VECTOR_MODIFIERS_TPP
# define VECTOR_MODIFIERS_TPP

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @tparam InputIterator 
 * @param first 
 * @param last 
 */
template<class Tp, class Allocator>
template <class InputIterator>
void
ft::vector<Tp, Allocator>::assign
(
	InputIterator first,
	InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{
	ft::check_valid(first, last);
	size_type size = 0;
	for (InputIterator it = first; it != last; it++)
	{
		++size;
	}
	allocate(size);
	_size = 0;
	for (size_type index = 0; index < size; ++index)
	{
		_alloc.construct(_vec + index, *(first++));
		++_size;
	}
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
ft::vector<Tp, Allocator>::assign
(
	typename ft::vector<Tp, Allocator>::size_type n,
	const typename ft::vector<Tp, Allocator>::value_type& val
)
{
	allocate(n);
	_size = 0;
	for (size_type index = 0; index < n; ++index)
	{
		_alloc.construct(_vec + index, val);
		++_size;
	}
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param val 
 */
template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::push_back
(const typename ft::vector<Tp, Allocator>::value_type& val)
{
	if (!_cap)
		reserve(1);
	if (_size + 1 > _cap)
		reserve(_cap * 2);
	_alloc.construct(_vec + _size, val);
	_size += 1;
}

template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::pop_back()
{
	if (_size  == 0)
		throw std::out_of_range("can");
	_alloc.destroy(&_vec[_size-- - 1]);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param position 
 * @param val 
 * @return ft::vector<Tp, Allocator>::iterator 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::insert
(
	typename ft::vector<Tp, Allocator>::iterator position,
	const typename ft::vector<Tp, Allocator>::value_type& val
)
{
	if (_size + 1 <= _cap)
	{
		_alloc.construct(_vec + _size, val);
		// _cap = _size + 1;
		_size++;
		for (iterator it = position; it < end(); it++)
		{
			value_type temp1 = back();
			*(end() - 1) = *it;
			*it = temp1;
		}
	}
	else
	{
		size_type i = position - begin();
		temp = t_alloc.allocate(_size * 2, 0);
		for (size_type index1 = 0; index1 < _size; ++index1)
			t_alloc.construct(temp + index1, _vec[index1]);
		t_alloc.construct(temp + _size, val);
		for (size_type index1 = 0; index1 < _size; ++index1)
			_alloc.destroy(_vec + index1);
		_alloc.deallocate(_vec, _cap);
		_alloc = t_alloc;
		_vec = temp;
		_cap = _size * 2;
		_size++;
		position = begin() + i;
		for (iterator it = position; it < end(); it++)
		{
			value_type temp1 = back();
			*(end() - 1) = *it;
			*it = temp1;
		}
	}
	return (position);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param position 
 * @param n 
 * @param val 
 */
template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::insert
(
	typename ft::vector<Tp, Allocator>::iterator position,
	typename ft::vector<Tp, Allocator>::size_type n, 
	const typename ft::vector<Tp, Allocator>::value_type& val
)
{
	size_type t_cap;
	if (_size + n > _cap)
	{
		temp = t_alloc.allocate(recommend(_size + n), 0);
		t_cap = recommend(_size + n);
	}
	else
	{
		temp = t_alloc.allocate(_cap, 0);
		t_cap = _cap;
	}
	size_type index = 0;
	size_type t_size = 0;
	for (iterator it = begin(); it != position; it++)
	{
		t_alloc.construct(temp + index, *it);
		t_size++;
		index++;
	}
	for (index = 0; index < n; index++)
		t_alloc.construct(temp + t_size + index, val);
	t_size = t_size + index;
	index = 0;
	for (iterator it = position; it != end(); it++)
	{
		t_alloc.construct(temp + t_size + index, *it);
		index++;
	}
	for (size_type index1 = 0; index1 < _size; ++index1)
		_alloc.destroy(_vec + index1);
	_alloc.deallocate(_vec, _cap);
	t_size = t_size + index;
	_alloc = t_alloc;
	_vec = temp;
	_size = t_size;
	_cap = t_cap;
}

/**
 * @brief Insert
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @tparam InputIterator 
 * @param position 
 * @param first 
 * @param last 
 */
template<class Tp, class Allocator>
template <class InputIterator>
void
ft::vector<Tp, Allocator>::insert
(
	typename ft::vector<Tp, Allocator>::iterator position, 
	InputIterator first, 
	InputIterator last, 
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*
)
{
	ft::check_valid(first, last);
	size_type t_cap;
	size_type size = 0;
	for (InputIterator it = first; it != last; it++)
	{
		++size;
	}
	// iterator iter = static_cast<iterator>(first);
	if (_size + size > _cap)
	{
		temp = t_alloc.allocate(recommend(_size + size), 0);
		t_cap = recommend(_size + size);
	}
	else
	{
		temp = t_alloc.allocate(_cap, 0);
		t_cap = _cap;
	}
	size_type index = 0;
	size_type t_size = 0;
	for (iterator it = begin(); it != position; it++)
	{
		t_alloc.construct(temp + index, *it);
		t_size++;
		index++;
	}
	index = 0;
	for (InputIterator it = first; it != last; it++)
	{
		t_alloc.construct(temp + t_size + index,*it);
		index++;
	}
	t_size = t_size + index;
	index = 0;
	for (iterator it = position; it != end(); it++)
	{
		t_alloc.construct(temp + t_size + index, *it);
		index++;
	}
	for (size_type index1 = 0; index1 < _size; ++index1)
		_alloc.destroy(_vec + index1);
	_alloc.deallocate(_vec, _cap);
	t_size = t_size + index;
	_alloc = t_alloc;
	_vec = temp;
	_size = t_size;
	_cap = t_cap;
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::erase(typename ft::vector<Tp, Allocator>::iterator position)
{
	_alloc.destroy(_vec + (position - begin()));
	for(size_type index = position - begin(); index < _size - 1; index++)
		_alloc.construct(_vec + index, *(_vec + index + 1));
	_size--;
	return (position);
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::erase
(
	typename ft::vector<Tp, Allocator>::iterator first,
	typename ft::vector<Tp, Allocator>::iterator last
)
{
	size_type siz = first - begin();
	size_type len = end() - begin();
	if (len > 0)
	{
		size_type index = 0;
		iterator t_end = end();
		for (iterator it = first; it != last; it++)
		{
			_alloc.destroy(_vec + siz + index);
			index++;
			_size--;
		}
		index = 0;
		for (iterator it = first; it != last; it++)
		{
			if (last + index == t_end)
				break;
			_alloc.construct(_vec  + siz + index, *(last + index));
			_alloc.destroy(_vec + siz + index);
			index++;
		}
		if (last + index != t_end)
		{
			while (index < len)
			{
				if (last + index == t_end)
				break;
				_alloc.construct(_vec  + siz + index, *(last + index));
				_alloc.destroy(_vec + siz + index);
				index++;
			}
		}
	}
	return first;
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::swap (ft::vector<Tp, Allocator>& x)
{
	temp = x._vec;
	t_alloc = x._alloc;
	size_type t_size = x._size;
	size_type t_cap = x._cap;
	x._vec = _vec;
	x._alloc = _alloc;
	x._size = _size;
	x._cap = _cap;
	_vec = temp;
	_alloc = t_alloc;
	_size = t_size;
	_cap = t_cap;
}

template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::clear()
{
	destruct(_size);
}

#endif
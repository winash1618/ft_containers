/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:13:44 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/11/12 12:46:35 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::vector
(
	const typename ft::vector<Tp,
	Allocator>::allocator_type& alloc
):_vec(ft::nullptr_f), _alloc(alloc), _cap(0), _size(0) {}
// fill constructor

template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::vector
(
	typename ft::vector<Tp, Allocator>::size_type len,
	const typename ft::vector<Tp, Allocator>::value_type& val,
	const typename ft::vector<Tp, Allocator>::allocator_type& alloc
):_alloc(alloc), _cap(0)
{
	allocate(len);
	construct_at_end(len, val);
}

// range constructor
template<class Tp, class Allocator>
template <class InputIterator>
ft::vector<Tp, Allocator>::vector
(
	InputIterator first,
	InputIterator last,
	const ft::vector<Tp, Allocator>::allocator_type& alloc,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*
):_alloc(alloc), _cap(0), _size(0)
{
	ft::check_valid(first, last);
	for (InputIterator it = first; it != last; it++)
	{
		++_size;
	}
	_vec = _alloc.allocate(_size);
	_cap = _size;
	
	for (size_type index = 0; index < _size; ++index)
	{
		_alloc.construct(_vec + index, *(first++));
	}
}

// Copy constructor
template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::vector (const ft::vector<Tp, Allocator>& x) :  _cap(0), _size(0)
{
	_alloc = x.get_allocator();
	copy(x);
}

template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::~vector ()
{
	deallocate_and_destruct(_cap, _size);
}
// Assignment operator
template<class Tp, class Allocator>
ft::vector<Tp, Allocator>& ft::vector<Tp, Allocator>::operator=(const ft::vector<Tp, Allocator>& x)
{
	if (this == &x) 
	{
		return *this;
	}
	destruct(size());
	
	if (x._vec)
	{
		this->_alloc = x.get_allocator();
		if (x.size() > this->capacity())
		{
			reallocate(this->capacity(), x.size());
		}
		uninitialized_alloc_copy(x);
	}
	else
	{
		_vec = nullptr_f;
		_size = 0;
	}
	return *this;
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::value_type*
ft::vector<Tp, Allocator>::data()
{
	return (_vec);
}

template<class Tp, class Allocator>
const typename ft::vector<Tp, Allocator>::value_type*
ft::vector<Tp, Allocator>:: data() const
{
	return (_vec);
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::allocator_type
ft::vector<Tp, Allocator>::get_allocator() const
{
	return (this->_alloc);
}

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

// Capacity based functions
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::size_type
ft::vector<Tp, Allocator>::size() const
{
	return (this->_size);
}


template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::size_type
ft::vector<Tp, Allocator>::capacity() const
{
	return (this->_cap);
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::size_type
ft::vector<Tp, Allocator>::max_size() const
{
	return (_alloc.max_size());
}

template<class Tp, class Allocator>
bool
ft::vector<Tp, Allocator>::empty() const
{
	return (_size == 0);
}

// Modifiers functions
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::operator[](typename ft::vector<Tp, Allocator>::size_type index)
{
	assert(index < size() && "Index out of range1");
	return _vec[index]; 
}
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::operator[](typename ft::vector<Tp, Allocator>::size_type index) const
{
	assert(index < size() && "Index out of range2");
	return _vec[index]; 
}
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::at(typename ft::vector<Tp, Allocator>::size_type n)
{
	if (n < size() && n >= 0)
		return (_vec[n]);
	else
		throw std::out_of_range("Index out of range");
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::at(typename ft::vector<Tp, Allocator>::size_type n) const
{
	return (n < size() ? _vec[n] : throw std::out_of_range("Index out of range"));
}

template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::clear()
{
	destruct(_size);
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
void
ft::vector<Tp, Allocator>::push_back(const typename ft::vector<Tp, Allocator>::value_type& val)
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

template<class Tp, class Allocator>
template <class InputIterator>
void
ft::vector<Tp, Allocator>::assign (InputIterator first, InputIterator last , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
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

template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::assign (typename ft::vector<Tp, Allocator>::size_type n, const typename ft::vector<Tp, Allocator>::value_type& val)
{
	allocate(n);
	_size = 0;
	for (size_type index = 0; index < n; ++index)
	{
		_alloc.construct(_vec + index, val);
		++_size;
	}
}

template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::resize (typename ft::vector<Tp, Allocator>::size_type n, typename ft::vector<Tp, Allocator>::value_type val)
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

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::insert(typename ft::vector<Tp, Allocator>::iterator position, const typename ft::vector<Tp, Allocator>::value_type& val) // single element insert
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

template<class Tp, class Allocator>
void
ft::vector<Tp, Allocator>::insert
(
	typename ft::vector<Tp, Allocator>::iterator position,
	typename ft::vector<Tp, Allocator>::size_type n, 
	const typename ft::vector<Tp, Allocator>::value_type& val
) // fill n index starting from iterator position
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
void
ft::vector<Tp, Allocator>::pop_back()
{
	if (_size  == 0)
		throw std::out_of_range("can");
	_alloc.destroy(&_vec[_size-- - 1]);
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::front()
{
	assert(!empty() && "front() called for empty vector");
	return *this->begin();
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::front() const
{
	assert(!empty() && "front() called for empty vector");
	return *this->begin();
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::back()
{
	assert(!empty() && "back() called for empty vector");
	return *(_vec + size() - 1);
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::back() const
{
	assert(!empty() && "back() called for empty vector");
	return *(_vec + size() - 1);
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
void ft::vector<Tp, Allocator>::print(void)
{
	size_type i = 0;
	std::cout << "Printing starts" << std::endl;
	while (i < _size)
	{
		std::cout << i << " th element = " << _vec[i] << std::endl;
		i++;
	}
	std::cout << "Printing ends" << std::endl;
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::allocate(typename ft::vector<Tp, Allocator>::size_type capacity)
{
	if (capacity > max_size())
		throw std::length_error("new size to allocate exceeds max_size()");
	_cap = capacity;
	_vec = _alloc.allocate(capacity, 0);
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::deallocate(std::size_t capacity)
{
	_alloc.deallocate(_vec, capacity);
	_cap = 0;
	_size = 0;
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::reallocate(std::size_t old_cap, std::size_t new_cap) {
	deallocate(old_cap);
	allocate(new_cap);
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::construct(std::size_t size, const typename ft::vector<Tp, Allocator>::value_type& value)
{
	_size = size;
	for (std::size_t index = 0; index < size; ++index)
		_alloc.construct(_vec + index, value);
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::construct_at_end(typename ft::vector<Tp, Allocator>::size_type size, const typename ft::vector<Tp, Allocator>::value_type& value)
{
	_size = size;
	for (std::size_t index = 0; index < size; ++index)
		_alloc.construct(_vec + index, value);
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::destruct(std::size_t size)
{
	for (std::size_t index = 0; index < size; ++index)
		_alloc.destroy(_vec + index);
	_size = 0;
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::allocate_and_copy_construct(std::size_t capacity, std::size_t size, const typename ft::vector<Tp, Allocator>::value_type& value)
{
	allocate(capacity);
	construct(size, value);
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::deallocate_and_destruct(std::size_t capacity, std::size_t size)
{
	destruct(size);
	deallocate(capacity);
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::uninitialized_alloc_copy(const ft::vector<Tp, Allocator>& other)
{
	_size = other.size();
	for (size_type index=0; index < _size; ++index)
		this->_alloc.construct(this->_vec + index, *(other._vec + index));
}

template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::copy(const ft::vector<Tp, Allocator>& other)
{
	if (other._vec)
	{
		allocate(other._size);
		uninitialized_alloc_copy(other);
	}
	else
		_vec = nullptr_f;
}

template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::size_type ft::vector<Tp, Allocator>::recommend(typename ft::vector<Tp, Allocator>::size_type new_size) const
{
	const typename ft::vector<Tp, Allocator>::size_type ms = max_size();
	if (new_size > ms)
		throw std::length_error("new size to allocate exceeds max_size()");
	const typename ft::vector<Tp, Allocator>::size_type cap = capacity();
	if (cap >= ms / 2)
		return ms;
	return std::max<typename ft::vector<Tp, Allocator>::size_type>(2*cap, new_size);
}
#endif
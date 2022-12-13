/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:31:35 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/13 18:54:08 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_INIT_TPP
# define VECTOR_INIT_TPP

/**
 * @brief Construct a new ft::vector<Tp, Allocator>::vector object
 * Constructs an empty container with the given allocator alloc.
 * @tparam Tp 
 * @tparam Allocator
 * @param alloc allocator to use for all memory allocations of this container
 */
template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::vector
(
	const typename ft::vector<Tp, Allocator>::allocator_type& alloc
) : _vec(ft::nullptr_f), _alloc(alloc), _cap(0), _size(0)
{
}

/**
 * @brief Construct a new ft::vector<Tp, Allocator>::vector object
 * Constructs the container with len copies of elements with value val.
 * @tparam Tp 
 * @tparam Allocator 
 * @param len the size of the container
 * @param val the value to initialize elements of the container with
 * @param alloc allocator to use for all memory allocations of this container
 */
template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::vector
(
	typename ft::vector<Tp, Allocator>::size_type len,
	const typename ft::vector<Tp, Allocator>::value_type& val,
	const typename ft::vector<Tp, Allocator>::allocator_type& alloc
) : _alloc(alloc), _cap(0)
{
	allocate(len);
	construct_at_end(len, val);
}

/**
 * @brief Construct a new ft::vector<Tp, Allocator>::vector object
 * Constructs a container with as many elements as the range [first,last), 
 * with each element constructed from its corresponding element in that range, 
 * in the same order.
 * @tparam Tp 
 * @tparam Allocator 
 * @tparam InputIterator 
 * @param first InputIterator element
 * @param last InputIterator element
 * @param alloc allocator to use for all memory allocations of this container
 */
template<class Tp, class Allocator>
template <class InputIterator>
ft::vector<Tp, Allocator>::vector
(
	InputIterator first,
	InputIterator last,
	const ft::vector<Tp, Allocator>::allocator_type& alloc,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*
) : _alloc(alloc), _cap(0), _size(0)
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

/**
 * @brief Construct a new ft::vector<Tp, Allocator>::vector object
 * Copy constructor. Constructs a container with a copy of each of the elements in x, in the same order.
 * @tparam Tp 
 * @tparam Allocator 
 * @param x another container to be used as source to initialize the elements of the container with
 */
template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::vector (const ft::vector<Tp, Allocator>& x) :  _cap(0), _size(0)
{
	_alloc = x.get_allocator();
	copy(x);
}

/**
 * @brief Destroy the ft::vector<Tp, Allocator>::vector object
 * Destructs the vector. The destructors of the elements are called and the used storage is deallocated. 
 * Note, that if the elements are pointers, the pointed-to objects are not destroyed.
 * @tparam Tp 
 * @tparam Allocator 
 */
template<class Tp, class Allocator>
ft::vector<Tp, Allocator>::~vector()
{
	deallocate_and_destruct(_cap, _size);
}

/**
 * @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param x another container to use as data source
 * @return ft::vector<Tp, Allocator>& equivalent to *this
 */
template<class Tp, class Allocator>
ft::vector<Tp, Allocator>&
ft::vector<Tp, Allocator>::operator=(const ft::vector<Tp, Allocator>& x)
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
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:43:14 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:43:15 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTILS_TPP
# define VECTOR_UTILS_TPP

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::allocator_type 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::allocator_type
ft::vector<Tp, Allocator>::get_allocator() const
{
	return (this->_alloc);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 */
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

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param capacity 
 */
template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::allocate(typename ft::vector<Tp, Allocator>::size_type capacity)
{
	if (capacity > max_size())
		throw std::length_error("new size to allocate exceeds max_size()");
	_cap = capacity;
	_vec = _alloc.allocate(capacity, 0);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param capacity 
 */
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

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param size 
 * @param value 
 */
template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::construct(std::size_t size, const typename ft::vector<Tp, Allocator>::value_type& value)
{
	_size = size;
	for (std::size_t index = 0; index < size; ++index)
		_alloc.construct(_vec + index, value);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param size 
 * @param value 
 */
template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::construct_at_end(typename ft::vector<Tp, Allocator>::size_type size, const typename ft::vector<Tp, Allocator>::value_type& value)
{
	_size = size;
	for (std::size_t index = 0; index < size; ++index)
		_alloc.construct(_vec + index, value);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param size 
 */
template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::destruct(std::size_t size)
{
	for (std::size_t index = 0; index < size; ++index)
		_alloc.destroy(_vec + index);
	_size = 0;
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param capacity 
 * @param size 
 * @param value 
 */
template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::allocate_and_copy_construct(std::size_t capacity, std::size_t size, const typename ft::vector<Tp, Allocator>::value_type& value)
{
	allocate(capacity);
	construct(size, value);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param capacity 
 * @param size 
 */
template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::deallocate_and_destruct(std::size_t capacity, std::size_t size)
{
	destruct(size);
	deallocate(capacity);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param other 
 */
template<class Tp, class Allocator>
void ft::vector<Tp, Allocator>::uninitialized_alloc_copy(const ft::vector<Tp, Allocator>& other)
{
	_size = other.size();
	for (size_type index=0; index < _size; ++index)
		this->_alloc.construct(this->_vec + index, *(other._vec + index));
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param other 
 */
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

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param new_size 
 * @return ft::vector<Tp, Allocator>::size_type 
 */
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
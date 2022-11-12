#ifndef VECTOR_ELEMENT_ACCESS_TPP
# define VECTOR_ELEMENT_ACCESS_TPP

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param index 
 * @return ft::vector<Tp, Allocator>::reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::operator[](typename ft::vector<Tp, Allocator>::size_type index)
{
	assert(index < size() && "Index out of range1");
	return _vec[index]; 
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param index 
 * @return ft::vector<Tp, Allocator>::const_reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::operator[](typename ft::vector<Tp, Allocator>::size_type index) const
{
	assert(index < size() && "Index out of range2");
	return _vec[index]; 
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param n 
 * @return ft::vector<Tp, Allocator>::reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::at(typename ft::vector<Tp, Allocator>::size_type n)
{
	if (n < size() && n >= 0)
		return (_vec[n]);
	else
		throw std::out_of_range("Index out of range");
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @param n 
 * @return ft::vector<Tp, Allocator>::const_reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::at(typename ft::vector<Tp, Allocator>::size_type n) const
{
	return (n < size() ? _vec[n] : throw std::out_of_range("Index out of range"));
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::front()
{
	assert(!empty() && "front() called for empty vector");
	return *this->begin();
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::const_reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::front() const
{
	assert(!empty() && "front() called for empty vector");
	return *this->begin();
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
ft::vector<Tp, Allocator>::back()
{
	assert(!empty() && "back() called for empty vector");
	return *(_vec + size() - 1);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::const_reference 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
ft::vector<Tp, Allocator>::back() const
{
	assert(!empty() && "back() called for empty vector");
	return *(_vec + size() - 1);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::value_type* 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::value_type*
ft::vector<Tp, Allocator>::data()
{
	return (_vec);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return const ft::vector<Tp, Allocator>::value_type* 
 */
template<class Tp, class Allocator>
const typename ft::vector<Tp, Allocator>::value_type*
ft::vector<Tp, Allocator>:: data() const
{
	return (_vec);
}
#endif
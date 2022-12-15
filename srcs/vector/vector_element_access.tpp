/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_element_access.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:42:54 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/15 18:30:25 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
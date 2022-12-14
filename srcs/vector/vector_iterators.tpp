/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:43:01 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:43:02 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATORS_TPP
# define VECTOR_ITERATORS_TPP

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::iterator 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::begin()
{
	return iterator(_vec);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::const_iterator 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_iterator
ft::vector<Tp, Allocator>::begin() const
{
	return const_iterator(_vec);
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::iterator 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
ft::vector<Tp, Allocator>::end()
{
	return iterator(_vec + size());
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::const_iterator 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_iterator
ft::vector<Tp, Allocator>::end() const
{
	return const_iterator(_vec + size());
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::reverse_iterator 
 */
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

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::reverse_iterator 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reverse_iterator
ft::vector<Tp, Allocator>::rend()
{
	return reverse_iterator(this->begin());
}

/**
 * @brief 
 * 
 * @tparam Tp 
 * @tparam Allocator 
 * @return ft::vector<Tp, Allocator>::const_reverse_iterator 
 */
template<class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reverse_iterator
ft::vector<Tp, Allocator>::rend() const
{
	return const_reverse_iterator(this->begin());
}

#endif
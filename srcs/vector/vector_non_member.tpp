/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_non_member.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:43:09 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:43:10 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_NON_MEMBER_TPP
# define VECTOR_NON_MEMBER_TPP

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Alloc 
 * @param lhs 
 * @param rhs 
 * @return true 
 * @return false 
 */
template <class T, class Alloc>
bool ft::operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Alloc 
 * @param lhs 
 * @param rhs 
 * @return true 
 * @return false 
 */
template <class T, class Alloc>
bool ft::operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs == rhs);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Alloc 
 * @param lhs 
 * @param rhs 
 * @return true 
 * @return false 
 */
template <class T, class Alloc>
bool ft::operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Alloc 
 * @param lhs 
 * @param rhs 
 * @return true 
 * @return false 
 */
template <class T, class Alloc>
bool ft::operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(rhs < lhs);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Alloc 
 * @param lhs 
 * @param rhs 
 * @return true 
 * @return false 
 */
template <class T, class Alloc>
bool ft::operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Alloc 
 * @param lhs 
 * @param rhs 
 * @return true 
 * @return false 
 */
template <class T, class Alloc>
bool ft::operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs < rhs);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Alloc 
 * @param x 
 * @param y 
 */
template <class T, class Alloc>
void ft::swap(ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
{
	x.swap(y);
}
#endif
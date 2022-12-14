/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_non_member_func.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:42:37 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:42:38 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_NON_MEMBER_FUNC_TPP
# define STACK_NON_MEMBER_FUNC_TPP

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator==(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c == y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator< (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c < y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c != y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator> (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c > y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c >= y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c <= y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 */
template <class T, class Container>
void swap(ft::stack<T, Container>& x, ft::stack<T, Container>& y)
{
	x.swap(y);
}
#endif
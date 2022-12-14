/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_member_func.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:42:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:42:34 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MEMBER_FUNC_TPP
# define STACK_MEMBER_FUNC_TPP

/**
 * @brief Construct a new ft::stack<T, Container>::stack object
 * 
 * @tparam T 
 * @tparam Container 
 * @param ctnr 
 */
template<class T, class Container>
ft::stack<T, Container>::stack
(const typename ft::stack<T, Container>::container_type& ctnr) : c(ctnr){}

/**
 * @brief Destroy the ft::stack<T, Container>::stack object
 * 
 * @tparam T 
 * @tparam Container 
 */
template<class T, class Container>
ft::stack<T, Container>::~stack(){} 

template<class T, class Container>
bool
ft::stack<T, Container>::empty() const
{
	return (c.empty());
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @return ft::stack<T, Container>::size_type 
 */
template<class T, class Container>
typename ft::stack<T, Container>::size_type
ft::stack<T, Container>::size() const
{
	return (c.size());
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @return ft::stack<T, Container>::value_type& 
 */
template<class T, class Container>
typename ft::stack<T, Container>::value_type&
ft::stack<T, Container>::top()
{
	return (c.back());
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @return const ft::stack<T, Container>::value_type& 
 */
template<class T, class Container>
const typename ft::stack<T, Container>::value_type&
ft::stack<T, Container>::top() const
{
	return (c.back());
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 */
template<class T, class Container>
void
ft::stack<T, Container>::push(const typename ft::stack<T, Container>::value_type& x)
{
	return (c.push_back(x));
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 */
template<class T, class Container>
void
ft::stack<T, Container>::pop()
{
	return (c.pop_back());
}
#endif
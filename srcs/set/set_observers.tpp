/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_observers.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:42:00 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:42:01 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_OBSERVERS_TPP
# define SET_OBSERVERS_TPP
template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::key_compare
ft::set<T, Compare, Alloc>::key_comp() const
{
	return (this->_comp);
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::value_compare
ft::set<T, Compare, Alloc>::value_comp() const
{
	return ft::set<T, Compare, Alloc>::value_compare(this->_comp);
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_capacity.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:41:25 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:41:26 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_CAPACITY_TPP
# define SET_CAPACITY_TPP
template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type
ft::set<T, Compare, Alloc>::size() const
{
	return (_size);
}

template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type
ft::set<T, Compare, Alloc>::max_size() const
{
	return (n_alloc.max_size());
}

template < class T, class Compare, class Alloc>
bool
ft::set<T, Compare, Alloc>::empty() const
{
	if (_size == 0)
		return true;
	return false;
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_allocator.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:41:21 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:41:22 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ALLOCATOR_TPP
# define SET_ALLOCATOR_TPP

template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::allocator_type
ft::set<T, Compare, Alloc>::get_allocator() const
{
	return (this->_alloc);
}
#endif
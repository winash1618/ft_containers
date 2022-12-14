/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocator.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:40:03 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:40:04 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ALLOCATOR_TPP
# define MAP_ALLOCATOR_TPP
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::allocator_type
ft::map<Key, T, Compare, Alloc>::get_allocator() const
{
	return (this->_alloc);
}
#endif
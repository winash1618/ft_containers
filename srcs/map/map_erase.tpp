/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_erase.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:40:30 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:40:31 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ERASE_TPP
# define MAP_ERASE_TPP

template <class Key, class T, class Compare, class Alloc>
void 
ft::map<Key, T, Compare, Alloc>::erase(typename ft::map<Key, T, Compare, Alloc>::iterator position)
{
	node_pointer __node;

	__node = const_cast<node_pointer>(position.__ptr_);
	if (__node == _nil || __node == NULL || _root == _nil || _root == NULL)
		return ;
	n_alloc.destroy(__node);
		
	map_remove(__node);
	n_alloc.deallocate(__node, 1);
	_size--;
	if (_size == 0)
		_root = NULL;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type
ft::map<Key, T, Compare, Alloc>::erase(const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
	node_pointer __nd;
	__nd = const_cast<node_pointer>(find(k).__ptr_);
	if(__nd != _nil)
	{
		erase(find(k));
		return 1;

	}
	return 0;
}
template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::erase (typename ft::map<Key, T, Compare, Alloc>::iterator first, typename ft::map<Key, T, Compare, Alloc>::iterator last)
{
	while (first != last)
	{
		iterator temp = first;
		first++;
		erase(temp);
	}
}

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::clear()
{
	destroy(_root);
	_size = 0;
	_root = NULL;
}
#endif
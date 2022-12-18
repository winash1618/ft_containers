/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:40:41 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 09:50:58 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INSERT_TPP
# define MAP_INSERT_TPP

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>
ft::map<Key, T, Compare, Alloc>::insert (const value_type& val)
{
	if (_root == NULL)
	{
		_root = mapAllocate(val, _nil);
		_root->_color = BLACK;
		ft::pair<iterator, bool> t = ft::make_pair<iterator, bool>(iterator(_nil, _root, _nil), true);
		_size = 1;
		return t;
	}
	node_pointer cur = _root;
	node_pointer parent = cur;
	while (cur != _nil)
	{
		if (_comp(cur->_data.first, val.first))
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (_comp(val.first, cur->_data.first))
		{
			parent = cur;
			cur = cur->_left;
		}
		else
			return ft::make_pair(iterator(_nil, cur, _nil), false);
	}
	cur = mapAllocate(val, parent);
	node_pointer newnode = cur;
	newnode->_color = RED;
	if (_comp(parent->_data.first, val.first))
		parent->_right = newnode;
	else
		parent->_left = newnode;
	balanceTreeAfterInsert(newnode, parent);
	_size++;
	_root->_color = BLACK;
	return ft::make_pair(iterator(_nil, newnode, _nil), true);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return (insert(val).first);
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void
ft::map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last)
{
	InputIterator it = first;
	while (it != last)
	{
		insert(*it);
		it++;
	}
}
#endif
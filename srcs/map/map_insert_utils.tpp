/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert_utils.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:04:07 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 13:04:08 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INSERT_UTILS_TPP
# define MAP_INSERT_UTILS_TPP


template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::node_pointer
ft::map<Key, T, Compare, Alloc>::mapAllocate(const typename ft::map<Key, T, Compare, Alloc>::value_type& val, typename ft::map<Key, T, Compare, Alloc>::node_pointer parent)
{
	node_pointer node;
	node = n_alloc.allocate(1);
	ft::RBTreeNode<value_type> temp(val);
	n_alloc.construct(node, temp);
	node->_parent = parent;
	node->_left = _nil;
	node->_right = _nil;
	return (node);
}

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::balanceTreeAfterInsert(typename ft::map<Key, T, Compare, Alloc>::node_pointer insertNode, typename ft::map<Key, T, Compare, Alloc>::node_pointer parent)
{
	while (parent != _nil && parent->_color == RED)
	{
		Node* grandParent = parent->_parent;
		if (grandParent->_left == parent)
		{
			Node* uncle = grandParent->_right;
			if (uncle != _nil && uncle->_color == RED)
			{
				parent->_color = BLACK;
				uncle->_color = BLACK;
				grandParent->_color = RED;
				insertNode = grandParent;
				parent = insertNode->_parent;
			}
			else
			{
				if (parent->_left == insertNode)
				{
					RotateR(grandParent);
					parent->_color = BLACK;
					grandParent->_color = RED;
				}
				else
				{
					RotateL(parent);
					RotateR(grandParent);
					grandParent->_color = RED;
					insertNode->_color = BLACK;
				}
				break;
			}
		}
		else
		{
			node_pointer uncle = grandParent->_left;
			if (uncle != _nil && uncle->_color == RED)
			{
				uncle->_color = BLACK;
				parent->_color = BLACK;
				grandParent->_color = RED;
				insertNode = grandParent;
				parent = insertNode->_parent;
			}
			else
			{
				if (parent->_right == insertNode)
				{
					RotateL(grandParent);
					parent->_color = BLACK;
					grandParent->_color = RED;
				}
				else
				{
					RotateR(parent);
					RotateL(grandParent);
					insertNode->_color = BLACK;
					grandParent->_color = RED;
				}
				break;
			}
		}
	}
}
#endif
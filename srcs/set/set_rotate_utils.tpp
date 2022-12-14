/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotate_utils.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:42:09 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:42:10 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ROTATE_UTILS_TPP
# define SET_ROTATE_UTILS_TPP
template <class T, class Compare, class Alloc>
void
ft::set<T, Compare, Alloc>::RotateL(node_pointer parent)
{
	node_pointer subR = parent->_right;
	node_pointer subRL = subR->_left;
	node_pointer parentParent = parent->_parent;
	parent->_right = subRL;
	subR->_left = parent;
	parent->_parent = subR;
	if (subRL != _nil)
		subRL->_parent = parent;
	if (_root == parent)
	{
		_root = subR;
		_root -> _parent = _nil;
	}
	else
	{
		if (parentParent->_left == parent)
			parentParent->_left = subR;
		else
			parentParent->_right = subR;
		subR->_parent = parentParent;
	}
}

template <class T, class Compare, class Alloc>
void
ft::set<T, Compare, Alloc>::RotateR(node_pointer parent)
{
	node_pointer subL = parent->_left;
	node_pointer subLR = subL->_right;
	node_pointer parentParent = parent->_parent;

	parent->_left = subLR;
	subL->_right = parent;
	if (subLR != _nil)
		subLR->_parent = parent;
	parent->_parent = subL;
	if (_root == parent)
	{
		_root = subL;
		_root->_parent = _nil;
	}
	else
	{
		if (parentParent->_left == parent)
			parentParent->_left = subL;
		else
			parentParent->_right = subL;
		subL->_parent = parentParent;
	}
}
#endif
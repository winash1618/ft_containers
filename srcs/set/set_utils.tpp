/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:42:22 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:42:23 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_UTILS_TPP
# define SET_UTILS_TPP
template <class T, class Compare, class Alloc>
const typename ft::set<T, Compare, Alloc>::node_pointer
ft::set<T, Compare, Alloc>::begin_left(void) const
{
	node_pointer left = _root;
	while (left != _nil && left->_left != _nil)
	{
		left = left->_left;
	}
	return left;
}

template <class T, class Compare, class Alloc>
const typename ft::set<T, Compare, Alloc>::node_pointer
ft::set<T, Compare, Alloc>::begin_right(void) const
{
	node_pointer right = _root;
	while (right != _nil && right->_right != _nil)
	{
		right = right->_right;
	}
	return right;
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::node_pointer
ft::set<T, Compare, Alloc>::begin_left(void)
{
	node_pointer left = _root;
	while (left != _nil && left->_left != _nil)
	{
		left = left->_left;
	}
	return left;
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::node_pointer
ft::set<T, Compare, Alloc>::begin_right(void)
{
	node_pointer right = _root;
	while (right != _nil && right->_right != _nil) 
	{
		right = right->_right;
	}
	return right;
}

template <class T, class Compare, class Alloc>
void
ft::set<T, Compare, Alloc>::destroy(node_pointer __nd)
{
	if (__nd == NULL)
		return;
	if (__nd != _nil)
	{
		destroy(__nd->_left);
		destroy(__nd->_right);
		__node_allocator __na;
		__na.destroy(__nd);
		__na.deallocate( __nd, 1);
	}
}
#endif
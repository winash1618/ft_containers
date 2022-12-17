/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operations.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:42:04 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/17 08:00:20 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_OPERATIONS_TPP
# define SET_OPERATIONS_TPP

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::find(const typename ft::set<T, Compare, Alloc>::key_type& k)
{
	node_pointer cur = _root;
	if (cur == NULL)
		return (iterator(_nil, _nil, _nil));
	while (cur != _nil)
	{
		if (_comp(cur->_data, k))
		{
			cur = cur->_right;

		}
		else if (_comp(k, cur->_data))
		{
			cur = cur->_left;
		}
		else
		{
			return (iterator(_nil, cur, _nil));
		}
		
	}
	return (end());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator
ft::set<T, Compare, Alloc>::find (const typename ft::set<T, Compare, Alloc>::key_type& k) const
{
	node_pointer cur = _root;
	if (cur == NULL)
		return (iterator(_nil, _nil, _nil));
	while (cur != _nil)
	{
		if (cur->_data < k)
			cur = cur->_right;
		else if (cur->_data > k)
			cur = cur->_left;
		else
		{
			return (const_iterator(_nil, cur, _nil));
		}
	}
	return (end());
}
template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::lower_bound(const typename ft::set<T, Compare, Alloc>::key_type& k)
{
	node_pointer __root = _root;
	node_pointer __result = _nil;
	if (__root == NULL)
		return (iterator(_nil, _nil, _nil));
	while (__root != _nil)
	{
		if (!_comp(__root->_data, k))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result != _nil)
		return iterator(_nil, __result, _nil);
	return (end());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::upper_bound(const typename ft::set<T, Compare, Alloc>::key_type& k)
{
	node_pointer __root = _root;
	node_pointer __result = _nil;
	if (__root == NULL)
		return (iterator(_nil, _nil, _nil));
	while (__root != _nil)
	{
		if (_comp( k, __root->_data))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result != _nil)
		return iterator(_nil, __result, _nil);
	return (end());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator
ft::set<T, Compare, Alloc>::lower_bound(const typename ft::set<T, Compare, Alloc>::key_type& k) const
{
	node_pointer __root = _root;
	node_pointer __result = _nil;
	if (__root == NULL)
		return (const_iterator(_nil, _nil, _nil));
	while (__root != _nil)
	{
		if (!_comp(__root->_data, k))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result != _nil)
		return const_iterator(_nil, __result, _nil);
	return (end());
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::const_iterator
ft::set<T, Compare, Alloc>::upper_bound(const typename ft::set<T, Compare, Alloc>::key_type& k) const
{
	node_pointer __root = _root;
	node_pointer __result = _nil;
	if (__root == NULL)
		return (const_iterator(_nil, _nil, _nil));
	while (__root != _nil)
	{
		if (_comp( k, __root->_data))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result != _nil)
		return const_iterator(_nil, __result, _nil);
	return (end());
}

template <class T, class Compare, class Alloc>
ft::pair<typename ft::set<T, Compare, Alloc>::const_iterator,typename ft::set<T, Compare, Alloc>::const_iterator>
ft::set<T, Compare, Alloc>::equal_range(const typename ft::set<T, Compare, Alloc>::key_type& k) const
{
	return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
}

template <class T, class Compare, class Alloc>
ft::pair<typename ft::set<T, Compare, Alloc>::iterator, typename ft::set<T, Compare, Alloc>::iterator>
ft::set<T, Compare, Alloc>::equal_range (const typename ft::set<T, Compare, Alloc>::key_type& k)
{
	return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
}

template <class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type
ft::set<T, Compare, Alloc>::count (const typename ft::set<T, Compare, Alloc>::key_type& k) const
{
	size_type counter = 0;
	const_iterator search = begin();
	while (search != end())
	{
		if ( *search == k)
			counter++;
		search++;
	}
	return (counter);
}


#endif
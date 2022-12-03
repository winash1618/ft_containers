#ifndef MAP_OPERATIONS_TPP
# define MAP_OPERATIONS_TPP

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::find(const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
	node_pointer cur = _root;
	node_pointer parent = nullptr_f;
	while (cur != nullptr_f)
	{
		if (_comp(cur->_data.first, k))
		{
			parent = cur;
			cur = cur->_right;

		}
		else if (_comp(k, cur->_data.first))
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			return (iterator(cur));
		}
	}
	return (end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::find (const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
	node_pointer cur = _root;
	node_pointer parent = nullptr_f;
	while (cur)
	{
		if (cur->_data.first < k)
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (cur->_data.first > k)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			return (const_iterator(cur));
		}
	}
	return (end());
}
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::lower_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
	node_pointer __root = _root;
	node_pointer __result = nullptr_f;
	while (__root != nullptr_f)
	{
		if (!_comp(__root->_data.first, k))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result)
		return iterator(__result);
	return (end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::upper_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
	node_pointer __root = _root;
	node_pointer __result = nullptr_f;
	while (__root != nullptr_f)
	{
		if (_comp( k, __root->_data.first))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result)
		return iterator(__result);
	return (end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::lower_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
	node_pointer __root = _root;
	node_pointer __result = nullptr_f;
	while (__root != nullptr_f)
	{
		if (!_comp(__root->_data.first, k))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result)
		return const_iterator(__result);
	return (end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::upper_bound(const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
	node_pointer __root = _root;
	node_pointer __result = nullptr_f;
	while (__root != nullptr_f)
	{
		if (_comp( k, __root->_data.first))
		{
			__result = __root;
			__root = __root->_left;
		}
		else
			__root = __root->_right;
	}
	if (__result)
		return const_iterator(__result);
	return (end());
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator,typename ft::map<Key, T, Compare, Alloc>::const_iterator>
ft::map<Key, T, Compare, Alloc>::equal_range(const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
	return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, typename ft::map<Key, T, Compare, Alloc>::iterator>
ft::map<Key, T, Compare, Alloc>::equal_range (const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
	return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type
ft::map<Key, T, Compare, Alloc>::count (const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
	size_type counter = 0;
	const_iterator search = begin();
	while (search != end())
	{
		if ( search->first == k)
			counter++;
		search++;
	}
	return (counter);
}


#endif
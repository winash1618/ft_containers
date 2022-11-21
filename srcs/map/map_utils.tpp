#ifndef MAP_UTILS_TPP
# define MAP_UTILS_TPP

template <class Key, class T, class Compare, class Alloc>
const typename ft::map<Key, T, Compare, Alloc>::node_pointer
ft::map<Key, T, Compare, Alloc>::begin_left(void) const
{
	node_pointer left = _root;
	while (left && left->_left)
	{
		left = left->_left;
	}
	return left;
}

template <class Key, class T, class Compare, class Alloc>
const typename ft::map<Key, T, Compare, Alloc>::node_pointer
ft::map<Key, T, Compare, Alloc>::begin_right(void) const
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return right;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::node_pointer
ft::map<Key, T, Compare, Alloc>::begin_left(void)
{
	node_pointer left = _root;
	while (left && left->_left)
	{
		left = left->_left;
	}
	return left;
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::node_pointer
ft::map<Key, T, Compare, Alloc>::begin_right(void)
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return right;
}

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::destroy(node_pointer __nd)
{
	if (__nd != nullptr_f)
	{
		destroy(__nd->_left);
		destroy(__nd->_right);
		__node_allocator __na;
		__na.destroy(__nd);
		__na.deallocate( __nd, 1);
	}
}
#endif
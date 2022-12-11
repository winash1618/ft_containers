#ifndef MAP_ITERATORS_TPP
# define MAP_ITERATORS_TPP
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::begin()
{
	if (_root == NULL)
		return iterator(_nil, _nil, _nil);
	return iterator(begin_right(), begin_left(), _nil);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::begin() const
{
	if (_root == NULL)
		return const_iterator(_nil, _nil, _nil);
	return const_iterator(begin_right(), begin_left(), _nil);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::end()
{
	node_pointer right = _root;
	
	// try
	// {
	// 	if (right == NULL)
	// 		throw std::exception(std::range_error("end: root is nil"));
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// 	exit(1);
	// }
	if (right == NULL)
		return iterator(_nil, _nil, _nil);
	
	while (right != _nil && right->_right != _nil)
	{
		// std::cout << "right: " << right->_data.first << std::endl;
		right = right->_right;
	}
	return iterator(right, _nil, _nil);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::end() const
{
	node_pointer right = _root;
	// try
	// {
	// 	if (right->_data.first)
	// 		throw std::exception(std::range_error("end: root is nil"));
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// 	exit(1);
	// }
	if (right == NULL)
		return const_iterator(_nil, _nil, _nil);
	while (right != _nil && right->_right != _nil)
	{
		right = right->_right;
	}
	return const_iterator(right, _nil, _nil);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator
ft::map<Key, T, Compare, Alloc>::rbegin()
{
	return reverse_iterator(this->end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator
ft::map<Key, T, Compare, Alloc>::rend()
{
	return reverse_iterator(this->begin());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator
ft::map<Key, T, Compare, Alloc>::rbegin() const
{
	return const_reverse_iterator(this->end());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator
ft::map<Key, T, Compare, Alloc>::rend() const
{
	return const_reverse_iterator(this->begin());
};
#endif
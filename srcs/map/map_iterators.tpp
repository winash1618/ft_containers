#ifndef MAP_ITERATORS_TPP
# define MAP_ITERATORS_TPP
template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::begin()
{
	return iterator(begin_right(), begin_left());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::begin() const
{
	return const_iterator(begin_right(), begin_left());
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::end()
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return iterator(right, nullptr_f);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator
ft::map<Key, T, Compare, Alloc>::end() const
{
	node_pointer right = _root;
	while (right && right->_right)
	{
		right = right->_right;
	}
	return const_iterator(right, nullptr_f);
}

reverse_iterator rbegin()														{return reverse_iterator(this->end());}
			reverse_iterator rend()															{return reverse_iterator(this->begin()); }
			const_reverse_iterator rbegin() const											{return const_reverse_iterator(this->end());}
			const_reverse_iterator rend() const												{return const_reverse_iterator(this->begin()); };
#endif
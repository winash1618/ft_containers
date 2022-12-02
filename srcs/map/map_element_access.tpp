#ifndef MAP_ELEMENT_ACCESS_TPP
# define MAP_ELEMENT_ACCESS_TPP

template <class Key, class T, class Compare, class Alloc>
const typename ft::map<Key, T, Compare, Alloc>::mapped_type&
ft::map<Key, T, Compare, Alloc>::at(const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
	return at(k);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type&
ft::map<Key, T, Compare, Alloc>::at(const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
	node_pointer __nd;
	__nd = const_cast<node_pointer>(find(k).__ptr_);
	if (__nd == _nil)
		throw std::out_of_range("map::at:  key not found");
	return (__nd->_data.second);
}


template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type&
ft::map<Key, T, Compare, Alloc>::operator[] (const key_type& key)
{
	iterator it = find(key);
	if (it != end())
	{
		return (it->second);
	}
	else
	{
		insert(ft::make_pair(key,mapped_type()));
		it = find(key);
		return (it->second);
	}
}
#endif
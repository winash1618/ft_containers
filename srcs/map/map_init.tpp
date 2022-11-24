#ifndef MAP_INIT_TPP
# define MAP_INIT_TPP

template <class Key, class T, class Compare, class Alloc>
explicit ft::map<Key, T, Compare, Alloc>::map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	: _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
{
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last,
	const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type()) :_root(nullptr_f), _comp(comp), _alloc(alloc)
{
	insert(first, last);
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map (const ft::map<Key, T, Compare, Alloc>::map& x)
{
	*this = x;
	return;
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map() {destroy(_root);}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map& operator=(const ft::map<Key, T, Compare, Alloc>::map& x)
{
	if (this != &x)
	{
		value_comp() = x.value_comp();
		_alloc = x.get_allocator();
		_comp = x._comp;
		n_alloc = x.n_alloc;
		_size = 0;
		_root = nullptr_f;
		insert(x.begin(), x.end());
	}
	return *this;
}

#endif
#ifndef MAP_INIT_TPP
# define MAP_INIT_TPP

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map (const key_compare& comp, const allocator_type& alloc)
	: _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
{
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last,
	const key_compare& comp,
	const allocator_type& alloc) :_root(nullptr_f), _comp(comp), _alloc(alloc)
{
	insert(first, last);
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map (const map& x)
{
	*this = x;
	return;
}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map() {destroy(_root);}

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>& ft::map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	if (this != &x)
	{
		this->value_comp() = x.value_comp();
		this->_alloc = x.get_allocator();
		this->_comp = x._comp;
		this->n_alloc = x.n_alloc;
		this->_size = 0;
		this->_root = nullptr_f;
		insert(x.begin(), x.end());
	}
	return *this;
}

#endif
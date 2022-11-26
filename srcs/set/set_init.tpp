#ifndef SET_INIT_TPP
# define SET_INIT_TPP

template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc)
: _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
{
}

template <class T, class Compare, class Alloc>
template <class InputIterator>
ft::set<T, Compare, Alloc>::set (InputIterator first, InputIterator last,
	const key_compare& comp,
	const allocator_type& alloc) : _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
{
	insert(first, last);
}
template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set (const set& x)
{
	*this = x;
	return;
}

template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>::~set()
{
	destroy(_root);
}

template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>& ft::set<T, Compare, Alloc>::operator=(const set& x)
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
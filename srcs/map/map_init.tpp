#ifndef MAP_INIT_TPP
# define MAP_INIT_TPP

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map (const key_compare& comp, const allocator_type& alloc)
	: _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
{
	ft::RBTreeNode<value_type> temp;
	_nil = n_alloc.allocate(1);
	n_alloc.construct(_nil, temp);
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
ft::map<Key, T, Compare, Alloc>::~map() 
{
	// __node_allocator __na;
	// __na.destroy(_nil);
	// __na.deallocate( _nil, 1);
	destroy(_root);
}

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
		this->_nil = x._nil;
		insert(x.begin(), x.end());
	}
	return *this;
}

#endif
#ifndef MAP_INIT_TPP
# define MAP_INIT_TPP

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map (const key_compare& comp, const allocator_type& alloc)
	:  _root(0),_comp(comp), _alloc(alloc), _size(0)
{
	ft::RBTreeNode<value_type> temp;
	_nil = n_alloc.allocate(1);
	n_alloc.construct(_nil, temp);
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
ft::map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last,
	const key_compare& comp,
	const allocator_type& alloc) : _root(0),_comp(comp), _alloc(alloc)
{
	ft::RBTreeNode<value_type> temp;
	_nil = n_alloc.allocate(1);
	n_alloc.construct(_nil, temp);
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
	for(const_iterator it = x.begin(); it != x.end(); it++)
		std::cout << it->second << std::endl;
	// this->clear();
	if (this != &x)
	{
		this->value_comp() = x.value_comp();
		this->_alloc = x.get_allocator();
		this->_comp = x._comp;
		this->n_alloc = x.n_alloc;
		this->_size = 0;
		this->_root = x._root;
		this->_nil = x._nil;
	}
	
	insert(x.begin(), x.end());
	return *this;
}

#endif
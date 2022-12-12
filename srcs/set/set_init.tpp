#ifndef SET_INIT_TPP
# define SET_INIT_TPP

template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc)
: _root(NULL), _comp(comp), _alloc(alloc), _size(0)
{
	ft::RBTreeNode<value_type> temp;
	_nil = n_alloc.allocate(1);
	n_alloc.construct(_nil, temp);
	_nil->_color = BLACK;
}

template <class T, class Compare, class Alloc>
template <class InputIterator>
ft::set<T, Compare, Alloc>::set (InputIterator first, InputIterator last,
	const key_compare& comp,
	const allocator_type& alloc) : _root(NULL), _comp(comp), _alloc(alloc), _size(0)
{
	ft::RBTreeNode<value_type> temp;
	_nil = n_alloc.allocate(1);
	n_alloc.construct(_nil, temp);
	_nil->_color = BLACK;
	insert(first, last);
}
template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>::set (const set& x): _root(NULL), _nil(NULL)
{
	*this = x;
	return;
}

template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>::~set()
{
	__node_allocator __na;
	__na.destroy(_nil);
	__na.deallocate( _nil, 1);
	destroy(_root);
}

template <class T, class Compare, class Alloc>
ft::set<T, Compare, Alloc>& ft::set<T, Compare, Alloc>::operator=(const set& x)
{
	if (this != &x)
	{
		if (_root)
			destroy(_root);
		this->value_comp() = x.value_comp();
		this->_alloc = x.get_allocator();
		this->_comp = x._comp;
		this->n_alloc = x.n_alloc;
		this->_size = 0;
		this->_root = NULL;
		if(_nil)
		{
			__node_allocator __na;
			__na.destroy(_nil);
			__na.deallocate( _nil, 1);
		}
		ft::RBTreeNode<value_type> temp;
		this->_nil = n_alloc.allocate(1);
		n_alloc.construct(_nil, temp);
		this->_nil->_color = BLACK;
		insert(x.begin(), x.end());
	}
	return *this;
}

#endif
#ifndef SET_ERASE_TPP
# define SET_ERASE_TPP

template < class T, class Compare, class Alloc>
void
ft::set<T, Compare, Alloc>::erase(typename ft::set<T, Compare, Alloc>::iterator position)
{
	node_pointer __root; // -> red–black tree
	node_pointer __node; // -> node to be deleted

	__node = const_cast<typename ft::set<T, Compare, Alloc>::node_pointer>(position.__ptr_);
	__root = _root;
	if (!__node || !__root)
		return ;
	n_alloc.destroy(__node);
	set_remove( __node);
	n_alloc.deallocate(__node, 1);
	_size--;
}

template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::size_type
ft::set<T, Compare, Alloc>::erase(const typename ft::set<T, Compare, Alloc>::key_type& k)
{
	node_pointer __nd;
	__nd = const_cast<typename ft::set<T, Compare, Alloc>::node_pointer>(find(k).__ptr_);
	if(__nd)
	{
		erase(find(k));
		return (1);
	}
	return 0;
}

template < class T, class Compare, class Alloc>
void
ft::set<T, Compare, Alloc>::erase(typename ft::set<T, Compare, Alloc>::iterator first, typename ft::set<T, Compare, Alloc>::iterator last)
{
	while (first != last)
	{
		iterator temp = first;
		first++;
		erase(temp);
	}
}

template <class T, class Compare, class Alloc>
void
ft::set<T, Compare, Alloc>::clear()
{
	destroy(_root);
	_size = 0;
	_root = nullptr_f;
}
#endif
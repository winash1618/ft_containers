#ifndef MAP_ERASE_TPP
# define MAP_ERASE_TPP

template <class Key, class T, class Compare, class Alloc>
void 
erase(iterator position)
{
	node_pointer __node; // -> node to be deleted

	__node = const_cast<node_pointer>(position.__ptr_);
	if (!__node || !_root)
		return ;
	n_alloc.destroy(__node);
		
	tree_remove(__node);
	n_alloc.deallocate(__node, 1);
	_size--;
}


template <class Key, class T, class Compare, class Alloc>
size_type
erase(const key_type& k)
{
	node_pointer __nd;
	__nd = const_cast<node_pointer>(find(k).__ptr_);
	if(__nd)
	{
		erase(find(k));
		return 1;

	}
	return 0;
}

template <class Key, class T, class Compare, class Alloc>
void
erase (iterator first, iterator last)
{
	while (first != last)
	{
		iterator temp = first;
		first++;
		erase(temp);
	}
}

#endif
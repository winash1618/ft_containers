#ifndef MAP_SWAP_TPP
# define MAP_SWAP_TPP

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::swap (map& x)
{
	node_pointer		t_root = x._root;
	key_compare			t_comp = x._comp;
	allocator_type		t_alloc = x._alloc;
	__node_allocator	tn_alloc = x.n_alloc;
	size_type			t_size = x._size;
	x._root = _root;
	x._comp = _comp;
	x._alloc = _alloc;
	x.n_alloc = n_alloc;
	x._size = _size;
	_root = t_root;
	_comp = t_comp;
	_alloc = t_alloc;
	n_alloc = tn_alloc;
	_size = t_size;
}
#endif
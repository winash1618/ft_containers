#ifndef SET_SWAP_TPP
# define SET_SWAP_TPP
template <class T, class Compare, class Alloc>
void
ft::set<T, Compare, Alloc>::swap (set& x)
{
	node_pointer		t_root = x._root;
	node_pointer		t_nil = x._nil;
	key_compare			t_comp = x._comp;
	allocator_type		t_alloc = x._alloc;
	__node_allocator	tn_alloc = x.n_alloc;
	size_type			t_size = x._size;
	x._root = _root;
	x._nil = _nil;
	x._comp = _comp;
	x._alloc = _alloc;
	x.n_alloc = n_alloc;
	x._size = _size;
	_root = t_root;
	_nil = t_nil;
	_comp = t_comp;
	_alloc = t_alloc;
	n_alloc = tn_alloc;
	_size = t_size;
}
#endif
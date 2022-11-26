#ifndef SET_ALLOCATOR_TPP
# define SET_ALLOCATOR_TPP

template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::allocator_type
ft::set<T, Compare, Alloc>::get_allocator() const
{
	return (this->_alloc);
}
#endif
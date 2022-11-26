#ifndef SET_NON_MEMBER_TPP
# define SET_NON_MEMBER_TPP
template <class T, class Compare, class Alloc>
inline bool operator==( const ft::set<T, Compare, Alloc>& lhs,
					const ft::set<T, Compare, Alloc>& rhs )
{
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Compare, class Alloc>
inline bool operator!=( const ft::set<T, Compare, Alloc>& lhs,
					const ft::set<T, Compare, Alloc>& rhs )
{
	return !(lhs == rhs);
}
	
template <class T, class Compare, class Alloc>
inline bool operator<( const ft::set<T, Compare, Alloc>& lhs,
					const ft::set<T, Compare, Alloc>& rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class T, class Compare, class Alloc>
inline bool operator<=( const ft::set<T, Compare, Alloc>& lhs,
					const ft::set<T, Compare, Alloc>& rhs )
{
	return !(rhs < lhs);
}
template <class T, class Compare, class Alloc>
inline bool operator>( const set<T, Compare, Alloc>& lhs,
					const set<T, Compare, Alloc>& rhs )
{
	return rhs < lhs;
}
template <class T, class Compare, class Alloc>
inline bool operator>= ( const ft::set<T, Compare, Alloc>& lhs,
					const ft::set<T, Compare, Alloc>& rhs )
{
	return !(lhs < rhs);
}
template <class T, class Compare, class Alloc>
void swap (ft::set<T, Compare, Alloc>& x, ft::set<T, Compare, Alloc>& y)
{
	x.swap(y);
}
#endif
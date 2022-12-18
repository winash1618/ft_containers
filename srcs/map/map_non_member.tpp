/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_non_member.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:40:51 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 07:48:53 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_NON_MEMBER_TPP
# define MAP_NON_MEMBER_TPP
template <class Key, class T, class Compare, class Alloc>
bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(lhs == rhs);
}
	
template <class Key, class T, class Compare, class Alloc>
bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <class Key, class T, class Compare, class Alloc>
bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(rhs < lhs);
}
template <class Key, class T, class Compare, class Alloc>
bool operator>( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
{
	return rhs < lhs;
}
template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return !(lhs < rhs);
}
template <class Key, class T, class Compare, class Alloc>
void swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y)
{
	x.swap(y);
}
#endif
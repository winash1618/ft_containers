/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:57:31 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 08:39:49 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP
# include <iostream>
# include <algorithm>
# include <functional>
# include "utils/pair.hpp"
# include "iterators/set_iterator.hpp"
# include "iterators/reverse_iterator.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> > 
	class set
	{
		public:
			typedef T																	key_type;
			typedef T																	value_type;
			typedef Compare																key_compare;
			typedef key_compare															value_compare;
			typedef Alloc																allocator_type;
			typedef value_type&															reference;
			typedef const value_type&													const_reference;

		private:
			typedef T																	__value_type;
			typedef typename allocator_type::template rebind<__value_type>::other		__allocator_type;
			typedef RBTreeNode<value_type>												Node;
			typedef Node																__node_pointer;
			typedef typename __allocator_type::template rebind<__node_pointer>::other	__node_allocator;
			typedef typename __node_allocator::pointer									node_pointer;

		public:
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename allocator_type::difference_type							difference_type;
			typedef typename allocator_type::size_type									size_type;
			typedef ft::__const_set_iterator<value_type, allocator_type>				iterator;
			typedef ft::__const_set_iterator<value_type, allocator_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;

		private:
			node_pointer																_root;
			node_pointer																_nil;
			key_compare																	_comp;
			allocator_type																_alloc;
			__node_allocator															n_alloc;
			size_type																	_size;

		public:
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			set (const set& x);
			~set();

			set&								operator=(const set& x);

			iterator							begin();
			const_iterator						begin() const;
			iterator							end();
			const_iterator						end() const;
			reverse_iterator					rbegin();
			const_reverse_iterator				rbegin() const;
			reverse_iterator					rend();
			const_reverse_iterator				rend() const;

			bool								empty() const;
			size_type							size() const;
			size_type							max_size() const;

			ft::pair<iterator,bool>				insert(const value_type& val);
			iterator							insert(iterator position, const value_type& val);
			template <class InputIterator>
			void								insert(InputIterator first, InputIterator last);
			void								erase(iterator position);
			size_type							erase(const key_type& k);
			void								erase(iterator first, iterator last);
			void								swap(set& x);
			void								clear();

			key_compare							key_comp() const;
			value_compare						value_comp() const;

			iterator							find(const key_type& k);
			const_iterator						find(const key_type& k) const;
			size_type							count(const key_type& k) const;
			iterator							lower_bound(const key_type& k);
			const_iterator						lower_bound(const key_type& k) const;
			iterator							upper_bound(const key_type& k);
			const_iterator						upper_bound(const key_type& k) const;
			pair<iterator,iterator>				equal_range(const key_type& k);
			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;

			allocator_type						get_allocator() const;

		private:
			const			node_pointer begin_left(void) const;
			const			node_pointer begin_right(void) const;
			node_pointer	begin_left(void);
			node_pointer	begin_right(void);
			void			destroy(node_pointer __nd);
			void			RotateL(node_pointer parent);
			void			RotateR(node_pointer parent);
			void			set_remove(node_pointer delete_node);
			void			removeYConnectionToDeleteNode(node_pointer y, node_pointer delete_node);
			void			changeY2Root(node_pointer y, node_pointer delete_node);
			void			balanceTreeAfterDelete(node_pointer x, node_pointer w);
	};

	template <class T, class Compare, class Alloc>
	bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
	template <class T, class Compare, class Alloc>
	bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
	template <class T, class Compare, class Alloc>
	bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
	template <class T, class Compare, class Alloc>
	bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
	template <class T, class Compare, class Alloc>
	bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
	template <class T, class Compare, class Alloc>
	bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );

	template <class T, class Compare, class Alloc>
	void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y);

	#include "./../srcs/set/set_allocator.tpp"
	#include "./../srcs/set/set_erase.tpp"
	#include "./../srcs/set/set_erase_utils.tpp"
	#include "./../srcs/set/set_rotate_utils.tpp"
	#include "./../srcs/set/set_non_member.tpp"
	#include "./../srcs/set/set_utils.tpp"
	#include "./../srcs/set/set_iterators.tpp"
	#include "./../srcs/set/set_init.tpp"
	#include "./../srcs/set/set_operations.tpp"
	#include "./../srcs/set/set_capacity.tpp"
	#include "./../srcs/set/set_insert.tpp"
	#include "./../srcs/set/set_swap.tpp"
	#include "./../srcs/set/set_observers.tpp"

}
#endif
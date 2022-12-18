/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:57:27 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 09:40:18 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <iostream>
# include <algorithm>
# include <functional>
# include "utils/pair.hpp"
# include "iterators/map_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
namespace ft
{
	template < class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key,T> >
	> class map
	{

		public:
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef ft::pair<const key_type, mapped_type>								value_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef value_type&															reference;
			typedef const value_type&													const_reference;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;
					value_compare(key_compare c) : comp(c) {}
				public:
					bool operator()(const value_type& __x, const value_type& __y) const
					{
						return comp(__x.first, __y.first);
					}
			};

		private:
			typedef ft::RBTreeNode<value_type>											Node;
			typedef Node																__node_pointer;
			typedef typename allocator_type::template rebind<__node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									node_pointer;

		public:
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename allocator_type::size_type									size_type;
			typedef typename allocator_type::difference_type							difference_type;
			typedef ft::__tree_iterator<value_type, allocator_type> 					iterator;
			typedef ft::__const_tree_iterator<value_type, allocator_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;

		private:
			node_pointer																_root;
			node_pointer																_nil;
			key_compare																	_comp;
			allocator_type																_alloc;
			__node_allocator															n_alloc;
			size_type																	_size;
			iterator																	iter;

		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map (const map& x);
			~map();

			map&									operator=(const map& x);

			iterator								begin();
			const_iterator							begin() const;
			iterator								end();
			const_iterator							end() const;
			reverse_iterator						rbegin();
			const_reverse_iterator					rbegin() const;
			reverse_iterator						rend();
			const_reverse_iterator					rend() const;

			bool									empty() const;
			size_type								size() const;
			size_type								max_size() const;

			mapped_type&							operator[](const key_type& key);
			mapped_type&							at(const key_type& k);
			const mapped_type&						at(const key_type& k) const;

			ft::pair<iterator,bool>					insert(const value_type& val);
			iterator								insert(iterator position, const value_type& val);
			template <class InputIterator>
			void									insert(InputIterator first, InputIterator last);
			void									erase(iterator position);
			size_type								erase(const key_type& k);
			void									erase(iterator first, iterator last);
			void									swap(map& x);
			void									clear();

			key_compare								key_comp() const;
			value_compare							value_comp() const;
			size_type								count(const key_type& k) const;
			iterator								find(const key_type& k);
			const_iterator							find(const key_type& k) const;
			iterator								lower_bound(const key_type& k);
			const_iterator							lower_bound(const key_type& k) const;
			iterator								upper_bound(const key_type& k);
			const_iterator							upper_bound(const key_type& k) const;
			ft::pair<iterator,iterator>				equal_range(const key_type& k);
			ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;

			allocator_type							get_allocator() const;

		private:
			node_pointer	begin_left(void);
			node_pointer	begin_right(void);
			node_pointer	mapAllocate(const value_type& val, node_pointer parent);
			const			node_pointer begin_left(void) const;
			const			node_pointer begin_right(void) const;
			void			destroy(node_pointer __nd);
			void			RotateL(node_pointer parent);
			void			RotateR(node_pointer parent);
			void			map_remove(node_pointer delete_node);
			void			removeYConnectionToDeleteNode(node_pointer y, node_pointer delete_node);
			void			changeY2Root(node_pointer y, node_pointer delete_node);
			void			balanceTreeAfterInsert(node_pointer insertNode, node_pointer parent);
			void			balanceTreeAfterDelete(node_pointer x, node_pointer w);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs );
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
						const map<Key,T,Compare,Alloc>& rhs );

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);

	#include "./../srcs/map/map_allocator.tpp"
	#include "./../srcs/map/map_capacity.tpp"
	#include "./../srcs/map/map_element_access.tpp"
	#include "./../srcs/map/map_erase.tpp"
	#include "./../srcs/map/map_erase_utils.tpp"
	#include "./../srcs/map/map_insert.tpp"
	#include "./../srcs/map/map_insert_utils.tpp"
	#include "./../srcs/map/map_utils.tpp"
	#include "./../srcs/map/map_swap.tpp"
	#include "./../srcs/map/map_init.tpp"
	#include "./../srcs/map/map_iterators.tpp"
	#include "./../srcs/map/map_observers.tpp"
	#include "./../srcs/map/map_operations.tpp"
	#include "./../srcs/map/map_rotate_utils.tpp"
	#include "./../srcs/map/map_non_member.tpp"
}
// #include "../srcs/map/map_init.tpp"
#endif
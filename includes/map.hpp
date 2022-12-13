#ifndef MAP_HPP
# define MAP_HPP
# include "utils/pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "iterators/tree_iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# define DEBUG_1 0
# define DEBUG_R 0

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
			typedef ft::RBTreeNode<value_type>												Node;
			typedef Node																	__node_pointer;
			typedef typename allocator_type::template rebind<__node_pointer>::other			__node_allocator;

		public:
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename allocator_type::size_type									size_type;
			typedef typename allocator_type::difference_type							difference_type;
			typedef typename __node_allocator::pointer									node_pointer;
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
			map& operator=(const map& x);
			iterator								begin();
			const_iterator							begin() const;
			iterator								end();
			const_iterator							end() const;
			size_type								count(const key_type& k) const;
			bool									empty() const;
			iterator								find(const key_type& k);
			const_iterator							find(const key_type& k) const;
			iterator								lower_bound(const key_type& k);
			iterator								upper_bound(const key_type& k);
			const_iterator							lower_bound(const key_type& k) const;
			const_iterator							upper_bound(const key_type& k) const;
			ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			ft::pair<iterator,iterator>				equal_range(const key_type& k);
			allocator_type							get_allocator() const;
			key_compare								key_comp() const;
			value_compare							value_comp() const;
			size_type								size() const;
			size_type								max_size() const;
			reverse_iterator						rbegin();
			reverse_iterator						rend();
			const_reverse_iterator					rbegin() const;
			const_reverse_iterator					rend() const;
			void									clear();
			const mapped_type&						at(const key_type& k) const;
			mapped_type&							at(const key_type& k);
			ft::pair<iterator,bool>					insert(const value_type& val);
			iterator								insert(iterator position, const value_type& val);
			template <class InputIterator>
			void									insert(InputIterator first, InputIterator last);
			mapped_type&							operator[](const key_type& key);
			void									swap(map& x);
			void									erase(iterator position);
			size_type								erase(const key_type& k);
			void									erase(iterator first, iterator last);
		private:
			const			node_pointer begin_left(void) const;
			const			node_pointer begin_right(void) const;
			node_pointer	begin_left(void);
			node_pointer	begin_right(void);
			void			destroy(node_pointer __nd);
			void			RotateL(node_pointer parent);
			void			RotateR(node_pointer parent);
			void			map_remove(node_pointer delete_node);
			void			removeYConnectionToDeleteNode(node_pointer y, node_pointer delete_node);
			void			changeY2Root(node_pointer y, node_pointer delete_node);
			void			balanceTreeAfterDelete(node_pointer x, node_pointer w);
		};
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);
	#include "./../srcs/map/map_allocator.tpp"
	#include "./../srcs/map/map_capacity.tpp"
	#include "./../srcs/map/map_element_access.tpp"
	#include "./../srcs/map/map_erase.tpp"
	#include "./../srcs/map/map_erase_utils.tpp"
	#include "./../srcs/map/map_insert.tpp"
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
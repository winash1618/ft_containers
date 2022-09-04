#ifndef MAP_HPP
# define MAP_HPP
# include "pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	enum color_t { BLACK, RED };

	template<class T>
	struct RBTreeNode
	{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		
		T _data;
		color_t _color;
		RBTreeNode(const T& data)
				:_left(nullptr)
				,_right(nullptr)
				,_parent(nullptr)
				,_data(data)
				,_color(RED)
		{}
	};

	template < class Key,                                     // map::key_type
	class T,                                       // map::mapped_type
	class Compare = std::less<Key>,                     // map::key_compare
	class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
	> class map
	{

		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const key_type, mapped_type>				value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef value_type&											reference;
			typedef const value_type&									const_reference;
			
			class value_compare
				: public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;

					value_compare(key_compare c) : comp(c) {}
				public:
					bool operator()(const value_type& __x, const value_type& __y) const
						{return comp(__x.first, __y.first);}
			};
			
		private:
			typedef pair<key_type, mapped_type>                             __value_type;
			typedef typename allocator_type::template rebind_alloc<__value_type>::other __allocator_type;

		public:
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef typename __allocator_type::pointer					__node_pointer;
			typedef typename __allocator_type::const_pointer			__node_const_pointer;
			typedef typename ft::__tree_iterator<__node_pointer> 		iterator;
			// typedef ft::__wrap_iter<value_type>							const_iterator;
			// typedef ft::reverse_iterator<iterator>						reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			
		private:
			typedef RBTreeNode<value_type>	Node;
			typedef Node*					__node_pointer
			__node_pointer _root;
			allocator_type _alloc;
			__allocator_type	t_alloc;
			size_type _size;
			Node* _head;

		public:
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _root(), _alloc(alloc), _size(0)
			{
				std::cout << "Map default constructor called" << std::endl;
			}
			// template <class InputIterator>
			// map (InputIterator first, InputIterator last,
			// 	const key_compare& comp = key_compare(),
			// 	const allocator_type& alloc = allocator_type());	
			// map (const map& x);

			// ~map();

			// iterator begin();
			// const_iterator begin() const;

			// void clear();

			// size_type count (const key_type& k) const;

			// bool empty() const;

			// iterator end();
			// const_iterator end() const;

			// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// pair<iterator,iterator>             equal_range (const key_type& k);

				
			// void erase (iterator position);
			// size_type erase (const key_type& k);
			// void erase (iterator first, iterator last);

			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;

			// allocator_type get_allocator() const;

			// single element insert
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				// when the size of the map is empty.
				// this will add new element to the map and return true since there is new allocation.
				if (_root == nullptr)
				{
					_root = t_alloc.allocate(1, 0);
					t_alloc.construct(_root, val);
					_root->_color = BLACK;
					return ft::make_pair(iterator(_root), true);
				}
				// this is searching for a match in the current map element if there
				// is a match it will return with false since there is no allocation.
				__node_pointer cur = _root;
				__node_pointer parent = nullptr;
				while (cur)
				{
					if (cur->_data.first < val.first)
					{
						parent = cur;
						cur = cur->_right;
					}
					else if (cur->_data.first > val.first)
					{
						parent = cur;
						cur = cur->left;
					}
					else
					{
						return ft::make_pair(iterator(cur), false);
					}
				}
				cur = _alloc.allocate(1, 0);
				_alloc.allocate(1, 0);

			}
			// // with hint insert	
			// iterator insert (iterator position, const value_type& val);
			// // range insert
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);


			// key_compare key_comp() const;


			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;

			// size_type max_size() const;

			// mapped_type& operator[] (const key_type& key);

			// map& operator= (const map& x);


			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;


			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			// size_type size() const;

			// void swap (map& x);

			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;

			// value_compare value_comp() const;

		private:
			
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

}
#endif
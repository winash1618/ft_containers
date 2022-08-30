#ifndef MAP_HPP
# define MAP_HPP
# include "pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"


// The read-only operations, such as search or tree traversal, 
// on a red–black tree require no modification from those used for binary search trees, 
// because every red–black tree is a special case of a simple binary search tree.
//---------------------------------------------------------------------------------
// Basic type definitions:
//---------------------------------------------------------------------------------

enum color_t { BLACK, RED };

struct RBnode {     // node of red–black tree
  RBnode* parent;   // == NULL if root of the tree
  RBnode* child[2]; // == NIL if child is empty
    // Index is:
    //   LEFT  := 0, if (key < parent->key)
    //   RIGHT := 1, if (key > parent->key)
  enum color_t color;
  int key;
};

#define NIL   NULL // null pointer  or  pointer to sentinel node
#define LEFT  0
#define RIGHT 1
#define left  child[LEFT]
#define right child[RIGHT]

struct RBtree { // red–black tree
  RBnode* root; // == NIL if tree is empty
};

// Get the child direction (∈ { LEFT, RIGHT })
//   of the non-root non-NIL  RBnode* N:
#define childDir(N) ( N == (N->parent)->right ? RIGHT : LEFT )
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------





namespace ft
{
	template < class Key,                                     // map::key_type
	class T,                                       // map::mapped_type
	class Compare = std::less<Key>,                     // map::key_compare
	class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
	> class map
	{
		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const Key, T>								value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef ft::__wrap_iter<value_type>							iterator;
			typedef ft::__wrap_iter<value_type>							const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
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

			// // single element insert
			// pair<iterator,bool> insert (const value_type& val);
			// // with hint insert	
			// iterator insert (iterator position, const value_type& val);
			// // range insert
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);


			// key_compare key_comp() const;


			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;

			// size_type max_size() const;

			// mapped_type& operator[] (const key_type& k);

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
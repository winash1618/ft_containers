#ifndef TREE_HPP
# define TREE_HPP
# include "pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "tree_iterator.hpp"
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
		RBTreeNode(const T& data) : _left(nullptr_f), _right(nullptr_f), _parent(nullptr_f), _data(data), _color(RED) {}
	};
	template < class T,
	class Compare,
	class Alloc > 
	class tree
	{
		public:
			typedef T														value_type;
			typedef Compare													value_compare;
			typedef Alloc													allocator_type;
			typedef RBTreeNode<value_type>									node;
			typedef typename allocator_type::template rebind<node>::other	node_allocator;
			typedef typename node_allocator::pointer						node_pointer;
		private:
			node_pointer													_root;
			value_compare													_comp;
			allocator_type													_alloc;

		public:
	};
} // namespace ft

#endif
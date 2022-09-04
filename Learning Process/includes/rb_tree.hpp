#ifndef RB_TREE_HPP
# define RB_TREE_HPP
# include "pair.hpp"
namespace ft
{
	// The read-only operations, such as search or tree traversal, 
	// on a red–black tree require no modification from those used for binary search trees, 
	// because every red–black tree is a special case of a simple binary search tree.
	//---------------------------------------------------------------------------------
	// Basic type definitions:
	//---------------------------------------------------------------------------------

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


	// template<class T,class Ref,class Ptr>
	// struct _TreeIterator
	// {
	// 	/*typedef Ref reference;
	// 	typedef Ptr pointer;*/
	// 	typedef RBTreeNode<T> Node;
	// 	typedef _TreeIterator<T, Ref, Ptr> Self;
	// 	Node* _node;
	// 	_TreeIterator(Node* node)
	// 		:_node(node)
	// 	{}
	// 	Ref operator*()
	// 	{
	// 		return _node->_data;
	// 	}
	// 	Ptr operator ->()
	// 	{
	// 		return &_node->_data;
	// 	}
	// 	bool  operator !=(const Self& s) const
	// 	{
	// 		return _node != s._node;
	// 	}
	// 	bool  operator ==(const Self& s) const
	// 	{
	// 		return _node == s._node;
	// 	}
	// 	Self& operator++()
	// 	{
	// 		if (_node->_right)
	// 		{
				
	// 			Node* left = _node->_right;
	// 			while (left->_left)
	// 			{
	// 				left = left->_left;
	// 			}
	// 				_node = left;
	// 		}
	// 		else
	// 		{
	// 			Node* cur = _node;
	// 			Node* parent = cur->_parent;
	// 			while (parent && cur == parent->_right)
	// 			{
	// 				cur = cur->_parent;
	// 				parent = parent->_parent;
	// 			}
	// 			_node = parent;
	// 		}
	// 		return *this;
	// 	}
	// 	Self& operator--()
	// 	{
	// 		if (_node->_left)
	// 		{
				
	// 			Node* right = _node->_left;
	// 			while (right->_right)
	// 			{
	// 				right = right->_right;
	// 			}
	// 			_node = right;
	// 		}
	// 		else
	// 		{
	// 			Node* cur = _node;
	// 			Node* parent = cur->_parent;
	// 			while (parent && cur == parent->_left)
	// 			{
	// 				cur = cur->_parent;
	// 				parent = parent->_parent;
	// 			}
	// 			_node = parent;
	// 		}
	// 		return *this;
	// 	}
	// };
	
	// template <class _Tp,  class _Allocator>
	// class tree
	// {
	// 	public:
	// 		typedef _Tp                                      value_type;
	// 		typedef _Allocator                               allocator_type;
	// 		typedef typename allocator_type::pointer         pointer;
	// 		typedef typename allocator_type::const_pointer   const_pointer;
	// 		typedef typename allocator_type::size_type       size_type;
	// 		typedef typename allocator_type::difference_type difference_type;
			
	// 		typedef RBTreeNode<value_type> __node;
	// 		typedef typename allocator_type::template rebind<__node>::other	__node_allocator;
	// 	private:
	// 		typedef typename allocator_type::pointer						__node_pointer;
	// 		typedef typename allocator_type::pointer						__node_const_pointer;
	// 		__node_pointer													__root;
		
	
	// };
	//---------------------------------------------------------------------------------
	// https://opensource.apple.com/source/xnu/xnu-2050.18.24/bsd/hfs/hfscommon/headers/RedBlackTree.h.auto.html
	//---------------------------------------------------------------------------------


	

}
#endif
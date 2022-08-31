#ifndef RB_TREE_HPP
# define RB_TREE_HPP
# incluede "pair.hpp"
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
	Color _color;
	RBTreeNode(const T& data)
			:_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_data(data)
			,_color(RED)
	{}
};




	template<class K, class V>
	class RBTree
	{
		typedef RBNode<K, V> Node;
		public:
			RBTree(): _root(nullptr) {}
			
		private:
			Node* _root;
	}
	//---------------------------------------------------------------------------------
	// https://opensource.apple.com/source/xnu/xnu-2050.18.24/bsd/hfs/hfscommon/headers/RedBlackTree.h.auto.html
	//---------------------------------------------------------------------------------


	

}
#endif
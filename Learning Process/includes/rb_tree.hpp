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

	template<class K, class V>
	struct RBNode {     // node of red–black tree
		RBNode<K, V>* _parent;   // == NULL if root of the tree
		RBNode<K, V>* _left;
		RBNode<K, V>* _right;
		ft::pair<K, V> _kv;
		enum color_t _color;
		RBNode(const ft::pair<K, V)& kv): _parent(nullptr_f)
										,_left(nullptr_f)
										,_right(nullptr_f)
										,_kv(kv)
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
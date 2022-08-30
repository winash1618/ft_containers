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
	struct RBnode {     // node of red–black tree
		RBnode<K, V>* _parent;   // == NULL if root of the tree
		RBnode<K, V>* _child[2]; // == NIL if child is empty
			// Index is:
			//   LEFT  := 0, if (key < parent->key)
			//   RIGHT := 1, if (key > parent->key)
		ft::pair<K, V> _kv;
		enum color_t _color;
		RBnode(const ft::pair<K, V)& kv): _parent(nullptr_f)
										,_child(nullptr)
										,_kv(kv)
										,_color(RED)
		{}
	};

	#define NIL   NULL // null pointer  or  pointer to sentinel node
	#define LEFT  0
	#define RIGHT 1
	#define left  _child[LEFT]
	#define right _child[RIGHT]

	struct RBtree { // red–black tree
		RBnode* root; // == NIL if tree is empty
	};

	// Get the child direction (∈ { LEFT, RIGHT })
	//   of the non-root non-NIL  RBnode* N:
	#define childDir(N) ( N == (N->parent)->right ? RIGHT : LEFT )
	//---------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------


	

}
#endif
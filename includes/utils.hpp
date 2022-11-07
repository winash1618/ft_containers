#ifndef UTILS_HPP
# define UTILS_HPP

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
	// Returns:  true if __x is a left child of its parent, else false
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	inline
	bool
	tree_is_left_child(_NodePtr __x)
	{
		if (__x != nullptr_f )
			if (__x->_parent != nullptr_f)
				return __x == __x->_parent->_left;
		return 0;
	}

	// Returns:  pointer to the left-most node under __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	inline
	_NodePtr
	tree_min(_NodePtr __x)
	{
		while (__x->_left != nullptr_f)
			__x = __x->_left;
		return __x;
	}

	// Returns:  pointer to the right-most node under __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	inline
	_NodePtr
	tree_max(_NodePtr __x)
	{
		while (__x->_right != nullptr_f)
			__x = __x->_right;
		return __x;
	}

	// Returns:  pointer to the next in-order node after __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	_NodePtr
	tree_next(_NodePtr __x)
	{
		if (__x->_right != nullptr_f)
			return tree_min(__x->_right);
		while (!tree_is_left_child(__x) && __x->_parent)
		{
			__x = __x->_parent;
		}
		return __x->_parent;
	}

	// Returns:  pointer to the previous in-order node before __x.
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	_NodePtr
	tree_prev(_NodePtr __x)
	{
		if (__x->_left != nullptr_f)
			return tree_max(__x->_left);
		while (tree_is_left_child(__x))
			__x = __x->_parent;
		return __x->_parent;
	}

	
}
#endif
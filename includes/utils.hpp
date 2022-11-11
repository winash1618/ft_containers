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
	// Returns:  true if current_node is a left child of its parent, else false
	// Precondition:  current_node != nullptr.
	template <class _NodePtr>
	inline
	bool
	tree_is_left_child(_NodePtr current_node)
	{
		if (current_node != nullptr_f )
			if (current_node->_parent != nullptr_f)
				return current_node == current_node->_parent->_left;
		return 0;
	}

	// Returns:  pointer to the left-most node under current_node.
	// Precondition:  current_node != nullptr.
	template <class _NodePtr>
	inline
	_NodePtr
	tree_min(_NodePtr current_node)
	{
		while (current_node->_left != nullptr_f)
			current_node = current_node->_left;
		return current_node;
	}

	// Returns:  pointer to the right-most node under current_node.
	// Precondition:  current_node != nullptr.
	template <class _NodePtr>
	inline
	_NodePtr
	tree_max(_NodePtr current_node)
	{
		while (current_node->_right != nullptr_f)
			current_node = current_node->_right;
		return current_node;
	}

	// Returns:  pointer to the next in-order node after current_node.
	// Precondition:  current_node != nullptr.
	template <class _NodePtr>
	_NodePtr
	tree_next(_NodePtr current_node)
	{
		if (current_node->_right != nullptr_f)
			return tree_min(current_node->_right);
		while (!tree_is_left_child(current_node) && current_node->_parent)
		{
			current_node = current_node->_parent;
		}
		return current_node->_parent;
	}

	// Returns:  pointer to the previous in-order node before current_node.
	// Precondition:  current_node != nullptr.
	template <class _NodePtr>
	_NodePtr
	tree_prev(_NodePtr current_node)
	{
		if (current_node->_left != nullptr_f)
			return tree_max(current_node->_left);
		while (tree_is_left_child(current_node))
			current_node = current_node->_parent;
		return current_node->_parent;
	}
}
#endif
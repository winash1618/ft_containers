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
		RBTreeNode() : _left(), _right(), _parent(), _data(), _color(BLACK) {}
		RBTreeNode(const T& data) : _left(), _right(), _parent(), _data(data), _color(RED) {}
	};

	template <class _NodePtr>
	inline
	bool
	tree_is_left_child(_NodePtr current_node, _NodePtr nil_node)
	{
		if (current_node != nil_node )
			if (current_node->_parent != nil_node)
				return current_node == current_node->_parent->_left;
		return 0;
	}

	template <class _NodePtr>
	inline
	_NodePtr
	tree_min(_NodePtr current_node, _NodePtr nil_node)
	{
		while (current_node->_left != nil_node)
			current_node = current_node->_left;
		return current_node;
	}

	template <class _NodePtr>
	inline
	_NodePtr
	tree_max(_NodePtr current_node, _NodePtr nil_node)
	{
		while (current_node->_right != nil_node)
			current_node = current_node->_right;
		return current_node;
	}

	template <class _NodePtr>
	_NodePtr
	tree_next(_NodePtr current_node, _NodePtr nil_node)
	{
		if (current_node->_right != nil_node)
			return tree_min(current_node->_right, nil_node);
		while (!tree_is_left_child(current_node, nil_node) && current_node->_parent != nil_node)
		{
			current_node = current_node->_parent;
		}
		return current_node->_parent;
	}

	template <class _NodePtr>
	_NodePtr
	tree_prev(_NodePtr current_node, _NodePtr nil_node)
	{
		if (current_node->_left != nil_node)
			return tree_max(current_node->_left, nil_node);
		while (tree_is_left_child(current_node, nil_node))
			current_node = current_node->_parent;
		return current_node->_parent;
	}
}
#endif
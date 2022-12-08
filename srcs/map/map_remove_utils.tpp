#ifndef MAP_REMOVE_UTILS_TPP
# define MAP_REMOVE_UTILS_TPP

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::map_remove(typename ft::map<Key, T, Compare, Alloc>::node_pointer delete_node)
{
	bool removed_black = false;
	node_pointer y;
	if (delete_node->_left == nullptr_f || delete_node->_right == nullptr_f)
		y = delete_node;
	else
	{
		node_pointer current_node = delete_node;
		if (current_node->_right != nullptr_f)
			y = tree_min(current_node->_right);
		else
		{
			while (!tree_is_left_child(current_node) && current_node->_parent)
				current_node = current_node->_parent;
			y = current_node->_parent;
		}
	}
	node_pointer x;
	if(y->_left != nullptr_f)
		x = y->_left;
	else
		x = y->_right;
	node_pointer w = nullptr_f;
	if (x != nullptr_f)
		x->_parent = y->_parent;
	if (y == _root)
		_root = x;
	else if (tree_is_left_child(y))
	{
		y->_parent->_left = x;
		w = y->_parent->_right;
	}
	else
	{
		y->_parent->_right = x;
		w = y->_parent->_left;
	}
	if (y->_color == BLACK)
		removed_black = true;
	if (_root == delete_node)
		changeY2Root(y, delete_node);
	else if (y != delete_node)
		removeYConnectionToDeleteNode(y, delete_node);
	if (removed_black && _root != nullptr_f)
	{
		if (x != nullptr_f)
			x->_color = BLACK;
		else
			balanceTreeAfterDelete(x, w);
	}
}

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::removeYConnectionToDeleteNode(typename ft::map<Key, T, Compare, Alloc>::node_pointer y, typename ft::map<Key, T, Compare, Alloc>::node_pointer delete_node)
{
	y->_parent = delete_node->_parent;
	if (tree_is_left_child(delete_node))
		y->_parent->_left = y;
	else
		y->_parent->_right = y;
	y->_left = delete_node->_left;
	y->_left->_parent = y;
	y->_right = delete_node->_right;
	if (y->_right != nullptr_f)
		y->_right->_parent = y;
	y->_color = delete_node->_color;
}
template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::changeY2Root(typename ft::map<Key, T, Compare, Alloc>::node_pointer y, typename ft::map<Key, T, Compare, Alloc>::node_pointer delete_node)
{
	y->_parent = delete_node->_parent;
	y->_left = delete_node->_left;
	y->_left->_parent = y;
	y->_right = delete_node->_right;
	if (y->_right != nullptr_f)
		y->_right->_parent = y;
	y->_color = delete_node->_color;
	_root = y;
}

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::balanceTreeAfterDelete(typename ft::map<Key, T, Compare, Alloc>::node_pointer x, typename ft::map<Key, T, Compare, Alloc>::node_pointer w)
{
	while (true)
	{
		if (!tree_is_left_child(w))
		{
			if (w->_color == RED)
			{
				w->_color = BLACK;
				w->_parent->_color = RED;
				RotateL(w->_parent);
				if (_root == w->_left)
					_root = w;
				w = w->_left->_right;
			}
			if (w == nullptr_f)
				break;
			if ((w->_left  == nullptr_f || w->_left->_color == BLACK) &&
				(w->_right == nullptr_f || w->_right->_color == BLACK))
			{
				w->_color = RED;
				x = w->_parent;
				if (x == _root || x->_color == RED)
				{
					x->_color = BLACK;
					break;
				}
				w = tree_is_left_child(x) ?
							x->_parent->_right : 
							x->_parent->_left; 
			}
			else
			{
				if (w->_right == nullptr_f || w->_right->_color == BLACK)
				{
					w->_left->_color = BLACK;
					w->_color = RED;
					RotateR(w);
					w = w->_parent;
				}
				w->_color = w->_parent->_color;
				w->_parent->_color = BLACK;
				w->_right->_color = BLACK;
				RotateL(w->_parent);
				break;
			}
		}
		else
		{
			if (w->_color == RED)
			{
				w->_color = BLACK;
				w->_parent->_color = RED;
				RotateR(w->_parent);
				if (_root == w->_right)
					_root = w;
				w = w->_right->_left;
			}
			if (w == nullptr_f)
				break;
			if ((w->_left  == nullptr_f || w->_left->_color == BLACK) &&
				(w->_right == nullptr_f || w->_right->_color == BLACK))
			{
				w->_color = RED;
				x = w->_parent;
				if (x->_color == RED || x == _root)
				{
					x->_color = BLACK;
					break;
				}
				w = tree_is_left_child(x) ?
							x->_parent->_right : 
							x->_parent->_left; 
			}
			else
			{
				if (w->_left == nullptr_f || w->_left->_color  == BLACK)
				{
					w->_right->_color = BLACK;
					w->_color = RED;
					RotateL(w);
					w = w->_parent;
				}
				w->_color = w->_parent->_color;
				w->_parent->_color = BLACK;
				w->_left->_color = BLACK;
				RotateR(w->_parent);
				break;
			}
		}
	}
}
#endif
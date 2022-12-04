#ifndef MAP_REMOVE_UTILS_TPP
# define MAP_REMOVE_UTILS_TPP

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::rb_transplant(typename ft::map<Key, T, Compare, Alloc>::node_pointer u, typename ft::map<Key, T, Compare, Alloc>::node_pointer v)
{
	if (u->_parent = _nil)
		_root = v;
	else if (u == u->_parent->_left)
		u->_parent->_left = v;
	else
		u->_parent->_right = v;
	v->_parent = u->_parent;
}

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::map_remove(typename ft::map<Key, T, Compare, Alloc>::node_pointer delete_node)
{
	// bool removed_black = false;
	// node_pointer y = (delete_node->_left == _nil || delete_node->_right == _nil) ?
	// 					delete_node : tree_next(delete_node, _nil);
	// node_pointer x = y->_left != _nil ? y->_left : y->_right;
	// node_pointer w = _nil;
	// if (x != _nil)
	// 	x->_parent = y->_parent;
	// if (y == _root)
	// 	_root = x;
	// else if (tree_is_left_child(y, _nil))
	// {
	// 	y->_parent->_left = x;
	// 	w = y->_parent->_right;
	// }
	// else
	// {
	// 	y->_parent->_right = x;
	// 	w = y->_parent->_left;
	// }
	// if (y->_color == BLACK)
	// 	removed_black = true;
	// if (_root == delete_node)
	// 	changeY2Root(y, delete_node);
	// else if (y != delete_node)
	// 	removeYConnectionToDeleteNode(y, delete_node);
	// if (removed_black && _root != _nil)
	// {
	// 	if (x != _nil)
	// 		x->_color = BLACK;
	// 	else
	// 		balanceTreeAfterDelete(x, w);
	// }
	node_pointer y = delete_node;
	node_pointer x;
	int y_original_color = y->_color;
	if (delete_node->_left == _nil)
	{
		x = delete_node->_right;
		rb_transplant(delete_node, delete_node->_right);
	}
	else if (delete_node->_right == _nil)
	{
		x == delete_node->_left;
		rb_transplant(delete_node, delete_node->_left);
	}
	else
	{
		y = tree_min(delete_node->_right)
		y_original_color = y->_color;
		x = y->_right;
		if (y->_parent == delete_node)
			x->_parent = y;
		else
		{
			rb_transplant(y, y->_right);
			y->_right = z->_right;
			y->_right->_parent = y;
		}
		rb_transplant(delete_node, y);
		y->_left = delete_node->_left;
		y->_left->_parent = y;
		y->_color = delete_node->_color
	}
	node_pointer w;
	if (y_original_color == BLACK)
	{
		while (x != _root && x->_color == BLACK)
		{
			if (x == x->_parent->_left)
			{
				w = x->_parent->_right;
				if (w->_color == RED)
				{
					w->_color = BLACK;
					x->_parent->_color = RED;
					RotateL(x->_parent);
					w = w->_parent->_right;
				}
				if (w->_left->_color == BLACK && w->_right->_color == BLACK)
				{
					w->_color = RED;
					x = x->_parent;
				}
				else if (w->_right->_color == BLACK)
				{
					w->_left->_color = BLACK;
					w->_color = RED;
					RotateR(w);
					w = x->_parent->_right;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = BLACK;
				w->_right->_color = BLACK;
				RotateL(x->_parent);
				x = _root;
			}
			else
			{
				w = x->_parent->_left;
				if (w->_color == RED)
				{
					w->_color = BLACK;
					x->_parent->_color = RED;
					RotateR(x->_parent);
					w = w->_parent->_left;
				}
				if (w->_right->_color == BLACK && w->_left->_color == BLACK)
				{
					w->_color = RED;
					x = x->_parent;
				}
				else if (w->_left->_color == BLACK)
				{
					w->_right->_color = BLACK;
					w->_color = RED;
					RotateL(w);
					w = x->_parent->_left;
				}
				w->_color = x->_parent->_color;
				x->_parent->_color = BLACK;
				w->_left->_color = BLACK;
				RotateR(x->_parent);
				x = _root;
			}
		}
		x->_color = BLACK;
	}
}

template <class Key, class T, class Compare, class Alloc>
void
ft::map<Key, T, Compare, Alloc>::removeYConnectionToDeleteNode(typename ft::map<Key, T, Compare, Alloc>::node_pointer y, typename ft::map<Key, T, Compare, Alloc>::node_pointer delete_node)
{
	y->_parent = delete_node->_parent;
	if (tree_is_left_child(delete_node, _nil))
		y->_parent->_left = y;
	else
		y->_parent->_right = y;
	y->_left = delete_node->_left;
	y->_left->_parent = y;
	y->_right = delete_node->_right;
	if (y->_right != _nil)
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
	if (y->_right != _nil)
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
		if (!tree_is_left_child(w, _nil))
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
			if (w == _nil)
				break;
			if ((w->_left  == _nil || w->_left->_color == BLACK) &&
				(w->_right == _nil || w->_right->_color == BLACK))
			{
				w->_color = RED;
				x = w->_parent;
				if (x == _root || x->_color == RED)
				{
					x->_color = BLACK;
					break;
				}
				w = tree_is_left_child(x, _nil) ?
							x->_parent->_right : 
							x->_parent->_left; 
			}
			else
			{
				if (w->_right == _nil || w->_right->_color == BLACK)
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
			if (w == _nil)
				break;
			if ((w->_left  == _nil || w->_left->_color == BLACK) &&
				(w->_right == _nil || w->_right->_color == BLACK))
			{
				w->_color = RED;
				x = w->_parent;
				if (x->_color == RED || x == _root)
				{
					x->_color = BLACK;
					break;
				}
				w = tree_is_left_child(x, _nil) ?
							x->_parent->_right : 
							x->_parent->_left; 
			}
			else
			{
				if (w->_left == _nil || w->_left->_color  == BLACK)
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
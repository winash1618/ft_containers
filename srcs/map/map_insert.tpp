#ifndef MAP_INSERT_TPP
# define MAP_INSERT_TPP

 
template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>
ft::map<Key, T, Compare, Alloc>::insert (const value_type& val)
{
	if (_root == _nil)
	{
		_root = n_alloc.allocate(1);
		ft::RBTreeNode<value_type> temp(val);
		n_alloc.construct(_root, temp);
		_root->_left = _nil;
		_root->_right = _nil;
		_root->_parent = _nil;
		_root->_color = BLACK;
		ft::pair<iterator, bool> t = ft::make_pair<iterator, bool>(iterator(_root), true);
		_size = 1;
		
		return t;
	}
	node_pointer cur = _root;
	node_pointer parent = _nil;
	while (cur != _nil)
	{
		if (_comp(cur->_data.first, val.first))
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (_comp(val.first, cur->_data.first))
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			return ft::make_pair(iterator(cur), false);
		}
	}
	cur = n_alloc.allocate(1);
	ft::RBTreeNode<value_type> temp(val);
	n_alloc.construct(cur, temp);
	cur->_left = _nil;
	cur->_right = _nil;
	cur->_parent = _nil;
	node_pointer newnode = cur;
	newnode->_color = RED;
	if (_comp(parent->_data.first, val.first))
	{
		parent->_right = newnode;
		newnode->_parent = parent;
	}
	else
	{
		parent->_left = newnode;
		newnode->_parent = parent;
	}
	while (parent != _nil && parent->_color == RED)
	{
		Node* grandParent = parent->_parent;
		if (grandParent->_left == parent)
		{
			Node* uncle = grandParent->_right;
			if (uncle != _nil && uncle->_color == RED)
			{
				parent->_color = BLACK;
				uncle->_color = BLACK;
				grandParent->_color = RED;
				cur = grandParent;
				parent = cur->_parent;
			}
			else
			{
				if (parent->_left == cur)
				{
					RotateR(grandParent);
					parent->_color = BLACK;
					grandParent->_color = RED;
				}
				else
				{
					RotateL(parent);
					RotateR(grandParent);
					grandParent->_color = RED;
					cur->_color = BLACK;
				}
				break;
			}
		}
		else
		{
			node_pointer uncle = grandParent->_left;
			if (uncle != _nil && uncle->_color == RED)
			{
				uncle->_color = BLACK;
				parent->_color = BLACK;
				grandParent->_color = RED;
				cur = grandParent;
				parent = cur->_parent;
			}
			else
			{
				if (parent->_right == cur)
				{
					RotateL(grandParent);
					parent->_color = BLACK;
					grandParent->_color = RED;
				}
				else
				{
					RotateR(parent);
					RotateL(grandParent);
					cur->_color = BLACK;
					grandParent->_color = RED;
				}
				break;
			}
		}
	}
	_size++;
	_root->_color = BLACK;
	return ft::make_pair(iterator(newnode), true);
}

template <class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator
ft::map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return (insert(val).first);
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void
ft::map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last)
{
	InputIterator it = first;
	while (it != last)
	{
		insert(*it);
		it++;
	}
}
#endif
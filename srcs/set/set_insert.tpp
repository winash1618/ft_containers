#ifndef SET_INSERT_TPP
# define SET_INSERT_TPP

template < class T, class Compare, class Alloc>
ft::pair<typename ft::set<T, Compare, Alloc>::iterator, bool>
ft::set<T, Compare, Alloc>::insert (const typename ft::set<T, Compare, Alloc>::value_type& val)
{
	if (_root == nullptr_f || !_size)
	{
		_root = n_alloc.allocate(1);
		ft::RBTreeNode<typename ft::set<T, Compare, Alloc>::value_type> temp(val);
		n_alloc.construct(_root, temp);
		_root->_color = BLACK;
		ft::pair<typename ft::set<T, Compare, Alloc>::iterator, bool> t = ft::make_pair<typename ft::set<T, Compare, Alloc>::iterator, bool>(iterator(_root), true);
		_size++;
		
		return t;
	}
	node_pointer cur = _root;
	node_pointer parent = nullptr_f;
	while (cur)
	{
		if (_comp(cur->_data, val))
		{
			parent = cur;
			cur = cur->_right;
		}
		else if (_comp(val, cur->_data))
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
	ft::RBTreeNode<typename ft::set<T, Compare, Alloc>::value_type> temp(val);
	n_alloc.construct(cur, temp);
	node_pointer newnode = cur;
	newnode->_color = RED;
	if (_comp(parent->_data, val))
	{
		parent->_right = newnode;
		newnode->_parent = parent;
	}
	else
	{
		parent->_left = newnode;
		newnode->_parent = parent;
	}
	while (parent && parent->_color == RED)
	{
		Node* grandParent = parent->_parent;
		if (grandParent->_left == parent)
		{
			Node* uncle = grandParent->_right;
			if (uncle && uncle->_color == RED)
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
			if (uncle && uncle->_color == RED)
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
	return ft::make_pair(typename ft::set<T, Compare, Alloc>::iterator(newnode), true);
}

template < class T, class Compare, class Alloc>
typename ft::set<T, Compare, Alloc>::iterator
ft::set<T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	(void)position;
	return (insert(val).first);
}

template < class T, class Compare, class Alloc>
template <class InputIterator>
void
ft::set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	for(InputIterator it = first; it != last; it++)
		insert(*it);
}
#endif
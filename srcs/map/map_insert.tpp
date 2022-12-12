#ifndef MAP_INSERT_TPP
# define MAP_INSERT_TPP

 
template <class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>
ft::map<Key, T, Compare, Alloc>::insert (const value_type& val)
{
	if (_root == NULL)
	{
		_root = n_alloc.allocate(1);
		ft::RBTreeNode<value_type> temp(val);
		n_alloc.construct(_root, temp);
		_root->_color = BLACK;
		_root->_parent = _nil;
		_root->_left = _nil;
		_root->_right = _nil;
		ft::pair<iterator, bool> t = ft::make_pair<iterator, bool>(iterator(_nil, _root, _nil), true);
		_size = 1;
		return t;
	}
	node_pointer cur = _root;
	node_pointer parent = cur;
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
			return ft::make_pair(iterator(_nil, cur, _nil), false);
		}
	}
	cur = n_alloc.allocate(1);
	ft::RBTreeNode<value_type> temp(val);
	n_alloc.construct(cur, temp);
	cur->_parent = parent;
	cur->_left = _nil;
	cur->_right = _nil;
	node_pointer newnode = cur;
	newnode->_color = RED;
	if (_comp(parent->_data.first, val.first))
		parent->_right = newnode;
	else
		parent->_left = newnode;
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
	// std::cout << "inserted" << std::endl;
	// try
	// {
	// 	if (_size == 10)
	// 	{

	// 		// if (begin().__ptr_->_right == _nil)
	// 		// 	throw std::runtime_error("root right child is not nil");
	// 		if (_root->_parent != _nil)
	// 			throw std::runtime_error("root parent is not nil");
	// 		if (_root->_color != BLACK)
	// 			throw std::runtime_error("root color is not black");
	// 		if (_root->_data.first != 4)
	// 			throw std::runtime_error("root data is not 4");
	// 		if (_root->_left->_data.first != 2)
	// 			throw std::runtime_error("left child data is not 2");
	// 		if (_root->_right->_data.first != 6)
	// 			throw std::runtime_error("right child data is not 6");
	// 		if (_root->_left->_left->_data.first != 1)
	// 			throw std::runtime_error("left left child data is not 1");
	// 		if (_root->_left->_right->_data.first != 3)
	// 			throw std::runtime_error("left right child data is not 3");
	// 		if (_root->_right->_left->_data.first != 5)
	// 			throw std::runtime_error("right left child data is not 5");
	// 		if (_root->_right->_right->_data.first != 8)
	// 			throw std::runtime_error("right right child data is not 8");
	// 		if (_root->_right->_right->_left->_data.first != 7)
	// 			throw std::runtime_error("right right left child data is not 7");
	// 		if (_root->_right->_right->_right->_data.first != 9)
	// 			throw std::runtime_error("right right right child data is not 9");
	// 		if (_root->_right->_right->_right->_right->_data.first != 10)
	// 			throw std::runtime_error("right right right right child data is not 10");
	// 		if (_root->_left->_parent != _root)
	// 			throw std::runtime_error("left child parent is not root");
	// 		if (_root->_right->_parent != _root)
	// 			throw std::runtime_error("right child parent is not root");
	// 		if (_root->_left->_color != BLACK)
	// 			throw std::runtime_error("left child color is not black");
	// 		if (_root->_right->_color != BLACK)
	// 			throw std::runtime_error("right child color is not black");
	// 		if (_root->_left->_left->_parent != _root->_left)
	// 			throw std::runtime_error("left left child parent is not left child");
	// 		if (_root->_left->_right->_parent != _root->_left)
	// 			throw std::runtime_error("left right child parent is not left child");
	// 		if (_root->_right->_left->_parent != _root->_right)
	// 			throw std::runtime_error("right left child parent is not right child");
	// 		if (_root->_right->_right->_parent != _root->_right)	
	// 			throw std::runtime_error("right right child parent is not right child");
	// 		if (_root->_left->_left->_color != BLACK)
	// 			throw std::runtime_error("left left child color is not black");
	// 		if (_root->_left->_right->_color != BLACK)
	// 			throw std::runtime_error("left right child color is not black");
	// 		if (_root->_right->_left->_color != BLACK)
	// 			throw std::runtime_error("right left child color is not black");
	// 		if (_root->_right->_right->_color != RED)
	// 			throw std::runtime_error("right right child color is not RED");
	// 		if (_root->_left->_left->_left != _nil)
	// 			throw std::runtime_error("left left left child is not nil");
	// 		if (_root->_left->_left->_right != _nil)
	// 			throw std::runtime_error("left left right child is not nil");
	// 		if (_root->_left->_right->_left != _nil)
	// 			throw std::runtime_error("left right left child is not nil");
	// 		if (_root->_left->_right->_right != _nil)
	// 			throw std::runtime_error("left right right child is not nil");
	// 		if (_root->_right->_left->_left != _nil)
	// 			throw std::runtime_error("right left left child is not nil");
	// 		if (_root->_right->_left->_right != _nil)
	// 			throw std::runtime_error("right left right child is not nil");
	// 		if (_root->_right->_right->_left == _nil)
	// 			throw std::runtime_error("right right left child is nil");
	// 		if (_root->_right->_right->_right == _nil)
	// 			throw std::runtime_error("right right right child is nil");
	// 		if (_root->_right->_right->_left->_color != BLACK)
	// 			throw std::runtime_error("right right left child color is not black");
	// 		if (_root->_right->_right->_right->_color != BLACK)
	// 			throw std::runtime_error("right right right child color is not black");
	// 		if (_root->_right->_right->_left->_left != _nil)
	// 			throw std::runtime_error("right right left left child is not nil");
	// 		if (_root->_right->_right->_left->_right != _nil)
	// 			throw std::runtime_error("right right left right child is not nil");
	// 		if (_root->_right->_right->_right->_left != _nil)
	// 			throw std::runtime_error("right right right left child is not nil");
	// 		if (_root->_right->_right->_right->_right == _nil)
	// 			throw std::runtime_error("right right right right child is nil");
	// 		if (_root->_right->_right->_right->_right->_color != RED)
	// 			throw std::runtime_error("right right right right child color is not red");
	// 		if (_root->_right->_right->_right->_right->_left != _nil)
	// 			throw std::runtime_error("right right right right left child is not nil");
	// 		if (_root->_right->_right->_right->_right->_right != _nil)
	// 			throw std::runtime_error("right right right right right child is not nil");
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// 	exit(1);
	// }
	
	return ft::make_pair(iterator(_nil, newnode, _nil), true);
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
		// std::cout << "inserting " << it->first << std::endl;
		insert(*it);
		it++;
	}
	// std::cout << "inserted" << std::endl;
	// try
	// {
	// 	// if (begin().__ptr_->_right == _nil)
	// 	// 	throw std::runtime_error("root right child is not nil");
	// 	if (_root->_parent != _nil)
	// 		throw std::runtime_error("root parent is not nil");
	// 	if (_root->_color != BLACK)
	// 		throw std::runtime_error("root color is not black");
	// 	if (_root->_left->_parent != _root)
	// 		throw std::runtime_error("left child parent is not root");
	// 	if (_root->_right->_parent != _root)
	// 		throw std::runtime_error("right child parent is not root");
	// 	if (_root->_left->_color != BLACK)
	// 		throw std::runtime_error("left child color is not black");
	// 	if (_root->_right->_color != BLACK)
	// 		throw std::runtime_error("right child color is not black");
	// 	if (_root->_left->_left->_parent != _root->_left)
	// 		throw std::runtime_error("left left child parent is not left child");
	// 	if (_root->_left->_right->_parent != _root->_left)
	// 		throw std::runtime_error("left right child parent is not left child");
	// 	if (_root->_right->_left->_parent != _root->_right)
	// 		throw std::runtime_error("right left child parent is not right child");
	// 	if (_root->_right->_right->_parent != _root->_right)	
	// 		throw std::runtime_error("right right child parent is not right child");
	// 	if (_root->_left->_left->_color != BLACK)
	// 		throw std::runtime_error("left left child color is not black");
	// 	if (_root->_left->_right->_color != BLACK)
	// 		throw std::runtime_error("left right child color is not black");
	// 	if (_root->_right->_left->_color != BLACK)
	// 		throw std::runtime_error("right left child color is not black");
	// 	if (_root->_right->_right->_color != RED)
	// 		throw std::runtime_error("right right child color is not RED");
	// 	if (_root->_left->_left->_left != _nil)
	// 		throw std::runtime_error("left left left child is not nil");
	// 	if (_root->_left->_left->_right != _nil)
	// 		throw std::runtime_error("left left right child is not nil");
	// 	if (_root->_left->_right->_left != _nil)
	// 		throw std::runtime_error("left right left child is not nil");
	// 	if (_root->_left->_right->_right != _nil)
	// 		throw std::runtime_error("left right right child is not nil");
	// 	if (_root->_right->_left->_left != _nil)
	// 		throw std::runtime_error("right left left child is not nil");
	// 	if (_root->_right->_left->_right != _nil)
	// 		throw std::runtime_error("right left right child is not nil");
	// 	if (_root->_right->_right->_left == _nil)
	// 		throw std::runtime_error("right right left child is nil");
	// 	if (_root->_right->_right->_right == _nil)
	// 		throw std::runtime_error("right right right child is nil");
	// 	if (_root->_right->_right->_left->_color != BLACK)
	// 		throw std::runtime_error("right right left child color is not black");
	// 	if (_root->_right->_right->_right->_color != BLACK)
	// 		throw std::runtime_error("right right right child color is not black");
	// 	if (_root->_right->_right->_left->_left != _nil)
	// 		throw std::runtime_error("right right left left child is not nil");
	// 	if (_root->_right->_right->_left->_right != _nil)
	// 		throw std::runtime_error("right right left right child is not nil");
	// 	if (_root->_right->_right->_right->_left != _nil)
	// 		throw std::runtime_error("right right right left child is not nil");
	// 	if (_root->_right->_right->_right->_right == _nil)
	// 		throw std::runtime_error("right right right right child is nil");
	// 	if (_root->_right->_right->_right->_right->_color != RED)
	// 		throw std::runtime_error("right right right right child color is not red");
	// 	if (_root->_right->_right->_right->_right->_left != _nil)
	// 		throw std::runtime_error("right right right right left child is not nil");
	// 	if (_root->_right->_right->_right->_right->_right != _nil)
	// 		throw std::runtime_error("right right right right right child is not nil");
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// 	exit(1);
	// }
}
#endif
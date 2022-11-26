#ifndef SET_HPP
# define SET_HPP
# include "pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "set_iterator.hpp"
# include "reverse_iterator.hpp"
# include "const_set_iterator.hpp"

namespace ft
{
template < class T,                        // set::key_type/value_type
			class Compare = std::less<T>,        // set::key_compare/value_compare
			class Alloc = std::allocator<T>      // set::allocator_type
		> class set
		{
			public:
				typedef T																	key_type;
				typedef T																	value_type;
				typedef Compare																key_compare;
				typedef key_compare															value_compare;
				typedef Alloc																allocator_type;
				typedef value_type&															reference;
				typedef const value_type&													const_reference;
			private:
				typedef T																	__value_type;
				typedef typename allocator_type::template rebind<__value_type>::other		__allocator_type;
				typedef RBTreeNode<value_type>												Node;
				typedef Node																__node_pointer;
				typedef typename __allocator_type::template rebind<__node_pointer>::other	__node_allocator;

			public:
				typedef typename allocator_type::pointer									pointer;
				typedef typename allocator_type::const_pointer								const_pointer;
				typedef typename allocator_type::size_type									size_type;
				typedef typename allocator_type::difference_type							difference_type;
				typedef typename __node_allocator::pointer									node_pointer;
				typedef ft::__const_set_iterator<value_type, allocator_type>				iterator;
				typedef ft::__const_set_iterator<value_type, allocator_type>				const_iterator;
				// typedef ft::set_iterator<value_type, __node_pointer>						iterator;
				// typedef ft::set_iterator<value_type, __node_pointer>						const_iterator;
				typedef ft::reverse_iterator<iterator>										reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			private:
				node_pointer																_root;
				key_compare																	_comp;
				allocator_type																_alloc;
				__node_allocator															n_alloc;
				size_type																	_size;

			public:
				explicit set (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
				// {
				// }
				template <class InputIterator>
				set (InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());
				// {
				// 	insert(first, last);
				// }
				set (const set& x);
				// {
				// 	*this = x;
				// 	return;
				// }

				~set();
				// {destroy(_root);}

				set& operator=(const set& x);
				// {
				// 	if (this != &x)
				// 	{
				// 		value_comp() = x.value_comp();
				// 		_alloc = x.get_allocator();
				// 		_comp = x._comp;
				// 		n_alloc = x.n_alloc;
				// 		_size = 0;
				// 		_root = nullptr_f;
						
				// 		insert(x.begin(), x.end());
				// 	}
				// 	return *this;
				// }

				iterator begin();
				// {
				// 	node_pointer left = _root;
				// 	while (left && left->_left)
				// 	{
				// 		left = left->_left;
				// 	}
				// 	node_pointer right = _root;
				// 	while (right && right->_right)
				// 	{
				// 		right = right->_right;
				// 	}
				// 	return iterator(right, left);
				// }

				const_iterator begin() const;
				// {
				// 	node_pointer left = _root;
				// 	while (left && left->_left)
				// 	{
				// 		left = left->_left;
				// 	}
				// 	node_pointer right = _root;
				// 	while (right && right->_right)
				// 	{
				// 		right = right->_right;
				// 	}
				// 	return const_iterator(right, left);
				// }

				iterator end();
				// {
				// 	node_pointer right = _root;
				// 	while (right && right->_right)
				// 	{
				// 		right = right->_right;
				// 	}
				// 	return iterator(right, nullptr_f);
				// }
				const_iterator end() const;
				// {
				// 	node_pointer right = _root;
				// 	while (right && right->_right)
				// 	{
				// 		right = right->_right;
				// 	}
				// 	return const_iterator(right, nullptr_f);
				// }

				size_type count (const key_type& k) const;
				// {
				// 	size_type counter = 0;
				// 	const_iterator search = begin();
				// 	while (search != end())
				// 	{
				// 		if ( *search == k)
				// 			counter++;
				// 		search++;
				// 	}
				// 	return (counter);
				// }

				bool empty() const;
				// {
				// 	if (_size == 0)
				// 		return true;
				// 	return false;
				// }

				iterator find (const key_type& k);
				// {
				// 	node_pointer cur = _root;
				// 	node_pointer parent = nullptr_f;
				// 	while (cur)
				// 	{
				// 		if (_comp(cur->_data, k))
				// 		{
				// 			parent = cur;
				// 			cur = cur->_right;
				// 		}
				// 		else if (_comp(k, cur->_data))
				// 		{
				// 			parent = cur;
				// 			cur = cur->_left;
				// 		}
				// 		else
				// 		{
				// 			return (iterator(cur));
				// 		}
				// 	}
				// 	return (end());
				// }
				const_iterator find (const key_type& k) const;
				// {
				// 	node_pointer cur = _root;
				// 	node_pointer parent = nullptr_f;
				// 	while (cur)
				// 	{
				// 		if (_comp(cur->_data, k))
				// 		{
				// 			parent = cur;
				// 			cur = cur->_right;
				// 		}
				// 		else if (_comp(k, cur->_data))
				// 		{
				// 			parent = cur;
				// 			cur = cur->_left;
				// 		}
				// 		else
				// 		{
				// 			return (iterator(cur));
				// 		}
				// 	}
				// 	return (end());
				// }


				iterator lower_bound (const key_type& k);
				// {
				// 	node_pointer __root = _root;
				// 	node_pointer __result = nullptr_f;
				// 	while (__root != nullptr_f)
				// 	{
				// 		if (!_comp(__root->_data, k))
				// 		{
				// 			__result = __root;
				// 			__root = __root->_left;
				// 		}
				// 		else
				// 			__root = __root->_right;
				// 	}
				// 	if (__result)
				// 		return iterator(__result);
				// 	return (end());
				// }

				iterator upper_bound (const key_type& k);
				// {
				// 	node_pointer __root = _root;
				// 	node_pointer __result = nullptr_f;
				// 	while (__root != nullptr_f)
				// 	{
				// 		if (_comp( k, __root->_data))
				// 		{
				// 			__result = __root;
				// 			__root = __root->_left;
				// 		}
				// 		else
				// 			__root = __root->_right;
				// 	}
				// 	if (__result)
				// 		return iterator(__result);
				// 	return (end());
				// }
				const_iterator lower_bound (const key_type& k) const;
				// {
				// 	node_pointer __root = _root;
				// 	node_pointer __result = nullptr_f;
				// 	while (__root != nullptr_f)
				// 	{
				// 		if (!_comp(__root->_data, k))
				// 		{
				// 			__result = __root;
				// 			__root = __root->_left;
				// 		}
				// 		else
				// 			__root = __root->_right;
				// 	}
				// 	if (__result)
				// 		return const_iterator(__result);
				// 	return (end());
				// }
				const_iterator upper_bound (const key_type& k) const;
				// {
				// 	node_pointer __root = _root;
				// 	node_pointer __result = nullptr_f;
				// 	while (__root != nullptr_f)
				// 	{
				// 		if (_comp( k, __root->_data))
				// 		{
				// 			__result = __root;
				// 			__root = __root->_left;
				// 		}
				// 		else
				// 			__root = __root->_right;
				// 	}
				// 	if (__result)
				// 		return const_iterator(__result);
				// 	return (end());
				// }
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
				// {return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));}
				pair<iterator,iterator> equal_range (const key_type& k);
				// {return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));}
				allocator_type get_allocator() const;
				// {return (this->_alloc);}
				key_compare key_comp() const;
				// {return (this->_comp);}
				value_compare value_comp() const;
				// {return value_compare(_comp);}
				size_type size() const;
				// {return (_size);}
				size_type max_size() const;
				// {return (n_alloc.max_size());}
				reverse_iterator rbegin();
																		// {return reverse_iterator(this->end());}
				reverse_iterator rend();
																		// {return reverse_iterator(this->begin()); }
				const_reverse_iterator rbegin() const;
															// {return const_reverse_iterator(this->end());}
				const_reverse_iterator rend() const;
															// {return const_reverse_iterator(this->begin()); }
				void clear();
																					// {destroy(_root); _size = 0; _root = nullptr_f;}
				// single element insert
				ft::pair<iterator,bool> insert (const value_type& val);
				// {
				// 	if (_root == nullptr_f || !_size)
				// 	{
				// 		_root = n_alloc.allocate(1);
				// 		ft::RBTreeNode<value_type> temp(val);
				// 		n_alloc.construct(_root, temp);
				// 		_root->_color = BLACK;
				// 		ft::pair<iterator, bool> t = ft::make_pair<iterator, bool>(iterator(_root), true);
				// 		_size++;
						
				// 		return t;
				// 	}
				// 	node_pointer cur = _root;
				// 	node_pointer parent = nullptr_f;
				// 	while (cur)
				// 	{
				// 		if (_comp(cur->_data, val))
				// 		{
				// 			parent = cur;
				// 			cur = cur->_right;
				// 		}
				// 		else if (_comp(val, cur->_data))
				// 		{
				// 			parent = cur;
				// 			cur = cur->_left;
				// 		}
				// 		else
				// 		{
				// 			return ft::make_pair(iterator(cur), false);
				// 		}
				// 	}
				// 	cur = n_alloc.allocate(1);
				// 	ft::RBTreeNode<value_type> temp(val);
				// 	n_alloc.construct(cur, temp);
				// 	node_pointer newnode = cur;
				// 	newnode->_color = RED;
				// 	if (_comp(parent->_data, val))
				// 	{
				// 		parent->_right = newnode;
				// 		newnode->_parent = parent;
				// 	}
				// 	else
				// 	{
				// 		parent->_left = newnode;
				// 		newnode->_parent = parent;
				// 	}
				// 	while (parent && parent->_color == RED)
				// 	{
				// 		Node* grandParent = parent->_parent;
				// 		if (grandParent->_left == parent)
				// 		{
				// 			Node* uncle = grandParent->_right;
				// 			if (uncle && uncle->_color == RED)
				// 			{     
				// 				parent->_color = BLACK;
				// 				uncle->_color = BLACK;
				// 				grandParent->_color = RED;
				// 				cur = grandParent;
				// 				parent = cur->_parent;
				// 			}
				// 			else
				// 			{
				// 				if (parent->_left == cur)
				// 				{
				// 					RotateR(grandParent);
				// 					parent->_color = BLACK;
				// 					grandParent->_color = RED;
				// 				}
				// 				else
				// 				{
				// 					RotateL(parent);
				// 					RotateR(grandParent);
				// 					grandParent->_color = RED;
				// 					cur->_color = BLACK;
				// 				}
				// 				break;
				// 			}
				// 		}
				// 		else 
				// 		{
				// 			node_pointer uncle = grandParent->_left;
				// 			if (uncle && uncle->_color == RED)
				// 			{
				// 				uncle->_color = BLACK;
				// 				parent->_color = BLACK;
				// 				grandParent->_color = RED;
				// 				cur = grandParent;
				// 				parent = cur->_parent;
				// 			}
				// 			else
				// 			{
				// 				if (parent->_right == cur)
				// 				{
				// 					RotateL(grandParent);
				// 					parent->_color = BLACK;
				// 					grandParent->_color = RED;
				// 				}
				// 				else
				// 				{
				// 					RotateR(parent);
				// 					RotateL(grandParent);
				// 					cur->_color = BLACK;
				// 					grandParent->_color = RED;
				// 				}
				// 				break;
				// 			}
				// 		}
				// 	}
				// 	_size++;
				// 	_root->_color = BLACK;
				// 	return ft::make_pair(iterator(newnode), true);
				// }
				// with hint insert	
				iterator insert (iterator position, const value_type& val);
				// {
				// 	(void)position;
				// 	return (insert(val).first);
				// }
				// range insert
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last);
				// {
				// 	for(InputIterator it = first; it != last; it++)
				// 		insert(*it);
				// }
				void swap (set& x);
				// {
				// 	node_pointer		t_root = x._root;
				// 	key_compare			t_comp = x._comp;
				// 	allocator_type		t_alloc = x._alloc;
				// 	__node_allocator	tn_alloc = x.n_alloc;
				// 	size_type			t_size = x._size;
				// 	x._root = _root;
				// 	x._comp = _comp;
				// 	x._alloc = _alloc;
				// 	x.n_alloc = n_alloc;
				// 	x._size = _size;
				// 	_root = t_root;
				// 	_comp = t_comp;
				// 	_alloc = t_alloc;
				// 	n_alloc = tn_alloc;
				// 	_size = t_size;
				// }
				
				void erase(iterator position);
				// {
				// 	node_pointer __root; // -> red–black tree
				// 	node_pointer __node; // -> node to be deleted

				// 	__node = const_cast<node_pointer>(position.__ptr_);
				// 	__root = _root;
				// 	if (!__node || !__root)
				// 		return ;
				// 	n_alloc.destroy(__node);
				// 	tree_remove( __node);
				// 	n_alloc.deallocate(__node, 1);
				// 	_size--;
				// }
				
				size_type erase (const key_type& k);
				// {
				// 	node_pointer __nd;
				// 	__nd = const_cast<node_pointer>(find(k).__ptr_);
				// 	if(__nd)
				// 	{
				// 		erase(find(k));
				// 		return (1);
				// 	}
				// 	return 0;
				// }
				void erase (iterator first, iterator last);
				// {
				// 	while (first != last)
				// 	{
				// 		iterator temp = first;
				// 		first++;
				// 		erase(temp);
				// 	}
				// }

			private:
				const			node_pointer begin_left(void) const;
				const			node_pointer begin_right(void) const;
				node_pointer	begin_left(void);
				node_pointer	begin_right(void);
				void destroy(node_pointer __nd);
				// {
				// 	if (__nd != nullptr_f)
				// 	{
				// 		destroy(__nd->_left);
				// 		destroy(__nd->_right);
				// 		__node_allocator __na;
				// 		__na.destroy(__nd);
				// 		__na.deallocate( __nd, 1);
				// 	}
				// }
				void RotateL(node_pointer parent);
				// {
				// 	node_pointer subR = parent->_right;
				// 	node_pointer subRL = subR->_left;
				// 	node_pointer parentParent = parent->_parent;
				// 	parent->_right = subRL;
				// 	subR->_left = parent;
				// 	parent->_parent = subR;
				// 	if (subRL)
				// 		subRL->_parent = parent;
				// 	if (_root == parent)
				// 	{
				// 		_root = subR;
				// 		_root -> _parent = nullptr_f;
				// 	}
				// 	else
				// 	{
				// 		if (parentParent->_left == parent)
				// 			parentParent->_left = subR;
				// 		else
				// 			parentParent->_right = subR;
				// 		subR->_parent = parentParent;
				// 	}
				// }

				void RotateR(node_pointer parent);
				// {
				// 	node_pointer subL = parent->_left;
				// 	node_pointer subLR = subL->_right;
				// 	node_pointer parentParent = parent->_parent;

				// 	parent->_left = subLR;
				// 	subL->_right = parent;
				// 	if (subLR)
				// 		subLR->_parent = parent;
				// 	parent->_parent = subL;
				// 	if (_root == parent)
				// 	{
				// 		_root = subL;
				// 		_root->_parent = nullptr_f;
				// 	}
				// 	else
				// 	{
				// 		if (parentParent->_left == parent)
				// 			parentParent->_left = subL;
				// 		else
				// 			parentParent->_right = subL;
				// 		subL->_parent = parentParent;
				// 	}
				// }

				void			set_remove(node_pointer delete_node);
				void			removeYConnectionToDeleteNode(node_pointer y, node_pointer delete_node);
				void			changeY2Root(node_pointer y, node_pointer delete_node);
				void			balanceTreeAfterDelete(node_pointer x, node_pointer w);
				// void tree_remove(node_pointer delete_node);
				// {
				// 	bool removed_black = false;
				// 	node_pointer y = (delete_node->_left == nullptr_f || delete_node->_right == nullptr_f) ?
				// 					delete_node : tree_next(delete_node);
				// 	node_pointer x = y->_left != nullptr_f ? y->_left : y->_right;
				// 	node_pointer w = nullptr_f;
				// 	if (x != nullptr_f)
				// 		x->_parent = y->_parent;
				// 	if (y == _root)
				// 		_root = x;
				// 	else if (tree_is_left_child(y))
				// 	{
				// 		y->_parent->_left = x;
				// 		w = y->_parent->_right;
				// 	}
				// 	else
				// 	{
				// 		y->_parent->_right = x;
				// 		w = y->_parent->_left;
				// 	}
				// 	if (y->_color == BLACK)
				// 		removed_black = true;
				// 	if (_root == delete_node)
				// 	{
				// 		y->_parent = delete_node->_parent;
				// 		y->_left = delete_node->_left;
				// 		y->_left->_parent = y;
				// 		y->_right = delete_node->_right;
				// 		if (y->_right != nullptr_f)
				// 			y->_right->_parent = y;
				// 		y->_color = delete_node->_color;
				// 		_root = y;
				// 	}
				// 	else if (y != delete_node)
				// 	{
				// 		y->_parent = delete_node->_parent;
				// 		if (tree_is_left_child(delete_node))
				// 			y->_parent->_left = y;
				// 		else
				// 			y->_parent->_right = y;
				// 		y->_left = delete_node->_left;
				// 		y->_left->_parent = y;
				// 		y->_right = delete_node->_right;
				// 		if (y->_right != nullptr_f)
				// 			y->_right->_parent = y;
				// 		y->_color = delete_node->_color;
				// 	}
				// 	if (removed_black && _root != nullptr_f)
				// 	{
				// 		if (x != nullptr_f)
				// 			x->_color = BLACK;
				// 		else
				// 		{
				// 			while (true)
				// 			{
				// 				if (!tree_is_left_child(w))
				// 				{
				// 					if (w->_color == RED)
				// 					{
				// 						w->_color = BLACK;
				// 						w->_parent->_color = RED;
				// 						RotateL(w->_parent);
				// 						if (_root == w->_left)
				// 							_root = w;
				// 						w = w->_left->_right;
				// 					}
				// 					if (w == nullptr_f)
				// 						break;
				// 					if ((w->_left  == nullptr_f || w->_left->_color == BLACK) &&
				// 						(w->_right == nullptr_f || w->_right->_color == BLACK))
				// 					{
				// 						w->_color = RED;
				// 						x = w->_parent;
				// 						if (x == _root || x->_color == RED)
				// 						{
				// 							x->_color = BLACK;
				// 							break;
				// 						}
				// 						w = tree_is_left_child(x) ?
				// 									x->_parent->_right : 
				// 									x->_parent->_left; 
				// 					}
				// 					else
				// 					{
				// 						if (w->_right == nullptr_f || w->_right->_color == BLACK)
				// 						{
				// 							w->_left->_color = BLACK;
				// 							w->_color = RED;
				// 							RotateR(w);
				// 							w = w->_parent;
				// 						}
				// 						w->_color = w->_parent->_color;
				// 						w->_parent->_color = BLACK;
				// 						w->_right->_color = BLACK;
				// 						RotateL(w->_parent);
				// 						break;
				// 					}
				// 				}
				// 				else
				// 				{
				// 					if (w->_color == RED)
				// 					{
				// 						w->_color = BLACK;
				// 						w->_parent->_color = RED;
				// 						RotateR(w->_parent);
				// 						if (_root == w->_right)
				// 							_root = w;
				// 						w = w->_right->_left;
				// 					}
				// 					if (w == nullptr_f)
				// 						break;
				// 					if ((w->_left  == nullptr_f || w->_left->_color == BLACK) &&
				// 						(w->_right == nullptr_f || w->_right->_color == BLACK))
				// 					{
				// 						w->_color = RED;
				// 						x = w->_parent;
				// 						if (x->_color == RED || x == _root)
				// 						{
				// 							x->_color = BLACK;
				// 							break;
				// 						}
				// 						w = tree_is_left_child(x) ?
				// 									x->_parent->_right : 
				// 									x->_parent->_left; 
				// 					}
				// 					else
				// 					{
				// 						if (w->_left == nullptr_f || w->_left->_color  == BLACK)
				// 						{
				// 							w->_right->_color = BLACK;
				// 							w->_color = RED;
				// 							RotateL(w);
				// 							w = w->_parent;
				// 						}
				// 						w->_color = w->_parent->_color;
				// 						w->_parent->_color = BLACK;
				// 						w->_left->_color = BLACK;
				// 						RotateR(w->_parent);
				// 						break;
				// 					}
				// 				}
				// 			}
				// 		}
				// 	}
				// }
		};
		template <class T, class Compare, class Alloc>
		inline bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
		// {
		// 	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		// }

		template <class T, class Compare, class Alloc>
		inline bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
		// {
		// 	return !(lhs == rhs);
		// }
			
		template <class T, class Compare, class Alloc>
		inline bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
		// {
		// 	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		// }
		template <class T, class Compare, class Alloc>
		inline bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
		// {
		// 	return !(rhs < lhs);
		// }
		template <class T, class Compare, class Alloc>
		inline bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
		// {
		// 	return rhs < lhs;
		// }
		template <class T, class Compare, class Alloc>
		inline bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs );
		// {
		// 	return !(lhs < rhs);
		// }
		template <class T, class Compare, class Alloc>
		void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y);
		// {
		// 	x.swap(y);
		// }
#include "./../srcs/set/set_allocator.tpp"
#include "./../srcs/set/set_erase.tpp"
#include "./../srcs/set/set_erase_utils.tpp"
#include "./../srcs/set/set_rotate_utils.tpp"
#include "./../srcs/set/set_non_member.tpp"
#include "./../srcs/set/set_utils.tpp"
#include "./../srcs/set/set_iterators.tpp"
#include "./../srcs/set/set_init.tpp"
#include "./../srcs/set/set_operations.tpp"
#include "./../srcs/set/set_capacity.tpp"
#include "./../srcs/set/set_insert.tpp"
#include "./../srcs/set/set_swap.tpp"
#include "./../srcs/set/set_observers.tpp"

}
#endif
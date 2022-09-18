#ifndef SET_HPP
# define SET_HPP
# include "pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "tree_iterator.hpp"
# include "reverse_iterator.hpp"

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
				typedef ft::__tree_iterator<value_type, node_pointer> 						iterator;
				typedef ft::__tree_iterator<value_type, node_pointer>						const_iterator;
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
				const allocator_type& alloc = allocator_type()) : _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
				{
				}
				template <class InputIterator>
				set (InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
				{
					insert(first, last);
				}
				set (const set& x)
				{
					*this = x;
					return;
				}

				~set() {destroy(_root);}

				set& operator=(const set& x)
				{
					if (this != &x)
					{
						value_comp() = x.value_comp();
						_alloc = x.get_allocator();
						_comp = x._comp;
						n_alloc = x.n_alloc;
						_size = 0;
						_root = nullptr_f;
						insert(x.begin(), x.end());
					}
					return *this;
				}

				iterator begin()
				{
					node_pointer left = _root;
					while (left && left->_left)
					{
						left = left->_left;
					}
					node_pointer right = _root;
					while (right && right->_right)
					{
						right = right->_right;
					}
					return iterator(right, left);
				}

				const_iterator begin() const
				{
					node_pointer left = _root;
					while (left && left->_left)
					{
						left = left->_left;
					}
					node_pointer right = _root;
					while (right && right->_right)
					{
						right = right->_right;
					}
					return const_iterator(right, left);
				}

				iterator end()
				{
					node_pointer right = _root;
					while (right && right->_right)
					{
						right = right->_right;
					}
					return iterator(right, nullptr_f);
				}
				const_iterator end() const
				{
					node_pointer right = _root;
					while (right && right->_right)
					{
						right = right->_right;
					}
					return const_iterator(right, nullptr_f);
				}

				size_type count (const key_type& k) const
				{
					size_type counter = 0;
					iterator search = begin();
					while (search != end())
					{
						if ( search->first == k)
							counter++;
						search++;
					}
					return (counter);
				}

				bool empty() const
				{
					if (_size == 0)
						return true;
					return false;
				}

				iterator find (const key_type& k)
				{
					node_pointer cur = _root;
					node_pointer parent = nullptr_f;
					while (cur)
					{
						if (cur->_data < k)
						{
							parent = cur;
							cur = cur->_right;
						}
						else if (cur->_data > k)
						{
							parent = cur;
							cur = cur->_left;
						}
						else
						{
							return (iterator(cur));
						}
					}
					return (end());
				}

				pair<const_iterator,const_iterator> equal_range (const key_type& k) const		{return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));}
				pair<iterator,iterator> equal_range (const key_type& k)							{return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));}
				const_iterator lower_bound (const key_type& k) const							{return const_iterator(lower_bound(k));}
				const_iterator upper_bound (const key_type& k) const							{return const_iterator(upper_bound(k));}
				const_iterator find (const key_type& k) const									{return (const_iterator(find(k)));}
				allocator_type get_allocator() const											{return (this->_alloc);}
				key_compare key_comp() const													{return (this->_comp);}
				value_compare value_comp() const												{return value_compare(_comp);}
				size_type size() const															{return (_size);}
				size_type max_size() const														{return (n_alloc.max_size());}
				reverse_iterator rbegin()														{return reverse_iterator(this->end());}
				reverse_iterator rend()															{return reverse_iterator(this->begin()); }
				const_reverse_iterator rbegin() const											{return const_reverse_iterator(this->end());}
				const_reverse_iterator rend() const												{return const_reverse_iterator(this->begin()); };
				void clear()																	{destroy(_root); _size = 0; _root = nullptr_f;}

			
				// single element insert
				ft::pair<iterator,bool> insert (const value_type& val)
				{
					// when the size of the set is empty.
					// this will add new element to the set and return true since there is new allocation.
					// std::cout << "I am inside insert" << std::endl;
					// if (_root == nullptr_f)
					// {std::cout << _size << "<-> size" << std::endl;
					// std::cout << val.first << "<-> val" << std::endl;}
					if (_root == nullptr_f)
					{
						_root = n_alloc.allocate(1);
						ft::RBTreeNode<value_type> temp(val);
						n_alloc.construct(_root, temp);
						_root->_color = BLACK;
						ft::pair<iterator, bool> t = ft::make_pair<iterator, bool>(iterator(_root), true);
						_size++;
						
						return t;
					}
					// this is searching for a match in the current set element if there
					// is a match it will return with false since there is no allocation.
					node_pointer cur = _root;
					node_pointer parent = nullptr_f;
					while (cur)
					{
						if (cur->_data < val)
						{
							parent = cur;
							cur = cur->_right;
						}
						else if (cur->_data > val)
						{
							parent = cur;
							cur = cur->_left;
						}
						else
						{
							return ft::make_pair(iterator(cur), false);
						}
					}
					// Here we create a new node and place it in the right place and then balance the tree.
					cur = n_alloc.allocate(1);
					ft::RBTreeNode<value_type> temp(val);
					n_alloc.construct(cur, temp);
					node_pointer newnode = cur;
					newnode->_color = RED;
					if (parent->_data < val) // due to the above while the parent reach next to the null leaf. we will check where to place the node (left or right) and place the node.
					{
						parent->_right = newnode;
						newnode->_parent = parent;
					}
					else
					{
						parent->_left = newnode;
						newnode->_parent = parent;
					}
					// The next step check if we have an unbalanced tree by looking at the color of the parent. while parent exists and color of the parent is RED we will stay in the while loop.
					while (parent && parent->_color == RED)
					{
						Node* grandParent = parent->_parent;// since parent exists we set the parent->_parent to grandParent.
						if (grandParent->_left == parent) // Now checking where grandParent's child is. if left we enter the if.
						{
							Node* uncle = grandParent->_right; // since the grandParent child is left we set the grandParent right as uncle.
							/*
										/
									grandParent(B)
									/        \
								parent(R)	uncle
								|				|
					(left(R) or right(R))
						*/
							if (uncle && uncle->_color == RED) // if uncle color is red as above enter if. 
							{
								/*
										/
									grandParent(B)
									/        \
								parent(R)	uncle(R)
								|				|
						(left(R) or right(R))
						*/
								parent->_color = BLACK;
								uncle->_color = BLACK;
								grandParent->_color = RED;
								cur = grandParent;
								parent = cur->_parent;
									/*
										/
									grandParent(R)
									/        \
								parent(B)	uncle(B)
								|				|
						(left(R) or right(R))
						*/
							}
							else
							{
								if (parent->_left == cur) // Here we are checking if we put parent->_left as newnode.
								{
										/*
										/
									grandParent(B)
									/        \
								parent(R)	uncle(R)
								/				|
							left(R) 
						*/
									RotateR(grandParent);
									parent->_color = BLACK;
									grandParent->_color = RED;
									/*
											/
										grandParent(R)(rotateR)(after this rotate parent will be in position of grandParent)
										/        \
									parent(B)	uncle(R)
									/				\
								left(R)
								*/
								}
								else
								{
										/*
										/
									grandParent(B)
									/        \
								parent(R)	uncle(R)
									\			|
								right(R) 
								*/
									RotateL(parent);
									RotateR(grandParent);
									grandParent->_color = RED;
									cur->_color = BLACK;
									/*
										/
									grandParent(R)
									/        \
								parent(R)	uncle(R)
									\			|
								right(B) 
								*/
								}
								break;
							}
						}
						else // same as above but just opposite.
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
					return ft::make_pair(iterator(newnode), true);
				}
				// with hint insert	
				iterator insert (iterator position, const value_type& val)
				{
					(void)position;
					return (insert(val).first);
				}
				// range insert
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
				{
					for(InputIterator it = first; it != last; it++)
					{
						insert(*it);
					}
				}

				iterator lower_bound (const key_type& k)
				{
					node_pointer __root = _root;
					node_pointer __result = nullptr_f;
					while (__root != nullptr_f)
					{
						if (!_comp(__root->_data.first, k))
						{
							__result = __root;
							__root = __root->_left;
						}
						else
							__root = __root->_right;
					}
					if (__result)
						return iterator(__result);
					return (end());
				}

				iterator upper_bound (const key_type& k)
				{
					node_pointer __root = _root;
					node_pointer __result = nullptr_f;
					while (__root != nullptr_f)
					{
						if (_comp( k, __root->_data.first))
						{
							__result = __root;
							__root = __root->_left;
						}
						else
							__root = __root->_right;
					}
					if (__result)
						return iterator(__result);
					return (end());
				}


				void swap (set& x)
				{
					node_pointer		t_root = x._root;
					key_compare			t_comp = x._comp;
					allocator_type		t_alloc = x._alloc;
					__node_allocator	tn_alloc = x.n_alloc;
					size_type			t_size = x._size;
					x._root = _root;
					x._comp = _comp;
					x._alloc = _alloc;
					x.n_alloc = n_alloc;
					x._size = _size;
					_root = t_root;
					_comp = t_comp;
					_alloc = t_alloc;
					n_alloc = tn_alloc;
					_size = t_size;
				}
				
				void erase(iterator position)
				{
					node_pointer __root; // -> red–black tree
					node_pointer __node; // -> node to be deleted


					
					__node = const_cast<node_pointer>(position.__ptr_);
					__root = _root;
					if (!__node || !__root)
						return ;
					n_alloc.destroy(__node);
					tree_remove( __node);
					n_alloc.deallocate(__node, 1);
					_size--;
				}
				
				size_type erase (const key_type& k)
				{
					node_pointer __nd;
					__nd = const_cast<node_pointer>(find(k).__ptr_);
					if(__nd)
						erase(find(k));
					return _size;
				}
				void erase (iterator first, iterator last)
				{
					while (first != last)
					{
						iterator temp = first;
						first++;
						erase(temp);
					}
				}

			private:


				void destroy(node_pointer __nd)
				{
					if (__nd != nullptr_f)
					{
						destroy(__nd->_left);
						destroy(__nd->_right);
						__node_allocator __na;
						__na.destroy(__nd);
						__na.deallocate( __nd, 1);
					}
				}
				void RotateL(node_pointer parent)
				{
					node_pointer subR = parent->_right;
					node_pointer subRL = subR->_left;
					node_pointer parentParent = parent->_parent;
								// initial tree
									/*parentParent
										|
										parent
										/	\
											subR
											/
										subRL
										*/
					parent->_right = subRL;
					subR->_left = parent;
					parent->_parent = subR;
										/*
										parent
										/	\
											subRL
											


											subR
											/
										parent


										subR
											|
										parent
										*/

					if (subRL)
						subRL->_parent = parent;
										/*
										parent
										|
										subRL
										*/
					if (_root == parent)
					{
						_root = subR;
						_root -> _parent = nullptr_f;
					}
					else
					{
						if (parentParent->_left == parent)
							parentParent->_left = subR;
							/*
								parentParent
									/
								subR
							*/
						else
							parentParent->_right = subR;
							/*
								parentParent
									\
									subR
							*/
						subR->_parent = parentParent;
							/*
							parentParent
								|
							subR
							*/

							// final tree
							/*
							parentParent
								|
							subR(left or right)
								/
							parent
								\
								subRL
								*/
					}
				}

				void RotateR(node_pointer parent)
				{
					node_pointer subL = parent->_left;
					node_pointer subLR = subL->_right;
					node_pointer parentParent = parent->_parent;

					parent->_left = subLR;
					subL->_right = parent;
					if (subLR)
						subLR->_parent = parent;
					parent->_parent = subL;
					if (_root == parent)
					{
						_root = subL;
						_root->_parent = nullptr_f;
					}
					else
					{
						if (parentParent->_left == parent)
							parentParent->_left = subL;
						else
							parentParent->_right = subL;
						subL->_parent = parentParent;
					}
				}

				void tree_remove(node_pointer __z)
				{
					// __z will be removed from the tree.  Client still needs to destruct/deallocate it
					// __y is either __z, or if __z has two children, tree_next(__z).
					// __y will have at most one child.
					// __y will be the initial hole in the tree (make the hole at a leaf)
					// std::cout << _size << std::endl;
					// if (_size == 1)
					// {
					// 	std::cout << "HI" << std::endl;
					// 	_root = nullptr_f;
					// 	return ;
					// }
					bool __removed_black = false;
					node_pointer __y = (__z->_left == nullptr_f || __z->_right == nullptr_f) ?
									__z : tree_next(__z);
					// __x is __y's possibly null single child
					node_pointer __x = __y->_left != nullptr_f ? __y->_left : __y->_right;
					// __w is __x's possibly null uncle (will become __x's sibling)
					node_pointer __w = nullptr_f;
					// link __x to __y's parent, and find __w
					if (__x != nullptr_f)
						__x->_parent = __y->_parent;
					if (__y == _root)
						_root = __x;
					else if (tree_is_left_child(__y))
					{
						__y->_parent->_left = __x;
						__w = __y->_parent->_right;// __w == nullptr_f
					}
					else
					{
						__y->_parent->_right = __x;
						// __y can't be root if it is a right child
						__w = __y->_parent->_left;
					}
					
					if (__y->_color == BLACK)
						__removed_black = true;
					// If we didn't remove __z, do so now by splicing in __y for __z,
					//    but copy __z's color.  This does not impact __x or __w.
					if (_root == __z)
					{
						// __z->_left != nulptr but __z->_right might == __x == nullptr_f 
						__y->_parent = __z->_parent;
						__y->_left = __z->_left;
						__y->_left->_parent = __y;
						__y->_right = __z->_right;
						if (__y->_right != nullptr_f)
							__y->_right->_parent = __y;
						__y->_color = __z->_color;
						_root = __y;
					}
					else if (__y != __z)
					{
						// __z->_left != nulptr but __z->_right might == __x == nullptr_f 
						__y->_parent = __z->_parent;
						if (tree_is_left_child(__z))
							__y->_parent->_left = __y;
						else
							__y->_parent->_right = __y;
						__y->_left = __z->_left;
						__y->_left->_parent = __y;
						__y->_right = __z->_right;
						if (__y->_right != nullptr_f)
							__y->_right->_parent = __y;
						__y->_color = __z->_color;
						// if (_root == __z)
						// 	_root = __y;
					}
					// There is no need to rebalance if we removed a red, or if we removed
					//     the last node.
					if (__removed_black && _root != nullptr_f)
					{
						// Rebalance:
						// __x has an implicit black color (transferred from the removed __y)
						//    associated with it, no matter what its color is.
						// If __x is _root (in which case it can't be null), it is supposed
						//    to be black anyway, and if it is doubly black, then the double
						//    can just be ignored.
						// If __x is red (in which case it can't be null), then it can absorb
						//    the implicit black just by setting its color to black.
						// Since __y was black and only had one child (which __x points to), __x
						//   is either red with no children, else null, otherwise __y would have
						//   different black heights under left and right pointers.
						// if (__x == _root || __x != nullptr_f && !__x->_color)
						if (__x != nullptr_f)
							__x->_color = BLACK;
						else
						{
							//  Else __x isn't root, and is "doubly black", even though it may
							//     be null.  __w can not be null here, else the parent would
							//     see a black height >= 2 on the __x side and a black height
							//     of 1 on the __w side (__w must be a non-null black or a red
							//     with a non-null black child).
							while (true)
							{
								if (!tree_is_left_child(__w))  // if x is left child
								{
									if (__w->_color == RED)
									{
										__w->_color = BLACK;
										__w->_parent->_color = RED;
										RotateL(__w->_parent);
										// __x is still valid
										// reset _root only if necessary
										if (_root == __w->_left)
											_root = __w;
										// reset sibling, and it still can't be null
										__w = __w->_left->_right;
									}
									// __w->_color is now BLACK, __w may have null children
									if ((__w->_left  == nullptr_f || __w->_left->_color == BLACK) &&
										(__w->_right == nullptr_f || __w->_right->_color == BLACK))
									{
										__w->_color = RED;
										__x = __w->_parent;
										// __x can no longer be null
										if (__x == _root || __x->_color == RED)
										{
											__x->_color = BLACK;
											break;
										}
										// reset sibling, and it still can't be null
										__w = tree_is_left_child(__x) ?
													__x->_parent->_right : 
													__x->_parent->_left; 
										// continue;
									}
									else  // __w has a red child
									{
										if (__w->_right == nullptr_f || __w->_right->_color == BLACK)
										{
											// __w left child is non-null and red
											__w->_left->_color = BLACK;
											__w->_color = RED;
											RotateR(__w);
											// __w is known not to be root, so root hasn't changed
											// reset sibling, and it still can't be null
											__w = __w->_parent;
										}
										// __w has a right red child, left child may be null
										__w->_color = __w->_parent->_color;
										__w->_parent->_color = BLACK;
										__w->_right->_color = BLACK;
										RotateL(__w->_parent);
										break;
									}
								}
								else
								{
									if (__w->_color == RED)
									{
										__w->_color = BLACK;
										__w->_parent->_color = RED;
										RotateR(__w->_parent);
										// __x is still valid
										// reset _root only if necessary
										if (_root == __w->_right)
											_root = __w;
										// reset sibling, and it still can't be null
										__w = __w->_right->_left;
									}
									// __w->_color is now BLACK, __w may have null children
									if ((__w->_left  == nullptr_f || __w->_left->_color == BLACK) &&
										(__w->_right == nullptr_f || __w->_right->_color == BLACK))
									{
										__w->_color = RED;
										__x = __w->_parent;
										// __x can no longer be null
										if (__x->_color == RED || __x == _root)
										{
											__x->_color = BLACK;
											break;
										}
										// reset sibling, and it still can't be null
										__w = tree_is_left_child(__x) ?
													__x->_parent->_right : 
													__x->_parent->_left; 
										// continue;
									}
									else  // __w has a red child
									{
										if (__w->_left == nullptr_f || __w->_left->_color  == BLACK)
										{
											// __w right child is non-null and red
											__w->_right->_color = BLACK;
											__w->_color = RED;
											RotateL(__w);
											// __w is known not to be root, so root hasn't changed
											// reset sibling, and it still can't be null
											__w = __w->_parent;
										}
										// __w has a left red child, right child may be null
										__w->_color = __w->_parent->_color;
										__w->_parent->_color = BLACK;
										__w->_left->_color = BLACK;
										RotateR(__w->_parent);
										break;
									}
								}
							}
						}
					}
				}
				/*       leftRotate <==                   
				|							|
				y							x
			/   \  					  /   \
			x     a					 a     y
		/   \							 /   \
		b     c							b      c
						==> rightRotate                      */
			void leftRotate(node_pointer x)
			{
				if (x->_right || !_root->_parent)
					return ;
				node_pointer y = x->_right; // sey y
				x->_right = y->_left;  // turn y’s left subtree into x’s right subtree
				if (!y->_left) 
					y->_left->_parent = x;
				y->_parent = x->_parent;  // link x’s parent to y
				if (!x->_parent)
					_root = y;
				else if (x == x->_parent->_left)
					x->_parent->_left = y;
				else
					x->_parent->_right = y;
				y->_left = x;  // put x on y’s left
				x->_parent = y;
			}

			void rightRotate(node_pointer y)
			{
				if (y->_left || !_root->_parent)
					return ;
				node_pointer x = y->_left; // sey y
				y->_left = x->_right;  // turn y’s left subtree into x’s right subtree
				if (!x->_right) 
					x->_right->_parent = y;
				x->_parent = y->_parent;  // link x’s parent to y
				if (!y->_parent)
					_root = x;
				else if (y == y->_parent->_right)
					y->_parent->_right = x;
				else
					y->_parent->_left = x;
				x->_right = y;  // put x on y’s left
				y->_parent = x;
			}
		};
		template <class T, class Compare, class Alloc>
		inline bool operator== ( const set<T,Compare,Alloc>& lhs,
							const set<T,Compare,Alloc>& rhs )
		{
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

		template <class T, class Compare, class Alloc>
		inline bool operator!= ( const set<T,Compare,Alloc>& lhs,
							const set<T,Compare,Alloc>& rhs )
		{
			return !(lhs == rhs);
		}
			
		template <class T, class Compare, class Alloc>
		inline bool operator<  ( const set<T,Compare,Alloc>& lhs,
							const set<T,Compare,Alloc>& rhs )
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		template <class T, class Compare, class Alloc>
		inline bool operator<= ( const set<T,Compare,Alloc>& lhs,
							const set<T,Compare,Alloc>& rhs )
		{
			return !(rhs < lhs);
		}
		template <class T, class Compare, class Alloc>
		inline bool operator>  ( const set<T,Compare,Alloc>& lhs,
							const set<T,Compare,Alloc>& rhs )
		{
			return rhs < lhs;
		}
		template <class T, class Compare, class Alloc>
		inline bool operator>= ( const set<T,Compare,Alloc>& lhs,
							const set<T,Compare,Alloc>& rhs )
		{
			return !(lhs < rhs);
		}
		template <class T, class Compare, class Alloc>
		void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
		{
			x.swap(y);
		}
}
#endif
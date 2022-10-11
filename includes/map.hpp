#ifndef MAP_HPP
# define MAP_HPP
# include "pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "tree_iterator.hpp"
# include "reverse_iterator.hpp"
# define DEBUG_1 0
# define DEBUG_R 0

namespace ft
{
	
	// enum color_t { BLACK, RED };

	// template<class T>
	// struct RBTreeNode
	// {
	// 	RBTreeNode<T>* _left;
	// 	RBTreeNode<T>* _right;
	// 	RBTreeNode<T>* _parent;
		
	// 	T _data;
	// 	color_t _color;
	// 	RBTreeNode(const T& data) : _left(nullptr_f), _right(nullptr_f), _parent(nullptr_f), _data(data), _color(RED) {}
	// };
	
	template < class Key,                                     // map::key_type
	class T,                                       // map::mapped_type
	class Compare = std::less<Key>,                     // map::key_compare
	class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
	> class map
	{

		public:
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef ft::pair<const key_type, mapped_type>								value_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef value_type&															reference;
			typedef const value_type&													const_reference;
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					key_compare comp;

					value_compare(key_compare c) : comp(c) {}
				public:
					bool operator()(const value_type& __x, const value_type& __y) const
						{return comp(__x.first, __y.first);}
			};
		// https://stackoverflow.com/questions/14148756/what-does-template-rebind-do
		private:
			// typedef pair<key_type, mapped_type>											__value_type;
			// typedef typename allocator_type::template rebind<__value_type>::other		__allocator_type;
			typedef RBTreeNode<value_type>												Node;
			typedef Node																__node_pointer;
			typedef typename allocator_type::template rebind<__node_pointer>::other	__node_allocator;

		public:
			// typedef typename allocator_type::reference									reference;
			// typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename allocator_type::size_type									size_type;
			typedef typename allocator_type::difference_type							difference_type;
			typedef typename __node_allocator::pointer									node_pointer;
			// typedef ft::__tree_iterator<value_type, node_pointer> 						iterator;
			// typedef ft::__tree_iterator<value_type, node_pointer>						const_iterator;
			typedef ft::__tree_iterator<allocator_type> 								iterator;
			typedef ft::__const_tree_iterator<allocator_type>									const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;

		private:
			node_pointer																_root;
			key_compare																	_comp;
			allocator_type																_alloc;
			__node_allocator															n_alloc;
			size_type																	_size;
			iterator																	iter;

		public:
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
			{
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) :_root(nullptr_f), _comp(comp), _alloc(alloc)
			{
				insert(first, last);
			}
			map (const map& x)
			{
				*this = x;
				return;
			}

			~map() {destroy(_root);}

			map& operator=(const map& x)
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
				// node_pointer left = _root;
				// while (left && left->_left)
				// {
				// 	left = left->_left;
				// }
				// node_pointer right = _root;
				// while (right && right->_right)
				// {
				// 	right = right->_right;
				// }
				// return iterator(right, left);
				// std::cout << "I am in iterator begin " << std::endl;
				return iterator(begin_right(), begin_left());
			}

			const_iterator begin() const
			{
				// if (_root == nullptr_f)
				// 	throw std::length_error("map size is zero");
				// std::cout << "const Iterator called" << std::endl;
				// node_pointer left = _root;
				// while (left && left->_left)
				// {
				// 	left = left->_left;
				// }
				// node_pointer right = _root;
				// while (right && right->_right)
				// {
				// 	right = right->_right;
				// }
				// return const_iterator(right, left);
				// std::cout << "I am in const_iterator begin " << std::endl;
				return const_iterator(begin_right(), begin_left());
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
				// std::cout << "==========================" << std::endl;
				// for (iterator it = begin(); it != end(); it++)
				// {
				// 	std::cout << it->first << std::endl;
				// }
				// // static int i;
				// std::cout << "----------------==========" << std::endl;
				node_pointer cur = _root;
				node_pointer parent = nullptr_f;
					// std::cout << "------------------------------" << std::endl;
				// std::cout << "i am here " << i << " times" << std::endl;
				// i++;
				while (cur != nullptr_f)
				{
					
					// std::cout << "HI" << std::endl;
					// std::cout << cur->_data.first << " " << k << std::endl;
					// std::cout << _comp(cur->_data.first, k) << std::endl;
					//  if (_comp(k, cur->_data.first))
					if (_comp(cur->_data.first, k))
					//  if (!_comp(cur->_data.first, k))
					// if (cur->_data.first < k)
					{
						parent = cur;
						// std::cout << &cur->_right << std::endl;
						cur = cur->_right;

					}
					else if (_comp(k, cur->_data.first))
					// else if (_comp(cur->_data.first, k))
					// else if (_comp(k, cur->_data.first))
					// else if (_comp(cur->_data.first, k))
					// else if (cur->_data.first > k)
					{
						parent = cur;
						cur = cur->_left;
					}
					else
					{
						
					// std::cout << "------------------------------" << std::endl;
						return (iterator(cur));
					}
					
				}
				// std::cout << "i am here " << i << " times" << std::endl;
				return (end());
			}
			const_iterator find (const key_type& k) const
			{
				node_pointer cur = _root;
				node_pointer parent = nullptr_f;
				while (cur)
				{
					
					//  if (_comp(k, cur->_data.first))
					// if (!_comp(cur->_data.first, k))
					if (cur->_data.first < k)
					{
						parent = cur;
						cur = cur->_right;
					}
					// else if (_comp(cur->_data.first, k))
					// else if (_comp(cur->_data.first, k))
					else if (cur->_data.first > k)
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
			const_iterator lower_bound (const key_type& k) const
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
					return const_iterator(__result);
				return (end());
			}
			const_iterator upper_bound (const key_type& k) const
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
					return const_iterator(__result);
				return (end());
			}
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const		{return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));}
			pair<iterator,iterator> equal_range (const key_type& k)							{return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));}
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
			const mapped_type& at (const key_type& k) const									{return at(k);}

			// at function
			mapped_type& at (const key_type& k)
			{
				node_pointer __nd;
				__nd = const_cast<node_pointer>(find(k).__ptr_);
				if (__nd == nullptr_f)
					throw std::out_of_range("map::at:  key not found");
				return (__nd->_data.second);
			}
			// single element insert
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				// when the size of the map is empty.
				// this will add new element to the map and return true since there is new allocation.
				// std::cout << "I am inside insert" << std::endl;
				// if (_root == nullptr_f)
				// {std::cout << _size << "<-> size" << std::endl;
				// std::cout << val.first << "<-> val" << std::endl;}
				// std::cout << val.first << std::endl;
				if (_root == nullptr_f)
				{
					_root = n_alloc.allocate(1);
					ft::RBTreeNode<value_type> temp(val);
					n_alloc.construct(_root, temp);
					_root->_color = BLACK;
					ft::pair<iterator, bool> t = ft::make_pair<iterator, bool>(iterator(_root), true);
					_size = 1;
					
					return t;
				}
				
				// this is searching for a match in the current map element if there
				// is a match it will return with false since there is no allocation.
				node_pointer cur = _root;
				node_pointer parent = nullptr_f;
				while (cur)
				{
					if (_comp(cur->_data.first, val.first))
					// if (cur->_data.first < val.first)
					{
						parent = cur;
						cur = cur->_right;
					}
					else if (_comp(val.first, cur->_data.first))
					// else if (cur->_data.first > val.first)
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
				
				// std::cout << val.first << " " << parent->_data.first << std::endl;
				// std::cout << parent->_data.first << " " << val.first << std::endl;
				// std::cout << _comp(val.first, parent->_data.first) << std::endl;
				// std::cout << _comp(parent->_data.first, val.first) << std::endl;
				if (_comp(parent->_data.first, val.first))
				// if (_comp(val.first, parent->_data.first))
				// if (parent->_data.first < val.first) // due to the above while the parent reach next to the null leaf. we will check where to place the node (left or right) and place the node.
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
				// std::cout << _size << std::endl;
				
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
				InputIterator it = first;
				while (it != last)
				{
					// std::cout << last->first ;
					// std::cout << it->first << std::endl;
					insert(*it);
					// std::cout << "Hi" << std::endl;
					it++;
				}
			}


			mapped_type& operator[] (const key_type& key)
			{
				iterator it = find(key);
				if (it != end())
				{
					return (it->second);
				}
				else
				{
					insert(ft::make_pair(key,mapped_type()));
					it = find(key);
					// std::cout << find(key)->second << std::endl;
					return (it->second);
				}
			}

			void swap (map& x)
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
				node_pointer __node; // -> node to be deleted

				__node = const_cast<node_pointer>(position.__ptr_);
				if (!__node || !_root)
					return ;
				n_alloc.destroy(__node);
					
				tree_remove(__node);
				// rbdelete( __node);
				n_alloc.deallocate(__node, 1);
				_size--;
			}
			
			size_type erase (const key_type& k)
			{
				node_pointer __nd;
				__nd = const_cast<node_pointer>(find(k).__ptr_);
				// std::cout << "hi2" << std::endl;
				if(__nd)
				{
					erase(find(k));
					return 1;

				}
				return 0;
			}
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					iterator temp = first;
					first++;
					// std::cout << temp->first << std::endl;
					// std::cout << "hi1" << std::endl;
					erase(temp);
				}
			}

		private:

			const node_pointer begin_left(void) const
			{
				node_pointer left = _root;
				while (left && left->_left)
				{
					left = left->_left;
				}
				return left;
			}
			const node_pointer begin_right(void) const
			{
				node_pointer right = _root;
				while (right && right->_right)
				{
					right = right->_right;
				}
				return right;
			}
			node_pointer begin_left(void)
			{
				node_pointer left = _root;
				while (left && left->_left)
				{
					left = left->_left;
				}
				return left;
			}
			node_pointer begin_right(void)
			{
				node_pointer right = _root;
				while (right && right->_right)
				{
					right = right->_right;
				}
				return right;
			}
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

				#if DEBUG_R
					std::cout << "************ Rotating Left ****************" << std::endl;
					if (subR)
						std::cout << "subR = parent->right = " << subR->_data.first << std::endl;
					else
						std::cout << "subR = parent->right = nullptr" << std::endl;
					if (subRL)
						std::cout << "subRL = subR->left = " << subRL->_data.first << std::endl;
					else
						std::cout << "subRL = subR->left = nullptr" << std::endl;
					if (parentParent)
						std::cout << "parentParent = parent->_parent = " << parentParent->_data.first << std::endl;
					else
						std::cout << "parentParent = parent->_parent = nullptr" << std::endl;
				#endif
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
				#if DEBUG_R
					if (parent->_right)
						std::cout << "parent->right = subRL = " << parent->_right->_data.first << std::endl;
					else
						std::cout << "parent->right = subRL = nullptr" << std::endl;
					if (subR->_left)
						std::cout << "subR->left = parent = " << subR->_left->_data.first << std::endl;
					else
						std::cout << "subR->left = parent = nullptr" << std::endl;
					if (parent->_parent)
						std::cout << "parent->_parent = subR = " << parent->_parent->_data.first << std::endl;
					else
						std::cout << "parent->_parent = subR = nullptr" << std::endl;
				#endif
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
				#if DEBUG_R
					if (subRL && subRL->_parent)
						std::cout << "subRL->_parent = parent = " << subRL->_parent->_data.first << std::endl;
					else 
						std::cout << "subRL->_parent = nullptr" << std::endl;
				#endif
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
			// void leftRotate(node_pointer x)
			// {
			// 	node_pointer y = x->_right;
			// 	x->_right = y->_left;
			// 	if (y->_left != nullptr_f) {
			// 	y->_left->_parent = x;
			// 	}
			// 	y->_parent = x->_parent;
			// 	if (x->_parent == nullptr_f) {
			// 	this->_root = y;
			// 	} else if (x == x->_parent->_left) {
			// 	x->_parent->_left = y;
			// 	} else {
			// 	x->_parent->_right = y;
			// 	}
			// 	y->_left = x;
			// 	x->_parent = y;
			// }

			// void rightRotate(node_pointer x)
			// {
			// 	node_pointer y = x->_left;
			// 	x->_left = y->_right;
			// 	if (y->_right != nullptr_f) {
			// 	y->_right->_parent = x;
			// 	}
			// 	y->_parent = x->_parent;
			// 	if (x->_parent == nullptr_f) {
			// 	this->_root = y;
			// 	} else if (x == x->_parent->_right) {
			// 	x->_parent->_right = y;
			// 	} else {
			// 	x->_parent->_left = y;
			// 	}
			// 	y->_right = x;
			// 	x->_parent = y;
			// }
			// void DeleteFix(node_pointer x)
			// {
			// 	node_pointer w;
			// 	while (x != _root && x->_color == BLACK)
			// 	{
			// 		if (tree_is_left_child(x))
			// 		{
			// 			w = x->_parent->_right;
			// 			if (w->_color == RED)
			// 			{
			// 				w->_color = BLACK;
			// 				x->_parent->_color = RED;
			// 				leftRotate(x->_parent);
			// 				w = x->_parent->_right;
			// 			}
			// 			if (w->_right && w->_right->_color == BLACK && w->_left && w->_left->_color == BLACK)
			// 			{
			// 				w->_color = RED;
			// 				x = x->_parent;
			// 			}
			// 			else 
			// 			{
			// 				if (w->_right && w->_right->_color == BLACK)
			// 				{
			// 					if (w->_left)
			// 						w->_left->_color = BLACK;
			// 					w->_color = RED;
			// 					rightRotate(w);
			// 					w = x->_parent->_right;
			// 				}
			// 				w->_color = x->_parent->_color;
			// 				x->_parent->_color = BLACK;
			// 				w->_right->_color = BLACK;
			// 				leftRotate(x->_parent);
			// 				x = _root;
			// 			}
			// 		}
			// 		else
			// 		{
			// 			w = x->_parent->_left;
			// 			if (w->_color == RED)
			// 			{
			// 				w->_color = BLACK;
			// 				x->_parent->_color = RED;
			// 				rightRotate(x->_parent);
			// 				w = x->_parent->_left;
			// 			}
			// 			if (w->_left && w->_left->_color == BLACK && w->_right && w->_right->_color == BLACK)
			// 			{
			// 				w->_color = RED;
			// 				x = x->_parent;
			// 			}
			// 			else
			// 			{
			// 				if (w->_left && w->_left->_color == BLACK)
			// 				{
			// 					if (w->_right)
			// 						w->_right->_color = BLACK;
			// 					w->_color = RED;
			// 					leftRotate(w);
			// 					w = x->_parent->_left;
			// 				}
			// 				w->_color = x->_parent->_color;
			// 				x->_parent->_color = BLACK;
			// 				w->_left->_color = BLACK;
			// 				rightRotate(x->_parent);
			// 				x = _root;
			// 			}
			// 		}
			// 	}
			// 	 x->_color = BLACK;
			// }

			// void rbTransplant(node_pointer u, node_pointer v)
			// {
			// 	if (u->_parent == nullptr_f) {
			// 	_root = v;
			// 	} else if (u == u->_parent->_left) {
			// 	u->_parent->_left = v;
			// 	} else {
			// 	u->_parent->_right = v;
			// 	}
			// 	if (v != nullptr_f)
			// 		v->_parent = u->_parent;
			// }
			// void rbdelete(node_pointer nodeToBeDeleted)
			// {
			// 	node_pointer x;
			// 	node_pointer y;

			// 	int originalColor = nodeToBeDeleted->_color;
			// 	if (nodeToBeDeleted->_left == nullptr_f )
			// 	{
			// 		x = nodeToBeDeleted->_right;
			// 		rbTransplant(nodeToBeDeleted, x); // Transplant nodeToBeDeleted with x.
			// 	}
			// 	else if (nodeToBeDeleted->_right == nullptr_f)
			// 	{
			// 		x = nodeToBeDeleted->_left;
			// 		rbTransplant(nodeToBeDeleted, x); // Transplant nodeToBeDeleted with x.
			// 	}
			// 	else
			// 	{
			// 		y = tree_min(nodeToBeDeleted->_right);
			// 		originalColor =y->_color;
			// 		x = y->_right;
			// 		if(y->_parent == nodeToBeDeleted)
			// 		{
			// 			x->_parent = y;
			// 		}
			// 		else
			// 		{
			// 			rbTransplant(y, y->_right);// transplant y with rightChild of y.
			// 			y->_right = nodeToBeDeleted->_right;
			// 			y->_right->_parent = y;
			// 		}
			// 		 rbTransplant(nodeToBeDeleted, y);// Transplant nodeToBeDeleted with y.
			// 		y->_left = nodeToBeDeleted->_left;
			// 		y->_left->_parent = y;
			// 		y->_color = nodeToBeDeleted->_color;
			// 	}
			// 	if (originalColor == BLACK)
			// 		DeleteFix(x);
			// }

			void tree_remove(node_pointer __z)
			{
				// __z will be removed from the tree.  Client still needs to destruct/deallocate it
				// __y is either __z, or if __z has two children, tree_next(__z).
				// __y will have at most one child.
				// __y will be the initial hole in the tree (make the hole at a leaf)
				#if DEBUG_1
				std::cout << "********************************************************" << std::endl;
				std::cout << "*********************** DEBUG CASE1 ********************" << std::endl;
				std::cout << "********************************************************" << std::endl;
				std::cout << "case : node to be deleted -> left == null and node to be deleted -> right = null" << std::endl;
				std::cout << "root = " << _root->_data.first << std::endl;
				std::cout << "root->right = " << _root->_right->_data.first << std::endl;
				std::cout << "root->left = " << _root->_left->_data.first << std::endl;
				std::cout << "node to be deleted = " << __z->_data.first << std::endl;
				std::cout << "------------------------------------------------" << std::endl;
				#endif
				
				bool __removed_black = false;
				node_pointer __y = (__z->_left == nullptr_f || __z->_right == nullptr_f) ?
								__z : tree_next(__z);
				// __x is __y's possibly null single child
				node_pointer __x = __y->_left != nullptr_f ? __y->_left : __y->_right;
				// __w is __x's possibly null uncle (will become __x's sibling)
				node_pointer __w = nullptr_f;
				// link __x to __y's parent, and find __w
				#if DEBUG_1
					if (__y)
						std::cout << "y = " << __y->_data.first << std::endl;
					else
						std::cout << "y is a nullptr" << std::endl;
					if (__x)
						std::cout << "x = " << __x->_data.first << std::endl;
					else
						std::cout << "x is a nullptr" <<std::endl;
				#endif
				
				if (__x != nullptr_f)
					__x->_parent = __y->_parent;
				if (__y == _root)
					_root = __x;
				else if (tree_is_left_child(__y))
				{
					__y->_parent->_left = __x;
					__w = __y->_parent->_right;// __w == nullptr_f
				#if DEBUG_1
					std::cout << "y is the left child" << std::endl;
					std::cout << "	so we are going to set __y->_parent->_left = __x" << std::endl;
					std::cout << "	w = " << __w->_data.first << std::endl;
					std::cout << "------------------------------------------------" << std::endl;
				#endif
				
				}
				else
				{
					__y->_parent->_right = __x;
					// __y can't be root if it is a right child
					__w = __y->_parent->_left;
					#if DEBUG_1
						std::cout << "y is the left child" << std::endl;
						std::cout << "so we are going to set __y->_parent->_right = __x" << std::endl;
						std::cout << "w = " << __w->_data.first << std::endl;
						std::cout << "------------------------------------------------" << std::endl;
					#endif
				}
				
				if (__y->_color == BLACK)
					__removed_black = true;
				// If we didn't remove __z, do so now by splicing in __y for __z,
				//    but copy __z's color.   
				if (_root == __z)
				{
					#if DEBUG_1
						std::cout << "node to be deleted == root" << std::endl;
					#endif
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
					#if DEBUG_1
						std::cout << "y != node to be deleted" << std::endl;
					#endif

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

				#if DEBUG_1
					if (__y->_parent)
						std::cout << "y->parent = " << __y->_parent->_data.first << std::endl;
					else
						std::cout << "y->parent is nullptr" << std::endl;

					if (__y->_left)
						std::cout << "y->left = " << __y->_left->_data.first << std::endl;
					else
						std::cout << "y->left is nullptr" << std::endl;
					if (__y->_right)
						std::cout << "y->right = " << __y->_right->_data.first << std::endl;
					else
						std::cout << "y->right is nullptr" << std::endl;
					if (__y->_color == BLACK)
						std::cout << "y->color = BLACK" << std::endl;
					else
						std::cout << "y->color = RED" << std::endl;
					std::cout << "Your node is detached from tree, you still need to clear it" << std::endl;
					std::cout << "------------------------------------------------------" << std::endl;
					if (__removed_black && _root != nullptr_f)
						std::cout << "We removed a black node and root != nullptr, means we need to rebalance" << std::endl;
					else
						std::cout << "There is no need to rebalance since we removed a red, or if we removed last node" << std::endl;
				#endif
				
				// There is no need to rebalance if we removed a red, or if we removed
				//     the last node.
				if (__removed_black && _root != nullptr_f)
				{
					
					#if DEBUG_1
						std::cout << "**********************************************" << std::endl;
						std::cout << "************* Rebalancing Begins *************" << std::endl;
						std::cout << "**********************************************" << std::endl;
						if (__x != nullptr)
							std::cout << "set x->color = BLACK and rebalancing done." << std::endl;
						else
							std::cout << "since x == nullptr, more work is needed inorder to rebalance." << std::endl;
					#endif
					if (__x != nullptr_f)
						__x->_color = BLACK;
					else
					{
						
						while (true)
						{
							
							if (!tree_is_left_child(__w))  // if x is left child
							{
								
								#if DEBUG_1
									std::cout << "	w is right child of it's parent" << std::endl;
									std::cout << "	w = " << __w->_data.first << std::endl;
									if (__w->_color == BLACK)
										std::cout << "	w->color = BLACK" << std::endl;
									else
										std::cout << "	w->color = RED" << std::endl;
									std::cout << "------------------------------------------------------" << std::endl;
								#endif
								if (__w->_color == RED)
								{
									__w->_color = BLACK;
									__w->_parent->_color = RED;
									#if DEBUG_1
										std::cout << "	since w->color = RED we are going to do following" << std::endl;
										std::cout << "		change w->color to BLACK" << std::endl;
										std::cout << "		change w->parent->color to RED" << std::endl;
										std::cout << "------------------------------------------------------" << std::endl;
										std::cout << "		before rotation" << std::endl;
										std::cout << "		w = " << __w->_data.first << std::endl;

									#endif
									RotateL(__w->_parent);
									#if DEBUG_1
									std::cout << "**********************************************" << std::endl;
									std::cout << "		After rotation" << std::endl;
									std::cout << "		w = " << __w->_data.first << std::endl;
									std::cout << "		Now set w = w->left->right" << std::endl;
									#endif
									// __x is still valid
									// reset _root only if necessary
									if (_root == __w->_left)
										_root = __w;
									// reset sibling, and it still can't be null
									__w = __w->_left->_right;
									#if DEBUG_1
										std::cout << "		new w = " << __w->_data.first << std::endl;
									#endif

								}
								if (__w == nullptr_f)
									break;
								// __w->_color is now BLACK, __w may have null children
								if ((__w->_left  == nullptr_f || __w->_left->_color == BLACK) &&
									(__w->_right == nullptr_f || __w->_right->_color == BLACK))
								{
									#if DEBUG_1
										std::cout << "		if ((__w->_left  == nullptr_f || __w->_left->_color == BLACK) &&" << std::endl 
												  << "		(__w->_right == nullptr_f || __w->_right->_color == BLACK))" << std::endl
												  << "		We are inside the above if condition :" << std::endl;
									#endif
									__w->_color = RED;
									__x = __w->_parent;
									#if DEBUG_1
										std::cout << "		set w->color = RED" << std::endl;
										std::cout << "		set x = w->parent = " << __x << std::endl;
									#endif
									// __x can no longer be null
									if (__x == _root || __x->_color == RED)
									{
										#if DEBUG_1
										std::cout << "		*****************************************" << std::endl;
										std::cout << "		if (__x == _root || __x->_color == RED)" << std::endl
												  << "		since the above if condition is true" << std::endl
												  << "		we are going to set x->color to BLACK" << std::endl
												  << "		and break out of the while loop" << std::endl;
										__x->_color = BLACK;
										#endif
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
								// 	std::cout << __w->_color  << " his" << std::endl;
								
									__w = __w->_right->_left;
								}
								if (__w == nullptr_f)
									break;
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
		// void leftRotate(node_pointer x)
		// {
		// 	if (x->_right || !_root->_parent)
		// 		return ;
		// 	node_pointer y = x->_right; // sey y
		// 	x->_right = y->_left;  // turn y’s left subtree into x’s right subtree
		// 	if (!y->_left) 
		// 		y->_left->_parent = x;
		// 	y->_parent = x->_parent;  // link x’s parent to y
		// 	if (!x->_parent)
		// 		_root = y;
		// 	else if (x == x->_parent->_left)
		// 		x->_parent->_left = y;
		// 	else
		// 		x->_parent->_right = y;
		// 	y->_left = x;  // put x on y’s left
		// 	x->_parent = y;
		// }

		// void rightRotate(node_pointer y)
		// {
		// 	if (y->_left || !_root->_parent)
		// 		return ;
		// 	node_pointer x = y->_left; // sey y
		// 	y->_left = x->_right;  // turn y’s left subtree into x’s right subtree
		// 	if (!x->_right) 
		// 		x->_right->_parent = y;
		// 	x->_parent = y->_parent;  // link x’s parent to y
		// 	if (!y->_parent)
		// 		_root = x;
		// 	else if (y == y->_parent->_right)
		// 		y->_parent->_right = x;
		// 	else
		// 		y->_parent->_left = x;
		// 	x->_right = y;  // put x on y’s left
		// 	y->_parent = x;
		// }
	

	};
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs )
		{
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

		template <class Key, class T, class Compare, class Alloc>
		inline bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(lhs == rhs);
		}
			
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs )
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(rhs < lhs);
		}
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs )
		{
			return rhs < lhs;
		}
		template <class Key, class T, class Compare, class Alloc>
		inline bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs )
		{
			return !(lhs < rhs);
		}
		template <class Key, class T, class Compare, class Alloc>
		void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
		{
			x.swap(y);
		}

}
#endif
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
			typedef ft::RBTreeNode<value_type>												Node;
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
			typedef ft::__tree_iterator<value_type, allocator_type> 								iterator;
			typedef ft::__const_tree_iterator<value_type, allocator_type>							const_iterator;
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
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			 : _root(nullptr_f), _comp(comp), _alloc(alloc), _size(0)
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
				return iterator(begin_right(), begin_left());
			}

			const_iterator begin() const
			{
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
				const_iterator search = begin();
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
				while (cur != nullptr_f)
				{
					if (_comp(cur->_data.first, k))
					{
						parent = cur;
						cur = cur->_right;

					}
					else if (_comp(k, cur->_data.first))
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

			const_iterator find (const key_type& k) const
			{
				node_pointer cur = _root;
				node_pointer parent = nullptr_f;
				while (cur)
				{
					if (cur->_data.first < k)
					{
						parent = cur;
						cur = cur->_right;
					}
					else if (cur->_data.first > k)
					{
						parent = cur;
						cur = cur->_left;
					}
					else
					{
						return (const_iterator(cur));
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
				node_pointer cur = _root;
				node_pointer parent = nullptr_f;
				while (cur)
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
					insert(*it);
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
				n_alloc.deallocate(__node, 1);
				_size--;
			}

			size_type erase (const key_type& k)
			{
				node_pointer __nd;
				__nd = const_cast<node_pointer>(find(k).__ptr_);
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
				parent->_right = subRL;
				subR->_left = parent;
				parent->_parent = subR;
				if (subRL)
					subRL->_parent = parent;
				if (_root == parent)
				{
					_root = subR;
					_root -> _parent = nullptr_f;
				}
				else
				{
					if (parentParent->_left == parent)
						parentParent->_left = subR;
					else
						parentParent->_right = subR;
					subR->_parent = parentParent;
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

			void tree_remove(node_pointer delete_node)
			{
				bool removed_black = false;
				node_pointer y = (delete_node->_left == nullptr_f || delete_node->_right == nullptr_f) ?
								 delete_node : tree_next(delete_node);
				node_pointer x = y->_left != nullptr_f ? y->_left : y->_right;
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

			void removeYConnectionToDeleteNode(node_pointer y, node_pointer delete_node)
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

			void changeY2Root(node_pointer y, node_pointer delete_node)
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
			void balanceTreeAfterDelete(node_pointer x, node_pointer w)
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
// #include "../srcs/map/map_init.tpp"
#endif
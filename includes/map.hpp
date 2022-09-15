#ifndef MAP_HPP
# define MAP_HPP
# include "pair.hpp"
# include <iostream>
# include <algorithm>
# include <functional>
# include "tree_iterator.hpp"
# include "reverse_iterator.hpp"

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
		RBTreeNode(const T& data) : _left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _color(RED) {}
	};
	
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
			typedef pair<key_type, mapped_type>											__value_type;
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
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _root(nullptr), _alloc(alloc), _size(0)
			{
				std::cout << "Map default constructor called" << std::endl;
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
			{
				insert(first, last);
			}
			map (const map& x)
			{
				std::cout << "Map copy constructor called" << std::endl;
				*this = x;
				return;
			}

			~map() {destroy(_root);}

			map& operator=(const map& x)
			{
				std::cout << "Map copy assignment operator called" << std::endl;
				if (this != &x)
				{
					value_comp() = x.value_comp();
					_alloc = x.get_allocator();
					_comp = x._comp;
					n_alloc = x.n_alloc;
					_size = 0;
					_root = nullptr;
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
				return iterator(right, nullptr);
			}
			const_iterator end() const
			{
				node_pointer right = _root;
				while (right && right->_right)
				{
					right = right->_right;
				}
				return const_iterator(right, nullptr);
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
				node_pointer parent = nullptr;
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
						return (iterator(cur));
					}
				}
				return (end());
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const		{return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));}
			pair<iterator,iterator> equal_range (const key_type& k)							{return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));}
			const_iterator lower_bound (const key_type& k) const							{return const_iterator(lower_bound(k));}
			const_iterator upper_bound (const key_type& k) const							{return const_iterator(upper_bound);}
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
			void clear()																	{destroy(_root); _size = 0; _root = nullptr;}
			const mapped_type& at (const key_type& k) const									{return at(k);}

			// at function
			mapped_type& at (const key_type& k)
			{
				node_pointer __nd;
				__nd = const_cast<node_pointer>(find(k).__ptr_);
				if (__nd == nullptr)
					throw std::out_of_range("map::at:  key not found");
				return (__nd->_data.second);
			}
			// single element insert
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				// when the size of the map is empty.
				// this will add new element to the map and return true since there is new allocation.
				// std::cout << "I am inside insert" << std::endl;
				// if (_root == nullptr)
				// {std::cout << _size << "<-> size" << std::endl;
				// std::cout << val.first << "<-> val" << std::endl;}
				if (_root == nullptr)
				{
					_root = n_alloc.allocate(1);
					ft::RBTreeNode<value_type> temp(val);
					n_alloc.construct(_root, temp);
					_root->_color = BLACK;
					ft::pair<iterator, bool> t = ft::make_pair<iterator, bool>(iterator(_root), true);
					_size++;
					
					return t;
				}
				// this is searching for a match in the current map element if there
				// is a match it will return with false since there is no allocation.
				node_pointer cur = _root;
				node_pointer parent = nullptr;
				while (cur)
				{
					if (cur->_data.first < val.first)
					{
						parent = cur;
						cur = cur->_right;
					}
					else if (cur->_data.first > val.first)
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
				if (parent->_data.first < val.first) // due to the above while the parent reach next to the null leaf. we will check where to place the node (left or right) and place the node.
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
				node_pointer __result = nullptr;
				std::cout << "i am inside " << std::endl;
				while (__root != nullptr)
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
				node_pointer __result = nullptr;
				while (__root != nullptr)
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
				x.t_size = _size;
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
				node_pointer P; // -> parent node of __node
				node_pointer S; // -> sibling of __node
				node_pointer C; // -> close nephew
				node_pointer D; // -> distant nephew

				__node = const_cast<node_pointer>(position.__ptr_);
				__root = _root;
				P = __node->_parent;
				if (tree_is_left_child(__node))
					P->_left = nullptr;
				else if (P && P->_right)
					P->_right = nullptr;
				bool dir;
				goto Start_D;      // jump into the loop
				// start of the (do while)-loop:
				do {
					dir = tree_is_left_child(__node);
					Start_D:
						if (tree_is_left_child(__node))
							S = P->_right;
						else if (P && P->_left)
							S = P->_left;
						if (tree_is_left_child(__node))
							D = P->_right;
						else if (P && P->_left)
							D = P->_left;
						if (tree_is_left_child(__node))
							C = P->_left;
						else if (P && P->_right)
							C = P->_right;
						
						if (S && S->_color == RED)
						{
							std::cout << "Case_D3" << std::endl;
							goto Case_D3; // S red ===> P+C+D black
						}
						
							// S is black:
						if (D != nullptr && D->_color == RED) // Not considered black
						{
							std::cout << "Case_D6" << std::endl;
							goto Case_D6; // D red && and S black
						}
						
						if (C != nullptr && C->_color == RED) // not considered black
						{
							std::cout << "Case_D5" << std::endl;
							goto Case_D5; // C red and S + D black
						}
						
						// Here both nephews are == nullptr (first iteration) or black later.
						if ( P && P->_color == RED)
						{
							std::cout << "Case_D4" << std::endl;
							goto Case_D4; // P red and C + S + D = black
						}
						std::cout << "Start_D" << std::endl;
						// Case_D1 (P+C+S+D black):
						if (S)
							S->_color = RED;
						__node = P; // new current node (maybe the root)
						// iterate 1 black level
						//   (= 1 tree level) higher
					} while (__node && (P = __node->_parent) != nullptr);
					// end of the (do while)-loop
					// Case_D2 (P == NULL):
  					return; // deletion complete
					Case_D3: // S red && P+C+D black:
						if (dir)
							RotateL(P); // P may be the root
						else
							RotateR(P);
						P->_color = RED;
						S->_color = BLACK;
						S = C; // != NIL
						// now: P red && S black
						if (!dir)
							D = S->_left; // distant nephew
						else
							D = S->_right;
						if (D != nullptr && D->_color == RED)
							goto Case_D6;      // D red && S black
						if(dir)
							C = S->_left; // close   nephew
						else
							C = S->_right;
						if (C != nullptr && C->_color == RED)
							goto Case_D5;      // C red && S+D black
						// Otherwise C+D considered black.
						// fall through to Case_D4
					Case_D4: // P red && S+C+D black:
						S->_color = RED;
						P->_color = BLACK;
						return; // deletion complete
					Case_D5: // C red && S+D black:
						if (!dir)
							RotateL(S);
						else
							RotateR(S);
						S->_color = RED;
						C->_color = BLACK;
						D = S;
						S = C;
						// now: D red && S black
						// fall through to Case_D6
					Case_D6: // D red && S black:
						if (dir)
							RotateL(P);
						else
							RotateR(P);
						S->_color = P->_color;
						P->_color = BLACK;
						D->_color = BLACK;
						return; // deletion complete
			}
			
			size_type erase (const key_type& k)
			{
				node_pointer __nd;
				__nd = const_cast<node_pointer>(find(k).__ptr_);
				if(__nd)
					erase(find(k));
			}
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
			}

		private:

			void destroy(node_pointer __nd)
			{
				if (__nd != nullptr)
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
					_root -> _parent = nullptr;
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
					_root->_parent = nullptr;
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
	};
		template <class Key, class T, class Compare, class Alloc>
		bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
			
		template <class Key, class T, class Compare, class Alloc>
		bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		
		template <class Key, class T, class Compare, class Alloc>
		bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
			
		template <class Key, class T, class Compare, class Alloc>
		bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		
		template <class Key, class T, class Compare, class Alloc>
		bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
							const map<Key,T,Compare,Alloc>& rhs );
		template <class Key, class T, class Compare, class Alloc>
		void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
		{
			x.swap(y);
		}

}
#endif
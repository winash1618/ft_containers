#ifndef RB_TREE_HPP
# define RB_TREE_HPP
# incluede "pair.hpp"
namespace ft
{
	// The read-only operations, such as search or tree traversal, 
	// on a red–black tree require no modification from those used for binary search trees, 
	// because every red–black tree is a special case of a simple binary search tree.
	//---------------------------------------------------------------------------------
	// Basic type definitions:
	//---------------------------------------------------------------------------------

	enum color_t { BLACK, RED };

	template<class T>
	struct RBTreeNode
	{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		
		T _data;
		Color _color;
		RBTreeNode(const T& data)
				:_left(nullptr)
				,_right(nullptr)
				,_parent(nullptr)
				,_data(data)
				,_color(RED)
		{}
	};


	template<class T,class Ref,class Ptr>
	struct _TreeIterator
	{
		/*typedef Ref reference;
		typedef Ptr pointer;*/
		typedef RBTreeNode<T> Node;
		typedef _TreeIterator<T, Ref, Ptr> Self;
		Node* _node;
		_TreeIterator(Node* node)
			:_node(node)
		{}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator ->()
		{
			return &_node->_data;
		}
		bool  operator !=(const Self& s) const
		{
			return _node != s._node;
		}
		bool  operator ==(const Self& s) const
		{
			return _node == s._node;
		}
		Self& operator++()
		{
			if (_node->_right)
			{
				
				Node* left = _node->_right;
				while (left->_left)
				{
					left = left->_left;
				}
					_node = left;
				}
				else
				{
					Node* cur = _node;
					Node* parent = cur->_parent;
					while (parent && cur == parent->_right)
					{
						cur = cur->_parent;
						parent = parent->_parent;
					}
					_node = parent;
				}
			return *this;
		}
		Self& operator--()
		{
			if (_node->_left)
			{
				
				Node* left = _node->_left;
				while (right->_right)
				{
					right = right->_right;
				}
				_node = right;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && cur == parent->_left)
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return *this;
		}
	};
	
	template<class K, class V>
	class RBTree
	{
		typedef RBNode<K, V> Node;
		public:
			RBTree(): _root(nullptr) {}
			typedef _TreeIterator<T, T&, T*> iterator;
		iterator begin()
		{
			Node* left = _root;
			while (left && left->_left)
			{
				left = left->_left;
			}

			return iterator(left);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		pair <iterator, bool>insert(const T& data)
		{
			//1.
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_color = BLACK;
				return make_pair(iterator(_root), true);
			}

			KeyOfT  koft;
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				//key
				if (koft(cur->_data) < koft(data))
				{
					parent = cur;
					cur = cur->_right;
				}
				//key
				else if (koft(cur->_data) > koft(data))
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return make_pair(iterator(cur), false);
				}
			}
			cur = new Node(data);
			Node* newnode = cur;
			newnode->_color = RED;
			if (koft(parent->_data) < koft(data))
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
						else //parent->_right == cur
						{
							RotateL(parent);
							RotateR(grandParent);
							grandParent->_color = RED;
							cur->_color = BLACK;
						}
						break;
					}
				}
				else //parent grandParent
				{
					Node* uncle = grandParent->_left;
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
			_root->_color = BLACK;
			return make_pair(iterator(newnode), true);
		}
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			Node* parentParent = parent->_parent;
			parent->_right = subRL;
			subR->_left = parent;

			parent->_parent = subR;
			if (subRL)
				subRL->_parent = parent;
			if (_root == parent)
			{
				_root = subR;
				_root->_parent = nullptr;
			}

			else
			{
				//subR
				if (parentParent->_left == parent)
					parentParent->_left = subR;
				else
					parentParent->_right = subR;
				subR->_parent = parentParent;
			}
		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			Node* parentParent = parent->_parent;
			//subLR parent->_left
			parent->_left = subLR;
			subL->_right = parent;
			//parent
			//subLR
			if (subLR)
				subLR->_parent = parent;
			parent->_parent = subL;
			//parent
			if (_root == parent)
			{
				_root = subL;
				_root->_parent = nullptr;
			}

			else
			{
				//parent
				if (parentParent->_left == parent)
					parentParent->_left = subL;
				else
					parentParent->_right = subL;
				//subL
				subL->_parent = parentParent;
			}
		}
		void Destory(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}

		~RBTree()
		{
			Destory(_root);
			_root = nullptr;
		}

		iterator Find(const K& key)
		{
			KeyOfT koft;
			Node* cur = _root;
			while (cur)
			{
				if (koft(cur->_data) > data)
				{
					cur = cur->_left;
				}
				else if (koft(cur->_data) < data)
				{
					cur = cur->_right;
				}
				else
				{
					return iterator(cur);
				}
			}

			return end();
		}

		bool _CheckBlance(Node* root,int blackNum, int count)
		{
			if (root == nullptr)
			{
				if (count != blackNum)
				{
					cout << "we don't" << endl;
					return false;
				}

				return true;
			}

			if (root->_color == RED && root->_parent->_color == RED)
			{
				cout << "i don't" << endl;
				return false;
			}

			if (root->_color == BLACK)
			{
				count++;
			}

			return _CheckBlance(root->_left, blackNum, count)
				&& _CheckBlance(root->_right, blackNum, count);
		}

		bool CheckBlance()
		{
			if (_root == nullptr)
			{
				return true;
			}

			if (_root->_color == RED)
			{
				cout << "are don't" << endl;
				return false;
			}

			int blackNum = 0;
			Node* left = _root;
			while (left)
			{
				if (left->_color == BLACK)
				{
					blackNum++;
				}

				left = left->_left;
			}

			int count = 0;
			return _CheckBlance(_root, blackNum, count);
		}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":"<<root->_kv.second<<endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	private:
		Node* _root;
	};
	//---------------------------------------------------------------------------------
	// https://opensource.apple.com/source/xnu/xnu-2050.18.24/bsd/hfs/hfscommon/headers/RedBlackTree.h.auto.html
	//---------------------------------------------------------------------------------


	

}
#endif
#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

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
		RBTreeNode(const T& data) : _left(nullptr_f), _right(nullptr_f), _parent(nullptr_f), _data(data), _color(RED) {}
	};
	// Returns:  true if __x is a left child of its parent, else false
	// Precondition:  __x != nullptr.
	template <class _NodePtr>
	inline
	bool
	tree_is_left_child(_NodePtr __x)
	{
		if (__x != nullptr_f )
			if (__x->_parent != nullptr_f)
				return __x == __x->_parent->_left;
		return 0;
	}

	// Returns:  pointer to the left-most node under __x.
	// Precondition:  __x != nullptr_f.
	template <class _NodePtr>
	inline
	_NodePtr
	tree_min(_NodePtr __x)
	{
		while (__x->_left != nullptr_f)
			__x = __x->_left;
		return __x;
	}

	// Returns:  pointer to the right-most node under __x.
	// Precondition:  __x != nullptr_f.
	template <class _NodePtr>
	inline
	_NodePtr
	tree_max(_NodePtr __x)
	{
		while (__x->_right != nullptr_f)
			__x = __x->_right;
		return __x;
	}

	// Returns:  pointer to the next in-order node after __x.
	// Precondition:  __x != nullptr_f.
	template <class _NodePtr>
	_NodePtr
	tree_next(_NodePtr __x)
	{
		if (__x->_right != nullptr_f)
			return tree_min(__x->_right);
		while (!tree_is_left_child(__x) && __x->_parent)
		{
			__x = __x->_parent;
		}
		return __x->_parent;
	}

	// Returns:  pointer to the previous in-order node before __x.
	// Precondition:  __x != nullptr_f.
	template <class _NodePtr>
	_NodePtr
	tree_prev(_NodePtr __x)
	{
		if (__x->_left != nullptr_f)
			return tree_max(__x->_left);
		while (tree_is_left_child(__x))
			__x = __x->_parent;
		return __x->_parent;
	}

	// template <class _V, class _NodePtr>
	// class __tree_iterator
	// {
	// 	public:
	// 		typedef _V value_type;
	// 	private:
	// 		typedef _NodePtr				__node_pointer;
	// 		// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
	// 	public:
	// 		__node_pointer					__ptr_;
	// 		__node_pointer					__end_;
	// 		typedef value_type& reference;
	// 		typedef value_type* pointer;
	// 		typedef ft::bidirectional_iterator_tag	iterator_category;
	// 		typedef std::ptrdiff_t					difference_type;

	// 		__tree_iterator() {}
	// 		__tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
	// 		__tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			
	// 		// __tree_iterator& operator=(const __tree_iterator<_V, _NodePtr>& __u) // commented for linux working fine in mac
	// 		// { 
	// 		// 	if (this != &__u) 
	// 		// 	{
	// 		// 		__ptr_ = static_cast<__tree_iterator<_V, _NodePtr> >(__u.__ptr_);
	// 		// 		__end_ = static_cast<__tree_iterator<_V, _NodePtr> >(__u.__end_);
	// 		// 	}
	// 		// 	return *this;
	// 		// }
	// 		reference operator*() const
	// 		{
	// 			return __ptr_->_data;
	// 		}
	// 		pointer operator->() const
	// 		{
	// 			return &__ptr_->_data;
	// 		}

	// 		__tree_iterator& operator++()
	// 		{
	// 			__ptr_ = tree_next(__ptr_);
	// 			return *this;
	// 		}
	// 		__tree_iterator operator++(int)
	// 		{
	// 			__tree_iterator __t(*this);
	// 			++(*this);
	// 			return __t;
	// 		}

	// 		__tree_iterator& operator--()
	// 		{
	// 			if (__ptr_ == nullptr_f)
	// 			{
	// 				__ptr_ = __end_;
	// 				return *this;
	// 			}
	// 			__ptr_ = tree_prev(__ptr_);
	// 			return *this;
	// 		}
	// 		__tree_iterator operator--(int)
	// 		{
				
	// 			__tree_iterator __t(*this);
	// 			--(*this); 
	// 			return __t;
	// 		}

	// 		friend bool operator==(const __tree_iterator& __x, const __tree_iterator& __y)
	// 			{return __x.__ptr_ == __y.__ptr_;}
	// 		friend bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y)
	// 			{return !(__x == __y);}

	// };

	
	template <class _V, class Alloc>
	class __tree_iterator
	{
		public:
			typedef Alloc allocator_type;
			typedef  _V value_type;
			typedef RBTreeNode<value_type>												Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr				__node_pointer;
			// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
			__node_pointer					__ptr_;
			__node_pointer					__end_;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;

			__tree_iterator() {}
			__tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
			__tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			// __tree_iterator& operator=(const __tree_iterator<_V, _NodePtr>& __u) // commented for linux working fine in mac
			// { 
			// 	if (this != &__u) 
			// 	{
			// 		__ptr_ = static_cast<__tree_iterator<_V, _NodePtr> >(__u.__ptr_);
			// 		__end_ = static_cast<__tree_iterator<_V, _NodePtr> >(__u.__end_);
			// 	}
			// 	return *this;
			// }
			reference operator*() const
			{
				return __ptr_->_data;
			}
			pointer operator->() const
			{
				return &__ptr_->_data;
			}

			__tree_iterator& operator++()
			{
				__ptr_ = tree_next(__ptr_);
				return *this;
			}
			__tree_iterator operator++(int)
			{
				__tree_iterator __t(*this);
				++(*this);
				return __t;
			}

			__tree_iterator& operator--()
			{
				if (__ptr_ == nullptr_f)
				{
					__ptr_ = __end_;
					return *this;
				}
				__ptr_ = tree_prev(__ptr_);
				return *this;
			}
			__tree_iterator operator--(int)
			{
				
				__tree_iterator __t(*this);
				--(*this); 
				return __t;
			}
			
			friend bool operator==(const __tree_iterator& __x, const __tree_iterator& __y)
				{return __x.__ptr_ == __y.__ptr_;}
			friend bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y)
				{return !(__x == __y);}
	};


	template <class _V, class Alloc>
	class __const_tree_iterator 
	{
		public:
			typedef Alloc																allocator_type;
			typedef typename allocator_type::value_type 								value_type;
			typedef ft::RBTreeNode<value_type>											Node;
			typedef Node																node_pointer;
			typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
			typedef typename __node_allocator::pointer									_NodePtr;
			typedef _NodePtr															__node_pointer;
			// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
			__node_pointer																__ptr_;
			__node_pointer																__end_;
			typedef const value_type&															reference;
			typedef const value_type*															pointer;
			typedef ft::bidirectional_iterator_tag										iterator_category;
			typedef std::ptrdiff_t														difference_type;
			typedef ft::__tree_iterator<_V, allocator_type> 							iterator;
			iterator																__iter;
			__const_tree_iterator() {}
			__const_tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
			__const_tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			__const_tree_iterator(iterator  iter):__iter(iter)
			{
				__ptr_ = __iter.__ptr_;
				__end_ = __iter.__end_;
			}
			// __const_tree_iterator(iterator const iter):__iter1(iter)
			// {
			// 	__ptr_ = __iter1.__ptr_;
			// 	__end_ = __iter1.__end_;
			// }
			// __const_tree_iterator& operator=(const __const_tree_iterator<Alloc>& __u) // commented for linux working fine in mac
			// { 
			// 	if (this != &__u) 
			// 	{
			// 		__ptr_ = static_cast<__const_tree_iterator<Alloc> >(__u.__ptr_);
			// 		__end_ = static_cast<__const_tree_iterator<Alloc> >(__u.__end_);
			// 	}
			// 	return *this;
			// }
			reference operator*() const
			{
				return __ptr_->_data;
			}
			pointer operator->() const
			{
				return &__ptr_->_data;
			}

			__const_tree_iterator& operator++()
			{
				__ptr_ = tree_next(__ptr_);
				return *this;
			}
			__const_tree_iterator operator++(int)
			{
				__const_tree_iterator __t(*this);
				++(*this);
				return __t;
			}

			__const_tree_iterator& operator--()
			{
				if (__ptr_ == nullptr_f)
				{
					__ptr_ = __end_;
					return *this;
				}
				__ptr_ = tree_prev(__ptr_);
				return *this;
			}
			__const_tree_iterator operator--(int)
			{
				
				__const_tree_iterator __t(*this);
				--(*this); 
				return __t;
			}

			friend bool operator==(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
				{return __x.__ptr_ == __y.__ptr_;}
			friend bool operator!=(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
				{return !(__x == __y);}
	};


	// template <class Alloc>
	// class __const_tree_iterator
	// {
	// 	public:
	// 		typedef Alloc																allocator_type;
	// 		typedef typename allocator_type::value_type 								value_type;
	// 		typedef RBTreeNode<value_type>												Node;
	// 		typedef Node																node_pointer;
	// 		typedef typename allocator_type::template rebind<node_pointer>::other		__node_allocator;
	// 		typedef typename __node_allocator::pointer									_NodePtr;
	// 		typedef _NodePtr				__node_pointer;
	// 		// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
	// 		__node_pointer					__ptr_;
	// 		__node_pointer					__end_;
	// 		typedef value_type& reference;
	// 		typedef value_type* pointer;
	// 		typedef ft::bidirectional_iterator_tag	iterator_category;
	// 		typedef std::ptrdiff_t					difference_type;
	// 		__const_tree_iterator() {}
	// 		__const_tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
	// 		__const_tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}
			
	// 		// __const_tree_iterator& operator=(const __const_tree_iterator<Alloc>& __u) // commented for linux working fine in mac
	// 		// { 
	// 		// 	if (this != &__u) 
	// 		// 	{
	// 		// 		__ptr_ = static_cast<__const_tree_iterator<Alloc> >(__u.__ptr_);
	// 		// 		__end_ = static_cast<__const_tree_iterator<Alloc> >(__u.__end_);
	// 		// 	}
	// 		// 	return *this;
	// 		// }
	// 		reference operator*() const
	// 		{
	// 			return __ptr_->_data;
	// 		}
	// 		pointer operator->() const
	// 		{
	// 			return &__ptr_->_data;
	// 		}

	// 		__const_tree_iterator& operator++()
	// 		{
	// 			__ptr_ = tree_next(__ptr_);
	// 			return *this;
	// 		}
	// 		__const_tree_iterator operator++(int)
	// 		{
	// 			__const_tree_iterator __t(*this);
	// 			++(*this);
	// 			return __t;
	// 		}

	// 		__const_tree_iterator& operator--()
	// 		{
	// 			if (__ptr_ == nullptr_f)
	// 			{
	// 				__ptr_ = __end_;
	// 				return *this;
	// 			}
	// 			__ptr_ = tree_prev(__ptr_);
	// 			return *this;
	// 		}
	// 		__const_tree_iterator operator--(int)
	// 		{
				
	// 			__const_tree_iterator __t(*this);
	// 			--(*this); 
	// 			return __t;
	// 		}

	// 		friend bool operator==(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
	// 			{return __x.__ptr_ == __y.__ptr_;}
	// 		friend bool operator!=(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
	// 			{return !(__x == __y);}
	// };
	// template <class _V, class _NodePtr>
	// class __const_tree_iterator
	// {
	// 	public:
	// 		typedef _V value_type;
	// 	private:
	// 		typedef _NodePtr				__node_pointer;
	// 		// value_type						__val; commenting this fixed the assignment operator overload error in ft::pair
	// 	public:
	// 		__node_pointer					__ptr_;
	// 		__node_pointer					__end_;
	// 		typedef value_type& reference;
	// 		typedef value_type* pointer;
	// 		typedef ft::bidirectional_iterator_tag	iterator_category;
	// 		typedef std::ptrdiff_t					difference_type;

	// 		__const_tree_iterator() {}
	// 		__const_tree_iterator(__node_pointer ptr): __ptr_(ptr) {}
	// 		__const_tree_iterator(__node_pointer end, __node_pointer ptr):__ptr_(ptr), __end_(end) {}

	// 		reference operator*() const
	// 		{
	// 			return __ptr_->_data;
	// 		}
	// 		pointer operator->() const
	// 		{
	// 			return &__ptr_->_data;
	// 		}

	// 		__const_tree_iterator& operator++()
	// 		{
	// 			__ptr_ = tree_next(__ptr_);
	// 			return *this;
	// 		}
	// 		__const_tree_iterator operator++(int)
	// 		{
	// 			__const_tree_iterator __t(*this);
	// 			++(*this);
	// 			return __t;
	// 		}

	// 		__const_tree_iterator& operator--()
	// 		{
	// 			if (__ptr_ == nullptr_f)
	// 			{
	// 				__ptr_ = __end_;
	// 				return *this;
	// 			}
	// 			__ptr_ = tree_prev(__ptr_);
	// 			return *this;
	// 		}
	// 		__const_tree_iterator operator--(int)
	// 		{
				
	// 			__const_tree_iterator __t(*this);
	// 			--(*this); 
	// 			return __t;
	// 		}

	// 		friend bool operator==(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
	// 			{return __x.__ptr_ == __y.__ptr_;}
	// 		friend bool operator!=(const __const_tree_iterator& __x, const __const_tree_iterator& __y)
	// 			{return !(__x == __y);}

	// };
}
#endif
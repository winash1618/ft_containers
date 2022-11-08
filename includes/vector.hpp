/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/11/08 13:32:41 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
// #include <iterator>
#include <cassert>
#include <cstddef>
#include <limits>
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "vec_utils.hpp"
namespace ft
{
	// template<class T>
	// class vector_iterator 
	// {
	// 	public:
	// 		typedef _Iter                                                      iterator_type;
	// 		typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
	// 		typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
	// 		typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
	// 		typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
	// 		typedef typename ft::iterator_traits<iterator_type>::reference         reference;
	// 	private:
	// 		iterator_type __i;
	// 	public:
	// 		__wrap_iter() {}
	// 		template <class _Up> 
	// 		__wrap_iter(const __wrap_iter<_Up>& __u) 
	// 			: __i(__u.base())
	// 		{
	// 		reference operator*() const 
	// 		{
	// 			return *__i;
	// 		}
	// 		pointer  operator->() const 
	// 		{
	// 			return (pointer)_VSTD::addressof(*__i);
	// 		}
	// 		__wrap_iter& operator++() 
	// 		{
	// 			++__i;
	// 			return *this;
	// 		}
	// 		__wrap_iter  operator++(int) 
	// 			{__wrap_iter __tmp(*this); ++(*this); return __tmp;}

	// 		__wrap_iter& operator--() 
	// 		{
	// 			--__i;
	// 			return *this;
	// 		}
	// 		__wrap_iter  operator--(int) 
	// 			{__wrap_iter __tmp(*this); --(*this); return __tmp;}
	// 		__wrap_iter  operator+ (difference_type __n) const 
	// 			{__wrap_iter __w(*this); __w += __n; return __w;}
	// 		__wrap_iter& operator+=(difference_type __n) 
	// 		{
	// 			__i += __n;
	// 			return *this;
	// 		}
	// 		__wrap_iter  operator- (difference_type __n) const 
	// 			{return *this + (-__n);}
	// 		__wrap_iter& operator-=(difference_type __n) 
	// 			{*this += -__n; return *this;}
	// 		reference    operator[](difference_type __n) const 
	// 		{
	// 			return __i[__n];
	// 		}
	// 		iterator_type base() const  {return __i;}

	// };
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef ft::iterator<pointer>							iterator;
			typedef ft::iterator<const_pointer>						const_iterator;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			// Constructor
			// empty container constructor
			explicit vector (const allocator_type& alloc = allocator_type())  :  _vec(nullptr_f), _alloc(alloc), _cap(0), _size(0) {}
			// fill constructor
			explicit vector (size_type len, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			 :  _alloc(alloc), _cap(0)
			{
				allocate(len);
				construct_at_end(len, val);
			}
			// range constructor
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : 
					_alloc(alloc), _cap(0), _size(0)
			{
				// if (first > last)
				// 	throw std::length_error("vector");
				// size_type size = ft::distance(first, last);
				for (InputIterator it = first; it != last; it++)
				{
					++_size;
				}
				_vec = _alloc.allocate(_size);
				_cap = _size;
				
				for (size_type index = 0; index < _size; ++index)
				{
					_alloc.construct(_vec + index, *(first++));
				}
			}
			// Copy constructor
			vector (const vector& x) :  _cap(0), _size(0)
			{
				_alloc = x.get_allocator();
				copy(x);
			}
			// Destructor
			~vector () {deallocate_and_destruct(_cap, _size);}
			// Assignment operator
			vector& operator=(const vector& x)
			{
				if (this == &x) 
				{
					return *this;
				}
				destruct(size());
				
				if (x._vec)
				{
					this->_alloc = x.get_allocator();
					if (x.size() > this->capacity())
					{
						reallocate(this->capacity(), x.size());
					}
					uninitialized_alloc_copy(x);
				}
				else
				{
					_vec = nullptr_f;
					_size = 0;
				}
				return *this;
			}
			value_type* data()									{return (_vec);}
			const value_type* data() const						{return (_vec);}
			allocator_type get_allocator() const				{return (this->_alloc);}
			// erase
			iterator erase (iterator position)
			{
				_alloc.destroy(_vec + (position - begin()));
				for(size_type index = position - begin(); index < _size - 1; index++)
					_alloc.construct(_vec + index, *(_vec + index + 1));
				_size--;
				return (position);
			}
			iterator erase (iterator first, iterator last)
			{
				size_type siz = first - begin();
				size_type len = end() - begin();
				if (len > 0)
				{
					size_type index = 0;
					iterator t_end = end();
					for (iterator it = first; it != last; it++)
					{
						_alloc.destroy(_vec + siz + index);
						index++;
						_size--;
					}
					index = 0;
					for (iterator it = first; it != last; it++)
					{
						if (last + index == t_end)
							break;
						_alloc.construct(_vec  + siz + index, *(last + index));
						_alloc.destroy(_vec + siz + index);
						index++;
					}
					if (last + index != t_end)
					{
						while (index < len)
						{
							if (last + index == t_end)
							break;
							_alloc.construct(_vec  + siz + index, *(last + index));
							_alloc.destroy(_vec + siz + index);
							index++;
						}
					}
				}
				return first;
			}

			// push_back
			void push_back (const value_type& val)
			{
				if (!_cap)
					reserve(1);
				if (_size + 1 > _cap)
					reserve(_cap * 2);
				_alloc.construct(_vec + _size, val);
				_size += 1;
			}
			
			// Iterators
			iterator               begin()              {return iterator(_vec);}
			const_iterator         begin()   const      {return const_iterator(_vec);}
			iterator               end()                {return iterator(_vec + size());}
			const_iterator         end()     const      {return const_iterator(_vec + size()); }
			
			//reverse Iterators
			reverse_iterator       rbegin() {return reverse_iterator(this->end());}
			const_reverse_iterator rbegin() const {return const_reverse_iterator(this->end());}
			reverse_iterator       rend() {return reverse_iterator(this->begin());}
			const_reverse_iterator rend() const {return const_reverse_iterator(this->begin());}
			
			// Capacity based functions
			size_type size() const {return (this->_size);}
			size_type capacity() const {return (this->_cap);}
			size_type max_size() const {return (_alloc.max_size());}
			bool empty() const {return (_size == 0);}
			
			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("Capacity allocated exceeds max_size()");
				else if (n > _cap)
				{
					pointer t_vec = t_alloc.allocate(n);
					for (_index = 0; _index < _size; ++_index)
						t_alloc.construct(t_vec + _index, _vec[_index]);
					for (_index = 0; _index < _size; ++_index)
						_alloc.destroy(_vec + _index);
					_alloc.deallocate(_vec, _cap);
					_alloc = t_alloc;
					_vec = t_vec;
					_cap = n;
				}	
					
			}

			// Modifiers functions
			reference       operator[](size_type index)
			{
				assert(index < size() && "Index out of range1");
				return _vec[index]; 
			}
			const_reference operator[](size_type index) const
			{
				assert(index < size() && "Index out of range2");
				return _vec[index]; 
			}
			reference       at(size_type n)
			{
				if (n < size() && n >= 0)
					return (_vec[n]);
				else
					throw std::out_of_range("Index out of range");
			}
			
			const_reference at(size_type n) const {return (n < size() ? _vec[n] : throw std::out_of_range("Index out of range"));}
			void clear() {destruct(_size);}

			// assign functions:
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				// InputIterator it = first;
				// if (it > last)
				// 	throw std::length_error("vector");
				// if (first > last)
				// 	throw std::length_error("vector");
				size_type size = 0;
				for (InputIterator it = first; it != last; it++)
				{
					++size;
				}
				// s./ize_type size = ft::distance(first, last);
				allocate(size);
				_size = 0;
				for (size_type index = 0; index < size; ++index)
				{
					_alloc.construct(_vec + index, *(first++ ));
					++_size;
				}
			}
			void assign (size_type n, const value_type& val)
			{
				allocate(n);
				_size = 0;
				for (size_type index = 0; index < n; ++index)
				{
					_alloc.construct(_vec + index, val);
					++_size;
				}
			}

			// resize
			void resize (size_type n, value_type val = value_type())
			{

				if (n > max_size())
					throw std::length_error("vector");
				if (n < _size)
				{
					for(size_type index = n; index < _size; index++)
						_alloc.destroy(_vec + index);
					_size = n;
				}
				else if (n >= _size && n < _cap )
				{
					for(size_type index = _size; index < n; index++)
						_alloc.construct(_vec + index, val);
					_size = n;
				}
				else
				{
					if (n > max_size())
						throw std::length_error("Capacity allocated exceeds max_size()");
					temp = t_alloc.allocate(n);
					for (size_type index = 0; index < _size; ++index)
						t_alloc.construct(temp + index, _vec[index]);
					for (size_type index = _size; index < n; ++index)
						t_alloc.construct(temp + index, val);
					for (size_type index = 0; index < _size; ++index)
						_alloc.destroy(_vec + index);
					_alloc.deallocate(_vec, _cap);
					_alloc = t_alloc;
					_vec = temp;
					_cap = recommend(n);
					_size = n;

				}
			}
			
			// // insert functions
			iterator insert (iterator position, const value_type& val) // single element insert
			{
				if (_size + 1 <= _cap)
				{
					_alloc.construct(_vec + _size, val);
					// _cap = _size + 1;
					_size++;
					for (iterator it = position; it < end(); it++)
					{
						value_type temp1 = back();
						*(end() - 1) = *it;
						*it = temp1;
					}
				}
				else
				{
					size_type i = position - begin();
					temp = t_alloc.allocate(_size * 2, 0);
					for (size_type index1 = 0; index1 < _size; ++index1)
						t_alloc.construct(temp + index1, _vec[index1]);
					t_alloc.construct(temp + _size, val);
					for (size_type index1 = 0; index1 < _size; ++index1)
						_alloc.destroy(_vec + index1);
					_alloc.deallocate(_vec, _cap);
					_alloc = t_alloc;
					_vec = temp;
					_cap = _size * 2;
					_size++;
					position = begin() + i;
					for (iterator it = position; it < end(); it++)
					{
						value_type temp1 = back();
						*(end() - 1) = *it;
						*it = temp1;
					}
				}
				return (position);
			}
			void insert (iterator position, size_type n, const value_type& val) // fill n index starting from iterator position
			{
				size_type t_cap;
				if (_size + n > _cap)
				{
					temp = t_alloc.allocate(recommend(_size + n), 0);
					t_cap = recommend(_size + n);
				}
				else
				{
					temp = t_alloc.allocate(_cap, 0);
					t_cap = _cap;
				}
				size_type index = 0;
				size_type t_size = 0;
				for (iterator it = begin(); it != position; it++)
				{
					t_alloc.construct(temp + index, *it);
					t_size++;
					index++;
				}
				for (index = 0; index < n; index++)
					t_alloc.construct(temp + t_size + index, val);
				t_size = t_size + index;
				index = 0;
				for (iterator it = position; it != end(); it++)
				{
					t_alloc.construct(temp + t_size + index, *it);
					index++;
				}
				for (size_type index1 = 0; index1 < _size; ++index1)
					_alloc.destroy(_vec + index1);
				_alloc.deallocate(_vec, _cap);
				t_size = t_size + index;
				_alloc = t_alloc;
				_vec = temp;
				_size = t_size;
				_cap = t_cap;
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				// if (first > last)
				// 	throw std::length_error("vector");
				size_type t_cap;
				size_type size = 0;
				for (InputIterator it = first; it != last; it++)
				{
					++size;
				}
				// iterator iter = static_cast<iterator>(first);
				if (_size + size > _cap)
				{
					temp = t_alloc.allocate(recommend(_size + size), 0);
					t_cap = recommend(_size + size);
				}
				else
				{
					temp = t_alloc.allocate(_cap, 0);
					t_cap = _cap;
				}
				size_type index = 0;
				size_type t_size = 0;
				for (iterator it = begin(); it != position; it++)
				{
					t_alloc.construct(temp + index, *it);
					t_size++;
					index++;
				}
				index = 0;
				for (InputIterator it = first; it != last; it++)
				{
					t_alloc.construct(temp + t_size + index,*it);
					index++;
				}
				t_size = t_size + index;
				index = 0;
				for (iterator it = position; it != end(); it++)
				{
					t_alloc.construct(temp + t_size + index, *it);
					index++;
				}
				for (size_type index1 = 0; index1 < _size; ++index1)
					_alloc.destroy(_vec + index1);
				_alloc.deallocate(_vec, _cap);
				t_size = t_size + index;
				_alloc = t_alloc;
				_vec = temp;
				_size = t_size;
				_cap = t_cap;
			}
			// popback and pushback
			void pop_back()
			{
				if (_size  == 0)
					throw std::out_of_range("can");
				_alloc.destroy(&_vec[_size-- - 1]);
			}
			reference       front()
			{
				assert(!empty() && "front() called for empty vector");
				return *this->begin();
			}
			const_reference front() const
			{
				assert(!empty() && "front() called for empty vector");
				return *this->begin();
			}
			reference       back()
			{
				assert(!empty() && "back() called for empty vector");
				return *(_vec + size() - 1);
			}
			const_reference back() const
			{
				assert(!empty() && "back() called for empty vector");
				return *(_vec + size() - 1);
			}
			void swap (vector& x)
			{
				temp = x._vec;
				t_alloc = x._alloc;
				size_type t_size = x._size;
				size_type t_cap = x._cap;
				x._vec = _vec;
				x._alloc = _alloc;
				x._size = _size;
				x._cap = _cap;
				_vec = temp;
				_alloc = t_alloc;
				_size = t_size;
				_cap = t_cap;
			}
		private:
			pointer temp;
			pointer _vec; // 
			Allocator t_alloc;
			Allocator 	_alloc; // std::allocator
			value_type t_val;
			size_type _index;
			size_type _cap;// Capacity 
			size_type _size;
			void print(void)
			{
				size_type i = 0;
				std::cout << "Printing starts" << std::endl;
				while (i < _size)
				{
					std::cout << i << " th element = " << _vec[i] << std::endl;
					i++;
				}
				std::cout << "Printing ends" << std::endl;
			}
			void allocate(size_type capacity)
			{
				if (capacity > max_size())
					throw std::length_error("new size to allocate exceeds max_size()");
				_cap = capacity;
				_vec = _alloc.allocate(capacity, 0);
			}

			void deallocate(std::size_t capacity)
			{
				_alloc.deallocate(_vec, capacity);
				_cap = 0;
				_size = 0;
			}

			void reallocate(std::size_t old_cap, std::size_t new_cap) {
				deallocate(old_cap);
				allocate(new_cap);
			}

			void construct(std::size_t size, const value_type& value)
			{
				_size = size;
				for (std::size_t index = 0; index < size; ++index)
					_alloc.construct(_vec + index, value);
			}

			void construct_at_end(size_type size, const value_type& value)
			{
				_size = size;
				for (std::size_t index = 0; index < size; ++index)
					_alloc.construct(_vec + index, value);
			}
			void destruct(std::size_t size)
			{
				for (std::size_t index = 0; index < size; ++index)
					_alloc.destroy(_vec + index);
				_size = 0;
			}
			void allocate_and_copy_construct(std::size_t capacity, std::size_t size, const value_type& value = value_type())
			{
				allocate(capacity);
				construct(size, value);
			}
			void deallocate_and_destruct(std::size_t capacity, std::size_t size)
			{
				destruct(size);
				deallocate(capacity);
			}
			void uninitialized_alloc_copy(const vector& other)
			{
				_size = other.size();
				for (size_type index=0; index < _size; ++index)
					this->_alloc.construct(this->_vec + index, *(other._vec + index));
			}
			void copy(const vector& other)
			{
				if (other._vec)
				{
					allocate(other._size);
					uninitialized_alloc_copy(other);
				}
				else
					_vec = nullptr_f;
			}
			size_type recommend(size_type new_size) const
			{
				const size_type ms = max_size();
				if (new_size > ms)
					throw std::length_error("new size to allocate exceeds max_size()");
				const size_type cap = capacity();
				if (cap >= ms / 2)
					return ms;
				return std::max<size_type>(2*cap, new_size);
			}
		} ;
		// Non-member function overloads
		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
		template <class T, class Alloc>
		bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs == rhs);
		}
		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(rhs < lhs);
		}
		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}
		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs);
		}
}
#endif

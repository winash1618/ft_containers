/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/23 12:05:08 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
namespace ft
{
	// template <bool>
	// class __vector_base_common
	// {
	// protected:
	// 	__vector_base_common() {}
	// 	void __throw_length_error() const;
	// 	void __throw_out_of_range() const;
	// };
	
	// template <class _Tp, class _Allocator>
	// class __vector_base
	// 	: protected __vector_base_common<true>
	// {
	// 	public:
	// 		typedef _Allocator                               allocator_type;
	// 		typedef allocator_traits<allocator_type>         __alloc_traits;
	// 		typedef typename __alloc_traits::size_type       size_type;
	// 	protected:
	// 		typedef _Tp                                      value_type;
	// 		typedef value_type&                              reference;
	// 		typedef const value_type&                        const_reference;
	// 		typedef typename __alloc_traits::difference_type difference_type;
	// 		typedef typename __alloc_traits::pointer         pointer;
	// 		typedef typename __alloc_traits::const_pointer   const_pointer;
	// 		typedef pointer                                  iterator;
	// 		typedef const_pointer                            const_iterator;

	// 		pointer                                         __begin_;
	// 		pointer                                         __end_;
	// 		// __compressed_pair<pointer, allocator_type> __end_cap_;

	// 		// allocator_type& __alloc()
	// 		// 	{return __end_cap_.second();}
	// 		// const allocator_type& __alloc() const
	// 		// 	{return __end_cap_.second();}
	// 		// pointer& __end_cap()
	// 		// 	{return __end_cap_.first();}
	// 		// const pointer& __end_cap() const
	// 		// 	{return __end_cap_.first();}

	// 		__vector_base();
	// 		__vector_base(const allocator_type& __a);
	// 		~__vector_base();

	// 		void clear()
	// 		{
	// 			__destruct_at_end(__begin_);
	// 		}
	// 		size_type capacity() const
	// 		{
	// 			return static_cast<size_type>(__end_cap() - __begin_);
	// 		}

	// 		void __destruct_at_end(pointer __new_last)
	// 		{
	// 			pointer __soon_to_be_end = __end_;
	// 			while (__new_last != __soon_to_be_end)
	// 				__alloc_traits::destroy(__alloc(), _VSTD::__to_address(--__soon_to_be_end));
	// 			__end_ = __new_last;
	// 		}

	// 		void __copy_assign_alloc(const __vector_base& __c)
	// 		{
	// 			__copy_assign_alloc(__c, integral_constant<bool,
	// 			__alloc_traits::propagate_on_container_copy_assignment::value>());
	// 		}

	// 		void __move_assign_alloc(__vector_base& __c)
	// 		_(
	// 				!__alloc_traits::propagate_on_container_move_assignment::value ||
	// 				is_nothrow_move_assignable<allocator_type>::value)
	// 			{__move_assign_alloc(__c, integral_constant<bool,
	// 						__alloc_traits::propagate_on_container_move_assignment::value>());}
	// 	private:
	// 		void __copy_assign_alloc(const __vector_base& __c, true_type)
	// 		{
	// 			if (__alloc() != __c.__alloc())
	// 			{
	// 				clear();
	// 				__alloc_traits::deallocate(__alloc(), __begin_, capacity());
	// 				__begin_ = __end_ = __end_cap() = nullptr;
	// 			}
	// 			__alloc() = __c.__alloc();
	// 		}

	// 		void __copy_assign_alloc(const __vector_base&, false_type)
	// 		{}

	// 		void __move_assign_alloc(__vector_base& __c, true_type)
	// 		_(is_nothrow_move_assignable<allocator_type>::value)
	// 			{
	// 				__alloc() = _VSTD::move(__c.__alloc());
	// 			}

	// 		void __move_assign_alloc(__vector_base&, false_type)
			
	// 			{}
	// };

/*---------------std::is_integral----------------------------------------*/

template<class T, T v>
  	struct integral_constant {
      const static T value = v;
      typedef T value_type;
      typedef integral_constant type;
      operator value_type() const { return value; }
      value_type operator()() const { return value; } //since c++14
  };

	typedef integral_constant<bool, true> true_type1;
	typedef integral_constant<bool, false> false_type1;

	template <class T>
	struct is_integral : public false_type1{};

	template <>
	struct is_integral<bool> : public true_type1{};

	template <>
	struct is_integral<char> : public true_type1{};

	template <>
	struct is_integral<signed char> : public true_type1{};

	template <>
	struct is_integral<unsigned char> : public true_type1{};

	template <>
	struct is_integral<wchar_t> : public true_type1{};

	template <>
	struct is_integral<short> : public true_type1{};

	template <>
	struct is_integral<int> : public true_type1{};

	template <>
	struct is_integral<long> : public true_type1{};

	template <>
	struct is_integral<long long> : public true_type1{};

	template <>
	struct is_integral<unsigned short> : public true_type1{};

	template <>
	struct is_integral<unsigned int> : public true_type1{};

	template <>
	struct is_integral<unsigned long> : public true_type1{};

	template <>
	struct is_integral<unsigned long long> : public true_type1{};




/*--------------implementation 1 of enable if-----------------------------*/
	/* enable_if definitions */
	template<bool B, class T>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {typedef T type;};

	/* True type and False type*/
	struct true_type {
		static const bool value = true;
	};

	struct false_type {
		static const bool value = false;
	};

	template<typename T>
	int is_int() {
	return false;
	}

	template<>
	int is_int<int>() {
	return true;
}
	// template<typename T>
	// struct ft::enable_if<> : false_type {};

	// template<typename T>
	// struct ft::enable_if<std::is_same<T, ft::iterator_traits<iterator_type>::iterator_category>, T>::type : true_type {};

/*--------------implementation 2 of enable if-----------------------------*/
// template <class Iter>
// using iter_cat_t = typename iterator_traits<Iter>::iterator_category;

// template <class T, class = void>
// constexpr bool is_iterator_v = false;

// template <class T>
// constexpr bool is_iterator_v<T, std::void_t<iter_cat_t<T>>> = true;
	
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			
			void say(void)
			{
				std::cout << "hello world" << std::endl;
			}
			/*--------------------------------------------------------------------*/
			/*-------------------------member type--------------------------------*/
			/*--------------------------------------------------------------------*/
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef ft::__wrap_iter<value_type>							iterator;
			typedef ft::__wrap_iter<value_type>							const_iterator;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::difference_type			difference_type;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			/*--------------------------------------------------------------------*/
			/*-------------------------member functions---------------------------*/
			/*--------------------------------------------------------------------*/
			// Constructor
			
			explicit vector (const allocator_type& alloc = allocator_type())  : _alloc(alloc), _vec(nullptr), _size(0), _cap(0) // empty container constructor
			{
				// say();
			}
			
		
			
			explicit vector (size_type len, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			 : _alloc(alloc), t_alloc(alloc) // fill constructor
			{
				std::cout << "hi" << std::endl;
				say();
				
				if (len > 0)
				{
					allocate(len * 2);
					construct_at_end(len, val);
				}
				for (std::size_t index = 0; index < _size; ++index)
				{
					std::cout << this->_vec[index] << std::endl;
				}
				// std::cout << typeid(allocator_type).name();
			}
			
			template <class InputIterator, typename = typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()
					) : _alloc(alloc), _size(0), _cap(0)// range constructor
			{
				say();
				std::cout << "hello i am here" << std::endl;
				// std::size_t size = 5;
				size_type size = ft::distance(first, last); // this will cause error because i am not using enable_if so it is passing int also
				// std::cout << size << std::endl;
				// std::cout << std::is_same<int, InputIterator>::value << std::endl;
				// std::cout << std::is_same<iterator, InputIterator>::value << std::endl;
				std::cout << typeid(iterator).name() << std::endl;
				std::cout << typeid(InputIterator).name() << std::endl;
				allocate(size);
				for (size_type index = 0; index < size; ++index)
				{
					_alloc.construct(_vec + index, *(first + index));
					std::cout << this->_vec[index] << std::endl;
					++_size;
				}
				// std::cout << _size << std::endl;
				// std::size_t index = 0;
				// for (; first != last; ++first)
				// {
				// 	_alloc.construct(_vec + index, *(first));
				// 	std::cout << this->_vec[index] << std::endl;
				// 	index++;
				// }
			}
			
			vector (const vector& x) : _size(0)  // Copy constructor
			{
				std::cout << "I am in copy constructor" << std::endl;
				// *this = x;
				_alloc = x.get_allocator();
				copy(x);
				std::cout << "I am back in copy again" << std::endl;
				for (std::size_t index = 0; index < _size; ++index)
				{
					std::cout << this->_vec[index] << std::endl;
				}
				std::cout << "End of copy constructor" << std::endl;
			}
			
			// Destructor
			~vector ()
			{
				deallocate_and_destruct(_cap, _size);
			}

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
					
					// if ()
					// {
					// 	this->_alloc = x.get_allocator();
					// }
					this->_alloc = x.get_allocator();
					if (x.size() > this->capacity())
					{
						reallocate(this->capacity(), x.size());
					}
					std::cout << x.size() << " " << _size << std::endl;
					uninitialized_alloc_copy(x);
				}
				else
				{
					_vec = nullptr;
					_size = 0;
				}
				// for (std::size_t index = 0; index < _size; ++index)
				// {
				// 	std::cout << this->_vec[index] << std::endl;
				// }
				return *this;
			}
			
			// Allocator based function
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}
			
			void push_back (const value_type& val)
			{
				std::cout << _cap << std::endl;
				if (!_cap)
				{
					_vec = _alloc.allocate(1, 0);
					_alloc.construct(_vec, val);
					_cap = 1;
					_size = 1;
				}
				else
				{
					if (_size + 1 > _cap)
					{
						std::cout << "HI I am inside overflow handler" << std::endl;
						temp = t_alloc.allocate(_size * 2, 0);
						for (_index = 0; _index < _size; ++_index)
						{
							t_alloc.construct(temp + _index, _vec[_index]);
						}
						t_alloc.construct(temp + _index, val);
						_alloc.deallocate(_vec, _cap);
						for (_index = 0; _index < _size; ++_index)
							_alloc.destroy(_vec + _index);
						_alloc = t_alloc;
						_vec = temp;
						_cap = _size * 2;
						_size++;
					}
					else
					{
						std::cout << "HI I am inside normal" << std::endl;
						// for (size_type index = 0; index < _size; ++index)
						// {
						// 	temp++;
						// }
						_alloc.construct(_vec + _size, val);
						
						_size += 1;
					}
				}
			}
			// Iterators
			iterator	begin()
			{
				return (_vec);
			}
			const_iterator         begin()   const
			{
				return (_vec);
			}
			iterator               end()
			{
				return (_vec + size()); 
			}
			const_iterator         end()     const
			{
				return (_vec + size()); 
			}
			
			reverse_iterator       rbegin()
			{
				return reverse_iterator(_vec + size()); 
			}
			const_reverse_iterator rbegin()  const
			{
				return reverse_iterator(_vec + size()); 
			}
			reverse_iterator       rend()
			{
				return reverse_iterator(_vec); 
			}
			const_reverse_iterator rend()    const
			{
				return reverse_iterator(_vec); 
			}
			
			// Capacity based functions
			size_type size() const
			{
				std::cout << "i am inside size " << std::endl;
				for (std::size_t index = 0; index < _size; ++index)
				{
					std::cout << this->_vec[index] << std::endl;
				}
				return (this->_size); 
			}
			size_type capacity() const
			{
				return (this->_cap);
			}
			size_type max_size() const
			{
				return (std::numeric_limits<difference_type>::max()); 
			}
			bool empty() const
			{
				if (_size)
					return (false);
				return (true);
			}
			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("Capacity allocated exceeds max_size()");
				else if (n > _cap)
					reallocate(_cap, n);
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
				return (n < size() ? _vec[n] : throw std::out_of_range("Index out of range"));
			}
			const_reference at(size_type n) const
			{
				return (n < size() ? _vec[n] : throw std::out_of_range("Index out of range"));
			}
			void clear()
			{
				 destruct(_size); 
			}

			// assign functions:
			template <class InputIterator, typename = typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type>
			void assign (InputIterator first, InputIterator last)
			{
				// deallocate_and_destruct(_cap, _size);
				size_type size = ft::distance(first, last);
				allocate(size * 2);
				for (std::size_t index = 0; index < size; ++index)
				{
					_alloc.construct(_vec + index, *(first + index));
					//std::cout << _vec[index] << std::endl;
					++_size;
				}
				// std::size_t index = 0;
				// for (; first != last; ++first)
				// {
				// 	_alloc.construct(_vec + index, *(first));
				// 	index++;
				// }
				
				// if (new_size <= capacity())
				// {
				// 	InputIterator mid = last;
				// 	bool growing = false;
				// 	if (new_size > size())
				// 	{
				// 		growing = true;
				// 		mid =  first;
				// 		ft::advance(mid, size());
				// 	}
				// 	pointer m = std::copy(first, mid, this->begin());
				// 	if (growing)
				// 	{
				// 		_size = new_size;
				// 		for (std::size_t index = 0; index < size; ++index)
				// 		{
				// 			_alloc.construct(_vec + index, *mid);
				// 			mid++;
				// 		}
				// 	}
				// 	else
				// 	{
				// 		for (std::size_t index = 0; index < size; ++index)
				// 		{
				// 			_alloc.destroy(_vec + index);
							
				// 		}
				// 		_size = 0;
				// 	}
				// }
				// else
				// {
				// 	deallocate();
				// 	allocate(recommend(new_size));
				// 	construct_at_end(first, last, new_size);
				// }
			}
			void assign (size_type n, const value_type& val)
			{
				allocate(n * 2);
				for (std::size_t index = 0; index < n; ++index)
				{
					_alloc.construct(_vec + index, val);
					//std::cout << _vec[index] << std::endl;
					++_size;
				}
			}

			// // insert functions
			// iterator insert (iterator position, const value_type& val) // single element insert
			// {
				
			// }
			// void insert (iterator position, size_type n, const value_type& val) // fill n index starting from iterator position
			// {
				
			// }
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last)
			// {
				
			// }
			// popback and pushback
			void pop_back()
			{
				if (_size  == 0)
					throw std::out_of_range("can");
				_alloc.destroy(&_vec[_size-- - 1]);
				// _alloc.destroy(_vec + size() - 1);
				// _size -= 1;
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
				std::cout << "swap" << std::endl;
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
		private:
			pointer temp;
			pointer _vec; // 
			Allocator t_alloc;
			Allocator 	_alloc; // std::allocator
			value_type t_val;
			size_type _index;
			size_type _cap;// Capacity 
			size_type _size;
			void allocate(size_type capacity)
			{
				if (capacity > max_size())
					throw std::length_error("new size to allocate exceeds max_size()");
				_cap = capacity;
				_vec = _alloc.allocate(capacity, 0);
			}
			// void allocate(size_type capacity)
			// {
			// 	_cap = capacity;
			// 	_vec = _alloc.allocate(capacity, 0);
			// }

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
				std::cout << _size << "i am in unin"  << std::endl;
				for (size_type index=0; index < _size; ++index)
				{
					std::cout << *(other._vec + index)  << std::endl;
					this->_alloc.construct(this->_vec + index, *(other._vec + index));
				}
				std::cout << "i am going out" << std::endl;
			}
			void copy(const vector& other)
			{
				if (other._vec) {
					allocate(other._size);
					uninitialized_alloc_copy(other);
				}
				else
					_vec = nullptr;
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
			// destruct_at_end(pointer __new_last)
			// {
			// 	pointer __soon_to_be_end = end();
			// 	while (__new_last != __soon_to_be_end)
			// 		__alloc_traits::destroy(__alloc(), _VSTD::__to_address(--__soon_to_be_end));
			// }
		} ;
		// Non-member function overloads
		// template <class T, class Alloc>
		// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		// {
			
		// }
		// template <class T, class Alloc>
		// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		// {
			
		// }
		// template <class T, class Alloc>
		// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		// {
			
		// }
		// template <class T, class Alloc>
		// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		// {
			
		// }
		// template <class T, class Alloc>
		// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		// {
			
		// }
		// template <class T, class Alloc>
		// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		// {
			
		// }
		// template <class T, class Alloc>
		// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		// {
			
		// }
			
		// template <class T, class Alloc = std::allocator<T> >
		// void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
		// {
		// 	typedef Alloc allocator_type;
			
		// 	allocator_type t_alloc;
		// 	T* t_vec;
		// 	typename allocator_type::size_type t_size;
		// 	typename allocator_type::size_type t_cap;
		// 	t_alloc = x._alloc;
		// 	t_vec = x._vec;
		// 	t_size = x._size;
		// 	t_cap = x._cap;
		// 	x._alloc = y._alloc;
		// 	x._vec = y._vec;
		// 	x._cap = y._cap;
		// 	x._size = y._size;
		// 	y._alloc = t_alloc;
		// 	y._vec = t_vec;
		// 	y._size = t_size;
		// 	y._cap = t_cap;
		// }
		// #include "vector.cpp" // include separate implementation file inside namespace
}
#endif

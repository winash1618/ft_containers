/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:50:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/11/10 06:46:05 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft
{
	template<class _Iter>
	class iterator 
	{
		public:
			typedef _Iter                                                      iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference         reference;
		private:
			iterator_type __i;
		public:
			iterator() {}
			iterator(iterator_type iter) : __i( iter ){}
			iterator(const iterator& x) : __i(x.base())
			{
				// std::cout << "Hi" << std::endl;
				// *this = x;
			}
			template<class X>
			iterator(const iterator<X>& u):__i(u.base())
			{
			}
			reference operator*() const 
			{
				return *__i;
			}
			pointer  operator->() const 
			{
				return (pointer)std::addressof(*__i);
			}
			iterator& operator++() 
			{
				++__i;
				return *this;
			}
			iterator  operator++(int) 
			{
				iterator __tmp(*this);
				++(*this);
				return __tmp;
			}

			iterator& operator--() 
			{
				--__i;
				return *this;
			}
			iterator  operator--(int) 
				{iterator __tmp(*this); --(*this); return __tmp;}
			iterator  operator+ (difference_type __n) const 
				{iterator __w(*this); __w += __n; return __w;}
			iterator& operator+=(difference_type __n) 
			{
				__i += __n;
				return *this;
			}
			iterator  operator- (difference_type __n) const 
				{return *this + (-__n);}
			iterator& operator-=(difference_type __n) 
				{*this += -__n; return *this;}
			reference    operator[](difference_type __n) const 
			{
				return __i[__n];
			}
			iterator_type base() const  {return __i;}

	};
	// template<class T>
	// class iterator 
	// {
	// 	private:
	// 		T* _iterator;

	// 	public:
	// 		typedef T													value_type;
	// 		typedef T*													pointer;
	// 		typedef T&													reference;
	// 		typedef std::ptrdiff_t										difference_type;
	// 		typedef std::random_access_iterator_tag						iterator_category;
	// 		// typedef typename iterator_traits<value_type>::iterator_category iterator_category;
	// 		// typedef typename ft::iterator_traits<T>::iterator_category iterator_catogory;
	// 		iterator() : _iterator(){}
	// 		iterator(T* iter) : _iterator( iter ){}
	// 		iterator(const iterator& x) {*this = x;}
	// 		template<typename X>
	// 		iterator(const iterator<X>& u):_iterator(u.base()) {}
			
	// 		iterator& operator=(const iterator<T>& __u) // commented for linux working fine in mac
	// 		{ 
	// 			if (this != &__u) 
	// 			{
	// 				this->_iterator = __u._iterator;
	// 			}
	// 			return *this;
	// 		}
	// 		reference operator*() const { 
	// 			return *_iterator; 
	// 		}
			
	// 		pointer operator->() const { 
	// 			return _iterator; 
	// 		}
			
	// 		iterator& operator++() { 
	// 			++_iterator; 
	// 			return *this; 
	// 		}
			
	// 		iterator operator++(int) { 
	// 			iterator tmp(*this); ++(*this); 
	// 			return tmp; 
	// 		}
			
	// 		iterator& operator--() { 
	// 			--_iterator;
	// 			return *this;
	// 		}
			
	// 		iterator operator--(int) { 
	// 			iterator tmp(*this); 
	// 			--(*this); 
	// 			return tmp;
	// 		}
			
	// 		iterator& operator+=(const difference_type other) { 
	// 			_iterator += other; 
	// 			return *this; 
	// 		}
			
	// 		iterator& operator-=(const difference_type other) { 
	// 			_iterator -= other; 
	// 			return *this;
	// 		}
			
	// 		difference_type operator-(const iterator& other) const { 
	// 			return std::distance(other._iterator, _iterator); 
	// 		}
	// 		// difference_type operator-(const iterator& other) const { 
	// 		// 	return std::distance(_iterator, other._iterator); 
	// 		// }
	// 		// iterator*  operator- (difference_type n) const
	// 		// {
	// 		// 	return iterator(_iterator - n);
	// 		// }
			
	// 		reference operator[](std::size_t index) const { 
	// 			return _iterator[index]; 
	// 		}
			
	// 		T* base() const
	// 		{
	// 			return _iterator;
	// 		}
	// 		// bool operator==(const iterator& rhs) const {return _iterator==rhs._iterator;}
	// 		// bool operator!=(const iterator& rhs) const {return _iterator!=rhs._iterator;}
	// };
	



	
	//-------------distance function-----------------------------------//

	// template <class _RandIter>
	// typename ft::iterator_traits<_RandIter>::difference_type
	// __distance(_RandIter first, _RandIter last, ft::random_access_iterator_tag)
	// {
	// 	// std::cout << last - first << " : distance" << std::endl;
	// 	// return last - first;
	// 	typename ft::iterator_traits<_RandIter>::difference_type r(0);
	// 	for (; first != last; ++first)
	// 		++r;
	// 	return r;
	// }
	// template<class _InputIter>
	// typename ft::iterator_traits<_InputIter>::difference_type
	// __distance (_InputIter first, _InputIter last, ft::input_iterator_tag)
	// {
	// 	typename ft::iterator_traits<_InputIter>::difference_type r(0);
	// 	for (; first != last; ++first)
	// 		++r;
	// 	return r;
	// }
	// template <class InputIter>
	// typename ft::iterator_traits<InputIter>::difference_type
	// distance(InputIter first, InputIter last)
	// {
	// 	return __distance(first, last, typename ft::iterator_traits<InputIter>::iterator_category());
	// }



	
	
	//--------------------------------------------------------------------//



	template <class _Iter1, class _Iter2>
	bool
	operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
	{
		
		return x.base() == y.base();
	}
	template <class _Iter1, class _Iter2>
	bool
	operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
	{
		
		return !(x == y);
	}
	template <class _Iter1, class _Iter2>
	bool
	operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
	{
		return x.base() < y.base();
	}
	template <class _Iter1, class _Iter2>
	bool
	operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
	{
		return y < x;
	}
	template <class _Iter1, class _Iter2>
	bool
	operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
	{
		return !(x.base() < y.base());
	}
	template <class _Iter1, class _Iter2>
	bool
	operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
	{
		return !(y.base() < x.base());
	}










	template <class _Iter1>
	bool
	operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
	{
		return x.base() == y.base();
	}
	template <class _Iter1>
	bool
	operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
	{
		// std::cout << "hfdsdf" << std::endl;
		return !(x == y);
	}
	template <class _Iter1>
	bool
	operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
	{
		return (x.base() < y.base());
	}
	template <class _Iter1>
	bool
	operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
	{
		// std::cout << "-----------" << std::endl;
		return (y < x);
	}
	template <class _Iter1>
	bool
	operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
	{
		return !(x.base() < y.base());
	}
	template <class _Iter1>
	bool
	operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y) 
	{
		return !(y.base() < x.base());
	}









	template <class _Iter1, class _Iter2>
	typename ft::iterator<_Iter1>::difference_type
	operator-(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y) 
	{
		return x.base() - y.base();
	}
	template <class _Iterator>
	_Iterator
	operator+(_Iterator n,
			std::size_t x) 
	{
		n += x;
		return n;
	}
	template <class _Iterator>
	_Iterator
	operator+(
			std::size_t x,  _Iterator n) 
	{
		n += x;
		return n;
	}
	template <class _Iterator>
	_Iterator
	operator-(_Iterator n,
			std::size_t x) 
	{
		n -= x;
		return n;
	}






}
#endif

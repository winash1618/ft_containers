/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:50:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/09/14 14:26:30 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{
	template<typename T>
	class iterator
	{
		private:
			T* _iterator;

		public:
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::ptrdiff_t					difference_type;
			typedef ft::random_access_iterator_tag	iterator_category;
			iterator() : _iterator(){}
			iterator(T* iter) : _iterator( iter ){}
			iterator(const iterator& x)
			{
				*this = x;
			}
			
			iterator& operator=(const iterator<T>& __u) // commented for linux working fine in mac
			{ 
				if (this != &__u) 
				{
					this->_iterator = __u._iterator;
				}
				return *this;
			}
			reference operator*() const { 
				return *_iterator; 
			}
			
			pointer operator->() const { 
				return _iterator; 
			}
			
			iterator& operator++() { 
				++_iterator; 
				return *this; 
			}
			
			iterator operator++(int) { 
				iterator tmp(*this); ++(*this); 
				return tmp; 
			}
			
			iterator& operator--() { 
				--_iterator;
				return *this;
			}
			
			iterator operator--(int) { 
				iterator tmp(*this); 
				--(*this); 
				return tmp;
			}
			
			iterator& operator+=(const difference_type other) { 
				_iterator += other; 
				return *this; 
			}
			
			iterator& operator-=(const difference_type other) { 
				_iterator -= other; 
				return *this;
			}
			
			difference_type operator-(const iterator& other) const { 
				return std::distance(_iterator, other._iterator); 
			}
			// difference_type operator-(const __wrap_iter& other) const { 
			// 	return std::distance(_iterator, other._iterator); 
			// }
			
			
			// iterator*  operator- (difference_type n) const
			// {
			// 	return __wrap_iter(_iterator - n);
			// }
			
			reference operator[](std::size_t index) const { 
				return _iterator[index]; 
			}
			
			T* base() const
			{
				return _iterator;
			}
			// bool operator==(const iterator& rhs) const {return _iterator==rhs._iterator;}
			// bool operator!=(const iterator& rhs) const {return _iterator!=rhs._iterator;}
	};
	



	
	//-------------distance function-----------------------------------//

	template <class _RandIter>
	typename ft::iterator_traits<_RandIter>::difference_type
	__distance(_RandIter first, _RandIter last, ft::random_access_iterator_tag)
	{
		// std::cout << last - first << " : distance" << std::endl;
		// return last - first;
		typename ft::iterator_traits<_RandIter>::difference_type r(0);
		for (; first != last; ++first)
			++r;
		return r;
	}
	template<class _InputIter>
	typename ft::iterator_traits<_InputIter>::difference_type
	__distance (_InputIter first, _InputIter last, ft::input_iterator_tag)
	{
		typename ft::iterator_traits<_InputIter>::difference_type r(0);
		for (; first != last; ++first)
			++r;
		return r;
	}
	template <class InputIter>
	typename ft::iterator_traits<InputIter>::difference_type
	distance(InputIter first, InputIter last)
	{
		return __distance(first, last, typename ft::iterator_traits<InputIter>::iterator_category());
	}
	//--------------------------------------------------------------------//

	//----------------iterator function----------------------------------//
	template <class _InputIter>
	void __advance(_InputIter& i,
				typename ft::iterator_traits<_InputIter>::difference_type n, input_iterator_tag)
	{
		for (; n > 0; --n)
			++i;
	}

	template <class _BiDirIter>
	void __advance(_BiDirIter& i,
				typename ft::iterator_traits<_BiDirIter>::difference_type n, bidirectional_iterator_tag)
	{
		if (n >= 0)
			for (; n > 0; --n)
				++i;
		else
			for (; n < 0; ++n)
				--i;
	}

	template <class _RandIter>
	void __advance(_RandIter& i,
				typename ft::iterator_traits<_RandIter>::difference_type n, random_access_iterator_tag)
	{
		i += n;
	}

	template <class _InputIter>
	void advance(_InputIter& i,
				typename ft::iterator_traits<_InputIter>::difference_type n)
	{
		assert(n >= 0 && "Attempt to advance(it, -n) on a non-bidi iterator");
		__advance(i, n, typename ft::iterator_traits<_InputIter>::iterator_category());
	}



	template <class _Iter1, class _Iter2>
	bool
	operator==(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y) 
	{
		return __x.base() == __y.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator<(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y) 
	{
		return __x.base() < __y.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator!=(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y) 
	{
		return !(__x == __y);
	}

	template <class _Iter1, class _Iter2>
	bool
	operator>(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y) 
	{
		return __y < __x;
	}

	template <class _Iter1, class _Iter2>
	bool
	operator>=(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y) 
	{
		return !(__x < __y);
	}

	template <class _Iter1, class _Iter2>
	bool
	operator<=(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y) 
	{
		return !(__y < __x);
	}

	template <class _Iter1>
	bool
	operator!=(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y) 
	{
		return !(__x == __y);
	}

	template <class _Iter1>
	bool
	operator>(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y) 
	{
		return __y < __x;
	}

	template <class _Iter1>
	bool
	operator>=(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y) 
	{
		return !(__x < __y);
	}

	template <class _Iter1>
	bool
	operator<=(const iterator<_Iter1>& __x, const iterator<_Iter1>& __y) 
	{
		return !(__y < __x);
	}

	
	template <class _Iter1, class _Iter2>
	typename iterator<_Iter1>::difference_type
	operator-(const iterator<_Iter1>& __x, const iterator<_Iter2>& __y) 
	{
		return __x.base() - __y.base();
	}

	template <class _Iter>
	_Iter
	operator+(_Iter __n,
			std::size_t __x) 
	{
		__n += __x;
		return __n;
	}
	template <class _Iter>
	_Iter
	operator-(_Iter __n,
			std::size_t __x) 
	{
		__n -= __x;
		return __n;
	}
}
#endif

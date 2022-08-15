/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:50:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/15 14:14:23 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{
	// template <class Category, class T, class Distance = ptrdiff_t,
	// class Pointer = T*, class Reference = T&>
	// struct iterator 
	// {
	// 	typedef T			value_type;
	// 	typedef Distance	difference_type;
	// 	typedef Pointer		pointer;
	// 	typedef Reference	reference;
	// 	typedef Category	iterator_category;
	// };

	template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
	struct iterator
	{
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
	};
	
	template<typename T>
	class My_iterator : public ft::iterator<ft::random_access_iterator_tag, int>
	{
		private:
			T* _iterator;

		public:
			My_iterator(T* iter = nullptr) : _iterator( iter )
			{
				
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
			
			difference_type operator-(const My_iterator& other) const { 
				return std::distance(_iterator, other._iterator); 
			}
			
			reference operator[](std::size_t index) const { 
				return _iterator[index]; 
			}
	};
	
	//-------------distance function-----------------------------------//

	template <class _RandIter>
	typename ft::iterator_traits<_RandIter>::difference_type
	__distance(_RandIter first, _RandIter last, ft::random_access_iterator_tag)
	{
		return last - first;
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
}
#endif

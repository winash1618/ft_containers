/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:50:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/17 19:02:18 by mkaruvan         ###   ########.fr       */
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
			iterator();
			//  {}
			iterator(iterator_type iter);
			//  : __i( iter )
			//  {}
			iterator(const iterator& x);
			//  : __i(x.base())
			//  {}
			template<class X>
			iterator(const iterator<X>& u);
			// :__i(u.base())
			//  {}
			reference operator*() const;
			//  {return *__i;}
			pointer  operator->() const;
			//  {return __i;}
			iterator& operator++();
			//  {++__i; return *this;}
			iterator  operator++(int);
			//  {iterator __tmp(*this); ++(*this); return __tmp;}
			iterator& operator--();
			//  {--__i; return *this;}
			iterator  operator--(int);
			//  {iterator __tmp(*this); --(*this); return __tmp;}
			iterator  operator+ (difference_type __n) const;
			//  {iterator __w(*this); __w += __n; return __w;}
			iterator& operator+=(difference_type __n);
			//  {__i += __n; return *this;}
			iterator  operator- (difference_type __n) const;
			//  const {return *this + (-__n);}
			iterator& operator-=(difference_type __n);
			//  {*this += -__n; return *this;}
			reference operator[](difference_type __n) const;
			//  const {return __i[__n];}
			iterator_type base() const;
			//  {return __i;}
	};

	template <class _Iter1, class _Iter2>
	bool operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	// {
	// 	return x.base() == y.base();
	// }
	template <class _Iter1, class _Iter2>
	bool operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	// {
	// 	return !(x == y);
	// }
	template <class _Iter1, class _Iter2>
	bool
	operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	// {
	// 	return x.base() < y.base();
	// }
	template <class _Iter1, class _Iter2>
	bool operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y); 
	// {
	// 	return y < x;
	// }
	template <class _Iter1, class _Iter2>
	bool
	operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	// {
	// 	return !(x.base() < y.base());
	// }
	template <class _Iter1, class _Iter2>
	bool operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	// {
	// 	return !(y.base() < x.base());
	// }
	template <class _Iter1>
	bool
	operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	// {
	// 	return x.base() == y.base();
	// }
	template <class _Iter1>
	bool operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	// {
	// 	return !(x == y);
	// }
	template <class _Iter1>
	bool operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	// {
	// 	return (x.base() < y.base());
	// }
	template <class _Iter1>
	bool operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	// {
	// 	return (y < x);
	// }
	template <class _Iter1>
	bool operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	// {
	// 	return !(x.base() < y.base());
	// }
	template <class _Iter1>
	bool operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	// {
	// 	return !(y.base() < x.base());
	// }
	
	template <class _Iter1, class _Iter2>
	typename ft::iterator<_Iter1>::difference_type
	operator-(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	// {
	// 	return x.base() - y.base();
	// }
	template <class _Iterator>
	_Iterator operator+(_Iterator n, std::size_t x);
	// {
	// 	n += x;
	// 	return n;
	// }
	template <class _Iterator>
	_Iterator operator+(std::size_t x,  _Iterator n);
	// {
	// 	n += x;
	// 	return n;
	// }
	template <class _Iterator>
	_Iterator operator-(_Iterator n, std::size_t x);
	// {
	// 	n -= x;
	// 	return n;
	// }
	#include "./../../srcs/extras/iterator.tpp"
	#include "./../../srcs/extras/iter_non_members.tpp"
}
#endif

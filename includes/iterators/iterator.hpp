/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:50:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/19 07:19:22 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft
{
	template<class _Iter>
	class iterator 
	{
		public:
			typedef _Iter															iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;

		private:
			iterator_type															__i;

		public:
			iterator();
			iterator(iterator_type iter);
			iterator(const iterator& x);
			template<class X>
			iterator(const iterator<X>& u);
			~iterator();

			iterator&															operator=(const iterator& __u);

			reference																operator*() const;
			pointer																	operator->() const;
			iterator&																operator++();
			iterator																operator++(int);
			iterator&																operator--();
			iterator																operator--(int);
			iterator																operator+ (difference_type __n) const;
			iterator&																operator+=(difference_type __n);
			iterator																operator- (difference_type __n) const;
			iterator&																operator-=(difference_type __n);
			reference																operator[](difference_type __n) const;
			iterator_type															base() const;
	};

	template <class _Iter1, class _Iter2>
	bool operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	template <class _Iter1, class _Iter2>
	bool operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	template <class _Iter1, class _Iter2>
	bool operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	template <class _Iter1, class _Iter2>
	bool operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y); 
	template <class _Iter1, class _Iter2>
	bool operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	template <class _Iter1, class _Iter2>
	bool operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	template <class _Iter1>
	bool operator==(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	template <class _Iter1>
	bool operator!=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	template <class _Iter1>
	bool operator<(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	template <class _Iter1>
	bool operator>(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	template <class _Iter1>
	bool operator>=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	template <class _Iter1>
	bool operator<=(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter1>& y);
	template <class _Iter1, class _Iter2>
	typename ft::iterator<_Iter1>::difference_type
	operator-(const ft::iterator<_Iter1>& x, const ft::iterator<_Iter2>& y);
	template <class _Iterator>
	_Iterator operator+(_Iterator n, std::size_t x);
	template <class _Iterator>
	_Iterator operator+(std::size_t x,  _Iterator n);
	template <class _Iterator>
	_Iterator operator-(_Iterator n, std::size_t x);

	#include "./../../srcs/extras/iterator.tpp"
	#include "./../../srcs/extras/iter_non_members.tpp"
}
#endif

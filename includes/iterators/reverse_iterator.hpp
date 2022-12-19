/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:27:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 21:56:23 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_const_iterator
	{
		private:
			Iterator _iter;

		protected:
			Iterator current;

		public:
			typedef Iterator														iterator_type;
			typedef std::ptrdiff_t													difference_type;
			typedef typename ft::iterator_traits<Iterator>::reference				reference;
			typedef typename ft::iterator_traits<Iterator>::pointer					pointer;
			typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;

			reverse_const_iterator();
			~reverse_const_iterator();
			explicit reverse_const_iterator(Iterator x);
			template <class U> 
			reverse_const_iterator(const reverse_const_iterator<U>& u);
			reverse_const_iterator(const reverse_const_iterator& x);

			reverse_const_iterator&													operator=(const reverse_const_iterator<Iterator>& __u);

			Iterator																base() const;
			reference																operator*() const;
			pointer																	operator->() const;
			reverse_const_iterator&													operator++();
			reverse_const_iterator													operator++(int);
			reverse_const_iterator&													operator--();
			reverse_const_iterator													operator--(int);
			reverse_const_iterator													operator+ (difference_type n) const;
			reverse_const_iterator&													operator+=(difference_type n);
			reverse_const_iterator													operator- (difference_type n) const;
			reverse_const_iterator&													operator-=(difference_type n);
			reference																operator[](difference_type n) const;
	};

	template <class _Iter1, class _Iter2>
	bool operator==(const reverse_const_iterator<_Iter1>& __x, const reverse_const_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator<(const reverse_const_iterator<_Iter1>& __x, const reverse_const_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator!=(const reverse_const_iterator<_Iter1>& __x, const reverse_const_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator>(const reverse_const_iterator<_Iter1>& __x, const reverse_const_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator>=(const reverse_const_iterator<_Iter1>& __x, const reverse_const_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator<=(const reverse_const_iterator<_Iter1>& __x, const reverse_const_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	typename ft::reverse_const_iterator<_Iter1>::difference_type operator-(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	typename ft::reverse_const_iterator<_Iter1>::difference_type operator+(const ft::reverse_const_iterator<_Iter1>& __x, const ft::reverse_const_iterator<_Iter2>& __y);

	template <class Iterator>
	class reverse_iterator
	{
		private:
			Iterator																	_iter;

		protected:
			Iterator																	current;

		public:
			typedef Iterator															iterator_type;
			typedef std::ptrdiff_t														difference_type;
			typedef typename ft::iterator_traits<Iterator>::reference					reference;
			typedef typename ft::iterator_traits<Iterator>::pointer						pointer;
			typedef typename ft::iterator_traits<Iterator>::value_type					value_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category			iterator_category;

			reverse_iterator();
			~reverse_iterator();
			explicit reverse_iterator(Iterator x);
			template <class U> 
			reverse_iterator(const reverse_iterator<U>& u);
			reverse_iterator(const reverse_iterator& x);

			reverse_iterator&															operator=(const reverse_iterator<Iterator>& __u);

			Iterator																	base() const;
			reference																	operator*() const;
			pointer																		operator->() const;
			reverse_iterator&															operator++();
			reverse_iterator															operator++(int);
			reverse_iterator&															operator--();
			reverse_iterator															operator--(int);
			reverse_iterator															operator+ (difference_type n) const;
			reverse_iterator&															operator+=(difference_type n);
			reverse_iterator															operator- (difference_type n) const;
			reverse_iterator&															operator-=(difference_type n);
			reference																	operator[](difference_type n) const;
	};

	template <class _Iter1, class _Iter2>
	bool operator==(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator<(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator!=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator>(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator>=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	bool operator<=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	typename ft::reverse_iterator<_Iter1>::difference_type operator-(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y);
	template <class _Iter1, class _Iter2>
	typename ft::reverse_iterator<_Iter1>::difference_type operator+(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y);

	#include "./../../srcs/extras/reverse_iterator.tpp"
	#include "./../../srcs/extras/const_reverse_iterator.tpp"
	#include "./../../srcs/extras/reverse_non_members.tpp"
}
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:27:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/10/08 13:46:41 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{

	const                         /* this is a const object...     */
	class nullptr_t
	{
	public:
	template<class T>          /* convertible to any type       */
	operator T*() const        /* of null non-member            */
		{ return 0; }           /* pointer...                    */

	template<class C, class T> /* or any type of null           */
		operator T C::*() const /* member pointer...             */
		{ return 0; }   

	private:
	void operator&() const;    /* Can't take address of nullptr */

	} nullptr_f = {};
	template <class Iterator>
	class reverse_iterator
		// : public ft::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
		// 				typename ft::iterator_traits<Iterator>::value_type,
		// 				typename ft::iterator_traits<Iterator>::difference_type,
		// 				typename ft::iterator_traits<Iterator>::pointer,
		// 				typename ft::iterator_traits<Iterator>::reference>
	{
	private:
		Iterator _iter;
	protected:
		Iterator current;
	public:
		typedef Iterator															iterator_type;
		typedef std::ptrdiff_t														difference_type;
		typedef typename ft::iterator_traits<Iterator>::reference					reference;
		typedef typename ft::iterator_traits<Iterator>::pointer						pointer;
		typedef typename ft::iterator_traits<Iterator>::value_type					value_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category			iterator_category;
		

		reverse_iterator(): _iter(), current(){}
		explicit reverse_iterator(Iterator x) : _iter(x), current(x) {}
		template <class U> 
		reverse_iterator(const reverse_iterator<U>& u):_iter(u.base()), current(u.base()) {}
		// template <class U> 
		// reverse_iterator& operator=(const reverse_iterator<U>& u);//c++11
		reverse_iterator(const reverse_iterator& x)
		{
			*this = x;
		}
		
		reverse_iterator& operator=(const reverse_iterator<Iterator>& __u) // commented for linux working fine in mac
		{ 
			if (this != &__u) 
			{
				_iter = current = __u.base();
			}
			return *this;
		}
		Iterator base() const
		{
			return current;
		}
		reference operator*() const
		{
			Iterator tmp = current;
			return *--tmp;
		}
		pointer   operator->() const
		{
			return &(operator*());
		}
		reverse_iterator& operator++()
		{
			--current; return *this;
		}
		reverse_iterator  operator++(int)
		{
			reverse_iterator tmp(*this); --current; return tmp;
		}
		reverse_iterator& operator--()
		{
			++current; return *this;
		}
		reverse_iterator  operator--(int)
		{
			reverse_iterator tmp(*this); ++current; return tmp;
		}
		reverse_iterator  operator+ (difference_type n) const
		{
			return reverse_iterator(current - n);
		}
		reverse_iterator& operator+=(difference_type n)
		{
			current -= n; return *this;
		}
		reverse_iterator  operator- (difference_type n) const
		{
			return reverse_iterator(current + n);
		}
		reverse_iterator& operator-=(difference_type n)
		{
			current += n; return *this;
		}
		reference         operator[](difference_type n) const
		{
			return *(*this + n);
		}
		// bool operator==(const reverse_iterator& rhs) const {return _iter==rhs._iter;}
		// 	bool operator!=(const reverse_iterator& rhs) const {return _iter!=rhs._iter;}
	};
	


template <class _Iter1, class _Iter2>
inline
bool
operator==(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
inline
bool
operator<(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() > __y.base();
}

template <class _Iter1, class _Iter2>
inline
bool
operator!=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return !(__x.base() == __y.base());
}

template <class _Iter1, class _Iter2>
inline
bool
operator>(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
inline
bool
operator>=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() <= __y.base();
}

template <class _Iter1, class _Iter2>
inline
bool
operator<=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __x.base() >= __y.base();
}

template <class _Iter1, class _Iter2>
	typename ft::reverse_iterator<_Iter1>::difference_type
	operator-(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y) 
	{
		return __y.base() - __x.base();
	}
template <class _Iter1, class _Iter2>
	typename ft::reverse_iterator<_Iter1>::difference_type
	operator+(const ft::reverse_iterator<_Iter1>& __x, const ft::reverse_iterator<_Iter2>& __y) 
	{
		return __x.base() + __y.base();
	}

	
	// Non member functions

	//---------relational operatators---------------------//
	// template <class Iterator>
	// bool operator==(const ft::reverse_iterator<Iterator>& lhs,
	// 				const ft::reverse_iterator<Iterator>& rhs)
	// {
	// 	return lhs.base() == rhs.base();
	// }

	// template <class Iterator, class i2>
	// inline bool operator!=(const ft::reverse_iterator<Iterator>& lhs,
	// 				const ft::reverse_iterator<i2>& rhs)
	// {
	// 	return lhs.base() != rhs.base();
	// }
	// template <class Iterator>
	// bool operator<(const ft::reverse_iterator<Iterator>& lhs,
	// 				const ft::reverse_iterator<Iterator>& rhs)
	// {
	// 	return lhs.base() > rhs.base();
	// }
	// template <class Iterator>
	// bool operator<=(const ft::reverse_iterator<Iterator>& lhs,
	// 				const ft::reverse_iterator<Iterator>& rhs)
	// {
	// 	return lhs.base() >= rhs.base();
	// }
	// template <class Iterator>
	// bool operator>(const ft::reverse_iterator<Iterator>& lhs,
	// 				const ft::reverse_iterator<Iterator>& rhs)
	// {
	// 	return lhs.base() < rhs.base();
	// }
	// template <class Iterator>
	// bool operator>=(const ft::reverse_iterator<Iterator>& lhs,
	// 				const ft::reverse_iterator<Iterator>& rhs)
	// {
	// 	return lhs.base() <= rhs.base();
	// }
	//-----------operator+(reverse_iterator)-------------//
	// template <class Iterator>
	// ft::reverse_iterator<Iterator> operator+(
	// 		typename ft::reverse_iterator<Iterator>::difference_type n,
	// 			const ft::reverse_iterator<Iterator>& rev_it)
	// {
	// 	return ft::reverse_iterator<Iterator>(rev_it.base() - n);
	// }
	// //-----------operator-(reverse_iterator)-------------//
	// template <class Iterator>
	// typename ft::reverse_iterator<Iterator>::difference_type operator-(
	// 	const ft::reverse_iterator<Iterator>& lhs,
	// 		const ft::reverse_iterator<Iterator>& rhs)
	// {
	// 	return rhs.base() - lhs.base();
	// }
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

	
	// template<typename T>
	// class reverse_iterator
	// {
	// 	private:
	// 		T* _rev_iter;

	// 	public:
	// 		typedef T											value_type;
	// 		typedef T*											pointer;
	// 		typedef T&											reference;
	// 		typedef typename std::ptrdiff_t						difference_type;
	// 		typedef typename std::random_access_iterator_tag	iterator_category;

	// 		typedef T iterator_type;
	// 		typedef my_reverse_iterator<T> self;
	// 		my_reverse_iterator() {}
	// 		explicit my_reverse_iterator(iterator_type rev_iter) : _rev_iter(rev_iter) {}
	// };


	
}
#endif

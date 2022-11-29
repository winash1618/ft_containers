/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:27:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/11/26 14:59:36 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{
	const
	class nullptr_t
	{
		public:
		template<class T>
		operator T*() const
		{
			return 0;
		}
		template<class C, class T>
		operator T C::*() const
		{
			return 0;
		}
		private:
		void operator&() const;
	} nullptr_f = {};
	template <class Iterator>
	class reverse_const_iterator
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
			

			reverse_const_iterator(): _iter(), current(){}
			explicit reverse_const_iterator(Iterator x) : _iter(x), current(x) {}
			template <class U> 
			reverse_const_iterator(const reverse_const_iterator<U>& u):_iter(u.base()), current(u.base()) {}
			reverse_const_iterator(const reverse_const_iterator& x)
			{
				*this = x;
			}
			
			reverse_const_iterator& operator=(const reverse_const_iterator<Iterator>& __u) // commented for linux working fine in mac
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
			reverse_const_iterator& operator++()
			{
				--current; return *this;
			}
			reverse_const_iterator  operator++(int)
			{
				reverse_const_iterator tmp(*this); --current; return tmp;
			}
			reverse_const_iterator& operator--()
			{
				++current; return *this;
			}
			reverse_const_iterator  operator--(int)
			{
				reverse_const_iterator tmp(*this); ++current; return tmp;
			}
			reverse_const_iterator  operator+ (difference_type n) const
			{
				return reverse_const_iterator(current - n);
			}
			reverse_const_iterator& operator+=(difference_type n)
			{
				current -= n; return *this;
			}
			reverse_const_iterator  operator- (difference_type n) const
			{
				return reverse_const_iterator(current + n);
			}
			reverse_const_iterator& operator-=(difference_type n)
			{
				current += n; return *this;
			}
			reference         operator[](difference_type n) const
			{
				return *(*this + n);
			}
			// bool operator==(const reverse_const_iterator& rhs) const {return _iter==rhs._iter;}
			// 	bool operator!=(const reverse_const_iterator& rhs) const {return _iter!=rhs._iter;}
	};
	template <class Iterator>
	class reverse_iterator
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
			reverse_iterator(const reverse_iterator& x)
			{
				*this = x;
			}
			
			reverse_iterator& operator=(const reverse_iterator<Iterator>& __u)
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
}
#endif

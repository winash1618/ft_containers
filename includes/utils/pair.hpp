/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:57:11 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/18 20:43:18 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2> 
	class pair
	{
		public:
			typedef T1							first_type;
			typedef T2							second_type;
			T1									first;
			T2									second;

			pair();
			pair(const T1& x, const T2& y);
			template<class U1, class U2>
			pair(const pair<U1, U2>& p);
			pair& operator=(const pair& p);
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}

	// std::equal
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	// std::lexicographical compare
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	#include "./../../srcs/extras/pair.tpp"
}
#endif
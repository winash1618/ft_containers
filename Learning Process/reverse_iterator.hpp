/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:27:34 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/14 13:53:57 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include <exception>
# include <stdexcept>
# include <algorithm>
# include <cassert>
# include <initializer_list>
# include <iterator>
# include <limits>
# include <memory>
# include <type_traits>
# include <utility>

namespace ft
{

	template <class Iterator>
	class reverse_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
	{
	protected:
		Iterator current;
	public:
		typedef Iterator                                            iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::reference       reference;
		typedef typename iterator_traits<Iterator>::pointer         pointer;

		constexpr reverse_iterator();
		constexpr explicit reverse_iterator(Iterator x);
		template <class U> constexpr reverse_iterator(const reverse_iterator<U>& u);
		template <class U> constexpr reverse_iterator& operator=(const reverse_iterator<U>& u);
		constexpr Iterator base() const;
		constexpr reference operator*() const;
		constexpr pointer   operator->() const;
		constexpr reverse_iterator& operator++();
		constexpr reverse_iterator  operator++(int);
		constexpr reverse_iterator& operator--();
		constexpr reverse_iterator  operator--(int);
		constexpr reverse_iterator  operator+ (difference_type n) const;
		constexpr reverse_iterator& operator+=(difference_type n);
		constexpr reverse_iterator  operator- (difference_type n) const;
		constexpr reverse_iterator& operator-=(difference_type n);
		constexpr reference         operator[](difference_type n) const;
	};
	
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

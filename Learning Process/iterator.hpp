/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:50:33 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/14 16:18:23 by mkaruvan         ###   ########.fr       */
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
			// typedef T											value_type;
			// typedef T*											pointer;
			// typedef T&											reference;
			// typedef typename std::ptrdiff_t						difference_type;
			// typedef typename std::random_access_iterator_tag		iterator_category;
			
			My_iterator(T* iter = nullptr) : _iterator( iter ) {}

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
}
#endif

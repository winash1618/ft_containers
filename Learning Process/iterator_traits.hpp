#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
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
	template<typename T>
	class reverse_iterator
	{
		private:
			T* _rev_iter;

		public:
			typedef T											value_type;
			typedef T*											pointer;
			typedef T&											reference;
			typedef typename std::ptrdiff_t						difference_type;
			typedef typename std::random_access_iterator_tag	iterator_category;

			typedef T iterator_type;
			typedef my_reverse_iterator<T> self;
			my_reverse_iterator() {}
			explicit my_reverse_iterator(iterator_type rev_iter) : _rev_iter(rev_iter) {}
	};
}
#endif
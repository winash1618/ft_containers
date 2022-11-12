#ifndef STACK_HPP
# define STACK_HPP

#include <stack>
#include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef Container							container_type;
		protected:
			Container c;
		public:
			explicit stack(const container_type& ctnr = container_type());
			~stack();
			bool										empty() const;
			size_type									size() const;
			value_type&									top();
			const value_type&							top() const;
			void										push(const value_type& x);
			void										pop();

			template <class T1, class C>
			friend bool operator==(const stack<T1, C>& x, const stack<T1, C>& y);
			template <class T1, class C>
			friend bool operator< (const stack<T1, C>& x, const stack<T1, C>& y);
			template <class T1, class C>
			friend bool operator!=(const stack<T1, C>& x, const stack<T1, C>& y);
			template <class T1, class C>
			friend bool operator> (const stack<T1, C>& x, const stack<T1, C>& y);
			template <class T1, class C>
			friend bool operator>=(const stack<T1, C>& x, const stack<T1, C>& y);
			template <class T1, class C>
			friend bool operator<=(const stack<T1, C>& x, const stack<T1, C>& y);
	};
	template <class T, class Container>
	bool operator==(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y);
	template <class T, class Container>
	bool operator< (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y);
	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y);
	template <class T, class Container>
	bool operator> (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y);
	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y);
	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y);

	template <class T, class Container>
	void swap(ft::stack<T, Container>& x, ft::stack<T, Container>& y);

	#include "../srcs/stack/stack_member_func.tpp"
	#include "../srcs/stack/stack_non_member_func.tpp"
}
#endif
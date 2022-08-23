#ifndef STACK_HPP
# define STACK_HPP

#include <stack>
#include "vector.hpp"
namespace ft
{
	template<class T, class Container = ft::vector<T>>
	class stack {
	public:
		using value_type      = typename Container::value_type;
		using reference       = typename Container::reference;
		using const_reference = typename Container::const_reference;
		using size_type       = typename Container::size_type;
		using container_type  = Container;
	
	protected:
		Container c;

	public:
	stack()  : c() {}
	~stack() ;
	explicit stack (const container_type& ctnr = container_type())

	bool empty() const{
		c.empty();
	}
	size_type size() const{
		c.size();
	}
	reference top(){
		c.end();
	}
	const_reference top() const{
		c.end();
	}

	void push(const value_type& x){
		c.push_back(x);
	}
	void pop(){
		c.pop_back();
	}

	void swap(stack& c) noexcept(is_nothrow_swappable_v<Container>)
};


template <class T, class Container>
  bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);

template <class T, class Container>
  void swap(stack<T, Container>& x, stack<T, Container>& y)
  noexcept(noexcept(x.swap(y)));
}
#endif
#ifndef STACK_HPP
# define STACK_HPP

#include <stack>
#include "vector.hpp"
namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack {
	public:
		typedef typename Container::value_type value_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::size_type size_type;
		typedef Container container_type;
	
	protected:
		Container c;

	public:
	
	explicit stack (const container_type& ctnr = container_type()) : c(ctnr){}
	~stack(){} 

	bool empty() const{
		return (c.empty());
	}
	size_type size() const{
		return (c.size());
	}
	reference top(){
		return (c.back());
	}
	const_reference top() const{
		return (c.back());
	}

	void push(const value_type& x){
		return (c.push_back(x));
	}
	void pop(){
		return (c.pop_back());
	}

};


template <class T, class Container>
  bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
  {
	return (x.c == y.c);
  }
template <class T, class Container>
  bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
  {
	return (x.c < y.c);
  }
template <class T, class Container>
  bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
  {
	return (x.c != y.c);
  }
template <class T, class Container>
  bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
  {
	return (x.c > y.c);
  }
template <class T, class Container>
  bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
  {
	return (x.c >= y.c);
  }
template <class T, class Container>
  bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
  {
	return (x.c <= y.c);
  }

template <class T, class Container>
  void swap(stack<T, Container>& x, stack<T, Container>& y)
  {
	x.c.swap(y.c);
  }
}
#endif
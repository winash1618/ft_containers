#ifndef PAIR_TPP
# define PAIR_TPP

template <class T1, class T2>
ft::pair<T1, T2>::pair():first(), second() {}

template <class T1, class T2>
ft::pair<T1, T2>::pair(const T1& x, const T2& y):first(x), second(y){}

template <class T1, class T2>
template<class U1, class U2>
ft::pair<T1, T2>::pair(const pair<U1, U2>& p): first(p.first)
{
	second = p.second;
}

template <class T1, class T2>
ft::pair<T1, T2>& ft::pair<T1, T2>::operator=(const pair& p) 
{
	if (this != &p)
	{
		first = p.first;
		second = p.second;
	}
	return *this;
}

template <class T1, class T2>
bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs.first==rhs.first && lhs.second==rhs.second;
}

template <class T1, class T2>
bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return !(lhs==rhs);
}

template <class T1, class T2>
bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
}

template <class T1, class T2>
bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return !(rhs<lhs);
}

template <class T1, class T2>
bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	return rhs<lhs;
}

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return !(lhs<rhs);
}
#endif
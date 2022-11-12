#ifndef STACK_NON_MEMBER_FUNC_TPP
# define STACK_NON_MEMBER_FUNC_TPP

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator==(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c == y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator< (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c < y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c != y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator> (const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c > y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c >= y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& x, const ft::stack<T, Container>& y)
{
	return (x.c <= y.c);
}

/**
 * @brief 
 * 
 * @tparam T 
 * @tparam Container 
 * @param x 
 * @param y 
 */
template <class T, class Container>
void swap(ft::stack<T, Container>& x, ft::stack<T, Container>& y)
{
	x.swap(y);
}
#endif
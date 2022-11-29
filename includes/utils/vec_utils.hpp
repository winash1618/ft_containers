#ifndef VEC_UTILS_HPP
# define VEC_UTILS_HPP

namespace ft
{
	template<class T, T v>
	struct integral_constant 
	{
		const static T value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
		value_type operator()() const { return value; } //since c++14
	};

	typedef integral_constant<bool, true> true_type1;
	typedef integral_constant<bool, false> false_type1;

	template <class T>
	struct is_integral : public false_type1{};

	template <>
	struct is_integral<bool> : public true_type1{};

	template <>
	struct is_integral<char> : public true_type1{};

	template <>
	struct is_integral<signed char> : public true_type1{};

	template <>
	struct is_integral<unsigned char> : public true_type1{};

	template <>
	struct is_integral<wchar_t> : public true_type1{};

	template <>
	struct is_integral<short> : public true_type1{};

	template <>
	struct is_integral<int> : public true_type1{};

	template <>
	struct is_integral<long> : public true_type1{};

	template <>
	struct is_integral<long long> : public true_type1{};

	template <>
	struct is_integral<unsigned short> : public true_type1{};

	template <>
	struct is_integral<unsigned int> : public true_type1{};

	template <>
	struct is_integral<unsigned long> : public true_type1{};

	template <>
	struct is_integral<unsigned long long> : public true_type1{};




/*--------------implementation 1 of enable if-----------------------------*/
	/* enable_if definitions */
	template<bool B, class T>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {typedef T type;};

	/* True type and False type*/
	struct true_type {
		static const bool value = true;
	};

	struct false_type {
		static const bool value = false;
	};

	template<typename T>
	int is_int() {
	return false;
	}

	template<>
	int is_int<int>() {
	return true;
	}

	// https://stackoverflow.com/questions/4307271/how-to-check-that-the-passed-iterator-is-a-random-access-iterator
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::random_access_iterator_tag)
	{
		if (first > last )
					throw std::length_error("vector");
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::input_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::output_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::forward_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, std::bidirectional_iterator_tag)
	{
		(void)first;
		(void)last;

	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::random_access_iterator_tag)
	{
		if (first > last )
					throw std::length_error("vector");
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::input_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::output_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::forward_iterator_tag)
	{
		(void)first;
		(void)last;
	}
	template <class _RandIter>
	void
	__check_valid(_RandIter first, _RandIter last, ft::bidirectional_iterator_tag)
	{
		(void)first;
		(void)last;

	}
	template <class InputIter>
	void
	check_valid(InputIter first, InputIter last)
	{
		__check_valid(first, last, typename ft::iterator_traits<InputIter>::iterator_category());
	}
	
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:58:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/08/06 17:29:34 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
namespace ft
{
	template <typename T>
	class Vector
	{
		public:
			// scope Vector<T>:: type definitions
			// typedef T ValueType;

			// constructors - specify size and an initial value
			Vector  (){}                      // vector of size = 0 and capacity = defaultCapacity
			// explicit Vector (size_t sz){}     // vector of size = capacity = sz ...
			// Vector  (size_t sz, const T& t){} // ... and all elements = t
			// Vector  (const Vector<T>&){}     // copy constructor
			// virtual ~Vector (){}              // destructor
			void say_hi()
			{
				std::cout << "hello world" << std::endl;
			}

			// // member operators
			// Vector<T>& operator =  (const Vector<T>&); // assignment operator
			// Vector<T>& operator += (const Vector<T>&); // expand to append argument
			// T&          operator [] (size_t);            // bracket operator
			// const T&    operator [] (size_t) const;      // const version

			// // other methods
			// bool     SetSize     (size_t);    // set size as specified, change capacity iff needed
			// bool     SetSize     (size_t, const T&); // ... and initialize new elements
			// bool     SetCapacity (size_t);    // force capacity change (up or down)
			// size_t   Size        () const;    // return size
			// size_t   Capacity    () const;    // return capacity

			// // Container class protocol
			// bool     Empty       () const;    // 1 iff empty
			// bool     PushBack    (const T&);  // expand by 1 new element appended at end
			// bool     PopBack     ();          // contract by 1 from end
			// void     Clear       ();          // make size = 0
			// T&       Front       ();          // return front element (index 0)
			// const T& Front       () const;    // cont version
			// T&       Back        ();          // return back element (index size - 1)
			// const T& Back        () const;    // const version

			// Iterator support
			// typedef      VectorIterator<T> Iterator; 
			// friend class VectorIterator<T>;
			// Iterator     Begin       () const;
			// Iterator     End         () const;
			// Iterator     rBegin      () const;
			// Iterator     rEnd        () const;

			// // Generic display methods 
			// void Display    (std::ostream& os, char ofc = '\0') const;
			// void Dump       (std::ostream& os) const;

			// overload of const T* operator, facilitates use of previously defined array functions
			// operator const T* () const; // auto conversion of vector to array
			// removed 11/10/04: new standard does not allow, creates ambiguities

		// protected:
		// 	// variables
		// 	size_t size_,        // current size of vector, 
		// 			capacity_;    // size of content_ array
		// 	T*     content_;     // pointer to the primative array elements

		// 	// method
		// 	static T*  NewArray (size_t);  // safe space allocator
	} ;
#include "vector.cpp" // include separate implementation file inside namespace
}
#endif
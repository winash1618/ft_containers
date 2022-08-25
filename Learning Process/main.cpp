#include "vector.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include <iterator>
#include "stack.hpp"
#include <vector>
#include <map>
#include <utility>

using namespace std;































































// int main()
// {
// 	// ft::vector<int> a(5, 4);
// 	vector<int> v1;
// 	 v1.assign (7,100);
// 	 v1.push_back(200);  
//     // Declaring an iterator
//     vector<int>::iterator i1;
// 	ft::vector<int> a(v1.begin(), v1.end());
// 	ft::vector<int> b(a);
// 	std::cout << "try to run operator[] : " << b[7] << std::endl;
// 	b.pop_back();
// 	std::cout << "size = " << b.size() << std::endl;
// 	// std::cout << b.size();
// 	// a.say();
// 	// container::vector<int> a();

// }

// int main() for iterator
// int main()
// {
		// vector<int> v1(1, 100);
		// ft::vector<int> v1(1 ,100);
		//  v1.push_back(2);  
		//  v1.push_back(20);  
		//  v1.push_back(10);  
		//  v1.push_back(201);  
		//  v1.push_back(203);  
		//  v1.push_back(204);  
		//  v1.push_back(202);  
		//  v1.push_back(208);  
		//  v1.push_back(209);  
		//  v1.push_back(206);  
		//  v1.push_back(207);  
		// ft::vector<int> a;
		// a.assign(v1.begin(), v1.end());

	    // Declaring an iterator
		// vector<int> v1(5, 100);
		// ft::vector<int> v1(5, 50);
		
		// std::cout << "std::is_integral<int>::value: " << ft::is_integral<double>::value << std::endl;
		// v1[0] = 100;
		// std::cout << v1[5] << std::endl;
		// std::cout << v1.size() << std::endl;

	    // vector<int>::iterator i1;
		// ft::vector<int> a(v1.begin(), v1.end());
		// std::cout << "Hi " << a[0] << std::endl;
		// std::cout << a.front() << std::endl;
		// ft::vector<int> b(a.begin(), a.end());
		// ft::vector<int> b(v1);
		// std::cout << "try to run operator[] : " << b[7] << std::endl;
		// v1.pop_back();
		// v1.pop_back();
		// std::cout << "size = " << v1.size() << std::endl;
		// std::cout << a.size();
		// // a.say();
		// // container::vector<int> a();
		// ft::vector<int>::iterator a1;
		// ft::vector<int>::iterator a3;
		// a1 = v1.begin();
		// a3 = v1.end();
		// std::cout << "begin() : " << v1.front() << std::endl;
		// std::cout << a1[7] << std::endl;
		// ft::vector<int>::reverse_iterator a2;
		// a2 = v1.rbegin();
		// std::cout << "begining is the end" << std::endl;
		// std::cout << a2[0] << std::endl;
		// // ft::advance(a1, 5);
		// std::cout << *a1 << std::endl;


		// std::cout << ft::distance(a1, a3) << std::endl;
		// b.assign(a1, a3);

		// ft::vector<int> b(3, 100);
		// ft::vector<int> c(5, 200);
		// b.print();
		// c.print();
		// b.swap(c);
		// b.print();
		// c.print();

		
		// v1.print();
		// ft::vector<int>::iterator i1;
		// ft::vector<int>::iterator i2;
		// ft::vector<int>::iterator i1;
		// ft::vector<int>::iterator i2;
		// vector<int>::iterator b1;
		// b1 = a.begin();
		// i1 = v1.begin() + 2;
		// i2 = v1.begin() + 5;


		// std::cout << "position : " << *i1 << std::endl;
		// std::cout << "position2 : " << b1[0] << std::endl;
		// v1.erase(i1);
		// v1.erase(i1, i2);
		// v1.print();
		// for(std::size_t i = 0;i < v1.size(); i++ )
		// {
		// 	std::cout << i << " th element " << v1[i] << std::endl;
		// }
		/*--------------------------------------------------------------*/
		/*--------------------------stack tests-------------------------*/
		/*--------------------------------------------------------------*/
		// ft::stack<int> a;
		// a.push(10);
		// std::cout << a.top() << std::endl;
		// a.pop();
		// std::cout << a.top() << std::endl;
		// std::vector<int> myvector;

		// set some initial content:
		// for (int i=1;i<10;i++) myvector.push_back(i);

		// myvector.resize(5);
		// myvector.resize(8,100);
  		// myvector.resize(5);
  		// myvector.resize(19);
		// std::cout << "myvector contains:";
		// for (int i=0;i<myvector.size();i++)
		// 	std::cout << ' ' << myvector[i];
		// std::cout << '\n';
		// std::cout << "size of std: " << myvector.size() << std::endl;
		// std::cout << "cap of ft: " << myvector.capacity() << std::endl;
		// std::cout << "My vector" <<std::endl;
		// ft::vector<int> myvector1;

		// set some initial content:
		// for (int i=1;i<10;i++)
		// 	myvector1.push_back(i);
		// myvector1.resize(5);
		// myvector1.resize(8,100);
  		// myvector1.resize(5);
  		// myvector1.resize(19);
		// std::cout << "size of vector  " << myvector1.size() << std::endl;
		// std::cout << "myvector contains:";
		// for (int i=0;i<myvector1.size();i++)
		// 	std::cout << ' ' << myvector1[i];
		// std::cout << '\n';
		// std::cout << "size of ft: " << myvector1.size() << std::endl;
		// std::cout << "cap of ft: " << myvector1.capacity() << std::endl;

		// std::vector<int> myvector (3,100);
		// std::vector<int>::iterator it;

		// it = myvector.begin() + 2;
		// it = myvector.insert ( it , 5, 200 );

		// myvector.insert (it,2,300);

		// // "it" no longer valid, get a new one:
		// it = myvector.begin();

		// std::vector<int> anothervector (2,400);
		// myvector.insert (it+2,anothervector.begin(),anothervector.end());

		// int myarray [] = { 501,502,503 };
		// myvector.insert (myvector.begin(), myarray, myarray+3);

		// std::cout << "myvector contains:";
// 		for (it=myvector.begin(); it<myvector.end(); it++)
// 			std::cout << ' ' << *it;
// 		std::cout << '\n';
// 		ft::vector<int> myvector1 (3,100);
// 		ft::vector<int>::iterator it1;

// 		it1 = myvector1.begin() +2 ;
// 		 myvector1.insert ( it1 , 5, 200 );
// 		for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
// 			std::cout << ' ' << *it1;
// 		std::cout << '\n';

// }
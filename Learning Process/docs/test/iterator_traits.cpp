// C++ STL iterator, iterator_traits class for vector and list

#include <iterator>

#include <vector>

#include <iostream>

#include <list>

#include <array>

using namespace std;

 

int main()

{

// vectors and list containers

vector<int> vec1;

vector<char> vec2;

list<char> lst;


 

typedef iterator_traits<vector<int>::iterator>::iterator_category cati;

typedef iterator_traits<vector<char>::iterator>::iterator_category catc;

typedef iterator_traits<vector<double>::iterator>::iterator_category catp;

typedef iterator_traits<array<string, 5>::iterator>::iterator_category catk;

typedef iterator_traits<list<char>::iterator>::iterator_category catlst;
int i;
 

// both are random-access iterators

cout<<"The type of iterator for vector<int> is identified by the tag: "<<" "<<typeid(cati).name()<<endl;
cout<<"The type of iterator for vector<int> is identified by the tag: "<<" "<<typeid(i).name()<<endl;

cout<<"The type of iterator for vector<char> is identified by the tag: "<<" "<<typeid(catc).name()<<"\n";

cout<<"The type of iterator for vector<char> is identified by the tag: "<<" "<<typeid(catp).name()<<"\n";

cout<<"The type of iterator for array<string, 5> is identified by the tag: "<<" "<<typeid(catk).name()<<"\n";

cout<<"The type of iterator for list<char> is identified by the tag: "<<typeid(catlst).name()<<endl;

cout<<"\nOperation: typeid(cati) == typeid(catc)"<<endl;

if(typeid(cati) == typeid(catc))

cout<<"The iterators type are the same."<<endl<<endl;

else

cout<<"The iterators type are not the same."<<endl<<endl;

 

// but the list iterator is bidirectional, not random access


cout<<"\nOperation: typeid(vec1.begin())==typeid(vec2.begin())"<<endl;

if(typeid(vec1.begin()) == typeid(vec2.begin()))

cout<<"The iterators type are the same."<<endl;

else

cout<<"The iterators type are not the same."<<endl;

return 0;

}
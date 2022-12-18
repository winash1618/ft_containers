#include "vector.hpp"
#include <iterator>
#include <vector>
#include <map>
#include <sys/time.h>
#include <iomanip>
#include <utility>

int main ()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		CT::vector<int> first;
		CT::vector<int> second;
		CT::vector<int> third;
		first.assign (7,100);             // 7 ints with a value of 100
		CT::vector<int>::iterator it;
		it=first.begin()+1;
		second.assign (it,first.end()-2);
		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.
	}

	{
		CT::vector<int> myvector;
		for (int i=1; i<=1000; i++) myvector.push_back(i);
		myvector.erase (myvector.begin()+5);
		myvector.erase (myvector.begin(),myvector.begin()+400);
	}

	{
		CT::vector<int> myvector (3,100);
		CT::vector<int>::iterator it;
		it = myvector.begin();
		it = myvector.insert ( it , 200 );
		myvector.insert (it,13,300);
		it = myvector.begin();
		std::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;

	return 0;
}
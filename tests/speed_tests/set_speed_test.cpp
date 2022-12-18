#include <iostream>
#include <set>
#include "set.hpp"
#include <string>
#include <sys/time.h>
#include <iomanip>
int main ()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	
	{
		int myints[] = {75,23,65,42,1375,23,65,42,1375,23,65,42,1375,23,65,42,1375,23,65,42,1375,23,65,42,1375,23,65,42,1375,23,65,42,13};
		CT::set<int> myset (myints,myints+30);
	}

	{
		CT::set<int> myset;
		CT::set<int>::iterator it;
		for (int i=1; i<1000; i++) myset.insert(i*10);
		it = myset.begin();
		++it;
		myset.erase (it);
		myset.erase (40);
		it = myset.find (60);
		myset.erase (it, myset.end());
	}

	{
		CT::set<int> myset;
		CT::set<int>::iterator it;
		CT::pair<CT::set<int>::iterator,bool> ret;
		for (int i=1; i<=5; ++i) myset.insert(i*10);
		ret = myset.insert(20);
		if (ret.second==false) it=ret.first;
		myset.insert (it,25);
		myset.insert (it,24);
		myset.insert (it,26);
		int myints[]= {5,10,15};
		myset.insert (myints,myints+3);
	}

	{

	}
	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;

	return 0;
}
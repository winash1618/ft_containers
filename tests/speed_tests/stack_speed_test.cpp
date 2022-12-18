
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <sys/time.h>
#include <iomanip>
#include "vector.hpp"
#include "stack.hpp"

int main ()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		std::deque<int> mydeque (300,100); 
		std::vector<int> myvector (200,200);
		CT::stack<int> first;
		CT::stack<int, std::deque<int> > second (mydeque);
		CT::stack<int,std::vector<int> > third;
		CT::stack<int,std::vector<int> > fourth (myvector);
	}

	{
		CT::stack<int> mystack;
		for (int i=0; i<500; ++i) mystack.push(i);
		while (!mystack.empty())
			mystack.pop();
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;

	return 0;
}
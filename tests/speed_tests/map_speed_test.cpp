#include <iostream>
#include <string>
#include <sys/time.h>
#include <iomanip>
#include <map>
#include "map.hpp"
int main ()
{
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	{
		CT::map<std::string,int> mymap;
		mymap["alpha"]=0;
		mymap["beta"]=0;
		mymap["gamma"]=0;
		mymap.at("alpha") = 10;
		mymap.at("beta") = 20;
		mymap.at("gamma") = 30;
	}

	{
		CT::map<char,int> mymap;
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
		mymap.clear();
		mymap['a']=1101;
		mymap['b']=2202;
	}

	{
		CT::map<char,int> mymap;
		mymap.insert ( CT::pair<char,int>('a',100) );
		mymap.insert ( CT::pair<char,int>('z',200) );
		CT::pair<CT::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( CT::pair<char,int>('z',500) );
		CT::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, CT::pair<char,int>('b',300));
		mymap.insert (it, CT::pair<char,int>('c',400));
		CT::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));
	}

	{
		CT::map<char,int> mymap;
		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;
		mymap['d']=100;
		mymap['e']=200;
		mymap['f']=300;
		mymap['g']=100;
		mymap['h']=200;
		mymap['i']=300;
		mymap['j']=100;
		mymap['k']=200;
		mymap['l']=300;
		mymap['m']=100;
		mymap['n']=200;
		mymap['o']=300;
		mymap['p']=100;
		mymap['q']=200;
		mymap['r']=300;
		mymap['s']=100;
		mymap['t']=200;
		mymap['u']=300;
		mymap['v']=100;
		mymap['w']=200;
		mymap['x']=300;
		mymap['y']=100;
		mymap['z']=200;
		mymap['+']=300;
		mymap['-']=100;
		mymap['@']=200;
		mymap['#']=300;
		CT::map<char,int>::iterator it=mymap.begin();
		mymap.erase (it);
		mymap.erase ('c');
		it=mymap.find('b');
		mymap.erase ( it, mymap.end() );
	}

	{
		CT::map<char,int> mymap;
		CT::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');
		itup=mymap.upper_bound ('d');
		mymap.erase(itlow,itup);
	}

	{
		CT::map<char,int> mymap;
		CT::map<char,int>::iterator it;
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		it=mymap.find('b');
		mymap.erase (it);
		mymap.erase ('c');
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );
	}

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	std::cout << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;

	return 0;
}
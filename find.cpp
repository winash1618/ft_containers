#include <map>
#include "includes/map.hpp"

int main ()
{
  CT::map<int,int> mymap;
  CT::map<int, int> mymap1;
  mymap[1]=101;
  mymap[2]=202;
  mymap[3]=302;
  mymap[4]=101;
  mymap[5]=202;
  mymap[6]=302;
  mymap[7]=101;
  mymap[8]=202;
  mymap[9]=302;
  mymap[10]=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
	mymap.erase(10);
	mymap.erase(4);
	mymap.erase(1);
	mymap.erase(2);
	mymap.erase(3);
	mymap.erase(5);
	mymap.erase(6);
	mymap.erase(7);
	mymap.erase(8);
	mymap.erase(9);
	mymap.erase(1);
	mymap.erase(0);
	mymap.erase(0);
	mymap.erase(0);
	mymap.erase(0);
	mymap.erase(0);
	mymap.erase(0);
	mymap[1]=101;
  	mymap[2]=202;
  	mymap[3]=302;
  	mymap[4]=101;
  	mymap[5]=202;
  	mymap[6]=302;
 	mymap[7]=101;
  	mymap[8]=202;
 	mymap[9]=302;
 	mymap[10]=302;
	mymap.erase(546654654);
	std::cout << mymap.size() << std::endl;

  return 0;
}
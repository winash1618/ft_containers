#include "pair.hpp"
#include "map.hpp"
#include <iostream>
#include <string>
#include <map>


int main()
{
	ft::map<std::string, int> A;
}





// #include "pair.hpp"      // std::pair, std::make_pair
// #include <string>       // std::string
// #include <iostream>     // std::cout

// int main () {
//   ft::pair <std::string,int> planet;
//   ft::pair <std::string,int> homeplanet;
  

//   planet = ft::make_pair("Earth",6371);

//   homeplanet = planet;
// 	ft::pair <std::string,int> exoplanet(homeplanet);
//   std::cout << "Home planet: " << exoplanet.first << '\n';
//   std::cout << "Planet size: " << exoplanet.second << '\n';
//   return 0;
// }
// #include "pair.hpp"
// #include <utility>      // std::pair
// #include <iostream>     // std::cout

// int main ()
// {
//   ft::pair<int,char> foo (10,'z');
//   ft::pair<int,char> bar (90,'a');

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }
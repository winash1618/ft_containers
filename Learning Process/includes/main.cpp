#include "pair.hpp"      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main () {
  ft::pair <std::string,int> planet;
  ft::pair <std::string,int> homeplanet;
  

  planet = ft::make_pair("Earth",6371);

  homeplanet = planet;
	ft::pair <std::string,int> exoplanet(homeplanet);
  std::cout << "Home planet: " << exoplanet.first << '\n';
  std::cout << "Planet size: " << exoplanet.second << '\n';
  return 0;
}
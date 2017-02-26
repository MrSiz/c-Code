#include "../pair.h"
#include <iostream>


int main()
{
	tinySTL::pair<int, double> p(1, 2.2);
	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;
	
	std::cout << tinySTL::get<0>(p) << std::endl;
	std::cout << tinySTL::get<1>(p) << std::endl;

	
}
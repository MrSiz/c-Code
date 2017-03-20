#include "../algorithm"
#include <iostream>

using namespace tinySTL;

int main()
{
	//test for lower_bound
	int arr0[6]{1, 2, 3, 4, 5, 5};
	std::cout << (lower_bound(arr0, arr0 + 6, 6) - arr0) << std::endl;
}
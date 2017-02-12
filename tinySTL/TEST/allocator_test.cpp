#include "../allocator.h"
#include <vector>
#include <iostream>

int main()
{
	int arr[] = { 1, 2, 3 };
	std::vector<int, tinySTL::allocator<int> > v(arr, arr + 3);
	for (auto val : v)
	{
		std::cout << val << '\n';
	}
	return 0;
}
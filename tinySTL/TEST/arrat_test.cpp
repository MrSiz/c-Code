#include "../array"
#include <iostream>

using namespace tinySTL;

int main()
{
	array<int, 5> arr{1, 2, 3};
	std::cout << arr[0] << std::endl;
	std::cout << arr.at(0) << std::endl;
	arr.fill(5);
	for (auto val : arr)
	{
		std::cout << val << std::endl;
	}
}
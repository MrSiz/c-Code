#include "../basic_sort.h"
#include <iostream>
int main()
{
	//test for insert_sort
	int arr[6] = {4, 3, 2, 5, 1, 3};
	tinySTL::insert_sort(arr, arr + 6);
	for (auto &val : arr)
	{
		std::cout << val << std::endl;
	}
	puts("===========================");
	//test for bubble_sort
	int arr1[6] = {3, 2, 5, 4, 4, 1};
	tinySTL::bubble_sort(arr1, arr1 + 6);
	for (auto &val : arr1)
	{
		std::cout << val << std::endl;
	}
}


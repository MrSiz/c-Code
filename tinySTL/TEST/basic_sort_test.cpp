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
	puts("===========================");
	//test for select_sort
	int arr2[6]{4, 2, 1, 5, 3, 3};
	tinySTL::select_sort(arr2, arr2 + 6);
	for (auto &val : arr2)
	{
		std::cout << val << std::endl;
	}
	puts("============================");
	//test for merge_sort
	int arr3[6] = {4, 3, 2, 5, 1, 6};
	int temp[6] = {};
	tinySTL::merge_sort(arr3, temp, 0, 5);
	for (auto &val : arr3)
	{
		std::cout << val << std::endl;
	}
	puts("=============================");
	//test for quick_sort
	int arr4[6] = {3, 2, 5, 4, 6, 1};
	tinySTL::quick_sort(arr4, 0, 5);
	for (auto &val : arr4)
	{
		std::cout << val << std::endl;
	}
	puts("==============================");
	
}


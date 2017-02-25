#ifndef TINYSTL_BASIC_SORT_H
#define TINYSTL_BASIC_SORT_H

#include <cstddef> //for size_t
#include "functional" //for less<>
#include "utility" //for swap
namespace tinySTL
{
	//insert sort
	//complexity O(n^2)
	template <class T, class C = tinySTL::less<T>>
	void insert_sort(T* first, T* last, C c = C())
	{
		size_t length = last - first;
		for (int i = 1; i < length; ++i)
		{
			for (int j = i; (j > 0) && (c(*(first + j), *(first + j - 1))); --j)
			{
				tinySTL::swap(*(first + j), *(first + j - 1));
			}
		}
	}

	//bubble sort
	//complexity O(n^2)
	template <class T, class C = tinySTL::less<T>>
	void bubble_sort(T* first, T* last, C c = C())
	{
		size_t n = last - first;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = n - 1; j > i; --j)
			{
				if (c(*(first + j), *(first + j - 1)))
				{
					tinySTL::swap(*(first + j), *(first + j - 1));
				}
			}
		}
	}
	
	//select sort
	//complexity O(n^2)
	template <class T, class C = tinySTL::less<T>>
	void select_sort(T* first, T* last, C c = C())
	{
		size_t n = last - first;
		for (int i = 0; i < n - 1; ++i)
		{
			int index = i;
			for (int j = n - 1; j > i; --j)
			{
				if (c(*(first + j), *(first + index)))
				{
					index = j;
				}
			}
			tinySTL::swap(*(first + i), *(first + index));
		}
	}
}

#endif // !TINYSTL_BASIC_SORT_H

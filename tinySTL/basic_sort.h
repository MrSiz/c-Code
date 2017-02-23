#ifndef TINYSTL_BASIC_SORT_H
#define TINYSTL_BASIC_SORT_H

#include <cstddef> //for size_t
#include "functional" //for less<>
#include "utility" //for swap
namespace tinySTL
{
	//insert sort
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
}

#endif // !TINYSTL_BASIC_SORT_H

#ifndef TINYSTL_BASIC_SORT_H
#define TINYSTL_BASIC_SORT_H

#include <cstddef> //for size_t
#include "functional" //for less<>
#include "utility" //for swap
#include <iostream>

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

	//merge sort
	//complexity O(nlgn)
	template <class T, class C = tinySTL::less<T>>
	void merge_sort(T* arr, T* temp, int left, int right, C c = C())
	{
		if (left == right)
			return;
		int m = (left + right) >> 1;
		merge_sort(arr, temp, left, m);
		merge_sort(arr, temp, m + 1, right);
		for (int i = left; i <= right; ++i)
		{
			temp[i] = arr[i];
		}
		int index1 = left, index2 = m + 1;
		for (int pos = left; pos <= right; ++pos)
		{
			if (index1 == m + 1)
			{
				arr[pos] = temp[index2++];
			}
			else if (index2 == right + 1)
			{
				arr[pos] = temp[index1++];
			}
			else if (c(*(temp + index1), *(temp + index2)))
			{
				arr[pos] = temp[index1++];
			}
			else
			{
				arr[pos] = temp[index2++];
			}
		}
	}
	
	//quick_sort
	//complexity O(nlgn)
	
	template <typename T, typename C = tinySTL::less<T>>
	void quick_sort(T* arr, T left, T right)
	{
		if (left >= right)
			return ;
		//choose the last element as pivot
		T pos = right, pivot = arr[right];
		T l = left, r = right - 1;
		do
		{
			while (arr[l] <= pivot)
			{
				++l;
			}
			while (l < r && arr[r] > pivot)
			{
				--r;
			}
			tinySTL::swap(arr[l], arr[r]);
		}while (l < r);
		tinySTL::swap(arr[pos], arr[l]);
		quick_sort(arr, left, l - 1);
		quick_sort(arr, l + 1, right);
		return ;
	}

	template <typename T, typename Comp = tinySTL::less<T>>
	void build_heap(T* arr, size_t index, size_t end_index, Comp comp = Comp())
	{
		auto func = [=](const auto pos) -> bool {
			return (pos >= end_index / 2) && pos < end_index;
		};
		while (!func(index))
		{
			//std::cout << "test" << std::endl;
			T lchild = (index << 1) + 1;
			T rchild = (index << 1) + 2;
			if (rchild < end_index && comp(*(arr + rchild), *(arr + lchild)))
				lchild = rchild;
			if (comp(*(arr + index), *(arr + lchild)))
				return ;
			tinySTL::swap(*(arr + index), *(arr + lchild));
			index = lchild;
	
			//std::cout << index << std::endl;
			//char q;
			//std::cin >> q;
		}
		return ;
	}
	
	template <typename T, typename C = tinySTL::less<T>>
	void heap_sort(T* arr, size_t length)
	{
		T pos = (length >> 1) - 1;
		while (pos >= 0)
		{
			build_heap<T, C>(arr, pos, length);
			--pos;
		}
		//for (int i = 0; i < length; ++i)
		//{
		//	std::cout << arr[i] << ' ';
		//}
		//std::cout << std::endl;
		size_t t = 0;
	
		for (int i = 0; i < length; ++i){
			//std::cout << 't' << t << ' ' << arr[t] << std::endl;
			//	std::cout << "finale" << arr[5] << std::endl;
			tinySTL::swap(arr[t++], arr[i]);
			//std::cout << "length " <<  length - t << std::endl;
			build_heap(arr + t, 0, length - t + 1);
		}
	}
}


#endif // !TINYSTL_BASIC_SORT_H

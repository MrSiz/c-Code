#ifndef TINYSTL_LIST_H
#define TINYSTL_LIST_H

#include <cstddef> //for size_t, ptrdiff_t

#include "allocator.h" //for allocator 
#include "iterator" //for iterator


namespace tinySTL
{

	template <class T>
	struct List_node
	{
		List_node* prev_node;
		List_node* next_node;
		T data;
	};

	template<class T, class Allocator = tinySTL::allocator<T>>
	class list
	{
	public:
		typedef T									 value_type;
		typedef Allocator							 allocator_type;
		typedef size_t								 size_type;
		typedef ptrdiff_t							 difference_type;
		typedef T&									 reference;
		typedef const T&							 const_reference;
		typedef typename Allocator::pointer			 pointer;
		typedef typename Allocator::const_pointer	 const_pointer;
		typedef T*									 iterator;
		typedef const T*							 const_iterator;
		typedef tinySTL::reverse_iterator<iterator>  reverse_iterator;
		typedef tinySTL::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
	    tinySTL::allocator<List_node<T>> data_allocator;
		List_node<T>* M_node;

	private:
		List_node<T>* M_get_node()
		{
			return data_allocator.allocate(1);
		}
		void M_put_node(List_node<T>* ptr)
		{
			data_allocator.deallocate(ptr);
		}
		void M_init()
		{
			M_node = M_get_node();
			M_node->next_node = M_node;
			M_node->prev_node = M_node;
		}
	public:
		explicit list() : data_allocator()
		{
			M_init();
		}
		list(const list& other) : data_allocator()
		{
			insert(begin(), other.begin(), other.end());
		}
		template <class InputIterator>
		list(InputIterator first, InputIterator last) : data_allocator()
		{
			insert(begin(), other.begin(), other.end());
		}
		~list()
		{
			clear();
		}
	public:
		list& operator=(const list& other)
		{

		}
		void clear()
		{
			erase(begin(), end());
		}
	};
}

#endif // !TINYSTL_LIST_H
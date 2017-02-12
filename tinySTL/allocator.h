#ifndef TINYSTL_ALLOCATOR_H
#define TINYSTL_ALLOCATOR_H

#include <cstddef>  //for size_t, ptrdiff_t
#include <new>		//for placement new
#include <cstdlib>  //for malloc, free

namespace tinySTL
{
	template <typename T>	
	class allocator
	{
	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;
	public:
		template <typename U>
		struct rebind
		{
			typedef allocator<U> other;
		};
	public:
		allocator() {}
		allocator(const allocator &other) {}
		template <typename U>
		allocator(const allocator<U>& other) {}

		~allocator() {}
	public:
		//Get the address of x
		T*		 address(T& x) const;
		const T* address(const T& x) const;

		T*		allocate();
		T*		allocate(size_t n);
		void	deallocate(T* ptr);
		void	deallocate(T* ptr, size_t n);
		
		void	construct(T* ptr);
		void	construct(T* ptr, const T& val);
		void	destroy(T* ptr);
		void	destroy(T* first, T* last);
		
		size_t  max_size() const;
	};
	template <typename T>
	T* allocator<T>::address(T& x) const
	{ 
		return &x;
	}
	template <typename T>
	const T* allocator<T>::address(const T& x) const
	{ 
		return &x;
	}
	//!!Can be improved;
	template <typename T>
	T* allocator<T>::allocate()
	{
		return static_cast<T*>(malloc(sizeof(T)));
	}
	template <typename T>
	T* allocator<T>::allocate(size_t n)
	{
		return n == 0 ? nullptr : static_cast<T*>(malloc(sizeof(T) * n));
	}
	template <typename T>
	void allocator<T>::deallocate(T* ptr)
	{
		free(ptr);
	}
	template <typename T>
	void allocator<T>::deallocate(T* ptr, size_t n)
	{
		free(ptr);
	}
	template <typename T>
	void allocator<T>::construct(T *ptr)
	{
		new(ptr) T();
	}
	template <typename T>
	void allocator<T>::construct(T* ptr, const T& val)
	{
		new(ptr) T(val);
	}
	template <typename T>
	void allocator<T>::destroy(T* ptr)
	{
		ptr -> ~T();
	}
	template <typename T>
	void allocator<T>::destroy(T* first, T* last)
	{
		for (; first != last; ++first)
		{
			first -> ~T();
		}
	}
	template <typename T>
	size_t  allocator<T>::max_size() const
	{
		return size_t(-1) / sizeof(T);
	}
}

#endif // ! TINYSTL_ALLOCATOR_H

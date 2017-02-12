#ifndef TINYSTL_INITIALIZER_LIST_H
#define TINYSTL_INITIALIZER_LIST_H

#include <cstddef> //for size_t

namespace tinySTL
{
	template< class T >
	class initializer_list
	{
	public:
		typedef T		 value_type;
		typedef const T& reference;
		typedef const T& const_reference;
		typedef size_t   size_type;
		typedef const T* iterator;
		typedef const T* const_iterator;
	private:
		iterator it_;
		size_type sz_;
	public:
		//I think it depends on the compiler 
		//to construct a container with initilizer_list.
		//= =

		constexpr initializer_list() noexcept : it_(0), sz_(0) {}
		constexpr size_type size() const noexcept
		{
			return sz_;
		}
		constexpr const_iterator begin() const noexcept
		{
			return it_;
		}
		constexpr const_iterator end() const noexcept
		{
			return begin() + size();
		}
	};
}
#endif // !TINYSTL_INITIALIZER_LIST_H

#ifndef  TINYSTL_SMART_POINTER_H
#define TINYSTL_SMART_POINTER_H

#include "type_traits" //for remove_reference



namespace tinySTL
{
	//deleter of unique_ptr
	template <class T>
	struct default_delete
	{
		constexpr default_delete() noexcept = default;
		template <class U>
		default_delete(const default_delete<U>& d) noexcept
		{

		}
		void operator()(T* ptr) const
		{
			delete ptr;
		}
	};

	template <class T>
	struct default_delete<T[]>
	{
		constexpr default_delete() noexcept = default;
		template<class U>
		default_delete(const default_delete<U[]>& d) noexcept
		{

		}
		template <class U>
		void operator()(U* ptr) const
		{
			delete[] ptr;
		}
	};

	template <class T>
	class shared_ptr
	{
		
	};
	
	
	template <class T, class Deleter = tinySTL::default_delete<T>> 
	class unique_ptr
	{
		class help
		{
		public:
			template <class U>
			static typename U::pointer help_func(typename U::pointer);

			template <class U>
			static T* help_func(...);

			using rm_ref = tinySTL::remove_reference<Deleter>::type;

			using type = decltype(help_func<Deleter>(0));

		};

	public:

	};
}


#endif // ! TINYSTL_SMART_POINTER_H
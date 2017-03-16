#ifndef  TINYSTL_SMART_POINTER_H
#define TINYSTL_SMART_POINTER_H

#include "type_traits" //for remove_reference
#include "pair.h" //for pair<>


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
		using pointer = help::type;
		using element_type = T;
		using deleter_type = Deleter;
	private:
		element_type* ptr;
		deleter_type deleter;
	public:
		//initialize ptr = nullptr if no argument
		// Disable copy from lvalue.
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;

		explicit unique_ptr(pointer ptr_val = nullptr) :ptr(ptr_val) {}
		unique_ptr(unique_ptr&& rhs) :ptr(nullptr) 
		{
			tinySTL::swap(ptr, rhs.ptr);
		}
		~unique_ptr()
		{
			auto& temp = get();
			if (temp)
			{
				get_deleter()(temp);
			}
		}
		pointer get() const
		{
			return ptr;
		}
		const Deleter& get_deleter() const noexcept
		{
			return deleter;
		}
		Deleter& get_deleter() noexcept
		{
			return deleter;
		}
		explicit operator bool() const noexcept
		{
			return ptr != nullptr;
		}
		pointer release()
		{
			pointer temp = nullptr;
			tinySTL::swap(temp, ptr);
			return temp;
		}
		void reset(pointer parameter_ptr = pointer())
		{
			auto& old_ptr = ptr;
			ptr = parameter_ptr;
			if (old_ptr != nullptr)
				get_deleter()(old_ptr);
		}
		void reset(std::nullptr_t p = nullptr)
		{
			reset(pointer());
		}
		pointer operator->() const noexcept
		{
			return get();
		}
		element_type& operator *() 
		{
			return *ptr;
		}
	};
}


#endif // ! TINYSTL_SMART_POINTER_H
#ifndef TINYSTL_PAIR_H
#define TINYSTL_PAIR_H

#include <cstddef> //for size_t

namespace tinySTL
{
	template<class T1,class T2>
	struct pair
	{
	public:
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;
	public:
		pair() : first(T1()), second(T2()) {}
		pair(const T1& t1, const T2& t2) : first(t1), second(t2) {}
		template <class U1, class U2>
		pair(const pair<U1, U2>& temp) : first(temp.first), second(temp.second) {}
	public:
		void swap(pair& p1, pair& p2)
		{
			first_type t1 = p1.first;
			first_type t2 = p1.second;
			p1.first = p2.first;
			p1.second = p2.second;
			p2.first = t1;
			p2.second = t2;
		}

		pair& operator=(const pair& temp)
		{
			pair t(temp);
			swap(t, *this);
			return *this;
		}
		
	};
	//add get<> function in my own way
	//maybe it is different from the std
	//additionally, rvalue isn't implemented now.
	
	template <size_t s, class T1, class T2>
	struct help_pair{};
	
	template <class T1, class T2>
	struct help_pair<0, T1, T2>
	{
		typedef T1 value_type;
	};
	
	template <class T1, class T2>
	struct help_pair<1, T1, T2>
	{
		typedef T2 value_type;
	};
	
	template <size_t s>
	struct get_pair{};
	
	template <>
	struct get_pair<0>
	{
		template <class T1, class T2>
		static T1& get_value(pair<T1, T2>& p)
		{
			return p.first;
		}
		
		template <class T1, class T2>
		static const T1& get_value(const pair<T1, T2>& p)
		{
			return p.first;
		}
	};
	
	template <>
	struct get_pair<1>
	{
		template <class T1, class T2>
		static T2& get_value(pair<T1, T2>& p)
		{
			return p.second;
		}
		
		template <class T1, class T2>
		static const T2& get_value(const pair<T1, T2>& p)
		{
			return p.second;
		}
	};
	
	
	template <size_t s, class T1, class T2>
	const typename help_pair<s, T1, T2>::value_type&
		get(const pair<T1, T2>& p)
	{
		return get_pair<s>::get_value(p);
	}
	
	template <size_t s, class T1, class T2>
	typename  help_pair<s, T1, T2>::value_type&
		get( pair<T1, T2>& p)
	{
		return get_pair<s>::get_value(p);
	}
	
	template <class T1, class T2>
	inline bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	inline bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	inline bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return lhs.first < rhs.first || ((lhs.first == rhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	inline bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	inline bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	inline bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	inline pair<T1, T2> make_pair(const T1& lhs, const T2& rhs)
	{
		return pair<T1, T2>(lhs, rhs);
	}

	template <class T1, class T2>
	inline void swap(pair<T1, T2>& lhs, pair<T1, T2>& rhs)
	{
		lhs.swap(rhs);
	}


}

#endif // !TINYSTL_PAIR_H
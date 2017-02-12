#ifndef TINYSTL_PAIR_H
#define TINYSTL_PAIR_H

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
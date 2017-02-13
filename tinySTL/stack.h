#ifndef TINYSTL_STACK_H
#define TINYSTL_STACK_H

namespace tinySTL
{
	template<class T, class Container = tinySTL::deque<T>> 
	class stack
	{
	public:
		typedef Container						container_type;
		typedef typename Container::value_type  value_type;
		typedef typename Container::size_type	size_type;
		typedef typename Container::reference	reference;
		typedef typename Container::const_reference	const_reference;
	protected:
		container_type con;
	public:
		explicit stack(const Container& cont = Container())
			: con(cont) {}
	public:
		stack operator=(const stack& other)
		{
			con.operator=(other.con);
		}
		reference top()
		{
			return con.back();
		}
		const_reference top() const
		{
			return con.back();
		}
		size_type capacity() const
		{
			return con.capacity();
		}
		bool empty()_const
		{
			return con.empty();
		}
		size_type size() const
		{
			return con.size();
		}
		void push(const value_type& value)
		{
			con.push_back(value);
		}
		void pop()
		{
			con.pop_back();
		}

	private:
		template <class T, class Container>
		inline bool operator==(const stack<T, Container>&, const stack<T, Container>&);
		template <class T, class Container>
		inline bool operator!=(const stack<T, Container>&, const stack<T, Container>&);
		template <class T, class Container>
		inline bool operator<(const stack<T, Container>&, const stack<T, Container>&);
		template <class T, class Container>
		inline bool operator<=(const stack<T, Container>&, const stack<T, Container>&);
		template <class T, class Container>
		inline bool operator>(const stack<T, Container>&, const stack<T, Container>&);
		template <class T, class Container>
		inline bool operator>=(const stack<T, Container>&, const stack<T, Container>&);
	};
}

#endif // !TINYSTL_STACK_H
 
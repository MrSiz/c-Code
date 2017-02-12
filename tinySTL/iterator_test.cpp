//#include "iterator"
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <iterator>
//int main()
//{
//	std::vector<int> temp_vector{ 1, 2, 3 };
//
//	std::vector<int> v;
//	std::back_insert_iterator < std::vector<int>> zz(v);
//	//std::back_insert_iterator < std::vector<int>> sss;
//	*zz = 2;
//	zz = 3;
//	for (auto & val : v)
//	{
//		std::cout << val << std::endl;
//	}
//	system("pause");
//	//std::copy(temp_vector.begin(), temp_vector.end(), tinySTL::back_insert_iterator < std::vector<int>>(v));
//	//for (auto &val : v)
//	//{
//	//	std::cout << val << '\n';
//	//}
//	
//	return 0;
//}

//#include "type_traits"
//#include <iostream>
//int main()
//{
//	std::cout << tinySTL::true_type::value << std::endl;
//	system("pause");
//	return 0;
//}

#include "initializer_list.h"
#include <iostream>

//int main()
//{
//	tinySTL::initializer_list<int> temp{ 1,2,3 };
//
//	system("pause");
//}

#include "vector"

int main()
{
	tinySTL::vector<int> v;
}
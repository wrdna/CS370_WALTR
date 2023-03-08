#include <array>
#include <vector>
#include <initializer_list>
#include <iostream>
#include "../waltr.hpp"

int main(void) 
{
    
	std::array<int, 1000000000> arr_stl;
	int arr_c[1000000000];
	std::vector<int> vec;

	for (int i = 0; i < 1000000000; i++)
	{

		vec.push_back(i);
		arr_c[i] = i;
		arr_stl[i] = i;

	}

	Waltr stlArray = Waltr(arr_stl);
	std::cout << std::endl;
	std::cout << std::endl;
	Waltr cArray = Waltr(arr_c, 1000000000);
	std::cout << std::endl;
	std::cout << std::endl;
	Waltr newVec = Waltr(vec);
	std::cout << std::endl;

}
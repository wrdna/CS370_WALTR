#include <array>
#include <vector>
#include <initializer_list>
#include <iostream>
#include "../drawStructure.hpp"

int main(void) 
{
    
	std::array<int, 10> arr_stl;
	int arr_c[10];
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{

		vec.push_back('c');
		arr_c[i] = ('c');
		arr_stl[i] = ('c');

	}

	DrawStructure stlArray = DrawStructure(arr_stl);
	std::cout << std::endl;
	std::cout << std::endl;
	DrawStructure cArray = DrawStructure(arr_c, 10);
	std::cout << std::endl;
	std::cout << std::endl;
	DrawStructure newVec = DrawStructure(vec);
	std::cout << std::endl;
}

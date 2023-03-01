#include <array>
#include <vector>
#include <initializer_list>
#include "drawStructure.hpp"

int main(void) 
{
    
	std::array<int , 100> arr_stl;
	int arr_c[100];
	std::vector<int> vec;

	for (int i = 0; i < 100; i++)
	{

		vec.push_back(i);
		arr_c[i] = i;
		arr_stl[i] = i;

	}

	DrawStructure stlArray = DrawStructure(arr_stl);
	DrawStructure cArray = DrawStructure(arr_stl);
	DrawStructure newVec = DrawStructure(vec);

}
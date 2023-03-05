#include <array>
#include <vector>
#include <iostream>
#include "drawStructure.hpp"

int main(void) {
	std::array<int,5> arr_stl={0,1,2,3,4};
	int arr_c[5] = {0,1,2,3,4};
	std::vector<int> vec = {5,6,7,8,9};
	int matrix_c[3][5] = {{3,1,2,3,4}
						 ,{5,6,7,8,9}
						 ,{10,11,12,13,14}};
	
	DrawStructure drawStructure = DrawStructure(matrix_c,3,5);
	// drawStructure(arr_c,5);
	// drawStructure(vec);
}

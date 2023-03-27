#include <array>
#include <vector>
#include <iostream>
#include "waltr.hpp"

int main(void) {
	std::array<int,5> arr_stl={0,1,2,3,4};
	int arr_c[5] = {0223,133,233,311,42};
	std::vector<int> vec = {0,0,0,0,0};
	
	Waltr myVector = Waltr(vec);

	vec = {1,0,0,0,0};
	vec = {0,1,0,0,0};
	vec = {0,0,1,0,0};
	vec = {0,0,0,1,0};
	vec = {0,0,0,0,1};
	// drawStructure(arr_c,5);
	// drawStructure(vec);
}
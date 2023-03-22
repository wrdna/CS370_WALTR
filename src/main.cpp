#include <array>
#include <vector>
#include <iostream>
#include "waltrDrawStructure.hpp"

int main(void) {
	std::array<int,5> arr_stl={0,1,2,3,4};
	int arr_c[5] = {0,1,2,3,4};
	std::vector<int> vec = {5,6,7,8,9,3,3,4,3};
	std::queue<int> queue;
	

	for(int i =0;i<vec.size();i++) {
		vec[i] = i;
	}

	Waltr waltr = Waltr(vec);
	// drawStructure(arr_c,5);
	// drawStructure(vec);
}

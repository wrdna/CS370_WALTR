#include <array>
#include <vector>
#include <iostream>
#include "waltrDrawStructure.hpp"

int main(void) {
	std::array<int,5> arr_stl={0,1,2,3,4};
	int arr_c[5] = {0,1,2,3,4};
	std::vector<int> vec = {0,0,0,0,0};
	
	Waltr waltr = Waltr(vec);

	for(int i =0;i<vec.size();i++) {
		vec[i] = i+1;
		waltr.logVector(vec);
	}

	// drawStructure(arr_c,5);
	// drawStructure(vec);
}

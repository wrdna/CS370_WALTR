#include <array>
#include <vector>
#include <iostream>
#include "waltrDrawStructure.hpp"

int main(void) {
	std::array<int,5> arr_stl={0,1,2,3,4};
	int arr_c[5] = {0,1,2,3,4};
	std::stack<int> stack;
	Waltr waltr = Waltr(stack);
	for(int i =0;i<5;i++) {
		stack.push(i);
		waltr.logStack(stack);
	}

	// drawStructure(arr_c,5);
	// drawStructure(vec);
}

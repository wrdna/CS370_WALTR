#include <array>
#include <vector>
#include <iostream>
#include "waltr.hpp"

int main(void) {
	std::array<int,5> arr_stl={0,1,2,3,4};
	int arr_c[5] = {0,1,2,3,4};
	std::vector<int> vec = {5,6,7,8,9,209,123,1313,1,3,13,12,3,5,5,32,4,324};
	std::queue<int> queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	
	Waltr waltr = Waltr(vec);
	// drawStructure(arr_c,5);
	// drawStructure(vec);
}

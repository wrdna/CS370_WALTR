#include <array>
#include <vector>
#include <iostream>
#include "waltr.hpp"

int main(void) {
	std::array<int,5> arr_stl={0,1,2,3,4};
	int arr_c[5] = {0223,133,233,311,42};
	std::vector<int> vec = {5,6,3,1,1,3,3};
	std::queue<int> queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	
	Waltr waltr = Waltr(arr_c, 5);
	// drawStructure(arr_c,5);
	// drawStructure(vec);
}
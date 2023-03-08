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
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(10);
	queue.push(20);
	queue.push(30);

	 std::stack<int> stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(10);
	stack.push(20);
	
	
	
	Waltr waltrV = Waltr(vec);
	Waltr waltrS = Waltr(stack);
	Waltr waltrQ = Waltr(queue);
	// drawStructure(arr_c,5);
	// drawStructure(vec);
}
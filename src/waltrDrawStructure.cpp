#include <stack>
#include <vector>
#include <array>
#include <queue>

#include <iostream>

#include "waltrDrawStructure.hpp"

//Remove when amalagated
#include "drawVector.cpp"
#include "drawStack.cpp"
#include "drawQueue.cpp"

/*
The user will create an object with a constructor overload which will visualize the
passed data structure.
INPUT: A data stucture, currently STL arrays, C-Style arrays, Vectors, Stacks, and Queues.
*/



/*
C-Style array constructor overload
INPUT: Pointer to C-Style Array, Size of array
*/
Waltr::Waltr(const int* c_array, int c_size) {
	toVector(c_array, c_array + c_size);
	drawVector(memory_vector);
}

/*
Vector constructor overload
INPUT: Pointer to vector
*/
Waltr::Waltr(const std::vector<int> vector) {
    toVector(vector.data(), vector.data() + vector.size());
	drawVector(memory_vector);
}


/*
Stack constructor overload
INPUT: Pointer to stack

Currently does not reference initial memory from the passed structure. (TODO)
*/
Waltr::Waltr(const std::stack<int> stack) {
	drawStack(stack);
}

/*
Queue constructor overload
INPUT: Pointer to queue

Currently does not reference initial memory from the passed structure. (TODO)
*/
Waltr::Waltr(const std::queue<int> queue) {
	//drawQueue(queue);
	printQueue(queue);
}

/*
Creates a shallow copy of the inputted structure, and stored
in the created DataStructure object.
INPUT: Pointer to beginning of array, pointer to end of array
*/
void Waltr::toVector(const int* begin, const int* end) {
	for(int*i = (int*)begin; i < end; i++) {
		memory_vector.push_back(i);
	}
}


/*
Prints vector, used for testing
*/
void Waltr::printVector(std::vector<int *> vector) {
	for(auto &x: vector) {
		std::cout<<*x<<" ";
	}
}

/*
Prints stack, used for testing
*/
void Waltr::printStack(std::stack<int> stack) {
	while(!stack.empty()) {
		std::cout<<stack.top()<<" ";
		stack.pop();
	}
}

/*
Prints queue used for testing
*/
void Waltr::printQueue(std::queue<int> queue) {
	while(!queue.empty()) {
		std::cout<<queue.front()<<" ";
		queue.pop();
	}
}
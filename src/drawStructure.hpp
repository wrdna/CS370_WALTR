#include <vector>
#include <array>
#include <stack>
#include <queue>

#ifndef DRAW_STRUCTURE
#define DRAW_STRUCTURE

class DrawStructure {
	private:
		std::vector<int *> memory_vector;
		//std::stack<int *> memory_stack;
		//std::queue<int *> memory_queue;
	public:

		//Overload for C-Style arrays
		DrawStructure(const int* c_array, int c_size);

		//Overload for STL arrays
		//Implementation in header file because of template
		template<std::size_t SIZE>
		DrawStructure(const std::array<int, SIZE> &stl_array) {
			toVector(stl_array.begin(), stl_array.end());
			printVector(memory_vector);
		}

		//Overload for vectors
		DrawStructure(const std::vector<int> vector);

		//Overload for stacks
		DrawStructure(const std::stack<int> stack);

		//Overload for queues
		DrawStructure(const std::queue<int> queue);

		//Convert inputted structure to a vector
		void toVector(const int* begin, const int* end);
		
		//printVector used for testing
		void printVector(std::vector<int *>vector);

		//printStack used for testing
		void printStack(std::stack<int> stack);

		//printQueue used for testing
		void printQueue(std::queue<int> queue);
};
#endif // DRAW_STRUCTURE
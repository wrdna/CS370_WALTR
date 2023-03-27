#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <typeinfo>

#ifndef WALTR_DRAW_STRUCTURE
#define WALTR_DRAW_STRUCTURE

/*TODO:
	Storing screens into an array, to be printed/cycled through 
	Up/down arrow keys to move between structure versions saved by log() 
*/
class Waltr {
	private:
		std::vector<int> memory_vector;
		std::vector<std::vector<int>> vector_log;
		std::vector<std::stack<int>> stack_log;
		std::vector<std::queue<int>> queue_log;
		//std::stack<int *> memory_stack;
		//std::queue<int *> memory_queue;
	public:
		//Overload for C-Style arrays
		Waltr(const int* c_array, int c_size);

		//Overload for STL arrays
		//Implementation in header file because of template
		template<std::size_t SIZE>
		Waltr(const std::array<int, SIZE> &stl_array) {
			logVector(toVector(stl_array.begin(), stl_array.end()));
		}

		//Overload for vectors
		Waltr(const std::vector<int> vector);

		//Overload for stacks
		Waltr(const std::stack<int> stack);

		//Overload for queues
		Waltr(const std::queue<int> queue);

		//Log overload for vector
		void logVector(std::vector<int> vector);
		
		//Log overload for stack
		void logStack(std::stack<int> stack);

		//Log overload for queue
		void logQueue(std::queue<int> queue);

		//Convert inputted structure to a vector
		std::vector<int> toVector(const int* begin, const int* end);

		//printVector used for testing
		void printVector(std::vector<int>vector);
		//printStack used for testing
		void printStack(std::stack<int> stack);
		//printQueue used for testing
		void printQueue(std::queue<int> queue);

		//prints vector log for testing
		void printVectorLog();
		
		//prints stack log for testing
		void printStackLog();
		
		//prints queue log for testing
		void printQueueLog();
		
		void drawVector(std::vector<int> myVector);

		void drawQueue(std::queue<int> myQueue);

		void drawStack(std::stack<int> myStack);

		~Waltr() {
			if (!vector_log.empty()) {
				printVectorLog();
			} else if (!stack_log.empty()) {
				printStackLog();
			} else if (!stack_log.empty()) {
				printVectorLog();
			}
		}

};
#endif // WALTR_DRAW_STRUCTURE
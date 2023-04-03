#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <typeinfo>
#include "tigr.h"

#ifndef WALTR_DRAW_STRUCTURE
#define WALTR_DRAW_STRUCTURE

/*TODO:
	Storing screens into an array, to be printed/cycled through 
	Up/down arrow keys to move between structure versions saved by log() 
*/
class Waltr {
	private:
		//There is a better way to do this (Likely templates)
		std::vector<std::vector<int>> vector_log;
		std::vector<std::stack<int>> stack_log;
		std::vector<std::queue<int>> queue_log;
		Tigr* current_screen;
		Tigr* temp_screen;
		std::vector<Tigr*> screen_list;
		int ifprinted = false;
		int buttons;
		int valuesLength;
		int mouseX = 0;
		int mouseY = 0;
		int screenX = 320;
    	int screenY = 240;
		int boxWidth;
		int barHeight;
		int bufferX;
		int bufferY;
		std::vector<int> coords;
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
		
		Tigr* drawVector(std::vector<int> myVector);

		void drawQueue(std::queue<int> myQueue);

		void drawStack(std::stack<int> myStack);

		void openVectorWindow();

		//DESTRUCTOR!!!
		~Waltr();

};
#endif // WALTR_DRAW_STRUCTURE
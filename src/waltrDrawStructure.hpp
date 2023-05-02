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
		std::vector<std::vector<int> > vector_log;
		std::vector<std::stack<int> > stack_log;
		std::vector<std::queue<int> > queue_log;
		Tigr* current_screen;
		int ifprinted = false;
		int buttons;
		int size;
		int mouseX = 0;
		int mouseY = 0;
		int screenX = 320;
    	int screenY = 240;
		int boxSize;
		int barHeight;
		int bufferX;
		int bufferY;
		int vector_index;
		int queue_index;
		int stack_index;
		int item_index;
		int page_index;
		bool help_screen_open;
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
		
		//prints inputted vector to screen
		void drawVector();
		
		void drawVectorMouse();
		
		void drawQueue();
		
		void drawStack();

		void openVectorWindow();
		
		void openQueueWindow();

		void openStackWindow();
		
		//help screens
		void drawVHelp();
	
		void drawQSHelp();



		//DESTRUCTOR!!!
		~Waltr();

};
#endif // WALTR_DRAW_STRUCTURE
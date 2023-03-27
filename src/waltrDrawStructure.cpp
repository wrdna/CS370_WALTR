#include <stack>
#include <vector>
#include <array>
#include <queue>

#include <iostream>
#include "tigr.h"
#include "waltrDrawStructure.hpp"

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
	logVector(toVector(c_array, c_array + c_size));
}

/*
Vector constructor overload
INPUT: Pointer to vector
*/
Waltr::Waltr(const std::vector<int> vector) {
    logVector(vector);
}

/*
Stack constructor overload
INPUT: Pointer to stack
*/
Waltr::Waltr(const std::stack<int> stack) {
	logStack(stack);
}

/*
Queue constructor overload
INPUT: Pointer to queue
*/
Waltr::Waltr(const std::queue<int> queue) {
	logQueue(queue);
}

/*
Stores a copy of the vectors current contents
*/
void Waltr::logVector(std::vector<int> vector) {
    vector_log.push_back(vector);
}

/*
Stores a copy of the stacks current contents
*/
void Waltr::logStack(std::stack<int> stack) {
    stack_log.push_back(stack);
}

/*
Stores a copy of the queues current contents
*/
void Waltr::logQueue(std::queue<int> queue) {
    queue_log.push_back(queue);
}

/*
Converts array to vector.
*/
std::vector<int> Waltr::toVector(const int* begin, const int* end) {
	std::vector<int> vector;

    for(int*i = (int*)begin; i < end; i++) {
		vector.push_back(*i);
	}

    return vector;
}

/*
Prints vector, used for testing
*/
void Waltr::printVector(std::vector<int> vector) {
	for(auto x: vector) {
		std::cout<<x<<" ";
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

/*
Prints vector log, used for testing
*/
void Waltr::printVectorLog() {
	for(auto vec: vector_log) {
        for(auto x: vec) {
		    std::cout<<x<<" ";
	    }
        std::cout<<std::endl;
	}
}

/*
Prints vector log, used for testing
*/
void Waltr::printStackLog() {
	for(auto stack: stack_log) {
        std::cout<<stack.top()<<" ";
        stack.pop();
    }
    std::cout<<std::endl;
}

/*
Prints vector log, used for testing
*/
void Waltr::printQueueLog() {
	for(auto queue: queue_log) {
        std::cout<<queue.front()<<" ";
        queue.pop();
	}
        std::cout<<std::endl;
}

void Waltr::drawVector(std::vector<int> myVector) {
    //create dimensions for a screen in tigr and include buffer for the edges
    int screenX = 320;
    int screenY = 240;
    int bufferX = 10;
    int bufferY = 100;

    //get the amount of elements in the vector
    int valuesLength = myVector.size();

    //scale the vector so it fits on screen
    int boxWidth = (screenX/myVector.size()) - (bufferX*2);  

    bool ifprinted = false;


    //create screen
    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your vector!", 0);
    tigrClear(screen, tigrRGB(0,0,0));
    tigrPrint(screen, tfont, bufferX, bufferY - 30, tigrRGB(255,0,0), "Index: ");
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)) {
    
        if (!ifprinted) {
            for(int i=0; i < valuesLength; i++) {
                
                tigrRect(screen, bufferX, bufferY, boxWidth, boxWidth, tigrRGB(0,0,0));
                tigrFillRect(screen, bufferX, bufferY, boxWidth, boxWidth, tigrRGB(38, 252, 66));
                tigrPrint(screen, tfont, (bufferX+(boxWidth/2)), (bufferY + (boxWidth/2)), tigrRGB(102,178,200), "%d", myVector[i]);
                tigrPrint(screen, tfont, (bufferX+(boxWidth/2)), (bufferY-(boxWidth/2)), tigrRGB(255, 0, 0), "%d", i);
                bufferX = bufferX + boxWidth + 2;
                
                //myVector.pop_back();
                
                for(int j = -1; j < i; j++) {
                    for(int g = -1; g < j; g++) {
                        tigrUpdate(screen);}
                }
            }
            ifprinted = true;
        }
        tigrUpdate(screen);
    }
    tigrFree(screen);
}

void Waltr::drawQueue(std::queue<int> myQueue) {
    int screenX = 320;
    int screenY = 240;
    int bufferX = 10;
    int bufferY = 30;

    int size = myQueue.size();
    
    std::queue<int> set = myQueue;

    int barHeight = (screenY/size) - 10;
    
    bool ifprinted = false;

    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Queue!", 0);
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)) {
        
        if (!ifprinted) {
            tigrClear(screen, tigrRGB(0,0,0));
            //tigrPrint(screen, tfont, 160, 15, tigrRGB(255,0,0), "Index: ");
            tigrPrint(screen, tfont, 200, 150, tigrRGB(38, 252, 66), "Front of Queue: %d", myQueue.front());

            bool test = false;

            for(int i=0; i<size; i++) {
                tigrRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(0,0,0));
                tigrFillRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(38, 252, 66));
                tigrPrint(screen, tfont, ((bufferX+75)), (bufferY-barHeight/50), tigrRGB(102,178,200), "%d", set.front());
                //tigrPrint(screen, tfont, (bufferX+160), (bufferY-barHeight/50), tigrRGB(255,0,0), "%d", i);
                if(set.size() == 1) {
                    tigrPrint(screen, tfont, 200, 200, tigrRGB(38, 252, 66), "End of Queue: %d", set.front());
                }
                set.pop();
                bufferY += barHeight;
                for(int j = -1; j < i; j++) {
                    for(int g = -1; g < j; g++) {
                        tigrUpdate(screen);
                    }
                }
            }
            ifprinted = true;
        }
        tigrUpdate(screen);
    }
    tigrFree(screen); 
}

void Waltr::drawStack(std::stack<int> myStack)
{
    
    int screenX = 320;
    int screenY = 240;
    int bufferX = 10;
    int bufferY = 30;
    
    std::stack<int> set = myStack;
    
    int size = myStack.size();

    int barHeight = (screenY/size) - 8;
    
    bool ifprinted = false;
    
    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Stack!", 0);
    
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)){ 
        if (!ifprinted) {
            tigrClear(screen, tigrRGB(0,0,0));
            //tigrPrint(screen, tfont, 160, 15, tigrRGB(255,0,0), "Index: ");
            tigrPrint(screen, tfont, 180, 180, tigrRGB(38,252,66), "Top of stack: %d", myStack.top());
            
            for (int i = 0; i < size; i++) {
                tigrRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(0,0,0));
                tigrFillRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(38, 252, 66));
                tigrPrint(screen, tfont, ((bufferX+75)), (bufferY-barHeight/50), tigrRGB(102,178,200), "%d", set.top());
                //tigrPrint(screen, tfont, (bufferX+160), (bufferY-barHeight/50), tigrRGB(255,0,0), "%d", i);
                if (set.size() == 1){
                    tigrPrint(screen, tfont, 180, 200, tigrRGB(38, 252, 66), "Bottom of stack: %d", set.top());
                }
                set.pop();
                bufferY += barHeight; 
                for(int j = -1; j < i; j++) {
                    for(int g = -1; g < j; g++) {
                        tigrUpdate(screen);
                    }
                }
            }
            ifprinted = true;   
        }
        tigrUpdate(screen);
    }
    tigrFree(screen);
}

Waltr::~Waltr() {
    if (!vector_log.empty()) {
        printVectorLog();
    } else if (!stack_log.empty()) {
        printStackLog();
    } else if (!stack_log.empty()) {
        printVectorLog();
    }
}

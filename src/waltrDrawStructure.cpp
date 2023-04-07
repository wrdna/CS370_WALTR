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

void Waltr::drawVector(std::vector<int> myVector) {
    bufferX = 90;
    bufferY = 210;

    //get the amount of elements in the vector
    size = myVector.size();
    coords.resize(size);

    //scale the vector so it fits on screen
    boxSize = 12;

    tigrPrint(current_screen, tfont, 30, 30, tigrRGB(50,50,200), "Current instance: %d / %d", vector_index, vector_log.size()-1);
    for(int i=0; i < size; i++) {
        tigrRect(current_screen, bufferX, bufferY, boxSize, boxSize, tigrRGB(0,0,0));
        tigrFillRect(current_screen, bufferX, bufferY, boxSize, boxSize, tigrRGB(0, 50, 0));
        tigrPrint(current_screen, tfont, bufferX + 3, bufferY - 15, tigrRGB(60, 0, 0), "%d", i);
        coords[item_index] = bufferX;
        bufferX = bufferX + boxSize + 2;
    }
    tigrRect(current_screen, screenX/2, screenY/2 - 30, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrFillRect(current_screen, screenX/2, screenY/2 - 30, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrPrint(current_screen, tfont, screenX/2 + 30, screenY/2 - 30, tigrRGB(255,0,0), "Index: %d", item_index);
    
    tigrRect(current_screen, screenX/2, screenY/2 - 10, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrFillRect(current_screen, screenX/2, screenY/2 - 10, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrPrint(current_screen, tfont, screenX/2 + 30, screenY/2 - 10, tigrRGB(255,0,0), "Type: %s", typeid(item_index).name());
    
    tigrRect(current_screen, screenX/2 - 40, screenY/2 - 40, 50, 50, tigrRGB(0,0,0));
    tigrFillRect(current_screen, screenX/2 - 40, screenY/2 - 40, 50, 50, tigrRGB(38, 252, 66));
    tigrPrint(current_screen, tfont, screenX/2 - 30, screenY/2 - 30, tigrRGB(255,0,0), "%d", vector_log[vector_index][item_index]);

    tigrFillRect(current_screen, coords[item_index]-2, bufferY-2, boxSize+4, boxSize+4, tigrRGB(0, 200, 0));
    tigrPrint(current_screen, tfont, coords[item_index]+3, bufferY - 15, tigrRGB(255, 0, 0), "%d", item_index);
}

void Waltr::drawVectorMouse(std::vector<int> myVector) {
    bufferX = 90;
    bufferY = 210; // create dimensions for a screen in tigr and include buffer for the edges

    size = myVector.size(); // get the amount of elements in the vector
    coords.resize(size);
    boxSize = 12;

    tigrPrint(current_screen, tfont, 30, 30, tigrRGB(50,50,200), "Current instance: %d / %d", vector_index, vector_log.size()-1);

    for(int i=0; i < size; i++) {
        tigrRect(current_screen, bufferX, bufferY, boxSize, boxSize, tigrRGB(0,0,0));
        tigrFillRect(current_screen, bufferX, bufferY, boxSize, boxSize, tigrRGB(38, 252, 66)); // prints boxes
        tigrPrint(current_screen, tfont, bufferX + 3, bufferY - 15, tigrRGB(255, 0, 0), "%d", i); // prints indices
        coords[i] = bufferX;
        bufferX = bufferX + boxSize + 2;
    }

    // note: all prints have a black box behind them so that when they print on top of each other, it doesn't look bad

    tigrRect(current_screen, screenX/2, screenY/2 - 40, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrFillRect(current_screen, screenX/2, screenY/2 - 40, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrPrint(current_screen, tfont, screenX/2 + 10, screenY/2 - 40, tigrRGB(255,0,0), "Index: %d", item_index); // prints index
    
    tigrRect(current_screen, screenX/2, screenY/2, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrFillRect(current_screen, screenX/2, screenY/2, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrPrint(current_screen, tfont, screenX/2 + 10, screenY/2 - 20, tigrRGB(255,0,0), "Type: %s", typeid(item_index).name()); // prints data type
    
    tigrRect(current_screen, screenX/2 - 50, screenY/2 - 40, 50, 50, tigrRGB(0,0,0));
    tigrFillRect(current_screen, screenX/2 - 50, screenY/2 - 40, 50, 50, tigrRGB(38, 252, 66));
    tigrPrint(current_screen, tfont, screenX/2 - 40, screenY/2 - 30, tigrRGB(255,0,0), "%d", vector_log[vector_index][item_index]); // prints green box with data inside
    
    tigrRect(current_screen, 0, screenY/2 + 105, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrFillRect(current_screen, 0, screenY/2 + 105, screenX, boxSize + 10, tigrRGB(0,0,0));
    tigrPrint(current_screen, tfont, coords[item_index] + 3, screenY/2 + 105, tigrRGB(255,0,0), "^"); // prints an arrow corresponding the box the user is on
    
    tigrFillRect(current_screen, coords[item_index], bufferY, boxSize, boxSize, tigrRGB(0,0,255)); // highlights box blue
}   

void Waltr::openVectorWindow() {
    //Order of vectors displayed may need to be flipped
    //tigrClear(screen, tigrRGB(0,0,0));
    
    current_screen = tigrWindow(screenX, screenY, (char*)"Your Vector!", 0);
    
    //Used to iterate over vector log
    vector_index = 0;

    //Used to iterate through current vector
    item_index = 0;

    //prints initial vector and instance number
    drawVector(vector_log[0]);
    tigrUpdate(current_screen);
    while (!tigrClosed(current_screen) && !tigrKeyDown(current_screen, TK_ESCAPE)) {
        if (tigrKeyDown(current_screen, TK_UP)  && vector_index < vector_log.size()-1) {
            vector_index++;
            tigrClear(current_screen,tigrRGB(0,0,0));
            drawVector(vector_log[vector_index]);
        }
        if (tigrKeyDown(current_screen, TK_DOWN) && vector_index > 0) {
            vector_index--;
            tigrClear(current_screen,tigrRGB(0,0,0));
            drawVector(vector_log[vector_index]);
        }

        if (tigrKeyDown(current_screen, TK_RIGHT) && item_index < vector_log[vector_index].size()-1) {
            item_index++;
            tigrClear(current_screen,tigrRGB(0,0,0));
            drawVector(vector_log[vector_index]);
        }

        if (tigrKeyDown(current_screen, TK_LEFT) && item_index > 0) {
            item_index--;
            tigrClear(current_screen,tigrRGB(0,0,0));
            drawVector(vector_log[vector_index]);
        }
        tigrUpdate(current_screen);
    }
    tigrFree(current_screen);
}

void Waltr::openVectorWindowMouse() {
    //Order of vectors displayed may need to be flipped
    //tigrClear(screen, tigrRGB(0,0,0));
    
    current_screen = tigrWindow(screenX, screenY, (char*)"Your Vector!", 0);
    
    //Used to iterate over vector log
    vector_index = 0;

    //Used to iterate through current vector
    item_index = 0;

    //prints initial vector and instance number
    drawVectorMouse(vector_log[0]);
    tigrUpdate(current_screen);
    while (!tigrClosed(current_screen) && !tigrKeyDown(current_screen, TK_ESCAPE)) {
        if (tigrKeyDown(current_screen, TK_UP)  && vector_index < vector_log.size()-1) {
            vector_index++;
            tigrClear(current_screen,tigrRGB(0,0,0));
            drawVectorMouse(vector_log[vector_index]);
        }
        if (tigrKeyDown(current_screen, TK_DOWN) && vector_index > 0) {
            vector_index--;
            tigrClear(current_screen,tigrRGB(0,0,0));
            drawVectorMouse(vector_log[vector_index]);
        }

        tigrMouse(current_screen, &mouseX, &mouseY, &buttons); // get mouse coordinates
        for (int i = 0; i < size; i++) { // test if mouse coordinates are within array boxes
            if(mouseX > coords[i] && mouseX < (coords[i]+ boxSize) && mouseY > bufferY && mouseY < (bufferY+boxSize)) {
                tigrFillRect(current_screen, coords[i], bufferY, boxSize, boxSize, tigrRGB(0,0,255)); // highlights box blue
                if(buttons & 1) { // if mouse button clicked
                    item_index = i;
                    tigrClear(current_screen,tigrRGB(0,0,0));
                    drawVectorMouse(vector_log[vector_index]);
                }
            } else {
                if (i != item_index) {
                    tigrFillRect(current_screen, coords[i], bufferY, boxSize, boxSize, tigrRGB(38, 252, 66)); // changes box back to green
                }
            }
        }
        tigrUpdate(current_screen);
    }
    tigrFree(current_screen);
}



Waltr::~Waltr() {
    if (!vector_log.empty()) {
        //openVectorWindow(); 
        openVectorWindowMouse();   
    } else if (!stack_log.empty()) {
        //openStackWindow();
    } else if (!queue_log.empty()) {
        //openQueueWindow();
    }
}

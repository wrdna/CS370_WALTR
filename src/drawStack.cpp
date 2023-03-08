#include "tigr.h"
#include "drawStack.hpp"
#include <iostream>
#include <stack>

void drawStack(std::stack<int> myStack)
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

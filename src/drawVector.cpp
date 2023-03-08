#include "tigr.h"
#include "drawVector.hpp"
#include <iostream>
#include <vector>

void drawVector(std::vector<int*> myVector) {
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
                tigrPrint(screen, tfont, (bufferX+(boxWidth/2)), (bufferY + (boxWidth/2)), tigrRGB(102,178,200), "%d", *(myVector[i]));
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

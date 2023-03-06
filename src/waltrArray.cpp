#include "tigr.h"
#include <iostream>
#include <vector>

using namespace std;

void drawArray(vector<int*> myVector) {
   
    //create dimensions for a screen in tigr and include buffer for the edges
    int screenX = 320;
    int screenY = 240;
    int bufferX = 10;
    int bufferY = 100;

    //get the amount of elements in the array
    int valuesLength = myVector.size();

    //scale the array so it fits on screen
    int boxWidth =   (screenX/myVector.size()) - (bufferX*2);  

    bool ifprinted = false;


    //create screen
    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Array!", 0);
    tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)){
     
        if (!ifprinted)
        {
            for(int i=0; i < valuesLength; i++){
                
                tigrRect(screen, bufferX, bufferY, boxWidth, boxWidth, tigrRGB(0,0,0));
                tigrFillRect(screen, bufferX, bufferY, boxWidth, boxWidth, tigrRGB(250, 250, 0));
                tigrPrint(screen, tfont, (bufferX+(boxWidth/2)), (bufferY + (boxWidth/2)), tigrRGB(0,0,0), "%d", *(myVector[i]));
                tigrPrint(screen, tfont, (bufferX+(boxWidth/2)), (bufferY+boxWidth+5), tigrRGB(0, 100, 250), "%d", i);
                bufferX = bufferX + boxWidth + 2;
                
                //myVector.pop_back();
                
                for(int j = -1; j < i; j++)
                {
                    for(int g = -1; g < j; g++){
                        tigrUpdate(screen);}
                }
            }
            ifprinted = true;
        }
        tigrUpdate(screen);
    }
    tigrFree(screen);
}

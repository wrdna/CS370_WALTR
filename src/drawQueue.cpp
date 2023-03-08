#include "tigr.h"
#include "drawQueue.hpp"
#include <iostream>
#include <queue>
// int main()
// {  
//     queue<int> q;  
//     for (int i = 0; i < 10; i++)
//         q.push(i);  
//     drawQueue(q);  
// }

void drawQueue(std::queue<int> myQueue){
    int screenX = 320;
    int screenY = 240;
    int bufferX = 50;
    int bufferY = 20;

    int size = myQueue.size();
    
    std::queue<int> set = myQueue;

    int barHeight = (screenY/size) - 10;
    
    bool ifprinted = false;

    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Queue!", 0);
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)) {
        
        if (!ifprinted) {

            tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));

            tigrPrint(screen, tfont, 200, 150, tigrRGB(0,100,250), "Top of Queue: %d", myQueue.front());

            bool test = false;

            for(int i=0; i<size; i++) {
                tigrRect(screen, bufferX, bufferY, 100, barHeight, tigrRGB(0,0,0));
                tigrFillRect(screen, bufferX, bufferY, 100, barHeight, tigrRGB(250,250,0));
                tigrPrint(screen, tfont, 160, (bufferY-barHeight/50), tigrRGB(0,100,250), "%d", set.front());
                if(set.size() == 1) {
                    tigrPrint(screen, tfont, 200, 200, tigrRGB(0,100,250), "Bottom of Queue: %d", set.front());
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
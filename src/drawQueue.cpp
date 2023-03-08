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

void drawQueue(std::queue<int> myQueue) {
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
            tigrPrint(screen, tfont, 160, 15, tigrRGB(255,0,0), "Index: ");
            tigrPrint(screen, tfont, 200, 150, tigrRGB(38, 252, 66), "Front of Queue: %d", myQueue.front());

            bool test = false;

            for(int i=0; i<size; i++) {
                tigrRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(0,0,0));
                tigrFillRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(38, 252, 66));
                tigrPrint(screen, tfont, ((bufferX+75)), (bufferY-barHeight/50), tigrRGB(102,178,200), "%d", set.front());
                tigrPrint(screen, tfont, (bufferX+160), (bufferY-barHeight/50), tigrRGB(255,0,0), "%d", i);
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
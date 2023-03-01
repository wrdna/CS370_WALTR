#include "tigr.h"
#include <iostream>
#include <queue>

using namespace std;

void drawQueue(queue<int>);

int main(int argc, char* argv[]){

    queue<int> waltrQueue;
    for(int i=0; i<10; i++){
        waltrQueue.push(i);
    }
    drawQueue(waltrQueue);


    return 0;
}


void drawQueue(queue<int> myQueue){
    int screenX = 320;
    int screenY = 240;
    int bufferX = 50;
    int bufferY = 20;

    int size = myQueue.size();

    int barHeight = (screenY/size) - 10;

    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Queue!", 0);
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)){

        tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));

        tigrPrint(screen, tfont, 200, 150, tigrRGB(0,100,250), "Top of Queue: %d", myQueue.front());

        for(int i=0; i<size; i++){
            tigrRect(screen, bufferX, bufferY, 50, barHeight, tigrRGB(0,0,0));
            tigrFillRect(screen, bufferX, bufferY, 50, barHeight, tigrRGB(250,250,0));
            tigrPrint(screen, tfont, 160, (bufferY-barHeight/2), tigrRGB(0,100,250), "%d", myQueue.front());
            if(myQueue.size() == 1){
                tigrPrint(screen, tfont, 200, 200, tigrRGB(0,100,250), "Bottom of Queue: %d", myQueue.front());
            }
            myQueue.pop();
            bufferY += barHeight;
        }




        tigrUpdate(screen);
    }
    tigrFree(screen);

    
}
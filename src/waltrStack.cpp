#include "tigr.h"
#include <iostream>
#include <stack>

using namespace std;




void drawStack(stack<int>);

int main (int argc, char* argv[]){
    stack<int> waltrStack;
    for(int i=0; i<11; i++){
        waltrStack.push(i);
    }
    drawStack(waltrStack);

    return 0;

}

void drawStack(stack<int> myStack){

    int screenX = 320;
    int screenY = 240;
    int bufferX = 50;
    int bufferY = 20;

    int size = myStack.size();

    int barHeight = (screenY/size) - 10;

    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Stack!", 0);
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)){

        tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));

        tigrPrint(screen, tfont, 200, 150, tigrRGB(0,100,250), "Top of stack: %d", myStack.top());

        for(int i=0; i<size; i++){
            tigrRect(screen, bufferX, bufferY, 50, barHeight, tigrRGB(0,0,0));
            tigrFillRect(screen, bufferX, bufferY, 50, barHeight, tigrRGB(250,250,0));
            tigrPrint(screen, tfont, 160, (bufferY-barHeight/2), tigrRGB(0,100,250), "%d", myStack.top());
            if(myStack.size() == 1){
                tigrPrint(screen, tfont, 200, 200, tigrRGB(0,100,250), "Bottom of stack: %d", myStack.top());
            }
            myStack.pop();
            bufferY += barHeight;
        }




        tigrUpdate(screen);
    }
    tigrFree(screen);
    //while(!myStack.empty()){
      //  cout << myStack.top() << " ";
        //myStack.pop();
    }







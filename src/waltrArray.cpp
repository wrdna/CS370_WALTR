#include "tigr.h"
#include <iostream>
#include <vector>

using namespace std;

void drawArray(vector<int *> myVector);

// int main(int argc, char* argv[]){
// /*
//     vector<int *> n;

//     for(int i=0; i<10; i++){
//         n->push_back(i);
//     }

//     //int arraySize = n.size();
//     drawArray(n);


// */

//     return 0;


// }


void drawArray(vector<int*> myVector){

    //create dimensions for a screen in tigr and include buffer for the edges
    int screenX = 320;
    int screenY = 240;
    int bufferX = 5;
    int bufferY = 10;

    //vector<int>& vecRef = myVector;
    

    //get the amount of elements in the array
    int valuesLength = myVector.size();

    //scale the array so it fits on screen
    int barWidth = ((screenX/valuesLength)-(bufferX*2));


    //create screen
    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Array!", 0);
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE)){

        tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));

    //make bars from array values and print index number above the bar

        for(int i=0; i<=valuesLength; i++){
            //int vecElement = myVector.at(i);
            tigrRect(screen, bufferX, bufferY, barWidth, *(myVector[i]), tigrRGB(0,0,0));
            tigrFillRect(screen, bufferX, bufferY, barWidth, *(myVector[i]), tigrRGB(250, 250, 0));
            tigrPrint(screen, tfont, bufferX, (bufferY/2), tigrRGB(0, 100, 250), "%d", i);
            bufferX = bufferX + barWidth;
        }

        tigrUpdate(screen);
    }
    tigrFree(screen);
}
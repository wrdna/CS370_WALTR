#include "tigr.h"
#include <iostream>
#include <stack>

void drawStack(std::stack<int> myStack);

// int main()
// {
//     stack<int> s;
//     for (int i = 0; i < 10; i++)
//         s.push(i);
//     drawStack(s);
// }

void drawStack(std::stack<int> myStack)
{
    
    int screenX = 320;
    int screenY = 240;
    int bufferX = 10;
    int bufferY = 20;
    
    std::stack<int> set = myStack;
    
    int size = myStack.size();
    
    int barHeight = (screenY/size) - 10;
    
    bool ifprinted = false;
    
    Tigr* screen = tigrWindow(screenX, screenY, (char*)"Your Stack!", 0);
    
    while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
    {
        
        if (!ifprinted)
        {
            
            tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
            
            tigrPrint(screen, tfont, 200, 150, tigrRGB(0,100,250), "Top of stack: %d", myStack.top());
            
            for(int i = 0; i < size; i++)
            {
                    tigrRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(0,0,0));
                    tigrFillRect(screen, bufferX, bufferY, 150, barHeight, tigrRGB(250,250,0));
                    tigrPrint(screen, tfont, 150, (bufferY-barHeight/50), tigrRGB(0,100,250), "%d", set.top());
                    if(set.size() == 1)
                    {
                            tigrPrint(screen, tfont, 200, 200, tigrRGB(0,100,250), "Bottom of stack: %d", set.top());
                    }
                    
                    set.pop();
                    bufferY += barHeight;
                    
                    for(int j = -1; j < i; j++)
                    {
                        for(int g = -1; g < j; g++)
                        {
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

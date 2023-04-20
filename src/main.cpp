#include <array>
#include <vector>
#include <iostream>
#include "waltrDrawStructure.hpp"

int main(void) {
	 std::vector<int> vec = {23,0,20,57,0,0,9,15,3,0};
	 Waltr waltr = Waltr(vec);
	 for(int i =0;i<=9;i++) {
	 	//vec[i] = i;
		waltr.logVector(vec);
	 }
	// waltr.logVector(vec);
	// drawStructure(arr_c,5);
	// drawStructure(vec);

    std::stack<int> stack;
    std::queue<int> queue;
//Waltr waltr = Waltr(stack);
  //  for(int i =0;i<5;i++) {
    //    stack.push(i);
      //  waltr.logStack(stack);
   // }
}

#include <array>
#include <vector>
#include <iostream>
#include "waltr.hpp"

int main(void) {
	// std::vector<int> vec = {0,0,0,0,0};
	// Waltr waltr = Waltr(vec);
	// for(int i =0;i<5;i++) {
	// 	vec[i] = i;
	// }
	// waltr.logVector(vec);
	// drawStructure(arr_c,5);
	// drawStructure(vec);

    std::vector<int> q = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
    Waltr waltr = Waltr(q);
    for(int i=0;i<q.size();i++) {
		q[i] = i;
		
    }
	waltr.logVector(q);
	waltr.logVector(q);
	
	
    // std::stack<int> stack;
    // std::queue<int> queue;
    // Waltr waltr = Waltr(queue);
    // for(int i =0;i<5;i++) {
    //     queue.push(i);
    //     waltr.logQueue(queue);
    // }
}

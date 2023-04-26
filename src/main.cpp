#include <array>
#include <vector>
#include <iostream>
#include "waltrDrawStructure.hpp"

int main(void) {
	
	
	
	std::vector<int> v;
	Waltr waltr = Waltr(v);
	for(int i=0;i<44;i++) {
		v.push_back(i*2);
	}
	waltr.logVector(v);
	waltr.logVector(v);
	
	
	
	/*
	
	std::stack<int> s;
	Waltr waltr2 = Waltr(s);
	for(int i=0;i<44;i++) {
		s.push(i*2);
	}
	waltr2.logStack(s);
	
	*/
	
	/*std::queue<int> q;
	Waltr waltr3 = Waltr(q);
	for(int i=0;i<44;i++) {
		q.push(i*2);
	}
	waltr3.logQueue(q);
	*/
}

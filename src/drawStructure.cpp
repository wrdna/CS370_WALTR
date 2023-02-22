#include <stack>
#include <vector>
#include <array>
#include <queue>

#include <iostream>

#include "drawStructure.hpp"
/*
Function description:
drawStructure()

This function will be passed a data structure and will call the proper function to
draw the passed data structure.

INPUT: An STL array, C Style array, or vector.
OUTPUT: None

*/

//TODO: Figure out STL arrays, convert arrays to array of pointers to be passed(?)


// template<std::size_t SIZE>
// void drawStructure(std::array<int, SIZE> &array) {
// 	//drawArraySTL(array);
// 	std::cout<<std::endl;
// 	for(int x : array) {
// 		std::cout<<x<<" ";
// 	}
// }

void drawStructure(int array[], int size) {
	//drawArrayCStyle(array);
	std::cout<<std::endl;
	for(int i=0;i<size;i++) {
		std::cout<<array[i]<<" ";
	}
}

void drawStructure(std::vector<int> &vector) {
	//drawVector(array);
	std::cout<<std::endl;
	for(int x : vector) {
		std::cout<<x<<" ";
	}
}



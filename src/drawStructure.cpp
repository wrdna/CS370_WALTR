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


/*
INPUT: Pointer to C-Style Array, Size of array

Creates shallow copy stored within object and calls function to draw
*/
DrawStructure::DrawStructure(const int* c_array, int c_size) {
	toVector(c_array, c_array + c_size);
	printVector(memory_vector);
	//drawVector(memory_vector);	
}

DrawStructure::DrawStructure(const int* const* c_array, int c_row, int c_col) {
	to2DVector(c_array, c_row, c_col);
	printVector2D(memory_matrix);
	//drawVector(memory_vector);
}

/*
INPUT: Vector

Creates shallow copy stored within object
*/
DrawStructure::DrawStructure(const std::vector<int> vector) {
    toVector(vector.data(), vector.data() + vector.size());
}

/*
INPUT: Pointer to beginning of array, pointer to end of array

Creates a shallow copy of the inputted structure, and stored
in the created DataStructure object.
*/
void DrawStructure::toVector(const int* begin, const int* end) {
	for(int*i = (int*)begin; i < end; i++) {
		memory_vector.push_back(i);
	}
}

void DrawStructure::to2DVector(const int* const* arr, int row, int col) {
	for(int i = 0; i < row; i++) {
		std::vector<int *> vector_row;
		for(int j = 0; j < col; j++) {
			vector_row.push_back((int*)&arr[i][j]);
		}
		memory_matrix.push_back(vector_row);
	}
}

/*
Prints vector, used for testing

To print value, index must be dereferenced with *
*/
void DrawStructure::printVector(std::vector<int *>vector) {
	for(auto & x: vector) {
		std::cout<<*x<<" ";
	}
}

void DrawStructure::printVector2D(std::vector<std::vector<int *>>vector2D) {
	for(auto& vector: vector2D) {
		for(auto & x: vector) {
			//std::cout<<*x<<" ";
			if(x != nullptr) {
                std::cout << *x << " ";
            } else {
                std::cout << "null ";
            }
		}
		std::cout<<std::endl;
	}
}

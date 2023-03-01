#include <vector>
#include <array>

#ifndef DRAW_STRUCTURE
#define DRAW_STRUCTURE

class DrawStructure {
	private:
		std::vector<int *>memory_vector;
	public:

		//Overload for C-Style arrays
		DrawStructure(const int* c_array, int c_size);

		//Overload for STL arrays
		//Implementation in header file because of template
		template<std::size_t SIZE>
		DrawStructure(const std::array<int, SIZE> &stl_array) {
			toVector(stl_array.begin(), stl_array.end());
			printVector(memory_vector);
			//drawVector(memory_vector);
		}

		//Overload for Vectors
		DrawStructure(const std::vector<int> vector);

		//Convert inputted structure to a vector
		void toVector(const int* begin, const int* end);
		
		//printVector used for testing
		void printVector(std::vector<int *>vector);
};
#endif // DRAW_STRUCTURE
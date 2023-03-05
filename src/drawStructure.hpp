#include <vector>
#include <array>

#ifndef DRAW_STRUCTURE
#define DRAW_STRUCTURE
#include <vector>

class DrawStructure {
	private:
		std::vector<int *>memory_vector;
		std::vector<std::vector<int *>>memory_matrix;
	public:

		//Overload for C-Style arrays
		DrawStructure(const int* c_array, int c_size);
		DrawStructure(const int* const* arr, int c_row, int c_col);

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

		//Convert inputted structure to a vector
		void to2DVector(const int* const* arr, int row, int col);
		
		//printVector used for testing
		void printVector(std::vector<int *>vector);

		//printVector2D used for testing
		void printVector2D(std::vector<std::vector<int *>>vector2D);

};
#endif // DRAW_STRUCTURE
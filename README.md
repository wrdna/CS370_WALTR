# WALTR

WALTR is a single header C++ library for visualization of data structures, compatible with Windows, MacOS, and Linux.

## Installation/Usage

1. Grab  **waltr.cpp** and **waltr.hpp**
2. Throw them into your project.
3. Link with
    - -lopengl32 and -lgdi32 on Windows
    - -framework OpenGL and -framework Cocoa on macOS
    - -lGLU -lGL -lX11 on Linux
4. You're done!

## Usage

To use WALTR, create an object and pass your data structure to the Waltr() constructor. Syntax is as follows:

```C++
Waltr waltr = Waltr(yourDataStructure);
```

The following table describes the proper syntax for parameters:

| Type     | Parameters |
| ----------- | ----------- |
| C-Style Array      | (pointer to array, size of array)     |
| STL Array   | (pointer to array)        |
| Vector      | (pointer to vector)     |
| Stack   | (pointer to stack)        |
| Queue   | (pointer to queue)        |
------

Here is an example using a vector.

```C++
#import <waltr.h>

int main(void) {
	std::vector<int> vec = {0,1,2,3,4};
	Waltr waltr = Waltr(vec);

	return 0;
}
```
And to compile:

```
Windows: g++ main.cpp waltr.cpp -lopengl32 -lgdi32
Mac: g++ main.cpp waltr.cpp -framework Cocoa -framework openGL
Linux:
```

## Restrictions

- Currently, WALTR only supports the integer type (More types in the future)

- WALTR only likes single digit integers at the moment, he's a picky eater but we're working on it!

- WALTR can only handle data structures with a size up to 10 currently, larger than 10 causes problems! (Also a work in progress)
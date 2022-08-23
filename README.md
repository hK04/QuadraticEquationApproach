# QuadraticEquationApproach
First approach to developing at University

This program meant to solve polymoial equations with form of $ax^2 + bx^2 + c = 0$

`main.cpp` - C program that solves the equation 

`equation.cpp` - includes functions of input, output, finding of discriminant and solving the equation

`equation.hpp` - prototypes of functions

`headers.hpp` - includes structures and constants

'unit_tests.cpp' - functions meant to test all methods in `equation.cpp`

`unit_tests.hpp` - prototypes of unit_tests 

# To compile:
open bash -> `g++ main.cpp equation.cpp unit_tests.cpp -o main.o` 
# To use documentation:
open bash -> `doxygen dox`, then open some of `.html`

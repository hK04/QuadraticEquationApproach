# QuadraticEquationApproach
First approach to developing at MIPT 

This program meant to solve polynomial equations with form of $ax^2 + bx^2 + c = 0$

`main.cpp` - main file of solution. Where you choose to compile with debug or release modes 

`equation.cpp` - includes functions of input, output, finding of discriminant and solving the equation

`equation.hpp` - includes prototypes of functions

`headers.hpp` - includes structures and constants

`unit_tests.cpp` - includes functions meant to test all methods in `equation.cpp`

`unit_tests.hpp` - includes prototypes of unit_tests 

# To compile:
```cd QuadraticEquationApproach/``` to make usual version: ```make``` to make debug version  ```make debug```

# To use documentation:
```cd QuadraticEquationApproach/```, ```doxygen dox```, then open some of ```.html```

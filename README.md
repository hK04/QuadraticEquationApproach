# QuadraticEquationApproach
[![](https://img.shields.io/badge/github-blue?style=for-the-badge)](https://github.com/hK04/QuadraticEquationApproach)

First approach to developing at MIPT 

This program meant to solve polynomial equations with form of $ax^2 + bx^2 + c = 0$

`main.cpp` - main file of solution. Where you choose to compile with debug or release modes 

`equation.cpp` - includes functions of input, output, finding of discriminant and solving the equation

`equation.hpp` - includes prototypes of functions

`headers.hpp` - includes structures and constants

`unit_tests.cpp` - includes functions meant to test all methods in `equation.cpp`

`unit_tests.hpp` - includes prototypes of unit_tests 

`colors.hpp` - includes names of supported colors of output

# To compile WITHOUT debug:
```bash
git clone https://github.com/hK04/QuadraticEquationApproach
cd QuadraticEquationApproach
make
./main # executable file
```

# To compile WITH debug:

```bash
git clone https://github.com/hK04/QuadraticEquationApproach
cd QuadraticEquationApproach
make debug
./main # executable file
```

```diff
- [Note] For most accurate debug you may change debug flags to $(DEBUGFLAGS)
```

# To use documentation:

```bash
git clone https://github.com/hK04/QuadraticEquationApproach
cd QuadraticEquationApproach
doxygen dox
cd html
classes.html
```

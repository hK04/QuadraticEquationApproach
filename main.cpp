/// \file

/** 
*   @file main.cpp
*   @mainpage Quadratic Equation Documentation
*   @section desc Description:
*   This program was written as first task at MIPT
*
*   @section download Downloading link:
*   <a href="https://github.com/hK04/QuadraticEquationApproach">->Github</a> 
*   @author Anoshin. M aka hK04
*   @brief Program meant to solve quadratic equations given in form of  \f$ax^2 + bx + c = 0\f$ 
*   
*/

/**
*   @page solution How to solve equation?
*   To solve the quation via this program you will need to download repository from github and use `main.cpp`
*/

/**
*   @page Downloading Where to download?
*   You may download program on my Github
*   <a href="https://github.com/hK04/QuadraticEquationApproach">->Github</a> 
*/

#include "equation.hpp"

#include <math.h>



int main(){
    double a, b, c;
    a = b = c = NAN;
    roots root;

    input(&a, &b, &c); //a*x^2 + b*x + c
    solve_equation(a, b, c, &root);
    output(&root);

    return 0;
}

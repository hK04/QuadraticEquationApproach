#define _CRT_SECURE_NO_WARNINGS
#include "equation.hpp"

int main(){
    double a, b, c;
    struct roots root;

    input(&a, &b, &c); //a*x^2 + b*x + c
    solve_equation(a, b, c, &root);
    output(&root);
    return 0;
}

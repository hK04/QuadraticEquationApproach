#include "equation.hpp"
#include "headers.hpp"

int main(){
    double a, b, c;
    struct roots root;

    input(&a, &b, &c); //a*x^2 + b*x + c
    solve_equation(a, b, c, &root);
    output(&root);

    return 0;
}

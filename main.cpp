#include "equation.hpp"

int main(){
    double a, b, c;
    struct roots root;

    input(&a, &b, &c);
    solve_equation(a, b, c, &root);
    output(a, b, c, root);
    return 0;
}

//указатели
//асерты
//две функции
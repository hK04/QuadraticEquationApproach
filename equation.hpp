#include <stdio.h>
#include <math.h>
#include "headers.hpp"

struct roots{
    int num_of_roots = 0;
    double arr[2] = { 0 };
};

enum ExitStatus{
   INFINITE_SOLS =  10000000,
   ZERO_SOLS = 0, 
   ONE_SOLS = 1,
   TWO_SOLS = 2

};

int is_equal(double x, double y){
    if (abs(x - y) <= THRESHOLD)
        return 1;
    return 0;

}

void input(double* a, double* b, double* c){
    printf("Write down the equation in form of a*x^2 + b*x + c = 0 \n");
    scanf("%lf%lf%lf", a, b, c);
}

void output(double a, double b, double c, struct roots root){
    int num_of_solutions = root.num_of_roots;

    switch (num_of_solutions){
    case INFINITE_SOLS:
        printf("Infinite number of solutions");
        return;

    case ZERO_SOLS:
        printf("No solution");
        return;

    case ONE_SOLS:
        printf("There's no solution"); 
        printf("\nSolution is: %.3lf", root.arr[0]);
        return;

    case TWO_SOLS:
        printf("There're two solutions");
        for (int i = 0; i <root.num_of_roots; i++)
            printf("\nSolution %ld is: %.3lf", i + 1, root.arr[i]);
        return;

    }
}

double computate_discriminant (double a, double b, double c){
    return (b * b - 4 * a * c);
}

void solve_equation(double a, double b, double c, struct roots* root){
    if (is_equal(a, 0)){
        if (is_equal(b, 0)){
            if (is_equal(c, 0)){
                (*root).num_of_roots = INFINITE_SOLS; //infinite number of solutions
                return;
            } else {
                (*root).num_of_roots = ZERO_SOLS; //no solutions 
                return;
            }
        }

        (*root).num_of_roots = 1;
        (*root).arr[0] = -1 * c / b;
        return;
    }

    double D = computate_discriminant(a, b, c);

    if (is_equal(D, 0)){
        (*root).num_of_roots = ONE_SOLS; //one solution
        (*root).arr[0] = - 1 * b / (2 * a);
        return;
    } 
    if (D < 0) {
        (*root).num_of_roots = ZERO_SOLS; //no solutions 
        return; 
    }

    (*root).num_of_roots = TWO_SOLS; //two solutions
    (*root).arr[0] = (- 1 * b - sqrt(D))/ (2 * a);
    (*root).arr[1] = (- 1 * b + sqrt(D))/ (2 * a);
    return;
}
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "headers.hpp"

int is_equal(double x, double y){
    assert(isfinite(x)  &&  isfinite(y) && "Coefficients are NaN!"); 

    if (abs(x - y) <= THRESHOLD) //использовать fabs  (!)
        return 1;
    return 0;

}

void input(double* a, double* b, double* c){
    assert(a != NULL && b != NULL && c != NULL && "Pointer to value is NULL");

    printf("Write down the equation in form of a*x^2 + b*x + c = 0 \n");
    scanf("%lf%lf%lf", a, b, c);
}

void output(struct roots* root){
    assert(root != NULL && "Pointer to Solutions is NULL");

    int num_of_solutions = root->num_of_roots;

    switch (num_of_solutions){
        case INFINITE_SOLS:
            printf("Infinite number of solutions");
            return;

        case ZERO_SOLS:
            printf("No solution");
            return;

        case ONE_SOLS:
            printf("There's one solution"); 
            printf("\nSolution is: %.3lf", root->arr[0]);
            return;

        case TWO_SOLS:
            printf("There're two solutions");
            for (int i = 0; i < num_of_solutions; i++)
                printf("\nSolution %ld is: %.3lf", i + 1, root->arr[i]);
            return;
    }
}

double computate_discriminant (double a, double b, double c){
    assert(isfinite(a) && isfinite(b)  && isfinite(c) && "Coefficients are NaN!");

    return (b * b - 4 * a * c);
}

void solve_quadratic_equation(double a, double b, double c, struct roots* root){
    assert(isfinite(a) && "Infinite Number");
    assert(isfinite(b) && "Infinite Number");
    assert(isfinite(c) && "Infinite Number");
    assert(!is_equal(a, 0) && "Not a quadratic equation"); 

    double D = computate_discriminant(a, b, c);

    if (is_equal(D, 0)){
        root->num_of_roots = ONE_SOLS; //one solution
        root->arr[0] = - 1 * b / (2 * a);
        return;
    } 
    if (D < 0){
        root->num_of_roots = ZERO_SOLS; //no solutions 
        return; 
    }

    root->num_of_roots = TWO_SOLS; //two solutions
    root->arr[0] = (- 1 * b - sqrt(D))/ (2 * a);
    root->arr[1] = (- 1 * b + sqrt(D))/ (2 * a);
    return;
}

void solve_linear_equation(double b, double c, struct roots* root){
    assert(isfinite(b) && isfinite(c) && "Coefficients are NaN!");
    if (is_equal(b, 0)){
        if (is_equal(c, 0)){
            root->num_of_roots = INFINITE_SOLS; //infinite number of solutions
            return;
        } else {
            root->num_of_roots = ZERO_SOLS; //no solutions 
            return;
        }
    }

    assert(!is_equal(b, 0) && "Not a linear equation"); 

    root->num_of_roots = 1;
    root->arr[0] = -1 * c / b;
    return;
}

void solve_equation(double a, double b, double c, struct roots* root){
    assert(isfinite(a) && isfinite(b)  && isfinite(c) && "Coefficients are NaN!");
    assert(root != NULL && "Pointer to Solutions is NULL");

    if (is_equal(a, 0)){
        solve_linear_equation(b, c, root);
        return;
    } else {
        solve_quadratic_equation(a, b, c, root);
        return;
    }
}
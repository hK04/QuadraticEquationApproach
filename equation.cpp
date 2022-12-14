/// \file

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "headers.hpp"
#include "colors.hpp"

int is_equal(const double x, const double y){
    assert(isfinite(x) && "Coefficient isnt finite!");
    assert(isfinite(y) && "Coefficient isnt finite!"); 

    return fabs(x - y) <= DELTA;
}

double minus_zero_to_zero(const double x){
    assert(isfinite(x) && "Solution is NaN!"); 
    
    if (is_equal(x, 0))
        return 0;
    else
        return x;
}

void input(double *const a, double *const b, double *const c){
    assert(a != NULL && "Pointer to value is NULL");
    assert(b != NULL && "Pointer to value is NULL");
    assert(c != NULL && "Pointer to value is NULL");

    printf("Write down the equation in form of a*x^2 + b*x + c = 0 \n");
    scanf("%lf%lf%lf", a, b, c);
}

void output(roots* root){
    assert(root != NULL && "Pointer to Solutions is NULL");

    int num_of_solutions = root->num_of_roots;

    switch (num_of_solutions){
        case INFINITE_SOLS:
            printf("%s", RED);
            printf("Infinite number of solutions\n");
            printf("%s", BLACK);
            return;

        case ZERO_SOLS:
            printf("%s", RED);
            printf("No solution\n");
            printf("%s", BLACK);
            return;

        case ONE_SOLS:
            printf("%s", YELLOW);
            printf("There's one solution\n");
            printf("%s", BLACK); 
            printf("Solution is: %lg\n", root->arr[0]);
            return;

        case TWO_SOLS:
            printf("%s", GREEN);
            printf("There're two solutions\n");
            printf("%s", BLACK); 
            for (int i = 0; i < num_of_solutions; i++){
                printf("Solution %d is: %lg\n", i + 1, root->arr[i]);
            }
            return;

        default:
            printf("Something went wrong. Better luck next time\n");
            printf("Number of solutions: %d\n", num_of_solutions);
            for (int i = 0; i < num_of_solutions; i++)
                printf("Solution %d is: %lg\n", i + 1, root->arr[i]);
            return;
    }
}

void solve_quadratic_equation(const double a, const double b, const double c, roots* root){
    assert(isfinite(a) && "Coefficient isnt finite!");
    assert(isfinite(b) && "Coefficient isnt finite!");
    assert(isfinite(c) && "Coefficient isnt finite!");

    assert(!is_equal(a, 0) && "Not a quadratic equation"); 
    assert(root != NULL && "Pointer to Solutions is NULL");

    double D = b * b - 4 * a * c;

    if (is_equal(D, 0)){
        root->num_of_roots = ONE_SOLS; //one solution
        root->arr[0] = -b / (2 * a);
        return;
    } 
    if (D < 0){
        root->num_of_roots = ZERO_SOLS; //no solutions 
        return; 
    }

    double sqrt_D = sqrt(D);

    root->num_of_roots = TWO_SOLS; //two solutions
    root->arr[0] = -(b + sqrt_D) / (2 * a);
    root->arr[1] = -(b - sqrt_D) / (2 * a);
    root->arr[0] = minus_zero_to_zero(root->arr[0]);
    root->arr[1] = minus_zero_to_zero(root->arr[1]);
    return;
}

void solve_linear_equation(const double b, const double c, roots* root){
    assert(isfinite(b) && "Coefficient isnt finite!");
    assert(isfinite(c) && "Coefficient isnt finite!");
    assert(root != NULL && "Pointer to Solutions is NULL");

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
    root->arr[0] = -c / b;
    root->arr[0] = minus_zero_to_zero(root->arr[0]);
    return;
}

void solve_polynomial_equation(const double a, const double b, const double c, roots* root){
    assert(isfinite(a) && "Coefficient isnt finite!");
    assert(isfinite(b) && "Coefficient isnt finite!");
    assert(isfinite(c) && "Coefficient isnt finite!");
    assert(root != NULL && "Pointer to Solutions is NULL");

    if (is_equal(a, 0)){
        solve_linear_equation(b, c, root);
    } else {
        solve_quadratic_equation(a, b, c, root);
    }
}
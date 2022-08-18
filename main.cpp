#include <stdio.h>
#include <math.h>

#include "headers.h"

struct roots{
    int num_of_roots = 0;
    double arr[2] = { 0 };
};

int main(){
    double a, b, c;
    struct roots root;

    input(&a, &b, &c);
    solve_equation(a, b, c, &root);
    output(a, b, c, root);
    return 0;
}

bool is_equal(double x, double y){
    if (abs(x - y) < THRESHOLD)
        return true;
    return false;

}

void input(double* a, double* b, double* c){
    printf("Write down the equation in form of a*x^2 + b*x + c = 0 \n");
    scanf("%lf%lf%lf", a, b, c);
}

void output(double a, double b, double c, struct roots root){
    if (is_equal(a, 0)){
        if (is_equal(b, 0)){
            if (is_equal(c, 0)){
                printf("Infinite number of solutions"); //infinite number of solutions
                return;
            } else {
                printf("There's no solution"); 
                return;
            }
        }
    }

    if (root.num_of_roots == 1){
        printf("There's one solution");
        printf("Solution is: %.3lf", root.arr[0]);
        return;
    }
    if (root.num_of_roots == 2){
        printf("There're two solutions");
        for (int i = 0; i <root.num_of_roots; i++)
            printf("\nSolution %ld is: %.3lf", i + 1, root.arr[i]);
    }else{
        printf("There's no solution"); 
    }
    return;

}

double computate_discriminant (double a, double b, double c){
    return (b * b - 4 * a * c);
}

void solve_equation(double a, double b, double c, struct roots* root){
    if (is_equal(a, 0)){
        if (is_equal(b, 0)){
            if (is_equal(c, 0)){
                (*root).num_of_roots = INF; //infinite number of solutions
                return;
            } else {
                (*root).num_of_roots = 0; //no solutions 
                return;
            }
        }

        (*root).num_of_roots = 1;
        (*root).arr[0] = -1 * c / b;
        return;
    }

    double D = computate_discriminant(a, b, c);

    if (is_equal(D, 0)){
        (*root).num_of_roots = 1; //one solution
        (*root).arr[0] = - 1 * b / (2 * a);
        return;
    } 
    if (D < 0) {
        (*root).num_of_roots = 0; //no solutions 
        return; 
    }

    (*root).num_of_roots = 2; //two solutions
    (*root).arr[0] = (- 1 * b - sqrt(D))/ (2 * a);
    (*root).arr[1] = (- 1 * b + sqrt(D))/ (2 * a);
    return;
}
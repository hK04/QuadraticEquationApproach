#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "unit_tests.hpp"
#include "equation.hpp"

int test_of_polynomial_equation(int numTest, double a, double b, double c, double num_of_roots, double x_1_right, double x_2_right){
    assert(isfinite(a) && isfinite(b) && isfinite(c) && "Coefficients are NaN!");
    assert(isfinite(num_of_roots) && isfinite(x_1_right) && isfinite(x_2_right) && "Solutions are NaN!");

    roots root = {0};
    solve_polynomial_equation(a, b, c, &root);

    if (root.num_of_roots != num_of_roots){
        printf("Test %d failed: a = %lg, b = %lg, c = %lg; Solutions: %lg %lg - Should be: %lg %lg\n", 
            numTest, a, b, c, root.arr[0], root.arr[1], x_1_right, x_2_right);

        return 0;
    } else {
        if (!is_equal(root.arr[0], x_1_right) || !is_equal(root.arr[1], x_2_right)){
            printf("Test %d failed: a = %lg, b = %lg, c = %lg; Solutions: %lg %lg - Should be: %lg %lg\n", 
                numTest, a, b, c, root.arr[0], root.arr[1], x_1_right, x_2_right);

            return 0;
        } else {
            printf("Test %d is succed\n", numTest);
            
            return 1;
        }
    }
}

int test_of_linear(int numTest, double b, double c, double x_right){
    assert(isfinite(b) && isfinite(c) && "Coefficients are NaN!");
    assert(isfinite(x_right) && "Solution is NaN!");

    roots root = {0};
    solve_linear_equation(b, c, &root);

    if (root.num_of_roots != 1){
        printf("Test %d failed: b = %lg, c = %lg; Solution: %lg - Should be: %lg\n", 
            numTest, b, c, root.arr[0], x_right);

        return 0;
    } else {
        if (!is_equal(root.arr[0], x_right)){
            printf("Test %d failed: b = %lg, c = %lg; Solution: %lg - Should be: %lg\n", 
                numTest, b, c, root.arr[0], x_right);

            return 0;
        } else {
            printf("Test %d is succed\n", numTest);
            return 1;
        }
    }
}

//we could write the same for linear, but i dont wanna cheat that much ;)

int test_of_quadratic(int numTest, double a, double b, double c, double x_1_right, double x_2_right){
    return test_of_polynomial_equation(numTest, a, b, c, 2, x_1_right, x_2_right);
}

int test_of_is_equal(int numTest, double x, double y, int right){
    assert(isfinite(x) && isfinite(y) && "Values are NaN!");
    assert(isfinite(right) && "Solution is NaN!");

    int equality = 0;
    equality = is_equal(x, y);
    
    if (equality == right){
        printf("Test %d is succed\n", numTest);

        return 1;
    } else {

        printf("Test %d failed: x = %lg, y = %lg; Solution: %d - Should be: %d\n", 
            numTest, x, y, equality, right);
        
        return 0;
    }
}


int Test(){
    int failed = 0;
    int number_of_test = 1;
    
    printf("Test of polynomial function\n");

    if (test_of_polynomial_equation(number_of_test++, 0,  0,  0, -1,  0,   0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 1,  2, -3,  2,  1,  -3) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 0,  4,  0,  1,  0,   0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 0,  2, -4,  1,  2,   0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 0,  0, 13,  0,  0,   0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 1, -1,  3,  0,  0,   0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 1,  4,  4,  1, -2,   0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 4,  4,  1,  1, -0.5, 0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++,0.0000000000002, 0.0000000000004, 0.0000000000002, 1, -1, 0) == 0) failed++;

    printf("\nTest of linear function\n");

    if (test_of_linear(number_of_test++, 6,   6,   -1) == 0) failed++;
    if (test_of_linear(number_of_test++, 0,   0,   -1) == 0) failed++;
    if (test_of_linear(number_of_test++, 8,  -4,  0.5) == 0) failed++;

    printf("\nTest of quadratic function\n");

    if (test_of_polynomial_equation(number_of_test++, 1,  2, -3,  2,  1, -3) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 1, -1,  3,  0,  0,  0) == 0) failed++;
    if (test_of_polynomial_equation(number_of_test++, 1,  4,  4,  1, -2,  0) == 0) failed++;

    printf("\nTest of is_equal\n");

    if (test_of_is_equal(number_of_test++, 0,  0,  1) == 0) failed++;
    if (test_of_is_equal(number_of_test++, 7,  7,  0) == 0) failed++;
    if (test_of_is_equal(number_of_test++, 8,  9,  1) == 0) failed++;

    return failed;
}

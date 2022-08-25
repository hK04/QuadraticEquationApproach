/// \file

#include "headers.hpp"

/**
*   @brief function what fixes -0.0000 to 0
*
*   @param[in] x is a value of first coefficient 
*   @return x if x != -0.0000, 0 if x == -0.0000
*
*/

double minus_zero_to_zero(const double x);

/**
*   @brief This function allows us to set values of a, b and c of ax^2 + bx + c
*
*   @param[in] a is a value of first coefficient 
*   @param[in] b is a value of second coefficient 
*   @param[in] c is a value of third coefficient 
*
*/

void input(double* a, double* b, double* c);

/**
*   @brief This function allows us to print solution of equation in console
*
*   @param[in] root is a structure of solution
*
*/

void output(roots* root);

/**
*   @brief function what finds difference between x and y and return 1 if it's <= than Threshold
*
*   @param[in] x is a first value
*   @param[in] y is a second value
*   @return 1 if values are nearly equal, 0 if values are not nearly equal
*
*/

int is_equal(const double x, const double y);

/**
*   @brief function what solves the equation in form ax^2 + bx + c = 0
*
*   @param[in] a is a value of first coefficient 
*   @param[in] b is a value of second coefficient 
*   @param[in] c is a value of third coefficient
*   @param[in] root is a structure of solution
*
*/

void solve_quadratic_equation(double a, double b, double c, roots* root);

/**
*   @brief function what solves the equation in form bx + c = 0
*
*   @param[in] b is a value of first coefficient 
*   @param[in] c is a value of second coefficient
*   @param[in] root is a structure of solution
*
*/

void solve_linear_equation(double b, double c, roots* root);

/**
*   @brief function what solves the polynomial equation in dependece with coefficients 
*
*   @param[in] a is a value of first coefficient 
*   @param[in] b is a value of second coefficient 
*   @param[in] c is a value of third coefficient
*   @param[in] root is a structure of solution
*
*/

void solve_polynomial_equation(const double a, const double b, const double c, roots* root);


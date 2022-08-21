/// \file

void input(double* a, double* b, double* c);

/**
*   @brief This function allows us to set values of a, b and c
*
*   @param[in] a is a value of first coefficient 
*   @param[in] b is a value of second coefficient 
*   @param[in] c is a value of third coefficient 
*
*/

void output(struct roots* root);

/**
*   @brief This function allows us to print solution of equation in console
*
*   @param[in] root is a structure of solution
*
*/

int is_equal(double x, double y);

/**
*   @brief function what finds difference between x and y and return 1 if it's <= than Threshold
*
*   @param[in] x is a first value
*   @param[in] y is a second value
*   @param[out] 1 - values are nearly equal
*   @param[out] 0 - values are not nearly equal
*
*/

void solve_quadratic_equation(double a, double b, double c, struct roots* root);

/**
*   @brief function what solves the equation when a != 0
*
*   @param[in] a is a value of first coefficient 
*   @param[in] b is a value of second coefficient 
*   @param[in] c is a value of third coefficient
*   @param[in] root is a structure of solution
*
*/

void solve_linear_equation(double b, double c, struct roots* root);

/**
*   @brief function what solves the equation when a == 0
*
*   @param[in] b is a value of second coefficient 
*   @param[in] c is a value of third coefficient
*   @param[in] root is a structure of solution
*
*/

void solve_equation(double a, double b, double c, struct roots* root);

/**
*   @brief function what solves the equation in dependece with coefficients 
*
*   @param[in] a is a value of first coefficient 
*   @param[in] b is a value of second coefficient 
*   @param[in] c is a value of third coefficient
*   @param[in] root is a structure of solution
*
*/
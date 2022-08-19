void input(double* a, double* b, double* c);
//function what allows us to set values of a, b and c 

void output(struct roots* root);
//function what allows us to get the solution written in console 

int is_equal(double x, double y);
//function what finds difference between x and y and return True if it's less than Threshold

double computate_discriminant (double a, double b, double c);
//function what computates the discriminant 

void solve_quadratic_equation(double a, double b, double c, struct roots* root);
//function what solves the equation when a != 0

void solve_linear_equation(double b, double c, struct roots* root);
//function what solves the equation when a == 0

void solve_equation(double a, double b, double c, struct roots* root);
//function what solves the equation in dependece with coefficients 
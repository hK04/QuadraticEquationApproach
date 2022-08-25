/// \file

#ifndef ALREADY_OPENED
#define ALREADY_OPENED

///This variable is the delta of equality
const double DELTA = 1e-7;

/** \struct roots
*   @brief  Structure with varible `num_of_roots` and array of solutions
*
*/

typedef struct{
    int num_of_roots = 0;
    double arr[2] = {0};
} roots;

/** \enum ExitStatus 
*   @brief  Enum meant to treat different types of exits in solution
*   
*/

enum ExitStatus{
   INFINITE_SOLS = -1, ///<This is ExitStatus in case of Infinite number of Solutions
   ZERO_SOLS     =  0, ///<This is ExitStatus in case of Zero number of Solutions
   ONE_SOLS      =  1, ///<This is ExitStatus in case of One Solution
   TWO_SOLS      =  2  ///<This is ExitStatus in case of Two Solutions
};

#endif //ALREADY_OPENED
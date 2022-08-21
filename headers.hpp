/// \file


///This variable is threshold of equality
const double THRESHOLD = 1e-7; //delta neighbourhood of equality

/** \struct roots
*   @brief  Structure with varible `num_of_roots` and array of solutions
*
*/

struct roots{
    int num_of_roots;
    double arr[2];
};

/** \enum ExitStatus 
*   @brief  Enum meant to treat different types of exits in solution
*
*/

enum ExitStatus{
   INFINITE_SOLS = -1, ///  This is ExitStatus in case of Infinite number of Solutions
   ZERO_SOLS     =  0, ///  This is ExitStatus in case of Zero number of Solutions
   ONE_SOLS      =  1, ///  This is ExitStatus in case of One Solution
   TWO_SOLS      =  2  ///  This is ExitStatus in case of Two Solutions
};


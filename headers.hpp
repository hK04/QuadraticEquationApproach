const double THRESHOLD = 1e-7; //delta neighborhood of equality

struct roots{
    int num_of_roots;
    double arr[2];
};

enum ExitStatus{
   INFINITE_SOLS =  -1,
   ZERO_SOLS = 0, 
   ONE_SOLS = 1,
   TWO_SOLS = 2

};

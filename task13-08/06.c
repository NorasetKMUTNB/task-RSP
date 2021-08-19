//create a new matrix that results from augmenting
//an (nxn) matrix with a column vector.
#include <stdio.h>
#include "matrix.c"
#include "vector.c"
#include "mycode.c"


int main()
{
    int n = 3;
//create matrix
    double **a = matrix(n,n);
//create vector
    double *b = vector(n);

//tester
    double num1[][9] = { {1,2,3,4,5,6,7,8,9 } };
    double num2[3] =  { 10, 11, 12 };

//add element in matrix & vector
    refill_matrix(a, n, n, num1[0]);
    copy_vector(b, num2, n);

    printf("matrix a :");
    print_matrix(a, n, n);

    printf("vector b :");
    print_vector(b, n);

    
//augmenting
    double **mu = aug(a, b, n);
    printf("augmenting of a & b :");
    print_matrix(mu, n, n+1);   
}
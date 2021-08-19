//create a reduced row echelon matrix of (mxn) dimension.
#include <stdio.h>
#include "matrix.c"
#include "mycode.c"


int main()
{
    int m = 3, n = 4;
//create matrix
    double **a = matrix(m,n);

//tester
    double num[][12] = { 
        { 1, -1, -2, 4,
        2, -1, -1, 2,
        2, 1, 4, 16 },
//tester_free
        { 1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12 } };

//add element in matrix
    refill_matrix(a, m, n, num[1]);

    printf("matrix a :");
    print_matrix(a, m, n);
    
//reducedre
    double **re = reducedre(a, m, n);
    printf("reduced row echelon a :");
    print_matrix(re, m, n);   
}
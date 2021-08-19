//create a new matrix that results from multiplying a matrix 'a' (mxn) by a column vector 'b' (nx1).
#include <stdio.h>
#include "matrix.c"
#include "vector.c"
#include "mycode.c"


double *multipmv(double **ma, double *vb, int m, int n)
{   
//creat new vector to collet multiplying a matrix and vector 
    double *multi = vector(m);

    for ( int r=0; r < m; r++ )     //loop for rows 
    {
        double ans = 0;             //set ans = 0 in next rows
        for( int c=0; c<n; c++ )    //loop for column & multip ans[r][c]
            ans += ma[r][c]*vb[c];

        multi[r] = ans;             //append ans in multi[r]
    }
    return multi;
} 


int main()
{
    int m = 2, n = 3;
//create matrix
    double **a = matrix(m,n);
//create vector
    double *b = vector(n);

//tester
    double num1[][6] = { { 4, 2, 4, 8, 3, 1 } };
    double num2[3] =  { 2, 2, 3 };

//add element in matrix & vector
    refill_matrix(a, m, n, num1[0]);
    copy_vector(b, num2, n);

    printf("matrix a :");
    print_matrix(a, m, n);

    printf("vector b :");
    print_vector(b, n);

//multiplication
    double *mu = multipmv(a, b, m, n);
    printf("multiplication of a & b :");
    print_vector(mu, m);

}

// create a new matrix that results from the multiplication of two matrices 'a' (mxn) and 'b' (nxp).
#include <stdio.h>
#include "matrix.c"
#include "mycode.c"


double **multip(double **a, double **b, int m, int n, int p)
{   
    //creat new matrix to collet multip
    double **multi = matrix(m,p);
    int i = 0;

    for ( int r=0; r < m; r++ )             //loop for rows
    {
        for ( int c=0; c < p; c++ )         //loop for column
        {
            double ans = 0;                 //set 0 next in column

            for( int ro=0; ro<n; ro++ )     //loop for multip ans[r][c]
                ans += a[r][ro]*b[ro][c];

            multi[r][c] = ans;              //append ans in multi[r][c]
        }
    }
    return multi;
} 


int main()
{
    int m = 2, n = 3, p = 2;
//create matrix
    double **a = matrix(m,n);
    double **b = matrix(n,p);

//tester
    double numt[][6] = { { 4, 2, 4, 8, 3, 1 }, 
                         { 3, 5, 2, 8, 7, 9 } 
        };

//add element in matrix
    refill_matrix(a, m, n, numt[0]);
    refill_matrix(b, n, p, numt[1]);

    printf("matrix a :");
    print_matrix(a, m, n);

    printf("matrix b :");
    print_matrix(b, n, p);

//multiplication
    double **mu = multip(a, b, m, n, p);
    printf("multiplication of a & b :");
    print_matrix(mu, m, p);
}
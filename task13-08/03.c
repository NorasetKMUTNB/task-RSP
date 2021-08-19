#include <stdio.h>
#include "matrix.c"

double **transpose(double **mat, int m, int n)
{
    double **mtemp = matrix( m, n ); 
    int r,c;

    for (r=0; r<m; r++)
    {
        for(c=0; c<n; c++) 
        {
            mtemp[c][r] = mat[r][c];    //swap mat[r][c] to mat[c][r]
        }
    }
    return mtemp;
}

int main()
{
    int M =3, N=3;
    double numbers[][9] = { 
        {1,2,3,4,5,6,7,8,9 },
        {1,0,0,0,1,0,0,0,1 } 
    };

//create martrix
    double **m1 = matrix(M,N);
    double **m2 = matrix(M,N);

//add element in matrix
    fill_matrix( m1, M, N, numbers[0], M*N );
    fill_matrix( m2, M, N, numbers[1], M*N );

//m1
    printf("m1 = ");
    print_matrix( m1, M, N );

    m1 = transpose(m1, M, N);   //transpose by call function transpose()
    printf("transpose m1 = ");
    print_matrix( m1, M, N );

//m2
    printf("m2 = ");
    print_matrix( m2, M, N );

    m2 = transpose(m2, M, N);   //transpose by call function transpose()
    printf("transpose m2 = ");
    print_matrix( m2, M, N );

//clear memory
    free_matrix( m1, M, N );
    free_matrix( m2, M, N );

    return 0;
}
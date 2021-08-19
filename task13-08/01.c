#include <stdio.h>
#include "matrix.c" 


double **identity(int n)   //input n size (num x num)
{
    //create matrix sq
    double **mat =  matrix( n, n );

    int r, c;
    for (r=0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            if(r==c)
                mat[r][c] = 1;  //mat[i][i] = 1
            else
                mat[r][c] = 0;  //mat[i][j] = 0
        }
    }
    return mat;
} 

int main() 
{
    int N = 3;
    double **m = identity( N ); //create matrix identity by call function identity()

    printf("m = ");
    print_matrix( m, N, N );

    free_matrix( m, N, N );
    return 0;
}
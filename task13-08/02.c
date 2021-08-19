#include <stdio.h>
#include <stdlib.h> //to random
#include "matrix.c"
#include <time.h>   //to use time


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


double **swapR(double **mat, int n, int rdis,int rsrc )
{
    double rtemp[n];    //temp for tran
    for (int i = 0; i < n; i++)
        rtemp[i] = mat[rdis][i];    //copy row dis in rtemp

    for (int i = 0; i < n; i++)
        mat[rdis][i] = mat[rsrc][i];    //row dis to row src

    for (int i = 0; i < n; i++)
        mat[rsrc][i] = rtemp[i];    //rtemp to row src
    return mat;
}


double **swapC(double **mat, int n, int cdis,int csrc )
{
    double ctemp[n];    //temp for tran
    for (int i = 0; i < n; i++)
        ctemp[i] = mat[i][cdis];    //copy colmun dis in ctemp

    for (int i = 0; i < n; i++)
        mat[i][cdis] = mat[i][csrc];    //colmun dis to colmun src

    for (int i = 0; i < n; i++)
        mat[i][csrc] = ctemp[i];    //ctemp to colmun src
    return mat;
}


double **permuteR(int n)
{
    double **imat = identity(n); //create matrix identity by call function identity()
    srand(time(NULL));      //set seed follow time value
    for (int i = 0; i < n; i++)
    {
        int ran = rand() % n;   //random index to swap
        swapR(imat, n, i, ran); //call function swapR() to swap index
    }
    return imat;
}


double **permuteC(int n)
{
    double **imat = identity(n); //create matrix identity by call function identity()
    srand(time(NULL));      //set seed follow time value
    for (int i = 0; i < n; i++)
    {
        int ran = rand() % n;   //random index to sawp
        swapC(imat, n, i, ran); //call function swapC() to swap index
    }
    return imat;
}


int main()
{
    int M = 4, N = 4;
    double **m1 = identity( N );
    double **m2 = permuteR( N );
    double **m3 = permuteC( N );

//m1  
    printf("normal form identity matrix : ");
    print_matrix( m1, M, N );

//m2
    printf("permute swap row : ");
    print_matrix( m2, M, N );

//m3
    printf("permute swap colmun : ");
    print_matrix( m3, M, N );


//clear memory
    free_matrix( m1, M, N );
    free_matrix( m2, M, N );
    free_matrix( m3, M, N );
    return 0;
}
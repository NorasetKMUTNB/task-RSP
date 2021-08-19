//solve a system of linear equations given in a matrix form
//A*x = b, where A is an (nxn) matrix and b is a column vector (nx1).
#include <stdio.h>
#include "matrix.c"
#include "vector.c"
#include "mycode.c"


double *equation(double **mat,double *vec, int m)
{
//creat new vector to collet ans equation
    double *vtemp = vector(m);  
//creat new matrix to save augmenting matrix & vector
    double **mu = aug(mat, vec, m);
    printf("matrix :");
    print_matrix(mu, m, m+1);  

//reducedre
    reducedre(mu, m, m+1);
    printf("reduced row echelon a :");
    print_matrix(mu, m, m+1);  

    for (int i = 0; i < m; i++)
        vtemp[i] = mu[i][m];

    return vtemp;
}



int main()
{
    int m = 3;
//create matrix
    double **a = matrix(m,m);
//create vector
    double *b = vector(m);

//tester
    double mnum[][9] = { 
        { -2, -1, -2,
            4, 3, 2,
            5, 1, 5  },
//matrix tester_free
        { 1, 2, 3,
            5, 6, 7,
            9, 10, 11  } };
    double vnum[][3] = {
        {0,6,3},
//vector tester_free        
        {4,8,12} };


//add element in matrix
    refill_matrix(a, m, m, mnum[1]);
    copy_vector(b, vnum[1], m);

    printf("matrix a :");
    print_matrix(a, m, m);

    printf("vector b :");
    print_vector(b, m);
    
//equation
    double *re = equation(a, b, m);
    printf("equation, reduced row echelon :");
    print_vector(re, m);   
}
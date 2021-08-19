#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//
double **refill_matrix( double **mat, int m, int n , double *vec ) 
{ 
    int i = 0;  //index in *vec

    for( int r=0; r<m; r++) 
    {
        for( int c=0; c<n; c++) 
        {
            mat[r][c] = vec[i];
            i++;
        }
    }
    return mat;
}


//
double **aug(double **ma, double *vb, int n)
{
//creat new matrix to augmenting
    double **mat = matrix(n,n+1);
    copy_matrix(mat, ma, n, n);     //copy ma and paste mat

    for (int i = 0; i < n; i++)     //loop for add element from column vector to matrix
        mat[i][n] = vb[i];    
    
    return mat;
}


//
double **reducedre(double **mat, int m, int n)
{
//set vatemp for save value
    double vatemp = 0, vatemp2 = 0;

    //phase_1    
    for(int r = 0; r < m; r++)      //loop for rows
    {
        for(int c = 0; c<=r; c++)   //loop for column end column that must be 1 
        {   
            vatemp = mat[r][r];     //save value mat[r][r]

            if( mat[r][c] == 0 ) continue;  //value at mat[r][c] == 0 does not anything
            
            else if(c==r)           //value at mat[r][r] set 1 that must edit all elements in row
            {
                for(int i = 0; i <n ; i++)  //edit all elements in row
                    mat[r][i] = (1/vatemp)*mat[r][i];
            }
            else if(c!=r)           //value at mat[r][c] set 0 that must edit all elements in row
            {
                vatemp2 = mat[r][c];        //save value mat[r][c] to edit

                for(int i = 0; i <n ; i++)  //edit all elements in row
                    mat[r][i] = mat[r][i] - (vatemp2)*mat[c][i];
            }

        }
    }

    //phase_2 
    for(int r = 0; r < m; r++)      //loop for rows
    {
        for(int c = 0; c < m; c++)  //loop for column
        {
            if(mat[r][c] == 0 || mat[r][c] == 1) continue;  //value at mat[r][c] == 0 or mat[r][c] == 1 does not anything
            
            else    //value at mat[r][c] set 0
            {
                vatemp2 = mat[r][c];        //save value mat[r][c] to edit

                for(int i = 0; i <n ; i++)  //edit all elements in row
                    mat[r][i] = mat[r][i] - (vatemp2)*mat[c][i];
            }
        } 
    }

    //free detection
    for (int r = 0; r < m; r++)         //loop for rows
    {
        int count = 0;                  //count for check 0
        for (int c = 0; c < m+1; c++)   //loop for columns
        {
            if(mat[r][c] == 0) count++;  //check 0 it is 0 all row? 
            if(count == m+1) printf("X%d is free\n",r);
        }
    }

    return mat;
}

//
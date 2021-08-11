/* 
8) Write a C program that
- reads integer numbers from the text file 'data.txt' up to N numbers. 
- sorts the numbers using the Quicksort algorithm.
- saves the stored list of integers to the output file named 'data_sorted.txt'.
Note:
- Write C code for the quicksort algorithm in the source file 'qsort.c'
and include it to your C project.
*/



#include<stdio.h>  
#include<stdlib.h>  //for exit() function.

#include"qsort.c"   //import code in qsort.c



int fline(FILE *fp)
{   
    int cline = 0;
    char strn;

    if(fp == NULL)  //not thing in file.
    {
        return 0;
    }
    while(!feof(fp))    //when it end line, it will break loop while.
    {
        strn = getc(fp);
        if(strn == '\n')
        {
            cline++;
        }
    }
    return cline;
}



int *getarrnum(int *arr,int cline, FILE *fp)   //str to int and get in arrray.
{
    int i = 0;
    int num = 0;

    rewind(fp);
    for(i=0; i<cline; i++)
    {
        fscanf(fp,"%d",&num);
        arr[i]=num;
    }

    return arr;     
}



int main()
{
    FILE *fp;   //pointer "fp" to FILE
    fp = fopen("data.txt","r");

    int cline = fline(fp);
    if(cline == 0)
    {
        printf("not thing in file.");
        exit(-1);   //exit error
    }
    int arrnum[cline];
    getarrnum(arrnum, cline, fp);

    fclose(fp);
    
    int i = 0;
    for(i=0; i<cline; i++)
    {
        printf("%d\n", arrnum[i]);
    }

    int *qarr = quicksort(arrnum,0,cline-1);

    //data_sorted
    fp = fopen("data_sorted.txt","w");

    for(i=0; i<cline; i++)
    {
        fprintf( fp, "%d\n", qarr[i]);
    }

    fclose(fp);
    return 0;
}


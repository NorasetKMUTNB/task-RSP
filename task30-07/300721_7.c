#include <stdio.h>  
#include <stdlib.h>

int main()
{
    int i;
    
    FILE* demo;  // pointer "demo" to FILE
    demo = fopen("data.txt","w");

    for ( i=0; i<1000; i++) 
    {
      fprintf( demo, "%d\n", rand() % 1000);
    }

    fclose(demo);

}
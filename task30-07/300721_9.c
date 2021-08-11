/*
9) Write a C program that behaves and produces the same output as
the Python script given below:

########################################

# convert an integer to a hex string
def to_hex( value ):
    HEX_DIGITS = '0123456789abcdef'
    s = ''
    if (value < 0):
        value += (1 << 32)  # 32-bit value
    while True:
        d = HEX_DIGITS[ value & 0xf ]
        s = d + s
        value >>= 4
        if value == 0:
            break
    s = '0x' + s
    return s

if __name__ == "__main__": # some test code
    print (to_hex(33))  # 0x21
    print (to_hex(-1))  # 0xffffffff

########################################
*/



#include<stdio.h>  
#include<stdlib.h>  //for exit() function.
#include<string.h>
#include<stdint.h>



char *to_hex(int64_t value)
{
    int64_t st = 1;
    char *s = malloc(sizeof(char)*10);
    strcpy(s,"");
    char *HEX_DIGITS = "0123456789abcdef";

    if(value<0)
    {
        value += (st << 32);  
    }

    while(!(value==0))
    {
        char di[1] = {HEX_DIGITS[ value & 0xf ],'\0'};
        char *temp = strdup(di);    //di getin temp
        //s = d + s;
        strcat(temp,s);
        strcpy(s,temp);

        value >>= 4;
    }

    char *ftemp = strdup(s);
    memset(s,0,sizeof(char)*10);    //reset all character to "".
    strncpy(s,"0x",2);  //copy "0x" add in slot 0-1.
    strncat(s,ftemp,8);
}



int main() 
{
    printf ("%s\n", to_hex(33));
    printf ("%s\n", to_hex(-1));
}
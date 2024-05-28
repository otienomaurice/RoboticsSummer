/******************************************************************************
//SIMPLE C PROGRAM FOR IMPLEMENTING THE MINPRINTF FUNCTION THAT PRINTS VARIABLE ARGUMENTS
//ADAPTED FROM "The C programming Language by Brian Kenaughan"

*******************************************************************************/
#define SIZE 25
#include <stdio.h>
#include <stdarg.h>
void  minprintf( char *this, ...);
int main()
{   char marrow[SIZE] = "Hello, World!";

    minprintf("%s", marrow);

    return 0;
}
void minprintf( char *this, ...){
    char *p, *sval;
    int thisInt;
    float thisFloat;
    
    //create a variable to step through each argument 
    //pa will step through each argument in the list
    va_list pa;
    //set pa to point to the first character
    va_start(pa,this);
    //step through all the characters
   //*p evaluates to true as long as there are characters in the memory location pointed by p
    for( p = this ; *p; ++p){
        if (*p != '%'){
            putchar(*p);
            continue;
        }
        switch (*++p){
            case 'd':
            thisInt = va_arg(pa,int);
            printf("%d",thisInt);
            break;
           
             case 's':
             for(sval = va_arg(pa, char *); *sval; sval++){
                 putchar(*sval);
             }
            break;
            
             case 'f':
             thisFloat = va_arg(pa,double);
             printf("%f",thisFloat);
            break;
        }
            
        }
        va_end(pa);
    }

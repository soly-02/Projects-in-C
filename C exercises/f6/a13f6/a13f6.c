#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void  decompose (long x,int *digits, float *avg, int *max );


main(){

long Number;
int numberOfDigits, maxDigit;
float average;

printf ("Please insert non-negative number: ");
Number = GetInteger();
decompose(Number, &numberOfDigits, &average, &maxDigit);

printf("Digits: %d\n",numberOfDigits);
printf ("Average: %.3f \n", average);
printf ("Max: %d",maxDigit);


}

void  decompose (long x,int *digits, float *avg, int *max ){
int dig;
float av;
int maxx;


dig=0;
maxx=0;
av= 0;
while (x>=1){

    dig++;
    av+= x%10;
    if (x%10>maxx)
        maxx= x%10;
    x=x/10;
}

/*if ()
dig++;
av+=x;
if (x>maxx)
        maxx= x;
        */

*digits= dig;
if (dig!=0)
*avg=av/dig;
else
    *avg=0;
*max= maxx;




}

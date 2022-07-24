/* File Name: a13f3.c
*  Author : Sofia Lypiridou
*--------------------------
* This program calculates the
* sum of the sequence 1/1, 1/2,... + 1/N
*---------------------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>
#include <stdlib.h>

main () {

int limit ;
float sum, counter ;

printf("Dwse orio :");
limit= GetInteger();
sum= 0;


for (counter=1; counter<=limit; counter++ ){

sum = sum + 1/counter ;


}

printf ("To athroisma einai %.2f ", sum );




}

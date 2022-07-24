/* File: afaf3.c
*---------------
*this program demonstrates
*the use of loops
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define CARS 80000
#define RATE 0.07
#define LIMIT 160000

main() {

     long cars;
     int years;

     cars= CARS;
     years=0;

    while(cars <= LIMIT){
        cars= ceil(cars* (1+ RATE));
        years++;

     }

    printf ("%d\n", years);
    printf("%ld\n", cars);


     }

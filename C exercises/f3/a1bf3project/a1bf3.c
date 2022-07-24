/* File: afaf3.c
*---------------
*this program demonstrates
*the use of loops
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>


main() {

     long cars, initialNumberOfCars, limit;
     int years;
     double rate;

     printf("Dwse arxiko arithmo autokinitwn: ");
     initialNumberOfCars= GetLong();
     printf("Dwse ton ethsio rythmo ayxhshs: ");
     rate= GetReal();
     printf("Dwse to orio: ");
     limit= GetLong();


     cars= initialNumberOfCars;
     years=0;

    while(cars <= limit){
        cars= ceil(cars* (1+ rate));
        years++;

     }

    printf ("%d\n", years);
    printf("%ld\n", cars);


     }


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
// oloys toys 1oys apo 0 mexri 1000
main () {

int number;
int i;
int divisors;

printf("Dwse enan arithmo: ");
number= GetInteger();

for (i=1; i<=number; i++) {
    if (number%i==0 )
    divisors++;
}
if (divisors==2)
    printf("Is PRIME \n");
else
    printf("is NOT PRIME\n");




}

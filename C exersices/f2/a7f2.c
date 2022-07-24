/* File name: a7f2.c
*  Author: Sofia Lypiridou
*-------------------------
*  This program demonstrates the use
*of conditionals
*-------------------------
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main() {

long code;
int hours;
double salary, wage, weekly_amount;

printf ("Enter the code: ");
code=GetLong();

if(code>=1000) {
    printf("Enter the yearly salary: ");
    salary= GetReal();
    weekly_amount = salary/52;
}
else {
    printf("Enter the number of hours: ");
    hours= GetInteger();
    printf("Enter the hourly wage: ");
    wage = GetReal();

    if(hours < 40)
       weekly_amount = hours * wage;

    else {
       weekly_amount = (40 * wage)+ (hours - 40) * 1.5 * wage ;
    }
}
printf ("The weekly amount is %g\n", weekly_amount);

}



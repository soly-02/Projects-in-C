/* File Name: a5f1.c
*Author: Sofia Lypiridou
*-----------------------
*This program calculates the gross income,
*the tax money and the final income of a worker
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    int hours;
    long hourlyPay;
    double taxPercent,tax,grossIncome, finalIncome;


    printf("Dwse ton arithmo twn wrwn :");
    hours = GetInteger();
    printf("Dwse thn wriaia antimisthia :");
    hourlyPay = GetLong () ;
    printf ("Dwse to pososto twn kratisewn :");
    taxPercent= GetReal();

    printf("%g\n",taxPercent);

    finalIncome= hours * hourlyPay;
    tax= finalIncome*taxPercent;
    grossIncome = finalIncome+ tax;

    printf("Oi akatharistes apodoxew einai %g\n", grossIncome);
    printf("Oi krathseiw einai %g\n", tax);
    printf("Oi kathares apodoxes einai %g\n", finalIncome);
}


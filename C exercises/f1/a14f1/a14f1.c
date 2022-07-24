/* File name: 14a1f.c
*   Author: Sofia Lypiridou
*---------------------------
*This program calculates the
*calories that a woman who
*lives a sedentary lifestyle
*needs to consume in a day.
*---------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main( ) {


    double baros, ypsos, BMR;
    int hlikia;

    printf( "Dwse varos se kila:\n");
    baros= GetReal();

    printf( "Dwse ypsos se cm:\n");
    ypsos= GetReal();

    printf ("Dwse hlikia se xronia:\n");
    hlikia = GetInteger();

    BMR= 655+ (9.6*baros)+(1.8*ypsos)-(4.7* hlikia);
    printf("To BMR einai %g", BMR);


    return 0;
}


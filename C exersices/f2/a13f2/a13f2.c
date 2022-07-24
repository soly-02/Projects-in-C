/* File Name: a13f2.c
*  Author : Sofia Lypiridou
*--------------------------
*  This program calculates the amount
*  of change given to a customer
*  by a vending machine.
*------------------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main() {
    int cups,money_needed,change ;

    printf (" Enter number of cups of coffee :");
    cups= GetInteger();
    money_needed= cups*70;
    if (money_needed <= 500) {


        change= 500-money_needed;
        printf( "Change:\n");


        printf( "2 euro coins: %d \n",(change/200));
        change= change%200;


        printf( "1 euro coins: %d \n", (change/100));
         change= change%100;


        printf( "50 cent coins: %d \n", change/50);
        change= change%50;


        printf( "20 cent coins: %d \n", change/20);
        change= change%20;


         printf( "10 cent coins: %d \n", change/10);




    }
    else
        printf ("Not enough money for that amount of coffee.");


}

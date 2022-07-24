/* File: a4f1.c
* Author: Sofia Lypiridou
*--------------
*This program calculates the profit
*and the total amount from sale
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){


    //Δήλωση Μεταβλητών
    long purchaseAmount;
    int rate;
    double profit, saleAmount;

   // Είσοδος Δεδομένων
   printf("Dwse thn katharh axia: ");
   purchaseAmount = GetLong();

   printf("Dwse to pososto kerdous: ");
   rate = GetInteger();

   // Επεξεργασία Δεδομένων
   profit = purchaseAmount*(rate/100.0);
   saleAmount = purchaseAmount + profit;

   // Εμφάνιση Αποτελεσμάτων
    printf("To kerdow einai %g\n", profit);
    printf("To synoliko poso einai %g\n", saleAmount);

}

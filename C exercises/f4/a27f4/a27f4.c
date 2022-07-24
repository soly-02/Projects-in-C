
/* File Name: a26f4.c
*  Author: Sofia Lypiridou
*-------------------------
*This program calculates the results
*of some functions.
*-----------------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

long encode(long N);
bool check (EN);

main (){

long Limit1,i, Limit2;


printf("Enter Lower Limit: ");
Limit1= GetInteger();

printf("Enter Upper Limit: ");
Limit2= GetInteger();


for (i=Limit1;i<=Limit2; i++){

    if (check(encode(i))== TRUE)
       printf("Code : %ld Encoding: %ld isValid: Yes.\n",i,encode(i));
       else
        printf("Code : %ld Encoding: %ld isValid: No.\n",i,encode(i));
}
}

long encode(long N){
int digits;

digits= (98-(N*100)%97)%97;
return (N*100+digits);

}

bool check (long EN) {
return (1== EN%97);

}

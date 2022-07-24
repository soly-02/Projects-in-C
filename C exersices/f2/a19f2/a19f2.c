/*File Name: a19f2.c
* Author: Sofia Lypiridou
*------------------------
*This program calculates
*the vehicle registration fees
* based on its CO2 emissions.
*-----------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main(){
    float fee;
    int emissions;
printf("Enter gram CO2/khm :");
emissions= GetInteger();

if (emissions>=0){

    if (emissions<=120)
       fee= emissions*0.9;

    else if (emissions<=140)
       fee= emissions*1.1;

    else if (emissions>140)
       fee= emissions*1.7;

printf("The fee is: %g\n", fee);

}

}


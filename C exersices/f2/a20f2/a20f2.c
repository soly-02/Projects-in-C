/* File Name: a20f2.c
*  Author: Sofia Lypiridou
*-------------------------
* This program prints a day
* based on a number given (1~7)
* (ex.1=Monday, 2=Tuesday etc)
*------------------------------
*/
 #include <stdio.h>
 #include "genlib.h"
 #include "simpio.h"

 main(){
 int number;

 printf("Enter one number from 1 to 7:\n");
 number= GetInteger();

 if (number==1)
    printf("Monday");
 else if (number==2)
   printf("Tuesday");

 else if (number==3)
   printf("Wednesday");

 else if (number==4)
   printf("Thursday");

 else if (number==5)
   printf("Friday");

 else if (number==6)
   printf("Saturday");

 else if (number==7)
   printf("Sunday");

 else
   printf("ERROR");




 }

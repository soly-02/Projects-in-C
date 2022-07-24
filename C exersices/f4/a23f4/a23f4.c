/* File Name: a23f4.c
*  Author: Sofia Lypiridou
*-------------------------
*This program receives 3 numbers
*that represent hours, minutes and seconds
*respectively and prints whether or not
*these numbers are valid.
*------------------------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


bool Valid_Time (int h, int m, int s);


main(){

int hours, minutes, seconds;

printf("Enter the hours : ");
hours= GetInteger();

printf("Enter the minutes : ");
minutes= GetInteger();

printf("Enter the seconds : ");
seconds= GetInteger();

if (Valid_Time(hours,minutes,seconds))
    printf ("THE TIME IS VALID.");

else
    printf ("THE TIME IS NOT VALID.");

}


bool Valid_Time (int h,  int m, int s){

return (h>=0 && h<=23 && m>=0 && m<=59 && s>=0 && s<=59);


}

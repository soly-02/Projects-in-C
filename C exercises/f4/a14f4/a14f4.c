/* File Name: a14f4.c
*  Author: Sofia Lypiridou
*-------------------------
*This program calculates the
*value of a function.
----------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

double max(double a, double b);
double gr (double a, double b, double c);

main (){

double y,a, b, c;

printf("Dwse a: ");
a= GetInteger();

printf("Dwse b: ");
b= GetInteger();

printf("Dwse c: ");
c= GetInteger();

y= (2*max(a,b)+3*gr(a,b,c))/4;

printf("y= %.2f",y);

}

double max(double a, double b){
if (a>b)
    return a;
    return b;

}

double gr(double a, double b, double c){
double max1;
max1=a;
if (max1<b)
    max1=b;
if (max1<c)
   max1=c;
return max1;
}

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

int g(int x, int y), f(int x);

main (){

int x, y;

printf("Enter x: ");
x= GetInteger();

printf("Enter y: ");
y= GetInteger();

printf ("f(x)= f(%d)= %d\n", x, f(x));
printf ("g(x,y)= g(%d,%d)= %d\n", x , y, g(x,y));
printf ("f(g(x,y))= f(g(%d,%d))= %d\n", x , y, f(g(x,y)));


}

int f(int x){

if (x>0)
    return (x+2);
return (-3*x+7);
}

int g(int x, int y){
if (x>0 && y>0)
 return (x-y);
return (7*x-5);

}

#include <stdio.h>
#include "genlib.h"
#include <math.h>
#include "simpio.h"

main(){

double A[5];
double apost[4];
int i;

for (i=0;i<5;i++){
    printf("Enter number (%d) :",i);
    A[i]=GetReal();
}
for (i=0;i<4;i++)
    apost[i]= fabs(A[i+1]-A[i]);

    printf("%.2f  %.2f  %.2f  %.2f  %.2f\n",A[0], A[1],A[2],A[3],A[4]);
     printf("%.2f  %.2f  %.2f  %.2f", apost[0],apost[1],apost[2],apost[3]);



}



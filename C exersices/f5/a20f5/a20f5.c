#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main () {
int A[5],i,temp1,temp2;
for (i=0;i<5;i++){
printf("Enter number : ");
A[i]= GetInteger();

}
temp1=A[1];
A[1]=A[0];
temp2=A[2];
A[2]=temp1;
temp1=A[3];
A[3]=temp2;
temp2=A[4];
A[4]=temp1;
A[0]=temp2;

for (i=0;i<5;i++)
 printf("%d ",A[i]);


}

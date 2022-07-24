/* File Name: a29f4.c
*  Author: Sofia Lypiridou
--------------------------
*This program the values of
*Euler's function.
*/

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int gcd(int x,int i);
bool coprime (int i,int j);
int phi(int i);

main(){
    int x,i;

printf("Enter X: ");
x=GetInteger();

for (i=1; i<=x;i++){

    printf("phi(%d) = %d\n", i,phi(i));
}
}

int gcd(int i,int j){
    int c;
while (j!=0){
        c=i;
    i=j;
    j=c%j;
}
    return i;
}

bool coprime(int i,int j){

 if (gcd(i,j)==1)
    return TRUE;
    return FALSE;
}



int phi (int i){
    int j,c;
    c=0;
for (j=1; j<=i; j++){
            if (coprime(i,j)== TRUE)
              c++;
}
              return c;
}



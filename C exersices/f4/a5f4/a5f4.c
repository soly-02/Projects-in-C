
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

//Πρωτότυπα συναρτήσεων
int sumCube (int num);
bool isArmstrong (int num);
int cube(int num);



main() {

   int i;

 for (i=1; i<=999; i++)
     if (isArmstrong(i))
        printf("%d\n",i);
}


int sumCube (int num){

int sum,dig1, dig2, dig3 ;

dig1=num %10;
dig2=(num%100)/10;
dig3= num/100;

sum= cube(dig1)+ cube(dig2)+ cube (dig3);




}

bool isArmstrong(int num) {

return (sumCube (num)==num);




}

int cube(int num) {

int prod, i;

prod=1;
for (i=0; i<3; i++){
 prod*= num;
}

return prod;



}

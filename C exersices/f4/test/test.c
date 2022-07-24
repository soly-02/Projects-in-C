#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

//πρωτότυπο συνάρτησης
int addTwo();


main () {



int n1, n2;
int result;

printf("Enter the first number: ");
n1=GetInteger();


printf("Enter the second number: ");
n2=GetInteger();

result = addTwo(n1, n2); //κλήση συνάρτησης

printf ("the sum is %d\n", result);

}

//ορισμ'ος συνάρτησης

int addTwo (int number1, int number2) {

int result;

result= number1+number2;

return result;


}

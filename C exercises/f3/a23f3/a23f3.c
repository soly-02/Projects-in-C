/* File Name: a20f3.c
*  Author : Sofia Lypiridou
*--------------------------
* This program receives a number
* and prints its ascending sequence
* with 2 as a step , starting from 1 if
* the number is odd and 0 if it
* is not.
*--------------------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main () {

int number, sequence;

 printf ("Enter number : ");
 number = GetInteger ();

 for (sequence= number%2; sequence<=number; sequence=sequence +2) {
    printf("%d ", sequence);

}


}

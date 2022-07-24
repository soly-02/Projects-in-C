/* File Name: a20f3.c
*  Author : Sofia Lypiridou
*--------------------------
* This program receives numbers
* that represent ages and prints
* the highest and the lowest one.
*--------------------------------
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main () {

int age, min , max ;


     printf ("Dwse ilikia : ");
     age= GetInteger ();
     min= age;
     max=age;

     while( age !=-1) {

            if (age> max)
               max= age ;
            if (age<min && age!=-1)
               min=age;
            printf ("Dwse ilikia : ");
            age= GetInteger ();
       }

     printf ("H megalyteri ilikia : %d\n", max);
     printf ("H mikroteri ilikia : %d", min);


}

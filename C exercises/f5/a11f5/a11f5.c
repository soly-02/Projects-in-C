/*File: a11f5.c
*--------------
* Demonstration of arrays
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>


#define CTS 10
#define S 3


main() {

double temper[CTS][S];

double natavg,devNat[CTS][S],maxDev[CTS], cityAvg[CTS];
int i,j;

// Input reading
for (i=0;i<CTS;i++)
  for (j=0;j<S;j++){
        printf("Enter temperature of city %d, period %d : ",i,j);
        temper[i][j]= GetReal();
}



/* Calculation of average of all cities-Periods*/
natavg=0;
for (i=0;i<CTS;i++){
    for (j=0;j<S;j++){
        natavg+= temper[i][j];
    }
}
natavg= natavg/(CTS*S);

// Calculation of city average

for (i=0;i<CTS;i++){
    cityAvg[i]=0;
    for (j=0; j<S; j++){
        cityAvg[i]+= temper[i][j];
    }
    cityAvg[i]= cityAvg[i]/S;
}

//Calculation of deviations from national average
for (i=0;i<CTS;i++)
for (j=0;j<S;j++)
    devNat[i][j]=fabs(temper[i][j]-natavg);

//Calculation of max city deviations.
for (i=0;i<CTS;i++){
    maxDev[i]=devNat[i][0];
for (j=1;j<S;j++){
    if (maxDev[i]<devNat[i][j])
       maxDev[i]=devNat[i][j];
}
}


// Printing of Results
printf("%3.1f\n", natavg);
for (i=0;i<CTS;i++)
    printf("City %d   %3.1f   %.1f\n", i, cityAvg[i], maxDev[i]);




    }



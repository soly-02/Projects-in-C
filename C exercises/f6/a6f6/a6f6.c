#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#define N 5
void readData (int A[N][4]);
void FindMean(int A[N][4],float* a,float* g,int n);


main (){
int A[N][4];
float a,g;

readData(A);

FindMean(A,&a,&g,1);

printf("Mesos oros barous andrwn: %.1f\n",a);
printf("Mesos oros barous gynaikwn:%.1f\n\n",g);

FindMean(A,&a,&g,2);
printf("Mesos oros ypsous andrwn: %.1f\n",a);
printf("Mesos oros ypsous gynaikwn: %.1f\n\n",g);

FindMean(A,&a,&g,3);
printf("Mesos oros ilikias andrwn: %.1f\n",a);
printf("Mesos oros ilikias gynaikwn: %.1f\n\n",g);


}


void readData (int A[N][4]){
int i;
for (i=0;i<N;i++){

    printf ("Dwse fylo: ");
    A[i][0]=GetInteger();
    printf ("Dwse baros: ");
    A[i][1]=GetInteger();
    printf ("Dwse ypsos: ");
    A[i][2]=GetInteger();
    printf ("Dwse ilikia: ");
    A[i][3]=GetInteger();
    printf ("-----\n");

}

}
void FindMean(int A[N][4],float* a,float* g, int n){
int i;
int suma,ma;
int sumg,mg;
suma=0;
sumg=0;
ma=0;
mg=0;
for (i=0;i<N;i++){

        if (A[i][0]==0){
          suma+=A[i][n];
          ma++;
        }
        else if (A[i][0]==1) {
          sumg+= A[i][n];
          mg++;
        }
}
if (ma!=0)
*a= (float)suma / (float)ma;
else
    *a=0;


if (mg!=0)
*g= (float)sumg / (float)mg;
else
*g=0;


}

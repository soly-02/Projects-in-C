#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>
#define C 50
void populate (int a[C]);
void printArr (int a[C],int n);
int checkTable(int a[C],int n);

main (){
int times,a[C],num;

populate (a);
printArr(a,C);
printf("Dwse arithmo apo to 0 ews to 9 : ");
num=GetInteger();
times= checkTable(a,num);
printf("O Arithmos %d emfanizetai %d fores.\n", num,times);
printf("Stis Theseis: \n");
printArr(a,times);
}


void populate (int a[C]){
    int i;
for (i=0;i<C;i++)
    a[i]=rand() % 10;

}
void printArr (int a[C],int n){
int i;
for (i=0;i<n;i++)
    printf("%3d ",a[i]);
printf("\n--------------\n");

}


int checkTable(int a[C],int n){
int c,i;
c=-1;
for (i=0;i<C;i++){
    if (a[i]==n){
        c++;
        a[c]=i;
    }

}

return c+1;


}

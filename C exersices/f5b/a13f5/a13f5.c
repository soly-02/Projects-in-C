#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>

void populate_data(int A[10][10],int R,int C);
void print_array(int A[10][10],int R,int C);
void change_array(int A[10][10],int R,int C);




main(){

int R,C, A[10][10];

printf("Dwse arithmo twn grammwn : ");
R= GetInteger();
printf("Dwse arithmo twn sthlwn : ");
C= GetInteger();

populate_data(A,R,C);
printf("ARXIKOS PINAKAS \n");
print_array(A,R,C);
change_array(A,R,C);
printf("ALLAGMENOS PINAKAS \n");
print_array(A,R,C);
}

void populate_data(int A[10][10], int R, int C){
    int i,j;
for (i=0;i<R;i++)
   for (j=0;j<C;j++)
        A[i][j]= (rand()%100);

}
void print_array(int A[10][10],int R,int C){
int i,j;

for (i=0;i<R;i++){
   for (j=0;j<C;j++)
        printf("%2d ",A[i][j] );
   printf("\n");
}
}

void change_array(int A[10][10],int R,int C){
int i,j,max,pos;

for (i=0;i<R;i++){
  max= A[i][1];

  for (j=0;j<C;j++)
      if (A[i][j]>max)
         max=A[i][j];

  j=0;
  while (A[i][j]<max){
    A[i][j]=max;
    j++;
  }





  }



}







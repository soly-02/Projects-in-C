#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int Get_Array(int A[100]);
void max_min_Array(int size, int array[size],int* Max,int* Min);



main(){


int A[100],c;

int max;
int min;
printf("Enter the elements of the array, one per line.\n");
printf("Use -1 to signal the end of the list.\n");
c= Get_Array(A);

max_min_Array(c,A, &max, &min);

printf("The range of values is %d-%d", min,max);



}

int Get_Array(int A[100]){
    int i;
i=0;
printf ("?");
A[i]=GetInteger();
while (A[i]!=-1){
    i++;
    printf("?");
    A[i]= GetInteger();

}

return i-1;
}


void max_min_Array(int size, int array[size],int* Max,int* Min){
int i;
*Max = array[0];
*Min = array[0];
for (i=1;i<=size;i++){
    if (array[i]>*Max)
       *Max= array[i];
    if (array[i]< *Min)
        *Min= array[i];
}
}

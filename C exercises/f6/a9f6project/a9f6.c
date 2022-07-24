#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define SALESMEN 4
#define PRODUCTS 5

void calculateSales(int s, int p,int sales[s][p],int price[p],int salesPerson[s]);
void calculateProductSales(int s,int p,int productSale[p],int sales[s][p]);
void maxArray(int size, int array[size],int* pMaxValue,int* pPosition);
void printArray(int size, int array[]);

int main () {
  int sales[SALESMEN][PRODUCTS]={{10,4,5,6,7},
                                 {7,0,12,1,3},
                                 {4,19,5,0,8},
                                 {3,2,1,5,6}
                                };
  int price []= {250,150,320,210,920};

  int salesPerson [SALESMEN]; // pinakas me pwliseis ka8e pwliti
  int productSale[PRODUCTS]; //pinakas me ta temaxia poy pwli8ikan apo ka8e pwliti
  int maxSalesman, maxProduct;
  int income,items;



  calculateSales(SALESMEN,PRODUCTS,sales,price,salesPerson);

  calculateProductSales(SALESMEN,PRODUCTS,productSale, sales);

  maxArray(SALESMEN, salesPerson, &income , &maxSalesman);

  maxArray(PRODUCTS, productSale,&items, &maxProduct);

  printf("Sales by Salesman: \n");

  printArray (SALESMEN,salesPerson);

  printf("Best Salesman was %d with  %d sales \n",maxSalesman, income);

  printf("Items of each product: \n");
  printArray(PRODUCTS, productSale);
  printf ("Best product is %d with %d items \n", maxProduct, items);

return 0;

}

void calculateSales(int s, int p,int sales[s][p],int price[p],int salesPerson[s]){
int i,j;

for (i=0;i<s;i++){
        salesPerson[i]=0;
    for (j=0;j<p; j++)
        salesPerson[i]+= sales[i][j]* price[j];

}
}

void calculateProductSales(int s,int p,int productSale[p],int sales[s][p]){
 int i,j;

  for (i=0;i<p;i++){
    productSale[i]=0;
    for (j=0;j<s;j++)
      productSale[i]+=sales[j][i];
  }
}

void maxArray(int size, int array[size],int* pMaxValue,int* pPosition){
int maxValue;
int pos;
int i;

maxValue= array[0];
pos= 0;
for (i=0;i<size;i++){
    if (array[i]>maxValue){
        maxValue= array[i];
        pos= i;
    }
}
*pMaxValue= maxValue;
*pPosition= pos;

}

void printArray(int size, int array[]){
int i;
for (i=0;i<size;i++)
    printf ("   %d    %d\n",i, array[i]);


}

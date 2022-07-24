#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

#define RENTS 20


typedef struct {

 int number;
 char type[20];
 int cc;
 char name [20];
 int days;
 float daily_rate;
 float total_charge;

} car_rentalT;

typedef struct{

 char type [20];
 int cc;
 float amount;

}best_carT;


int getData(car_rentalT rentals[]);
float calcTotals ( car_rentalT rentals[],int numRentals);
best_carT findBest(car_rentalT rentals[],int numRentals);
void printData (car_rentalT rentals[],int numRentals,int total,best_carT best);

int main (){

car_rentalT rentals [RENTS];
int numRentals;
float total;
best_carT bestCar;

numRentals=getData(rentals);
total = calcTotals(rentals, numRentals);
bestCar= findBest(rentals, numRentals);
printData(rentals,numRentals,total,bestCar);



return 0;
}



int getData(car_rentalT rentals[]){
  int i, numRentals;

  printf("Dose ton arithmo twn enoikiasewn : ");
  numRentals = GetInteger();

  for (i=0; i<numRentals; i++){

    printf ("\nDose ta stoixeia tis enoikiasis %d: \n",i);
    rentals[i].number = i;

    printf("Dose marka : ");
    gets (rentals[i].type);

    printf("Dose kivika : ");
    rentals[i].cc = GetInteger();

    printf("Dose onoma pelati : ");
    gets (rentals[i].name);

    printf ("Dose imeres enoikiasis :");
    rentals[i].days = GetInteger();

    printf ("Dose timi ana imera : ");
    rentals[i].daily_rate=GetReal();


  }

return numRentals;

}


float calcTotals ( car_rentalT rentals[],int numRentals){


 int i;
 float total=0;

 for (i=0;i<numRentals; i++){

    rentals[i].total_charge= rentals[i].daily_rate * rentals[i].days;
    total += rentals[i].total_charge;

 }
return total;
}

best_carT findBest(car_rentalT rentals[],int numRentals){

     int i,max;
     best_carT best;

     strcpy (best.type, rentals[0].type);
     best.cc= rentals[0].cc;
     best.amount=rentals[0].total_charge;

     for (i=1;i<numRentals;i++){
        if (best.amount< rentals[i].total_charge){
            strcpy (best.type, rentals[i].type);
            best.cc= rentals[i].cc;
            best.amount=rentals[i].total_charge;
        }
     }

return best;

}


void printData (car_rentalT rentals[],int numRentals,int total,best_carT best){

   int i;

   printf("\n\n");
   printf("%-7s %-20s %-10s %-5s %-5s %-6s %-8s\n",
          "Number", "Name","Type","CC","Days","Price","Total");

   for (i=0;i<73;i++)
    printf ("-");
   printf("\n");

   for (i=0; i<numRentals; i++){
    printf("%-7d %-20s %-10s %-5d %-5d %-6.2f %-8.2f\n",
    rentals[i].number,
    rentals[i].name,
    rentals[i].type,
    rentals[i].cc,
    rentals[i].days,
    rentals[i].daily_rate,
    rentals[i].total_charge);


   }
   for (i=0;i<73;i++)
    printf ("-");
   printf("\n");

   printf ("%58s %-8.2f\n","Total",total);
   printf("Best car: %s  %d rented for %.2f Euros\n",best.type,best.cc,best.amount);

}

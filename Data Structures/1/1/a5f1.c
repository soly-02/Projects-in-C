#define maxP 1001         //μέγιστο πλήθος στοιχείων συνόλου
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[maxP];
typedef int stoixeio_synolou;


boolean isFibonacci(stoixeio_synolou n,typos_synolou setF);
void createFibonacciSet(stoixeio_synolou threshold,typos_synolou setF);
void displayset(typos_synolou set);

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < maxP; i++)
        synolo[i] = FALSE;
}


void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}


int main(){

stoixeio_synolou max,check;
typos_synolou setF;
do{
printf("Dwse to megistoarithmo :");
scanf("%d",&max);
} while (max<2 || max>1000);

createFibonacciSet( max, setF);
displayset(setF);

do{
printf("Enter number to check:");
scanf("%d",&check);
if (check>=0){
    if (Melos(check,setF)==TRUE)
        printf("Fibonacci!\n");
    else
        printf("Not Fibonacci...\n");

}
}while (check>=0);

return 0;
}



boolean isFibonacci(stoixeio_synolou n,typos_synolou setF){


return Melos(n,setF);

}

void createFibonacciSet(stoixeio_synolou threshold,typos_synolou setF){
int i,done,a[2];

Dimiourgia(setF);
a[0]=0;
a[1]=1;
Eisagogi(0,setF);
Eisagogi(1,setF);
done=0;
do{
    if (a[1]+ a[0]<= threshold){
    a[0]+=a[1];
    Eisagogi(a[0],setF);

    }
     else
        done=1;
    if (a[1]+ a[0]<= threshold){
    a[1]+=a[0];
    Eisagogi(a[1],setF);

    }else
      done=1;

}while( done==0);


}


void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < maxP ;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}


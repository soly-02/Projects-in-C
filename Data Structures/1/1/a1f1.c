#define megisto_plithos 201        //μέγιστο πλήθος στοιχείων συνόλου
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;


boolean isPrime (stoixeio_synolou n);
void createPrimeSet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou primeSet);
void displaySet(typos_synolou primeSet, stoixeio_synolou first,stoixeio_synolou last);

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);


void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
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
stoixeio_synolou first,last;

do{
        do{
    printf("Enter first number :");
    scanf("%d",&first);
        }while ((first<2 || first>200));

        do{
    printf("Enter last number :");
    scanf("%d",&last);
        }while (last<2 || last>200);

} while ( first>last);

typos_synolou primeSet;
createPrimeSet(first,last,primeSet);
displaySet(primeSet,first,last);


return 0;
}


boolean isPrime (stoixeio_synolou n){

stoixeio_synolou i;

for (i=2;i<= n/2;i++)
    if (n%i==0)
     return FALSE;
return TRUE;

}

void createPrimeSet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou primeSet){
stoixeio_synolou i;

Dimiourgia(primeSet);

for (i=first; i<=last;i++)
  if (isPrime(i)==TRUE)
    Eisagogi(i,primeSet);

}

void displaySet(typos_synolou primeSet, stoixeio_synolou first,stoixeio_synolou last){
stoixeio_synolou i;

for (i=first; i<=last;i++)
    if (primeSet[i]==TRUE)
        printf("%d ",i);




}

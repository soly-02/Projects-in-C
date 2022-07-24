#define QueueLimit 10  //το όριο μεγέθους της ουράς
#include <stdio.h>

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void TraverseQ(QueueType Queue);
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count= 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Count) ==  QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue -> Count = (Queue -> Count) -1;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue -> Count= (Queue -> Count)+1;
	}
	else
		printf("Full Queue\n");
}

void TraverseQ(QueueType Queue) {
	int i,current;
	 printf("Queue: ");
	if(EmptyQ(Queue))
    {
        printf("Empty Queue");
    }
	else {
       current=Queue.Front;
       for (i=0;i<Queue.Count;i++){
          printf("%d ", Queue.Element[current]);
          current = (current + 1) % QueueLimit;
       }


	}
	printf("\n");
}





int main(){

QueueType Queue;
QueueElementType i,item;

CreateQ(&Queue);

//a
printf("---a---\n");
for (i=0;i<10;i++)
    AddQ(&Queue,i);
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

//b
printf("---b---\n");
AddQ(&Queue,666);
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

//c
printf("---c---\n");
RemoveQ(&Queue,&item);
TraverseQ(Queue);
printf("Removed Item=%d Front=%d Rear=%d Count=%d\n",item,Queue.Front,Queue.Rear,Queue.Count);


//d
printf("---d---\n");

AddQ(&Queue,666);
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

//e

printf("---e---\n");

AddQ(&Queue,666);
TraverseQ(Queue);
printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

//f
printf("---f---\n");

while (!EmptyQ(Queue)){
    RemoveQ(&Queue,&item);
TraverseQ(Queue);
printf("Removed Item=%d Front=%d Rear=%d Count=%d\n",item,Queue.Front,Queue.Rear,Queue.Count);


}



return 0;
}



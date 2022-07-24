
/* Queue */
#include <stdio.h>
#define QueueLimit 4  //το όριο μεγέθους της ουράς




typedef struct{
int arrival;
int stay;
int start;
int end;
  }QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
QueueType TimesInQueue(QueueType *Queue);
void ReadCustomer (QueueType *Queue);
void TraverseQ(char s[], QueueType Queue);

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
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
	}
	else
		printf("Full Queue");
}



int main(){
int i;
QueueType WaitingQueue,ServiceQueue;
CreateQ(&WaitingQueue);
for (i=1;i<QueueLimit;i++)
    ReadCustomer (&WaitingQueue);
TraverseQ("Waiting Queue",WaitingQueue);
ServiceQueue= TimesInQueue(&WaitingQueue);
TraverseQ("Waiting Queue",WaitingQueue);
TraverseQ("Service Queue",ServiceQueue);

return 0;
}

void ReadCustomer (QueueType *Queue){
int af,an;
printf("Give: arrival time,stay time for client:");
QueueElementType fn;
scanf("%d,%d",&af,&an);
fn.arrival= af;
fn.stay=an;
fn.end=-1;
fn.start=-1;
AddQ(Queue,fn);

}

void TraverseQ(char s[], QueueType Queue){
int current;
int i=0;

if (!EmptyQ(Queue)){
    printf ("%s\n",s);
    current = Queue.Front;
    printf("Client \t\t\tStart\tEnd\tArrival\tStay\n");
    while (current != Queue.Rear) {
            printf("Client %d\t\t%d\t%d\t%d\t%d\n",i+1,Queue.Element[i].start,Queue.Element[i].end,Queue.Element[i].arrival,Queue.Element[i].stay);
           current = (current + 1) % QueueLimit;
             i++;



}


}
else
printf ("%s is empty",s);

printf ("\n");

}

QueueType TimesInQueue(QueueType *Queue){
int earliestStart =0; //χρόνος έναρξης εξυπηρέτησης
int currentStart=0; //ώρα έναρξης εξυπηρέτησης για τρέχοντα πελάτη
int currentEnd=0;
QueueType QueueServiced;
QueueElementType CurrentCust;
CreateQ(&QueueServiced);
while (!EmptyQ(*Queue)){
    RemoveQ(Queue,&CurrentCust);
    if (CurrentCust.arrival>earliestStart)
       currentStart=CurrentCust.arrival;
       else
         currentStart=earliestStart;

         currentEnd=currentStart+CurrentCust.stay;
         earliestStart=currentEnd;
  CurrentCust.start=currentStart;
  CurrentCust.end=currentEnd;
  AddQ(&QueueServiced,CurrentCust);

}

return QueueServiced;


}


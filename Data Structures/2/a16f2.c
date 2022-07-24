#define StackLimit 50   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50

typedef struct  {
int Timi;
char Megethos;
} Fanelaki;

typedef Fanelaki StackElementType;   // ο τύπος των στοιχείων  της στοίβας
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;






typedef enum {
    FALSE, TRUE
} boolean;

void TraverseStack(StackType Stack);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

#include <stdio.h>


void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{

    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack){

  int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c, %d \n",Stack.Element[i].Megethos,Stack.Element[i].Timi);
    }
    printf("\n");


}






int main(){

int no,i,p,size,price;
char s;
Fanelaki f;
StackType Box,OutBox;
CreateStack(&Box);
CreateStack(&OutBox);


// (1)
printf("Give number of items ");
scanf("%d",&no);

//(2)
printf("Give the items to store\n");


for(i=0;i<no;i++){

printf("Give price ");
scanf("%d",&p);

printf("Give size ");
scanf(" %c",&s);

f.Megethos=s;
f.Timi=p;

Push(&Box,f);
}
printf("Items in the box");

//(3)
 TraverseStack(Box);



// (4)
printf("What size do you want? ");
scanf( " %c",&s);
i=1;

    while (EmptyStack(Box)==FALSE && i==1){

        Pop(&Box,&f);

        if (f.Megethos != s){
        Push(&OutBox,f);

        }
        else
            i=0;

    }





if (i==1)
printf("Not Found the size %c\n\n",s);
else
printf("Found the size %c\n\n",s);

//(5)

printf("Items in the box");
TraverseStack(Box);

printf("Items out of the box");
TraverseStack(OutBox);

//(6)

while (EmptyStack(OutBox)==FALSE ){

        Pop(&OutBox,&f);
        Push(&Box,f);

        }

// (7)

printf("Items in the box");
TraverseStack(Box);

printf("Items out of the box");
TraverseStack(OutBox);



return 0;
}



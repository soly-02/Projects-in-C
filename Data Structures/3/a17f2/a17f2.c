#include <stdio.h>
#include <stdlib.h>



// FILENAME StackADT.h
                    /* ΥΛΟΠΟΙΗΣΗ ΣΤΟΙΒΑΣ ΜΕ ΠΙΝΑΚΑ *
              *ΤΑ ΣΤΟΙΧΕΙΑ ΤΗΣ ΣΤΟΙΒΑΣ ΕΙΝΑΙ ΤΥΠΟΥ int */

#define StackLimit 20   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50


typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
StackType CopyStack(StackType *s1);


void TraverseStack(StackType Stack);


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




int main()
{
    StackType s1,s2;
    int i;
    CreateStack(&s1);
    for (i=0;i<20;i++)
        Push(&s1,i);
     printf("Stack s1");
     TraverseStack(s1);
     s2= CopyStack(&s1);
     printf("After copying s1 to s2\n");
     printf("Stack s1");
     TraverseStack(s1);
     printf("Stack s2");
     TraverseStack(s2);

    return 0;
}





 void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
}


StackType CopyStack(StackType *s1){
StackType s2,tempS;
StackElementType a;
CreateStack(&s2);
CreateStack(&tempS);
while (!EmptyStack(*s1)){
    Pop (&*s1,&a);
    Push(&tempS,a);

}
while (!EmptyStack(tempS)){
    Pop(&tempS,&a);
    Push(&*s1,a);
    Push(&s2,a);


}
return s2;

}

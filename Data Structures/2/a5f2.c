
#define StackLimit 15   // το όριο μεγέθους της στοίβας, ενδεικτικά ίσο με 50


typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int
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


void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

int main(){
int i;
StackType Stack,Help;
StackElementType n,x,c;

CreateStack(&Stack);
for (i=0;i<15;i++)
    Push(&Stack,i*10);

CreateStack(&Help);

TraverseStack(Stack);

printf("Give nth element(n<=6): ");
scanf("%d",&n);


// (a)
for (i=1;i<=2;i++)
Pop(&Stack,&x);


printf("\nQuestion a: x=%d",x);
TraverseStack(Stack);

// (b)
for (i=1;i<=2;i++){
Pop (&Stack,&x);
Push(&Help,x);
}


printf("\nQuestion b: x=%d",x);
for (i=1;i<=2;i++){
Pop (&Help,&x);
Push(&Stack,x);
}
TraverseStack(Stack);

//(c)
for (i=1;i<=n;i++)
Pop(&Stack,&x);

printf("\nQuestion c: x=%d",x);
TraverseStack(Stack);

//(d)
for (i=1;i<=n;i++){
Pop (&Stack,&x);
Push(&Help,x);
}


printf("\nQuestion d: x=%d",x);
for (i=1;i<=n;i++){
Pop (&Help,&x);
Push(&Stack,x);
}
TraverseStack(Stack);

//(e)
for (i=1;i<=15-n-2;i++){
Pop (&Stack,&x);
Push(&Help,x);
}


printf("\nQuestion e: x=%d",x);
for (i=1;i<=15-n-2;i++){
Pop (&Help,&x);
Push(&Stack,x);
}
TraverseStack(Stack);

//(f)
for (i=1;i<=11-n;i++){
Pop (&Stack,&x);
Push(&Help,x);
}


printf("\nQuestion f: x=%d",x);
for (i=1;i<=15-n-4;i++){
Pop (&Help,&x);
Push(&Stack,x);
}
TraverseStack(Stack);

//(g)
c=n+2;
for (i=0;i<15-c;i++)
 Pop(&Stack,&x);

 printf("\nQuestion g: x=%d",x);
TraverseStack(Stack);

return 0;
}


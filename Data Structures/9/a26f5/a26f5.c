#include <stdio.h>
#include <stdlib.h>

typedef struct{
int AM;
int Rec;
} BinTreeElementType;             /*ο τύπος των στοιχείων του ΔΔΑ

          ενδεικτικά τύπου int */

typedef struct{
int AM;
char LN[20];
char FN[20];
char SEX;
int YEAR;
float MO;
}studEND;



typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);
int BuildBST(BinTreePointer *Root);
void PrintStudent(int RecNum);
void printStudentsWithGrade(float theGrade);
void writeNewStudents(BinTreePointer *Root, int *size);



void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item.AM < (*Root) ->Data.AM)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item.AM > (*Root) ->Data.AM)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.AM < Root->Data.AM)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.AM > Root->Data.AM)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ΑΔΕΙΟ ΔΕΝΔΡΟ ΤΟ KeyValue ΔΕ ΘΑ ΒΡΕΘΕΙ *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //* αναζήτησε αναδρομικά τον κόμβο που περιέχει την τιμή KeyValue και διάγραψέ τον
          if (KeyValue.AM < (*Root)->Data.AM)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΔΡΟ *
          else
            if (KeyValue.AM > (*Root)->Data.AM)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ΔΕΞΙ  ΥΠΟΔΕΝΔΡΟ *
            else                                       //* TO KeyValue ΒΡΕΘΗΚΕ ΔΙΑΓΡΑΦΗ ΤΟΥ ΚΟΜΒΟΥ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ΔΕΝ ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ, ΑΛΛΑ ΟΧΙ ΔΕΞΙ *)
                        free(TempPtr);
                   }
                   else                               //* ΕΧΕΙ 2 ΠΑΙΔΙΑ *)
                   {
                        //* ΕΥΡΕΣΗ ΤΟΥ INORDER ΑΠΟΓΟΝΟΥ ΤΟΥ *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ΜΕΤΑΚΙΝΗΣΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΤΗς ΡΙΖΑΣ ΤΟΥ ΥΠΟΔΕΝΔΡΟΥ
                        ΠΟΥ ΕΞΕΤΑΖΕΤΑΙ ΚΑΙ ΔΙΑΓΡΑΦΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΚΟΜΒΟΥ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("(%d,%d),",Root->Data.AM,Root->Data.Rec);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }

   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί προδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        printf("%d ",Root->Data);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί μεταδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data);
    }
   // printf("U");
}

int main(){

BinTreePointer ARoot,LocPtr;
int size;
boolean found;
BinTreeElementType indexRec;
float theGrade;

//--1--
printf("Q1. Build BST from a file\n");
size= BuildBST(&ARoot);

//--2--
printf("Q2. Print size and BST\n");
printf("Size=%d\n",size);
printf("Nodes of BST\n");

RecBSTInorder(ARoot);

//--3--
printf("\nQ3. Write new students, update file and BST\n");
writeNewStudents(&ARoot,&size);

//--4--
printf("Q4. Print size and BST\n");
printf("Size=%d\n",size);
printf("Nodes of BST\n");
RecBSTInorder(ARoot);

//--5--
printf("\nQ5. Search for a student\n");
printf("Give student's code?");
scanf("%d",&indexRec.AM);
RecBSTSearch(ARoot,indexRec,&found,&LocPtr);
if (found){
    PrintStudent(LocPtr->Data.Rec);
}
else
    printf("NOT FOUND");


//--6--
printf("Q6. Print size and BST\n");
printf("Size=%d\n",size);
printf("Nodes of BST\n");
RecBSTInorder(ARoot);

//--7--
printf("\nQ7. Print students with grades >= given grade\n");
printf("Give the grade: ");
scanf("%f",&theGrade);
printStudentsWithGrade(theGrade);

return 0;
}

int BuildBST(BinTreePointer *Root){
FILE* fp;
int nscan;
char termch;
int size=0;
BinTreeElementType indexRec;
studEND student;




CreateBST(&*Root);

fp = fopen("foitites.dat", "r");
if (fp!=NULL){
    while(TRUE) {
        nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",
                     &student.AM,student.LN,student.FN,&student.SEX,&student.YEAR,&student.MO,&termch);


        if (nscan==EOF)
            break;
        if (nscan!=7 || termch!='\n')
            printf("ERROR\n");
        else{
            indexRec.AM=student.AM;
            indexRec.Rec=size;
            RecBSTInsert(&*Root,indexRec);
            size++;
        }
    }
    fclose(fp);
    return size;
}
}

void writeNewStudents(BinTreePointer *Root, int *size){
FILE* fp;
BinTreeElementType indexRec;
studEND student;
boolean found;
BinTreePointer LocPtr;
char ar;
int ss=*size;

fp = fopen("foitites.dat", "a");
if (fp!=NULL){

      do{

            printf("Give student's AM?");
            scanf("%d",&indexRec.AM);
            RecBSTSearch(*Root,indexRec,&found,&LocPtr);

            if (!found){
                student.AM=indexRec.AM;
               printf("Give student surname?");
               scanf("%s",&student.LN);
               printf("Give student name?");
               scanf("%s",&student.FN);
               printf("Give student sex F/M?");
               scanf("%s",&student.SEX);
               printf("Give student's registration year?");
               scanf("%d",&student.YEAR);
               printf("Give student grade?");
               scanf("%f",&student.MO);
               ss++;
               printf("Size=%d\n\n",ss);
               indexRec.Rec=ss-1;
               RecBSTInsert(&*Root,indexRec);
               fprintf(fp,"%d,%s,%s,%c,%d,%.1f\n",
                     student.AM,student.FN,student.LN,student.SEX,student.YEAR,student.MO);
            }
            else
                printf("O AM yparxei idi sto arxeio");



      printf("Continue Y/N: ");
            do{
                    scanf("%s",&ar);

            }while(ar!='y' && ar!='Y' && ar!='N' && ar!='n');


    }while(ar!='n' && ar!='N');
    fclose(fp);
    *(size)=ss;
}


}

void PrintStudent(int recNum){
FILE* fp;
int nscan;
char termch;
int lines;
BinTreeElementType indexRec;
studEND student;
fp = fopen("foitites.dat", "r");
lines=0;

if (fp!=NULL){
    while(lines< recNum+1) {
        nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",
                     &student.AM,student.FN,student.LN,&student.SEX,&student.YEAR,&student.MO,&termch);
         if (nscan==EOF)
            break;
        if (nscan!=7 || termch!='\n')
            printf("ERROR\n");

        lines++;
    }
    if (lines==recNum+1){

    printf("%d,%s,%s,%c,%d,%.1f\n",
                     student.AM,student.FN,student.LN,student.SEX,student.YEAR,student.MO);
}

}
fclose(fp);




}

void printStudentsWithGrade (float theGrade){

FILE *fp;
    int nscan;
    char termch;
    studEND student;
    fp = fopen("foitites.dat","r");
    if(fp!=NULL){
        while(TRUE){
            nscan = fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",&student.AM,student.FN,student.LN,&student.SEX,&student.YEAR,&student.MO,&termch);
            if(nscan==EOF){
                break;
            }
            if(nscan!=7 || termch != '\n'){
                printf("ERROR\n");
            }else{
                if(student.MO>=theGrade){
                    printf("%d,%s,%s,%c,%d,%.1f\n",student.AM,student.FN,student.LN,student.SEX,student.YEAR,student.MO);
                }
            }
        }
        fclose(fp);
    }







}


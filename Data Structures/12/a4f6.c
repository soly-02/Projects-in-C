#include <stdio.h>
#include <string.h>

#define HMax 9             /*     το μέγεθος του πίνακα HashTable
                                ενδεικτικά ίσο με 5 */
#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */

typedef struct{
     char noumeraki[11];
     int code;
}ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               * ενδεικτικά τύπου int */
typedef char KeyType[32];

typedef struct {
	KeyType RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας δεικτών προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // Dδείκτης σε μια υπολίστα συνωνύμων
    int StackPtr;           // δείκτης προς την πρώτη ελεύθερη θέση της λίστας List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);
void BuildHashList(HashListType *HList);
int findAverage(KeyType s);
void Search_HashList_By_Subject(HashListType HList, int code);


int HashKey(KeyType Key)
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
	/*σε περίπτωση που το KeyType δεν είναι ακέραιος
	θα πρέπει να μετατρέπεται κατάλληλα το κλειδί σε αριθμό*/
	int avg;
	avg=findAverage(Key);

	return avg%HMax;
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList.
   Επιστρέφει: Την δομή HList
*/
{
	int index;

	HList->Size=0;           //ΔΗΜΙΟΥΡΓΕΙ ΜΙΑ ΚΕΝΗ ΛΙΣΤΑ
	HList->StackPtr=0;       //ΔΕΙΚΤΗς ΣΤΗ ΚΟΡΥΦΗ ΤΗΣ ΣΤΟΙΒΑΣ ΤΩΝ ΕΛΕΥΘΕΡΩΝ ΘΕΣΕΩΝ

    /*ΑΡΧΙΚΟΠΟΙΕΙ ΤΟΝ ΠΙΝΑΚΑ HashTable ΤΗΣ ΔΟΜΗΣ HList ΩΣΤΕ ΚΑΘΕ ΣΤΟΙΧΕΙΟΥ ΤΟΥ
        ΝΑ ΕΧΕΙ ΤΗ ΤΙΜΗ EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //Δημιουργία της στοίβας των ελεύθερων θέσεων στη λίστα HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList.
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη.
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά.
*/
{
	return(HList.Size==VMax);
}


void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης
                εγγραφής στην υπολίστα */
{
	int Next,res;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{//HList.List[Next].RecKey,KeyArg
	    res=strcmp(HList.List[Next].RecKey,KeyArg);
		if (res==0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}

void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει.
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec.
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη,
                και ενημερώνει τη δομή HList.
   Επιστρέφει: Την τροποποιημένη δομή HList.
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά,
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί,
                εμφάνιση αντίστοιχου μηνύματος
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}



void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
            for (i=0; i<HMax;i++)
              printf("%d| %d\n",i,HList.HashTable[i]);

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}


void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d,",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
	   printf("%d) %s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}

int main(){
    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int Loc,Pred;
    char surname[20];
    char ar;
    int code;


    //--1--
    printf("1. Create HashList\n");
    BuildHashList(&HList);
    PrintPinakes(HList);

    //--2--
    printf("2. Insert new teacher\n");
     do{
            printf("Enter teacher's name:");
            scanf("%s",AnItem.RecKey);
            printf("Enter teacher's surname:");
            scanf("%s",surname);

        strcat(AnItem.RecKey," ");
         strcat(AnItem.RecKey,surname);


            printf("Enter teacher's phone: ");
            scanf("%s",AnItem.Data.noumeraki);

            printf("Enter teacher's code: ");
            scanf("%d",&AnItem.Data.code);

     AddRec(&HList,AnItem);

     printf("\nContinue Y/N: ");
            do{
                    scanf("%s",&ar);

            }while(ar!='y' && ar!='Y' && ar!='N' && ar!='n');


    }while(ar!='n' && ar!='N');
    PrintPinakes(HList);



    //--3--

    printf("3. Delete a teacher\n");

    printf("Enter teacher's name:");
            scanf("%s",AnItem.RecKey);
            printf("Enter teacher's surname:");
            scanf("%s",surname);

        strcat(AnItem.RecKey," ");
         strcat(AnItem.RecKey,surname);
    DeleteRec(&HList,AnItem.RecKey);
     PrintPinakes(HList);


     //--4--
     printf("4. Search for a teacher\n");
     printf("Enter teacher's name:");
            scanf("%s",AnItem.RecKey);
            printf("Enter teacher's surname:");
            scanf("%s",surname);
     strcat(AnItem.RecKey," ");
         strcat(AnItem.RecKey,surname);

     SearchHashList(HList,AnItem.RecKey,&Loc,&Pred);

     if (Loc!=-1)

     printf("[%s, %s, %d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.noumeraki,HList.List[Loc].Data.code);
else
 printf ("DEN YPARXEI EGGRAFH ME KLEIDI %s\n",AnItem.RecKey);

      //--5--

      printf("\n5. Search by subject\n");
      printf("Enter code: ");
      scanf("%d",&AnItem.Data.code);
      printf("List of teachers with subject code %s \n",AnItem.Data.code);
      Search_HashList_By_Subject(HList,AnItem.Data.code);


return 0;}

int findAverage(KeyType s)
{
    int i;
    char first,last;
    int avg;
    if(s[0]>='a' && s[0]<= 'z')
    {

        first=s[0]-32;

    }
    for(i=0;i<30;i++)
    {
      if (s[i+1]== 0)
       break;


    }

    last=s[i];

      if(s[0]>='a' && s[0]<= 'z')
    {

        last=last-32;

    }


    avg=(first-64 +last-64)/2;

    return avg;
}

void BuildHashList(HashListType *HList){
    ListElm AnItem;
    int kkkey;
    FILE* fp;
    int nscan;
    fp = fopen("i4f6.txt", "r");
    char surname[20],termch;

    CreateHashList(&*HList);

    if (fp!=NULL){
    while(TRUE) {
       nscan = fscanf(fp,"%10[^,],%20[^,],%10[^,],%d%c",AnItem.RecKey,surname,AnItem.Data.noumeraki,&AnItem.Data.code,&termch);
       if (nscan==EOF)
            break;
       if (nscan!=5 || termch!='\n')
            printf("ERROR\n");
       else
       {
         strcat(AnItem.RecKey," ");
         strcat(AnItem.RecKey,surname);
         AddRec(&*HList,AnItem);
       }

        }
    }
  fclose(fp);
}

  void Search_HashList_By_Subject(HashListType HList, int code){

  int i,SubIndex;




  for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                  if (HList.List[SubIndex].Data.code == code)
                  printf("%d: [%s, %s, %d]\n",SubIndex, HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.noumeraki,HList.List[SubIndex].Data.code);

                   SubIndex = HList.List[SubIndex].Link;
               }
          }




  }

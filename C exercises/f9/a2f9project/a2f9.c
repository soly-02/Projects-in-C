#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>

 if (i!=0 && j!=0){
            five_to_seven_table[i*j].year=i;
            five_to_seven_table[i*j].grade =j;
            }
            else if (i=0 && j!=0){
                five_to_seven_table[j].year=i;
                five_to_seven_table[j].grade =j;

            }
             else
                five_to_seven_table[i].year=i;
                five_to_seven_table[i].grade =j;
        }



typedef struct{
 char name[30];
 int apousies;
}studentT;

#define M 100

void readInput (FILE* infile,studentT student[],int* pApontes, int* pStudents);
void writeOutput (FILE* outfile, studentT student[],int apontes, int totalstudents);

int main (){

FILE* infile;
FILE* outfile;

char inputFileName [30];
char outputFileName [30];
studentT student[M];
int apontes, students;

printf("Dwste to onoma gia to arxeio eisodou: ");
gets(inputFileName);

printf("Dwste to onoma gia to arxeio e3odou: ");
gets(outputFileName);


infile = fopen(inputFileName, "r");
if (infile==NULL){
    printf("Cannot open input file");
    exit(1);
}
outfile = fopen(outputFileName, "w");


readInput(infile, student,&apontes, &students);

writeOutput(outfile,student, apontes, students);

fclose(infile);
fclose (outfile);

return 0;

}



void readInput (FILE* infile,studentT student[],int* pApontes, int* pStudents){

     int nscan, apousies;
     char name [30], comments [68], termch;
     int line=0;
     *pApontes = 0;
     *pStudents = 0;


     while (TRUE){

        nscan = fscanf(infile, "%30[^,], %d, %68[^\n]%c",
                                name, &apousies,comments,&termch);

        if (nscan == EOF)
            break;

        line++;

        if (nscan != 4 || termch != '\n'){
            printf("Error in line %d. Program termination\n", line);
            exit(1);
        }
        if (apousies > 100){
            strcpy (student[*pApontes].name, name);
            student[*pApontes].apousies= apousies;
            (*pApontes)++;


        }
        (*pStudents)++;
     }

}


void writeOutput (FILE* outfile, studentT student[],int apontes, int totalstudents){
int i;
  fprintf(outfile, "%-30s%9s\n", "ONOMATEPWNYMO","APOYSIES");

  for (i=1; i<=39; i++)
    fputc('-',outfile);
  fputc('\n', outfile);

   for (i=0; i<apontes; i++)
    fprintf(outfile,"%-30s%9d\n",student[i].name,student[i].apousies);

for (i=1; i<=39; i++)
    fputc('-',outfile);
  fputc('\n', outfile);


  fprintf(outfile,"%-30s%9d\n","SYNOLO MATHITWN :",totalstudents);
  fprintf(outfile,"%-30s%9d\n","SYNOLO APONTWN :",apontes);
}

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

typedef struct{
int num;
char name[28];
int points;
}basket;

int  readFromFile(FILE* infile,basket info[100] );
void writeToFile(FILE* outfile, basket info[100],int num);
main(){

FILE* infile;
FILE* outfile;
infile=fopen("i11f9.dat", "r");
basket info[100];
if (infile==NULL){
    printf("EROOR");
    exit(1);

}
int num;


num=readFromFile(infile,info);


outfile= fopen("baso11f9.dat", "w");

writeToFile(outfile,info,num);

fclose(infile);
fclose(outfile);

}

int  readFromFile(FILE* infile,basket info[100] ){
int tots=0;
int nscan,i;
char termch;


while(TRUE){

    nscan= fscanf(infile,"%d,%28[^,],%d",&info[tots].num,info[tots].name,&info[tots].points);


   if (nscan== EOF)
    break;

tots++;

}

return tots;


}




void writeToFile(FILE* outfile, basket info[100],int num){

int i,pai,pon;
pai=pon=0;
for (i=0;i<num;i++){
fprintf(outfile,"%-28s %d\n",info[i].name, info[i].points );
if (info[i].points>=10)
    pai++;
pon+=info[i].points;
}
fprintf(outfile,"%-28s %d\n","SYNOLO PONTWN",pon );
fprintf(outfile,"%-28s %d\n","SYNOLO PAIKTWN >=10",pai );

}


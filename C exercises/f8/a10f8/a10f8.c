#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

typedef struct{
char name[60];
int startMonth;
int duration;
}diary;

void ReadWorkpackages(diary data[100],int num);
int FindFirstWp(diary data[100], int num);
int  FindMakespan (diary data[100], int num);

int main(){
int packs,first,span;
diary projects [100];

printf ("Enter total work packages: ");
packs= GetInteger();

ReadWorkpackages(projects,packs);

first= FindFirstWp(projects,packs);
printf ("FIRST WP: %s start: %d duration: %d\n",projects[first].name, projects[first].startMonth, projects[first].duration);

span= FindMakespan(projects,packs);
printf("Total duration = %d", span);
return 0;
}



void ReadWorkpackages(diary data[100],int num){
int i;
for (i=0;i<num;i++){
    printf("WP Name : ");
    gets(data[i].name);
    printf ("WP Start Month : ");
    data[i].startMonth= GetInteger();
    printf ("WP Duration : ");
    data[i].duration= GetInteger();

}
}


int FindFirstWp(diary data[100], int num){
int min=data[0].startMonth;
int i,pos=0;
for (i=1;i<num;i++){
  if (data[i].startMonth<min){
    min= data[i].startMonth;
    pos=i;
  }
}
return pos;

}


int  FindMakespan (diary data[100], int num){
int max=-1;
int i,span,pos;
for (i=0;i<num;i++){
  if (data[i].startMonth + data[i].duration >max){
    max= data[i].startMonth+ data[i].duration;
    pos=i;
  }
}
span= max;

return span;




}

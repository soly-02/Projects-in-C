#include <stdio.h>
#include<conio.h>

typedef struct  {
  int app_id;
  char name[24];
  int sqr_meters;
  int fetes;
}Enoikos;

typedef struct   {
  float dapanes;
  float koinoxrista;
}month_expence;

typedef struct  {
    int tm;
    int fetes;
  float therm_sum;
  float koin_sum;
  float total;
}all_sums;


int ReadNumApparts();
month_expence ReadMonthData();
void ReadEnoikoiData(int diamerismata, Enoikos oikodomi[diamerismata]);
all_sums Calculations(int diamerismata,Enoikos oikodomi[diamerismata],month_expence me,month_expence flat[diamerismata]);
void print_all(int diamerismata,Enoikos oikodomi[diamerismata],month_expence me,month_expence flat[diamerismata],all_sums all);

int main(){
Enoikos oikodomi[20];
month_expence polik [20];
int num = ReadNumApparts();
month_expence me= ReadMonthData();


ReadEnoikoiData(num,oikodomi);
all_sums all= Calculations(num,oikodomi,me,polik);




print_all(num,oikodomi, me,polik,all);


return 0;
}

int ReadNumApparts(){
    int num;
 printf("DWSE ARITHMO DIAMERISMATWN?");
 scanf("%d",&num);
return num;

}

month_expence ReadMonthData(){
    month_expence data;
  printf("DWSE MHNIAIO POSO THERMANSHS?");
 scanf("%f",&data.dapanes);
  printf("DWSE MHNIAIO POSO KOINOXRHSTWN?");
 scanf("%f",&data.koinoxrista);
return data;

}

void ReadEnoikoiData(int diamerismata, Enoikos oikodomi[diamerismata]){
for (int i=0;i<diamerismata;i++){
        fflush(stdin);
        oikodomi[i].app_id=i;

     printf("Dwse onomateponymo? ");
      gets(oikodomi[i].name);

       printf("Dwse t.m? ");
       scanf("%d",&oikodomi[i].sqr_meters);
      printf("Dwse fetes? ");
      scanf("%d",&oikodomi[i].fetes);


}}
all_sums Calculations(int diamerismata,Enoikos oikodomi[diamerismata],
                      month_expence me,month_expence flat[diamerismata]){


   int total_fetes=0;
   int total_tm=0;
   all_sums sums;

   sums.koin_sum=0;
   sums.therm_sum=0;
   sums.total=0;

   int i;






for ( i=0;i<diamerismata;i++){

      total_fetes= total_fetes + oikodomi[i].fetes;
      total_tm= total_tm + oikodomi[i].sqr_meters;
}

sums.fetes= total_fetes;
sums.tm=total_tm;


for ( i=0;i<diamerismata;i++){
   flat[i].dapanes= ((double)oikodomi[i].fetes/ total_fetes)* me.dapanes;
   flat[i].koinoxrista= ((double)oikodomi[i].fetes/ total_fetes)*me.koinoxrista;

}





for (i=0;i<diamerismata;i++){
   sums.koin_sum= sums.koin_sum+ flat[i].koinoxrista;
   sums.therm_sum= sums.therm_sum+ flat[i].dapanes;

}
 sums.total= sums.koin_sum + sums.therm_sum;


return sums;

}

void print_all(int diamerismata,Enoikos oikodomi[diamerismata],month_expence me,month_expence flat[diamerismata],all_sums all){


printf("%3s%26s%5s%6s%12s%12s%12s\n", "A/A","ONOMATEPWNYMO","T.M.","FETES","POSO THERM.","POSO KOIN.", "SYNOLO");
for(int i=0;i<76;i++)
    printf("-");

     printf("\n");

for (int i=0;i<diamerismata;i++){

printf("%3d%26s%5d%6d%12.2f%12.2f%12.2f\n", oikodomi[i].app_id+1,oikodomi[i].name,oikodomi[i].sqr_meters,oikodomi[i].fetes,flat[i].dapanes,flat[i].koinoxrista, flat[i].dapanes+flat[i].koinoxrista);

}

for(int i=0;i<76;i++)
    printf("-");

     printf("\n");


printf("%-29s%5d%6d%12.2f%12.2f%12.2f\n","SYNOLA",all.tm,all.fetes,all.therm_sum,all.koin_sum, all.total);



}





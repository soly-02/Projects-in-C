#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

typedef struct {

 int width;
 int height;
 int depth;
 int area;
 int volume;

} box;

void Dims(box *info);
void calc_area(box *info);
void calc_volume(box *info);

int main (){

box mation;
Dims(&mation);
calc_area(&mation);
calc_volume(&mation);

printf("To emvadon tou koutiou einai %d cm2\n", mation.area);
printf("O ogos tou koutiou einai %d cm3", mation.volume);

return 0;
}

void Dims(box *info){

printf("Dose to mikos tou koutiou se cm: ");
(*info).width= GetInteger();
printf("Dose to ypsos tou koutiou se cm: ");
(*info).height= GetInteger();
printf("Dose to vathos tou koutiou se cm: ");
(*info).depth= GetInteger();



}


void calc_area(box *info){

(*info).area= 2*((*info).width * (*info).depth)+ 2*((*info).width * (*info).height)+ 2*((*info).depth * (*info).height);

}

void calc_volume(box *info){


(*info).volume= (*info).width * (*info).height * (*info).depth;





}

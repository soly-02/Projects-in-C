/* File Name : a28f4.c
*  Author: Sofia Lypiridou
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int get_code();
double discount_percentage(int c);
int product_points(int c, double p);



int main (){

int code, points;
double price, finalPrice, discount, total, discountSum;

total=discountSum=0;
points=0;

code= get_code();
while (code!=0){
  printf("Dwse thn timh: ");
  price=GetReal();
  discount= discount_percentage(code)*price;
  finalPrice= price- discount;
  points+= product_points(code, finalPrice);
  total+=finalPrice;
  discountSum+= discount;
  code= get_code();


}
printf("-------------------\n");
printf("Teliko synolo: %.2f Euro \n", total);
printf ("Ekptwsh: %.2f Euro\n", discountSum);
printf ("Pontoi %d\n",points);


return 0;
}


int get_code(){
int c;

 printf("Dwse ton kwdiko: ");
 c= GetInteger();
while (c<0 || c>2000){

  printf("Lathos Kwdikos(0~2000)\n");
  printf("Dwse ton kwdiko: ");
  c= GetInteger ();
}
return c;

}

double discount_percentage(int code){

  if (code<=300) return 0.05;
  else if (code<=500) return 0.10;
  else if (code<=1000) return 0.15;
  else return 0.20;


}



int product_points(int c, double p){
int points;
points=1;
if (c>+1000 && c<=1500)
    points+= ceil(p/5);
return points;

}

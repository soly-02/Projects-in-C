#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 3

// Dhlwseis
void readData(int rows,int cols,double temper[rows][cols]);
double calculateAvarage(int rows,int cols,double temper[rows][cols]);
void calculateAvgCity(int rows,int cols,double temper[rows][cols],double avarage[rows]);
void calculateMaxDeviation(int rows,int cols,double temper[rows][cols],double natavg,double mdeviation[]);
void printResults(int rows, int cols,double natavg,double average[rows][cols],double mdeviation[]);


int main()

{
    double temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;


	/*Read all Temperatures*/
	 readData(CTS,S,temper);



	/*Calculating The Average of all Cities&Temps*/
   natavg=calculateAvarage(CTS,S,temper);


	/*Calculating Average temp on each City*/
	calculateAvgCity(CTS,S,temper,average);



	/*Calculating Standard Deviation*/
	calculateMaxDeviation(CTS,S,temper,natavg,mdeviation);
    /*Calculating max Deviation*/

    /*Printing results*/
    printResults(CTS,S,natavg,average,mdeviation);

}


void readData (int rows,int cols,double temper[rows][cols]){
    int i,j;

    for (i=0; i<rows; i++)
		for (j=0; j<cols; j++)
		  	{
              printf("Temp of City %d During %d 8-hour period: ",i,j);
              temper[i][j] = GetReal();
              }

}

double calculateAvarage(int rows,int cols,double temper[rows][cols]){

int i,j;
double natavg;

    natavg = 0;
    for (i=0; i<CTS; i++)
      for (j=0; j<S; j+=1)
         natavg += temper[i][j];
    natavg = natavg/(rows*cols);
    return natavg;
}


void calculateAvgCity(int rows,int cols,double temper[rows][cols],double average[rows]){

int i,j;

	for (i=0; i<rows; i++)
    {
        average[i] = 0;
        for (j=0; j<cols; j++)
        {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/cols;
    }

}

void calculateMaxDeviation(int rows,int cols,double temper[rows][cols],double natavg,double mdeviation[]){

int i,j;
double devnat[rows][cols];

for (i=0; i<rows; i++)
        for (j=0; j<cols; j++)
            devnat[i][j] = fabs(natavg-temper[i][j]);

for (i=0; i<rows; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<cols; j++)
            if (mdeviation[i]<devnat[i][j]) mdeviation[i] = devnat[i][j];
    }

}

void printResults(int rows, int cols,double natavg,double average[rows][cols],double mdeviation[]){
int i;
 printf("%3.1f\n", natavg);
    for (i=0; i<rows; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
    system("PAUSE");
    return 0;


}



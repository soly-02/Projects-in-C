
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

long long GetLongLong(void);

main (){
long long a,p;
 int A[16],i;
 bool b;

b=TRUE;
printf("Insert card number :");
a= GetLongLong();
p=a;


if (a<4000000000000000)
    b=FALSE;
if (b==TRUE){
for (i=15;i>=0;i--){
    A[i]=a%10;
    a= a/10;
}

}

if (a!=0)
    b= FALSE;

    if (A[0]<4 || A[0]>7)
        b= FALSE;

        if (b!=FALSE){

                for (i=0;i<16;i=i+2){
                    A[i]=2*A[i];
                    if (A[i]>=10)
                        A[i]= (A[i]%10) + (A[i]/10);
                }
         a=0;
         for (i=0;i<16;i++)
              a+= A[i];
          if (a%10!=0)
            b= FALSE;


                }
if (b==FALSE)
printf("%lld is invalid", p);
else
    printf ("%lld is VALID", p);

}



long long GetLongLong(void)
{
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}

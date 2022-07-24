main (){
    char carray[100];


    int count,A[100],nc=0,i, sum = 0;



    printf("Insert a string: ");

    gets(carray);

    for (count = 0; carray[count] != '\0'; count++){

        if(carray[count] >= '0' && carray[count] <= '9'){
          A[nc]= carray[count];
          nc++;
          sum += (carray[count] - '0');
        }

    }

if (nc!=0){
for (i=0;i<nc;i++){
        printf("%c", A[i]);
        if (i!=nc-1)
            printf (" + ");
    }

    printf(" = %d\n", sum);

}
else
   printf("No digits in input.") ;



}

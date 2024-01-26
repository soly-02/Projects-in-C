#include <stdio.h>
void common (char word1[], char word2[]);
void common_once (char word1[], char word2[]);

int main(){
char w1[30],w2[30];
printf("Insert two words to find the common characters\n");
printf("Word 1: ");
gets(w1);
printf("Word 2: ");
gets(w2);
common(w1,w2);
common_once(w1,w2);

return 0;
}

void common (char word1[], char word2[]){

int i,j,flag=0;
printf("Common Characters : ");
for (i = 0; word1[i]!='\0' ; i++){
    flag=0;
    for (j=0; word2[j]!='\0' ; j++){
            if (word1[i] == word2[j] && !flag){
               printf("%c",word1[i]);
               flag=1;
            }



    }
}
printf("\n");

}

void common_once (char word1[], char word2[]){


int i,j,flag=0,n=0;
char str[30];
printf("Unique Common Characters : ");
for (i = 0; word1[i]!='\0' ; i++){
    flag=0;
    for (j=0; word2[j]!='\0' ; j++){
              if (word1[i] == word2[j] && !flag){
               str[n]= word1[i];
               n++;
               flag=1;
            }
    }

}

// Used as an index in the modified string
    int index = 0;

    // Traverse through all characters
    for (int i = 0; i < n; i++) {
        // Check if str[i] is present before it
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j])
                break;
        }

        // If not present, then add it to the result.
        if (j == i)
            str[index++] = str[i];
    }

    // Add null character at the end to terminate the string
    str[index] = '\0';

   printf("%s",str);



}






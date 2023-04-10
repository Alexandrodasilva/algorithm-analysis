#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void contar(char *string, char *subString){
    int i;
    int j = 0;
    int incr = 0;

    for(i = 0;  i < 11; i++){
        if(string[i] == subString[j]){
            j++;
        }else{
            j = 0;
        }
        if(j == strlen(subString)){
           incr++; 
        }
    }
    printf("\n");
    printf("%d\n", incr);
}
int main() {
    char string[11];
    char subString[3];
    scanf("%s",string);
    scanf("%s",subString);
    contar(string, subString);
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char str[100], str_length;
    int j, contA = 0, contE = 0, contI = 0, contO = 0, contU = 0;
    scanf("%[^\n]s", str);
    str_length = strlen(str);
    for(j = 0; j < str_length; j++){
        printf("=%c\n", str[j]);
        if(str[j] == 'a' || str[j] == 'A'){
            contA++;
        }else if(str[j] == 'e' || str[j] == 'E'){
            contE++;
        }else if(str[j] == 'i' || str[j] == 'I'){
            contI++;
        }else if(str[j] == 'o' || str[j] == 'O'){
            contO++;
        }else if(str[j] == 'u' || str[j] == 'U'){
            contU++;
        }
    }
    printf("a %d\n", contA);
    printf("e %d\n", contE);
    printf("i %d\n", contI);
    printf("o %d\n", contO);
    printf("u %d\n", contU);
    return 0;
}

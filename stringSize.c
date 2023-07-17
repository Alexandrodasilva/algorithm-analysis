#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int tamstr(){

}
int main() {
    int i =0, j = 0;
    char str[10];
    while(strcmp(str, "FIM") !=0){
        scanf("%[^\n]%*c", str);
    }
    if(strcmp(str, "FIM") !=0){
      printf("%c", str);
    }
    
	return 0;
}
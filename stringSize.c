#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int tamstr(char *str){
  int str_legth;
  str_legth = strlen(str);
  return str_legth;
}
int main() {
    int i =0, j = 0;
    char str[10];
    while(scanf("%9s", str) == 1){
      if(strcmp(str, "FIM") == 0){
        break;
      }
      printf("%d\n",tamstr(str));
    }
	return 0;
}
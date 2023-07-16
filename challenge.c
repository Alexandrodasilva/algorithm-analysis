#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void derivada(int *coeficiente, int *expoente){
    int tamanho = 0, i;

    while (coeficiente[tamanho] != -1){
        tamanho++;
    }

    for(i = 0; i < tamanho; i++){
        coeficiente[i] *= expoente[i];
        expoente[i] -= 1;
    }

}
int main() {
    int n, i;
    //scanf("%d", &n);
    int coeficiente[n], expoente[n];
    char incognita[n];
    while(scanf("%d", &n) != EOF){
        if(n == 0){
           break;
        }
        for(i = 0; i < n; i++){
            scanf("%d %c %d", &coeficiente[i], &incognita[i], &expoente[i]);
        }
        coeficiente[n] = -1;
        expoente[n] = -1;
    }
    derivada(coeficiente, expoente);
    printf("f'(x)=+");
    for(int i = 0; i < n; i++){
        if(expoente[i] ==  0){
            printf("%d", coeficiente[i]);
        }
        else{
            printf("%d%c^%d", coeficiente[i], incognita[i], expoente[i]);
            if(i < n-1 ){
                printf("+");
            }
        }
    }
    printf("\n");
	return 0;
}
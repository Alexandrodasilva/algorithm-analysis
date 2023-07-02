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
         printf("%d %d", coeficiente[i], expoente[i]);
    }

}
int main() {
    int n, i, coeficiente[2], expoente[2];
    char incognita[2];
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
    // printf("f'(x)=")
	return 0;
}
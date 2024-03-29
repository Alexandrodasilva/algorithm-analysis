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
        if(expoente[i] > 0){
            coeficiente[i] *= expoente[i];
            expoente[i] -= 1;   
        }else if(expoente[i] == 0){
            coeficiente[i] = 0;
        }
    }

}
int main() {
    int n, i;

    int *coeficiente, *expoente;
    char *incognita;
    while(scanf("%d", &n) != EOF){
        if(n == 0){
           break;
        }

        coeficiente = malloc((n+1) * sizeof(int));
        expoente = malloc((n+1) * sizeof(int));
        incognita = malloc((n+1) * sizeof(char));

        for(i = 0; i < n; i++){
            scanf("%d %c %d", &coeficiente[i], &incognita[i], &expoente[i]);
        }

        coeficiente[n] = -1;
        expoente[n] = -1;

        derivada(coeficiente, expoente);

        printf("f'(x)=");

        for(int i = 0; coeficiente[i] != -1; i++){
            if(expoente[i] == 0 && coeficiente[i] != 0){
                if(coeficiente[i] > 0){
                    printf("+%d", coeficiente[i]);
                }else if(coeficiente[i] < 0){
                    printf("%d", coeficiente[i]);
                }
            }else if(expoente[i] > 0){
                if(coeficiente[i] > 0){
                    printf("+%d%c^%d", coeficiente[i], incognita[i], expoente[i]);
                }else if(coeficiente[i] < 0){
                    printf("%d%c^%d", coeficiente[i], incognita[i], expoente[i]);
                }
            }
            
        }
        printf("\n");
        free(coeficiente);
        free(incognita);
        free(expoente);
    }
	return 0;
}
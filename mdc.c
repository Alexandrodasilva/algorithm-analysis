#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int x, y;
    int index = 0, index1 =0, index2 =0, valor = 1;
    int tamanho = 0;
    int capacidade = 1, capacidade2 = 1, capacidade3 = 1;
    int *vt1 = (int*)malloc(capacidade * sizeof(int));
    int *vt2 = (int*)malloc(capacidade2 * sizeof(int));
    int *vt3 = (int*)malloc(capacidade3 * sizeof(int));

    scanf("%d",&x );
    scanf("%d", &y);

    for(int i = 1; i <= x; i++){
        if(x%i == 0){
            capacidade *= 2;
            vt1 = (int*)realloc(vt1, capacidade * sizeof(int));
            vt1[index] = i;
            index++;
        }
    }

    for(int i = 1; i <= y; i++){
        if(y%i == 0){
            capacidade2 *=2;
            vt2 = (int*)realloc(vt2, capacidade2 * sizeof(int));
            vt2[index1] = i;
            index1++;
        }
    }

    if(sizeof(vt1) > sizeof(vt2)){
        for(int i = 0; i < sizeof(vt1); i++){
            for(int j = 0; j <sizeof(vt1); j++){
                if(vt1[i] == vt2[j]){
                    capacidade3 *= 2;
                    vt3 = (int*)realloc(vt3, capacidade3 * sizeof(int));
                    vt3[index2] = vt2[j];
                    index2++;
                }
            }
        }
    }
    else{
        for(int i = 0; i < sizeof(vt2); i++){
            for(int j = 0; j < sizeof(vt2); j++){
                if(vt1[i] == vt2[j]){
                    capacidade3 *= 2;
                    vt3 = (int*)realloc(vt3, capacidade3 * sizeof(int));
                    vt3[index2] = vt2[j];
                    index2++;
                }
            }
        }
    }
    for(int i = 0; i < sizeof(vt3); i++){
        if(vt3[i] > valor){
            valor = vt3[i];
        }
    }
   // printf("%d\n", valor);
    free(vt1);
    free(vt2);
    free(vt3);
    return 0;
}
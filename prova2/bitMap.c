#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void computar(int l, int c, int matriz[][205]){
    int i, j;
    int aux1 = 0,aux0 = 0;
    int auxD;
    for( i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(matriz[i][j] == 0){
                aux0++;
            }
            if(matriz[i][j] == 1){
                aux1++;
            }
        }
    }
    if(aux0 > 0 && aux1 == 0){
        printf("0");
    }
    if(aux1 > 0 && aux0 == 0){
        printf("1");
    }
    else{
        printf("D");
    }
}

int main() {
    int n, a, i, j; // variaveis 
    int l, c; // linha e coluna
    int matriz[205][205];
    scanf("%d", &n);
    for(a = 0; a < n; a++){
        scanf("%d %d", &l, &c);
        for( i = 0; i < l; i++){
            for(j = 0; j < c; j++){
                scanf("%1d", &matriz[i][j]);
            }
        }
        computar(l, c, matriz);
    }
	return 0;
}
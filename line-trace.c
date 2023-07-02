#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    float traco[n][n],soma = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%f", &traco[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        soma += traco[i][i];
    }
    printf("tr(A) = ");
    for(int i = 0; i < n; i++){
        printf("(%.2f) ", traco[i][i]);
        if(i < n -1){
            printf("+ ");
        }
    }
    printf("= %.2f\n", soma);
    return 0;
}
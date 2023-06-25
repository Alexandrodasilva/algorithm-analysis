#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n;
    float traco[3][3], vt[3], soma = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%f", &traco[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        vt[i] = traco[i][i];
    }

    for(int i = 0; i < 3; i++){
        soma += vt[i];
    }
    
    printf("tr(A) = (%.2f) + (%.2f) + (%.2f) = %.2f\n", vt[0], vt[1], vt[2], soma);
    return 0;
}
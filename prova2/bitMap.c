#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void computar(int matriz[][200], int L, int C, int linha, int coluna) {
    int i, j;
    int aux0 = 0, aux1 = 0;

    for (i = linha; i < linha + L; i++) {
        for (j = coluna; j < coluna + C; j++) {
            if (matriz[i][j] == 0) {
                aux0++;
            } else {
                aux1++;
            }
        }
    }

    if(L*C == 0){}
    else{
        if (aux0 == L*C ) {
        printf("%d", 0);
        } else if (aux1 == L*C) {
            printf("%d", 1);
        } else {
            printf("D");
            int novoL = L/2;
            int novoC = C/2;
            
            if (C % 2 != 0) {
                novoC++;
            }

            if (L % 2 != 0) {
                novoL++;
            }

            computar(matriz, novoL, novoC, linha, coluna); //QSE
            computar(matriz, novoL, C - novoC, linha, coluna + novoC); //QSD
            computar(matriz, L - novoL, novoC, linha + novoL, coluna); //QIE
            computar(matriz, L - novoL, C - novoC, linha + novoL, coluna + novoC); //QID
        }
    }
    
}

int main() {
    int n, a, i, j;
    int l, c;
    int matriz[50][200];
    scanf("%d", &n);

    for (a = 0; a < n; a++) {
        scanf("%d %d", &l, &c);

        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                scanf("%1d", &matriz[i][j]);
            }
        }

        computar(matriz, l, c, 0, 0);
        printf("\n");
    }

    return 0;
}

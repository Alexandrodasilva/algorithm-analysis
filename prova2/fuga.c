#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    long long int x, y, tipo;
} Nave;

typedef struct{
    Nave nave1, nave2;
    double distancia;
}parMaisproximo;

double calc(Nave nave1, Nave nave2) {
    long long int x = (nave1.x - nave2.x);
    long long int y = (nave1.y - nave2.y);
    return (x * x + y * y);
}

parMaisproximo encontrarParMaisProximo(){

}

int main() {
    long long int n;
    scanf("%d", &n);
    Nave *nave = (Nave*)malloc(10000000 * sizeof(Nave));
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &nave[i].x, &nave[i].y, &nave[i].tipo);
    }

    double menorDist = -1;
    long long int j, i, indNave1 = -1, indNave2 = -1;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (nave[i].tipo != nave[j].tipo) {
                double distancia = calc(nave[i], nave[j]);
                if (menorDist == -1 || distancia < menorDist) {
                    menorDist= distancia;
                    indNave1 = i;
                    indNave2 = j;
                }
            }
        }
    }

    printf("%d %d %d %d\n", nave[indNave1].x, nave[indNave1].y, nave[indNave2].x, nave[indNave2].y);
    
    free(nave);
    return 0;
}

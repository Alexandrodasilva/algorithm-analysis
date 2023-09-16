#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//o que falta nesse quest?o que n?o passa, meu Deus do C?u
typedef struct {
    int x, y, tipo;
} Nave;

double calc(Nave nave1, Nave nave2) {
    int x = (nave1.x - nave2.x);
    int y = (nave1.y - nave2.y);
    return (x * x + y * y);
}


int main() {
    int n;
    scanf("%d", &n);
    
    Nave *nave = (Nave*)malloc(50000 * sizeof(Nave));
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &nave[i].x, &nave[i].y, &nave[i].tipo);
    }

    double menorDist = -1;
    int j, i, indNave1 = -1, indNave2 = -1;

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

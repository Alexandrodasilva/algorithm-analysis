#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Ponto;

int compare(const void *a, const void *b) {
    Ponto *p1 = (Ponto *)a;
    Ponto *p2 = (Ponto *)b;
    if (p1->x == p2->x) return p1->y - p2->y;
    return p1->x - p2->x;
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    Ponto *pontos = (Ponto *)malloc(N * sizeof(Ponto));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &pontos[i].x, &pontos[i].y);
    }

    qsort(pontos, N, sizeof(Ponto), compare);

    int numNaves = 1;
    int x1 = pontos[0].x;
    int y1 = pontos[0].y;

    for (int i = 1; i < N; i++) {
        int distx = pontos[i].x - x1;
        int disty = pontos[i].y - y1;
        if (distx * distx + disty * disty > L * L) {
            numNaves++;
            x1 = pontos[i].x;
            y1 = pontos[i].y;
        }
    }

    printf("%d\n", numNaves);

    free(pontos);
    return 0;
}

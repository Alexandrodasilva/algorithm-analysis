#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct {
    long long x;
    long long y;
    int type;
} Ship;

// Função para comparar duas naves com base em suas coordenadas x
int compareX(const void *a, const void *b) {
    return ((Ship*)a)->x - ((Ship*)b)->x;
}

// Função para calcular a distância entre duas naves
double calculateDistance(Ship ship1, Ship ship2) {
    long long dx = ship1.x - ship2.x;
    long long dy = ship1.y - ship2.y;
    return sqrt(dx * dx + dy * dy);
}

// Função recursiva para encontrar a distância mínima entre naves de tipos diferentes
double findMinDistance(Ship ships[], int left, int right) {
    if (right - left <= 3) {
        // Se houver apenas algumas naves, faça uma verificação direta
        double minDist = DBL_MAX;
        for (int i = left; i <= right; i++) {
            for (int j = i + 1; j <= right; j++) {
                if (ships[i].type != ships[j].type) {
                    double dist = calculateDistance(ships[i], ships[j]);
                    if (dist < minDist) {
                        minDist = dist;
                    }
                }
            }
        }
        return minDist;
    }

    // Divide o conjunto em duas partes
    int mid = (left + right) / 2;
    double minDistLeft = findMinDistance(ships, left, mid);
    double minDistRight = findMinDistance(ships, mid + 1, right);

    // Encontre a menor distância entre as duas partes
    double minDist = fmin(minDistLeft, minDistRight);

    // Verifique se há naves próximas à linha de divisão
    Ship strip[right - left + 1];
    int stripSize = 0;
    for (int i = left; i <= right; i++) {
        if (abs(ships[i].x - ships[mid].x) < minDist) {
            strip[stripSize++] = ships[i];
        }
    }

    // Ordena as naves na faixa pela coordenada y
    qsort(strip, stripSize, sizeof(Ship), compareX);

    // Verifique as naves na faixa para encontrar distâncias menores
    for (int i = 0; i < stripSize; i++) {
        for (int j = i + 1; j < stripSize && (strip[j].y - strip[i].y) < minDist; j++) {
            if (strip[i].type != strip[j].type) {
                double dist = calculateDistance(strip[i], strip[j]);
                if (dist < minDist) {
                    minDist = dist;
                }
            }
        }
    }

    return minDist;
}

int main() {
    int n;
    scanf("%d", &n);

    Ship *ships = (Ship *)malloc(n * sizeof(Ship));

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %d", &ships[i].x, &ships[i].y, &ships[i].type);
    }

    // Ordena as naves pelo eixo x
    qsort(ships, n, sizeof(Ship), compareX);

    double minDistance = findMinDistance(ships, 0, n - 1);

    if (minDistance < DBL_MAX) {
        printf("%.6lf\n", minDistance);
    } else {
        printf("Nenhuma combinação de naves encontrada.\n");
    }

    free(ships);
    return 0;
}

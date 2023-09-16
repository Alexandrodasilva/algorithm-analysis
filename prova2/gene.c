#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontrar_gene(char *codigo_genetico, char *gene_messias, int n, int m) {

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (gene_messias[j] != '_') {
                if(gene_messias[j] != codigo_genetico[i + j]){
                    break;
                }
            }
        }

        if (j == m) {
            printf("%d\n", i);
            return;
        }
    }

    printf("Nao descendente\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char codigo_genetico[n];
    char gene_messias[m];

    scanf("%s", codigo_genetico);
    scanf("%s", gene_messias);


    encontrar_gene(codigo_genetico, gene_messias, n, m);

    return 0;
}
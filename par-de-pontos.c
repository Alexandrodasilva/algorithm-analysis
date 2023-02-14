
// Par de pontos mais próximo

// Descrição
// Dado um conjunto de pontos em posição geral no plano, encontre a menor distância entre quaisquer dois pontos do conjunto.
// Cada ponto é descrito por suas coordenadas no plano. Todas as coordenadas são números inteiros entre 0 e 999.

// Formato de entrada
// A entrada é composta por uma linha contendo o número n representando o número de pontos do conjunto, seguida por n linhas contendo dois números cada contendo as coordenadas de cada ponto.
// EX:
// 5
// 316 729
// 917 29
// 547 533
// 892 881
// 247 29

// Formato de saída
// A saída é um número real com quatro casas decimais de precisão representando a menor distância entre qualquer par de pontos.
// EX:
// 455.3427

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void calc(int q, int *x, int *y){
	int i, j;
	float aux = 10000000;
	for(i = 1; i <= q; i++){
		for(j = i+1; j <= q; j++){
			if(sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2)) < aux){
				aux = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
			}
		}
	}
	printf("%.4f ", aux);

}

int main (void) {
    int i;
	int quant;
	scanf("%d", &quant);
	int x[quant];
	int y[quant];
	for(i = 1; i <= quant; i++){
		scanf("%d %d",&x[i], &y[i]);
	}
	calc(quant, x, y);
   return EXIT_SUCCESS;
}


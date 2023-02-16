// Intercalação

// Descrição
// Dadas duas listas de elementos ordenados L1[1..n1] e L2[1..n2],
// descreva um algoritmo iterativo para produzir uma lista ordenada L[1..(n1+n2)] com todos os elementos de L1 e L2.

// Formato de entrada

// As duas primeiras linhas da entrada consistem em inteiros n1 e n2 correspondendo aos tamanhos das listas L1 e L2.
// As n1 linhas seguintes correspondem aos elementos da lista L1 e os n2 elementos após estes correspondem aos elementos de L2.

// Formato de saída

// A saída consiste nos elementos da lista ordenada L contendo todos os elementos de L1 e L2 com um elemento por linha.

// entrada:
// 3
// 4
// 2
// 4
// 8
// 3
// 5
// 9
// 10

// saida:
// 2
// 3
// 4
// 5
// 8
// 9
// 10

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int quantL1, quantL2, i = 1;

    scanf("%d", &quantL1);
    scanf("%d", &quantL2);

    int linha1[quantL1];
    int linha2[quantL2];

    while (i <= quantL1)
    {
        scanf("%d", &linha1[i]);
        i++;
    }
    while (i <= quantL2)
    {
        scanf("%d", &linha1[i]);
        i++;
    }
    
    
    
	return 0;
}
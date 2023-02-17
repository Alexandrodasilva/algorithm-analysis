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

void intercalar(int *linha1, int *linha2, int quantL1, int quantL2){
    int quant_total = quantL1 + quantL2;
    int i, v3[quant_total], j = 0;
    for(i = 0; i <= quant_total && j < quantL2; i+=2 ){
        if(j < quantL1 && j < quantL2){
            v3[i] = linha1[j];
            v3[i+1] = linha2[j];
            j++;  
        }
        else{
            v3[i] = linha2[j];
        }
    }
    for(i = 0; i < quant_total; i++){
        printf("%d\n", v3[i]);
    }
}

int main() {
    int quantL1, quantL2, i = 0, j = 0, quant_total;

    scanf("%d", &quantL1);
    scanf("%d", &quantL2);

    int linha1[quantL1];
    int linha2[quantL2];

    while (i < quantL1)
    {
        scanf("%d", &linha1[i]);
        i++;
    }

    while (j < quantL2)
    {
        scanf("%d", &linha2[j]);
        j++;
    }

    intercalar(linha1, linha2, quantL1, quantL2);
	return 0;
}
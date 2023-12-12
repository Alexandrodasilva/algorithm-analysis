#include <stdio.h>

void merge(int *vetor, int *vetorA, int i, int m, int j){
  int i1 = i, i2 = m + 1, k = i;
  while (i1 <= m && i2 <= j){
    if(vetorA[i1] <= vetorA[i2]){
      vetor[k++] = vetorA[i1++];
    }
    else{
      vetorA[k++] = vetor[i2++];
    } 
  }
  if(i1 > m){
    copiar(&vetor[k], &vetorA[i2], j - i2 + 1);
  } 
  else{
    copiar(&vetor[k], &vetorA[i1], m - i1 + 1);
  } 
  copiar(&vetor[i], &vetorA[i], j - i + 1);
}

void mergeSort(int *vetor, int *vetorA, int i, int j){
  if(i <j){
    int m = i + (j - i) / 2;
    mergeSort(vetor, vetorA, i, m);
    mergeSort(vetor, vetorA, m + 1, j);
    merge(vetor, vetorA, i, m, j);
  }
}

void copiar(int *vetor, int *vetorA, int tamanho){
  for(int i = 0; i < tamanho; i++){
    vetor[i] = vetorA[i];
  }
}
int main(void) {
  int i = 0, j = 6;
  int vetor[6] = {4,2,9,3,8,1}, vetorA[6];
  mergeSort(vetor, vetor, i, j);
  return 0;
}
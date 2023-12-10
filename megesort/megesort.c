#include <stdio.h>

void merge(int *vetor, int i, int m, int j){

}

void mergeSort(int *vetor, int i, int j){
  if(i <j){
    int m = i + (j - i) / 2;

    mergeSort(vetor, i, m);
    mergeSort(vetor, m + 1, j);
    merge(vetor, i, m, j);
  }
}

int main(void) {
  int i = 0, j = 6;
  int vetor[6] = {4,2,9,3,8,1};
  mergeSort(vetor, i, j);
  return 0;
}
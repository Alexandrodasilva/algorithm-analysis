#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int selectSort(){

}

int main(){
    int A[] = {89, 45, 68, 90, 29, 34, 17};
    int i, j, min, aux;

    for(i = 0; i < 7-1; i++){
       min = i;
       for(j = i + 1; j < 7; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        aux = A[i];
        A[i] = A[min];
        A[min] = aux;
    }

    for(i = 0; i < 7; i++){
        printf("%d - ", A[i]);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void merge(int *seq, int low, int mid, int high, int *aux) {
    int i, j, k;
    int t[100000];

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        (*aux)++;
        if (seq[i] <= seq[j]) {
            t[k++] = seq[i++];
        } else {
            t[k++] = seq[j++];
        }
    }

    while (i <= mid) {
        t[k++] = seq[i++];
    }

    while (j <= high) {
        t[k++] = seq[j++];
    }

    for (i = low; i <= high; i++) {
        seq[i] = t[i];
    }
}

void megesort(int *seq, int low, int high, int *aux){
    if(low < high){
        int mid = (low + high)/2;
        megesort(seq, low, mid, aux);
        megesort(seq, mid+1, high, aux);
        merge(seq, low, mid, high, aux);
    }
}

int main() {
    int n, seq[100000], low, high, aux;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &seq[i]);
        }

        low = 0;
        high = n - 1;
        aux = 0;
        megesort(seq, low, high, &aux);
        printf("(%d)\n", aux);
        if( aux % 2 == 0) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }
    
    return 0;
}

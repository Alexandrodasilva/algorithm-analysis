#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int merge(int *seq, int low, int mid, int high, int aux){
    int i,j,k,t[100000];
    i = low;
    j = mid +1;
    k=low;
    while (i <= mid && j <= high)
    {
        if(seq[i] >= seq[j]){
            t[k++] = seq[j++];
            aux ++;
        }else{
            t[k++] = seq[i++];
        }
    }
    while (i <=mid)
    {
        t[k++] = seq[i++];
    }
    while (j <= high)
    {
        t[k++] = seq[j++];
    }
    for(i= low; i<=high; i++){
        seq[i] = t[i];
    } 
    return aux;
}

int megesort(int *seq, int low, int high, int aux){
    //uso do algoritmo merge
    int mid;
    if(low != high){
        mid= (low+high)/2;
        megesort(seq, low, high, aux);
        megesort(seq, mid+1, high, aux);
        merge(seq, low, mid, high, aux);
    }
    return aux;

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
        if( megesort(seq, low, high, aux)% 2 == 0) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }
    }
    
    return 0;
}

       //utilizar o algoritmo de selectioSort
        // int aux = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j < n; j++) {
        //         if (seq[i] > seq[j]) {
        //             aux++;
        //         }
        //     }
        // }
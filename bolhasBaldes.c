#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int megesort(int *seq, int n){
    //uso do algoritmo merge
}

int main() {
    int n, seq[100000];
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &seq[i]);
        }


        if ( megesort(seq, n)% 2 == 0) {
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
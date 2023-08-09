#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int verificacao(int *vt1, int n ){
    int i, aux = 1;
    for(i =0 ; i < n -1 ; i++){
        if(vt1[i] > vt1[i+1]){
            aux = -1;
            break;
        }
    }
    return aux;
}

int intercala(int *vt1, int *vt2,int n ){
    int i, j, aux = 0;
    n *= 2;
    int *vt3 = malloc(n * sizeof(int));
    printf("%d\n", n);
    if(verificacao(vt1, n) == -1 || verificacao(vt2, n) == -1){
        aux = -1;
    }else{
        for(i = 0; i < n; i++){
          for(i = 0; i < n; i++){
          
          }
        }
    }
    return(aux);
}

int main() {
    int i = 0;
    int *vt1 = malloc(n * sizeof(int));
    int *vt2 = malloc(n * sizeof(int));
    char finalLinha = '\n';
    while (scanf("%d%c", &vt1[i], &finalLinha) == 2 && finalLinha != '\n'){

    }
    for(i = 0; i < n ; i++){
        scanf("%d", &vt1[i]);
    }
    for(i = 0; i < n ; i++){
        scanf("%d", &vt2[i]);
    }
    printf("\n");
    printf("%d",intercala(vt1,vt2, n));
	return 0;
}
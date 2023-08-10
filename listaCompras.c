#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[10];
    int quantidade;
    float valor;
}lista;

int main(){
    lista l;
    
    scanf("%d", &l.quantidade);
    printf("%d\n", l.quantidade);

}
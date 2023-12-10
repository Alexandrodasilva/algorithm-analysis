#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct lista {
    char nome[10];
    float valor;
    int quantidade;
    struct lista *prox;
}lista;

void inserir(lista **head, char *nome, float valor, int quantidade){
    lista *l = malloc(sizeof(lista));
    strcpy(l->nome, nome);
    l->valor = valor;
    l->quantidade = quantidade;
    l->prox = NULL;

    if(*head == NULL){
            *head = l;
    }else{
        lista *atual = *head;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = l;
    }
}
void remover( float valor, int quantidade){

}
void removerGrupo(float valor){

}
void consultar(lista *head){
    lista *novo = head;
    float soma = 0;
    while(novo != NULL){
        soma += novo->valor * novo->quantidade;
        novo = novo->prox;
    }
    printf("Atualmente a lista esta em R$%.2f\n", soma);
}

void procurar(lista *head, char *nome){
    lista *novo = head;
    while(novo->prox != NULL){
        if(novo->nome == nome){
            printf("%s\n- %f\n- %d\n", novo->nome, novo->valor, novo->quantidade);
        }else{
            printf("%s nao foi encontrado.", nome);
        }
        novo = novo->prox;
    }
}

int main(){
    lista l;
    lista *head = NULL;
    char str[13];
    while (1) {
        scanf("%s", str);
        if (!strcmp(str, "INSERIR")) {
            scanf("%s %f %d", l.nome, &l.valor, &l.quantidade);
            inserir(&head, l.nome, l.valor, l.quantidade);
        }else if(!strcmp(str, "REMOVER")){
            scanf("%f %d", &l.valor, &l.quantidade);
            remover(l.valor, l.quantidade);
        }else if(!strcmp(str, "REMOVERGRUPO")){
            scanf("%f", &l.valor);
            removerGrupo(l.valor);
        }else if(!strcmp(str, "CONSULTAR")){
            consultar(head);
        }else if(!strcmp(str, "PROCURAR")){
            scanf("%s", l.nome);
            procurar(head, l.nome);
        }else{
            break; 
        }
    }
    //scanf("%d", &l.quantidade);
    //printf("%d\n", l.quantidade);

}
// Sairam as notas do Enem

// Descrição

// Para publicar as notas do Enem o INEP vai precisar da sua ajuda. Ele vai lhe fornecer duas sequências,
// uma contendo os CPFs de todos os que se apresentaram à prova e outra contendo as notas correspondentes.
// A correspondência entre CPFs e notas se dá pela posição em ambas sequências, assim, por exemplo, 
// o terceiro elemento na sequência de CPFs tem a nota registrada no terceiro elemento na sequência de notas.
//  Adicionalmente, o INEP terá o cuidado de lhe entregar a sequência dos CPFs ordenada de forma ascendente.

// Dado um CPF, sua missão é retornar a nota do respectivo candidato ou o aviso "NAO SE APRESENTOU" que deverá 
// ser emitido caso o CPF não se encontre na sequência dos CPFs fornecida pelo INEP. Seu programa deverá ser
// eficiente, pois poderão haver muitos inscritos querendo ver as notas e o INEP não quer que o sistema fique 
// sobrecarregado.  

// Serão vários casos de testes dados aqui no thehuxley e, para este fim, podemos supor que os CPFs são números
// inteiros quaisquer.

// Formato de entrada

// O programa receberá as seguintes entradas

// 1. Uma linha com um inteiro n que representa o número de inscritos que se apresentaram à prova.
// 2. Uma sequência de n inteiros,  um por linha, cada um representando um CPF.
// 3. Uma sequência de n inteiros, um por linha, cada um representando uma nota.
// 4. Uma linha com um inteiro m que representa o número de casos de teste.
// 5. Uma sequência de m CPFs, um por linha, para os quais serão pesquisadas as notas.

// Formato de saída

// A nota de cada um dos m CPFs ou a mensagem  "NAO SE APRESENTOU", uma linha para cada consulta.


// Entrada


// 6
// 2
// 4
// 8
// 10
// 15
// 17
// 700
// 100
// 300
// 900
// 750
// 780
// 3
// 10
// 5
// 4


// Saída

// 900
// NAO SE APRESENTOU
// 100

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calc(int N_inscritos, int *inscritos, int *notas, int N_testes, int *testes){
     int i, j;
     for( i = 1; i <= N_testes; i++){
        for(j = 1; j <= N_inscritos; j++){
            if(inscritos[j] == testes[i]){
                printf("%d", notas[i]);
            }else{
                printf("NAO SE APRESENTOU");
            }
        }
     }
}

int main() {
	int i, N_inscritos, N_testes;
    printf("N de inscritos\n"); 
    scanf("%d", &N_inscritos);
    int inscritos[N_inscritos];
    for(i = 1; i <= N_inscritos; i++){
        scanf("%d", &inscritos[i]);
    }

    printf("N de notas\n");
    int notas[N_inscritos];
    for(i = 1; i <= N_inscritos; i++){
      scanf("%d", &notas[i]);  
    }

    printf("N de testes\n");
    scanf("%d", &N_testes);
    int testes[N_testes];
    for(i = 1; i <= N_testes; i++){
        scanf("%d", &testes[i]);  
    }
    printf("acabou\n");
    calc(N_inscritos, inscritos, notas, N_testes, testes);
    return 0;
}
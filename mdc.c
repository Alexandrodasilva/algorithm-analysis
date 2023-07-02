#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//ALGOEITMO DE EUCLIDES
int mdc(int a, int b){
    int aux, r;
    if(b == 0){
        return a;
    }
    return mdc(b, a % b);
}
int main(){
    int a, b;
    scanf("%d",&a );
    scanf("%d", &b);
    printf("%d", mdc(a,b));
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int x, y;
    int index1 =0, index2 =0, valor = 1;
    int *vt1 = NULL;
    int *vt2 = NULL;
    int *vt3 = NULL;

    scanf("%d",&x );
    scanf("%d", &y);

    for(int i = 1; i <= x; i++){
        if(x%i == 0){
            vt1 = (int*)realloc(vt1, (index1 + 1) * sizeof(int));
            vt1[index1] = i;
            index1++;
        }
    }

    for(int i = 1; i <= y; i++){
        if(y%i == 0){
            vt2 = (int*)realloc(vt2, (index2 + 1) * sizeof(int));
            vt2[index2] = i;
            index2++;
        }
    }

    if(index1 > index2){
        vt3 = (int*)malloc(index1* sizeof(int));
        for(int i = 0; i < index1; i++){
            for(int j = 0; j < index2; j++){
                if(vt1[i] == vt2[j]){
                    vt3[index2] = vt2[i];
                    index2++;
                    break;
                }
            }
        }
    }
    else{
        vt3 = (int*)malloc(index2 * sizeof(int));
        for(int i = 0; i < index2; i++){
            for(int j = 0; j < index1; j++){
                if(vt1[i] == vt2[j]){
                    vt3[i] = vt2[i];
                    break;
                }
            }
        }
    }
    for(int i = 0; i < index2; i++){
        if(vt3[i] > valor){
            valor = vt3[i];
        }
    }
   printf("%d\n", valor);
    free(vt1);
    free(vt2);
    free(vt3);
    return 0;
}
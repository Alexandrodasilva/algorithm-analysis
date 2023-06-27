#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc(int x, int y){
    while((x < y && y % x) || (y < x && x % y)){
        if(x < y){
            y -=x; 
        }else{
            x -=y;
        }
    }

}
int main(){
    int x, y;

    scanf("%d",&x );
    scanf("%d", &y);
    mdc(x, y);
    printf("%d", mdc(x, y));
    return 0;
}
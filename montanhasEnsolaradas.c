#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i, j, c, n, coord[30000][8848];
    scanf("%d", &c);
    for(i = 0; i < c; i++){
        scanf("%d", &n);
        for(j = 0; j < n; j++){
            scanf("%d %d", coord[j][j]);
        }
    }
	return 0;
}
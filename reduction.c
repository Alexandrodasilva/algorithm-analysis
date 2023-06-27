#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void reduction(float *x, float *y){
    &x -=&y;
    return printf("%.2f %.2f", *x, *y);
}

int main() {
    float x, y;
    scanf("%f", &x);
    scanf("%f", &y);
    reduction(&x, &y);
	return 0;
}
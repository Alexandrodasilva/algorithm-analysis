#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void reduction(float *ptr_x, float *ptr_y){
    *ptr_x -=*ptr_y;
    printf("%.2f %.2f", *ptr_x, *ptr_y);
}

int main() {
    float x, y;
    float *ptr_x, *ptr_y;
    scanf("%f", &x);
    scanf("%f", &y);
    ptr_x = &x, ptr_y = &y;
    reduction(ptr_x, ptr_y);
	return 0;
}
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define COORD_MAX 4.2e9
#define MAX_POINTS 1e6
#define EPSILON 0.00001

typedef struct {
  long unsigned int x;
  long unsigned int y;
} t_point;


int main(int argc, char* argv[]){
  int n, l, i;
  t_point* pontos;
  t_point p;
  
  n = atoi(argv[1]); //número de pontos
  l = atoi(argv[2]); //limite de alcance
  
  if((n-1)*(n-1) > COORD_MAX){
  	printf("Limite de coordenada ultrapassado.\n");
  	return 1;
  }
  
  pontos = (t_point *)malloc(n*sizeof(t_point));
  
  //Os pontos são gerados segundo a função y = x*x, ,o que garante que os pontos estarão em posição geral sem precisar realizar nenhum teste. Deve-se observar, porém, que desta forma, todos os pontos estarão sobre a envoltória convexa.
  for(i = 0; i < n;i++){
    p.x = i;
    p.y = i*i;
		pontos[i] = p;
  }
  
  printf("%d %d\n", n, l);
  for(i = 0; i < n; i++)
    printf("%lu %lu\n", pontos[i].x, pontos[i].y);

  return 0;
}




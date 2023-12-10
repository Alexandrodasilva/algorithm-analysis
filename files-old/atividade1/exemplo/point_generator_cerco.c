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

int check_gp(t_point p, t_point* points, int n){
  int i, j;
  long long int a, b, c;
  for(i = 0; i < n-1; i++){
    for(j = i+1; j < n; j++){
      a = (long long)points[j].y-(long long)points[i].y;
      b = (long long)points[i].x-(long long)points[j].x;
      c = ((long long)points[i].x*(long long)points[j].y) - ((long long)points[i].y*(long long)points[j].x);
      if(a*p.x + b*p.y < EPSILON && a*p.x + b*p.y > -EPSILON){
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char* argv[]){
  int n, l, i;
  t_point* pontos;
  t_point p;
  
  n = atoi(argv[1]); //número de pontos
  l = atoi(argv[2]); //limite de alcance
  
  pontos = (t_point *)malloc(n*sizeof(t_point));
  
  srand((uint)time(NULL));
  
  for(i = 0; i < n;){
    p.x = rand()%(long unsigned)COORD_MAX;
    p.y = rand()%(long unsigned)COORD_MAX;
    //Se precisar que os pontos sejam em posição geral, descomentar o bloco if a seguir
    //Os pontos são gerados aleatoriamente e cada vez que um ponto novo vai ser acrescentado, testa-se se a regra de posição geral é respeitada. Em caso positivo o ponto é acrescentado, em caso negativo, gera-se outro ponto aleatoriamente. Este procedimento é altamente ineficiente, mas é uma solução rápida para gerar um conjunto pequeno de pontos. 
    if(i < 2 || check_gp(p, pontos, i))
      pontos[i++] = p;
  }
  
  printf("%d %d\n", n, l);
  for(i = 0; i < n; i++)
    printf("%lu %lu\n", pontos[i].x, pontos[i].y);

  return 0;
}




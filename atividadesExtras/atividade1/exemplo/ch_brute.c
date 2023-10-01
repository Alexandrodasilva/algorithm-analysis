#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long llint;

typedef struct {
  llint x;
  llint y;
} tpoint;

typedef struct{
  tpoint p1;
  tpoint p2;
} tedge;

typedef struct{
  llint a;
  llint b;
  llint c;
} tlineeq;

tlineeq line_coefs(tpoint p1, tpoint p2){
  tlineeq eq;
  eq.a = p2.y-p1.y;
  eq.b = p1.x-p2.x;
  eq.c = p1.x*p2.y-p1.y*p2.x;
  return eq;
}

llint apply_line(tlineeq line, tpoint p){
  return line.a*p.x+line.b*p.y-line.c;
}

double dist(tpoint p, tpoint q){
	return sqrt(pow((double)(p.x)-(double)(q.x), 2)+pow((double)(p.y)-(double)(q.y), 2));
}

int main(){
	long unsigned i, j, k, n, m = 0, l, l1, l2;
	llint cont = 0;
	llint d;
	double distancia;
	tpoint* pontos;
	tedge *arestas;
  tlineeq linha;
	
	scanf("%lu %lu", &n, &l);
	pontos = (tpoint *)malloc(n*sizeof(tpoint));
	for(i = 0; i < n; i++){
		scanf("%lld %lld", &pontos[i].x, &pontos[i].y);
	}

  arestas = (tedge *)malloc(n*sizeof(tedge));
  
  for (i = 0; i < n-1; i++){
    for(j = i+1; j < n; j++){
      linha = line_coefs(pontos[i], pontos[j]);
      l1 = 0;
      l2 = 0;
      for(k = 0; k < n; k++){
        d = apply_line(linha, pontos[k]);
        if(d < 0) l1++;
        if(d > 0) l2++;
        if(l1 > 0 && l2 > 0) break;
      }
      if(l1 == 0 || l2 == 0){
        cont++;
				arestas[m].p1 = pontos[i];
        arestas[m++].p2 = pontos[j];
        distancia = dist(pontos[i], pontos[j]);
        if(distancia > l) cont = cont + (llint)(ceil(distancia/l)-1);
      }
    }
  }
  
  printf("%lld\n", cont);
  
  free(pontos);
  free(arestas);
  return 0;
}

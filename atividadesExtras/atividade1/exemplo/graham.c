#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.000001

typedef struct{
	long unsigned x;
	long unsigned y;
} tpoint;

typedef struct{
	tpoint* content;
	long unsigned size;
} tstack;

double dist(tpoint p, tpoint q){
	return sqrt(pow((double)(p.x)-(double)(q.x), 2)+pow((double)(p.y)-(double)(q.y), 2));
}

long long int det(tpoint p1, tpoint p2, tpoint p3){
	return (p1.x*p2.y + p3.x*p1.y + p2.x*p3.y - p3.x*p2.y - p2.x*p1.y - p1.x*p3.y);
}

double cross(tpoint p0, tpoint p1, tpoint p2){
	tpoint p1_, p2_;
	p1_.x = p1.x-p0.x;
	p1_.y = p1.y-p0.y;
	p2_.x = p2.x-p0.x;
	p2_.y = p2.y-p0.y;
	
	return p1_.x*p2_.y - p2_.x*p1_.y;
}

long long int cross_prod(tpoint p1, tpoint p2){
	return (p1.x)*(p2.y)-(p1.y)*(p2.x);
}

void push(tpoint p, tstack *s){
	s->content[s->size++] = p;
	return;
}

tpoint pop(tstack *s){
	return s->content[s->size = s->size-1];
}

int comp(const void *a, const void *b){
	long long cp;
	tpoint p1 = *(tpoint *)a;
	tpoint p2 = *(tpoint *)b;
	
	cp = cross_prod(p2,p1);
	
	if(cp > 0) return 1;
	else if(cp < 0) return -1;
	else return 0;
}

tstack grahamScan(tpoint pontos[], long unsigned n){
	long unsigned i, j, m;
	long unsigned x, y;
	tpoint menor_y = pontos[0];
	tpoint p;
	long unsigned ind_menor_y = 0;
	tpoint* pontos2;
	tstack s;
	
	pontos2 = (tpoint *)malloc(n*sizeof(tpoint));
	
	for(i = 1; i < n; i++){
		if(pontos[i].y < menor_y.y){
			menor_y = pontos[i];
			ind_menor_y = i;
		}
		if(pontos[i].y > menor_y.y - EPSILON && pontos[i].y < menor_y.y + EPSILON){
			if(pontos[i].x < menor_y.x){
				menor_y = pontos[i];
				ind_menor_y = i;
			}
		}
	}
	
	x = menor_y.x;
	y = menor_y.y;
	
	for(i = 0, j = 0; i < n; i++){
		if(i != ind_menor_y){
			pontos2[j].x = pontos[i].x-x;
			pontos2[j++].y = pontos[i].y-y; 
		}
	}
	
	qsort(pontos2, n-1, sizeof(tpoint), comp);
	
	
	s.content = (tpoint *)malloc(n*sizeof(tpoint));
	s.size = 0;
	tpoint zero = {0, 0};
	push(zero, &s);
	push(pontos2[0], &s);
	push(pontos2[1], &s);
	
	for(i = 2; i < n-1; i++){
		while(det(s.content[s.size-2], s.content[s.size-1], pontos2[i]) < 0) pop(&s);
		push(pontos2[i], &s);
	}
	
	m = s.size;
	for(i = 0; i < m; i++){
		p = pop(&s);
		pontos2[i].x = p.x+x;
		pontos2[i].y = p.y+y;
	}
	for(i = 0; i < m; i++){
		push(pontos2[i], &s);
	}

	free(pontos2);
	return s;
}

int main(){
	long unsigned i, n, l;
	long long unsigned int cont = 0;
	double d;
	tpoint* pontos;
	tpoint p, q, first;
	tstack s;
	
	scanf("%lu %lu", &n, &l);
	pontos = (tpoint *)malloc(n*sizeof(tpoint));
	for(i = 0; i < n; i++){
		scanf("%lu %lu", &pontos[i].x, &pontos[i].y);
	}
	
	s = grahamScan(pontos, n);

	first = p = pop(&s);
	cont++;

	while(s.size > 0){
		q = pop(&s);
		cont++;
		d = dist(p, q);

		if(d > l) cont = cont + (long long unsigned)(ceil(d/l)-1);
		p = q;
	}

	d = dist(p, first);

	if(d > l) cont = cont + (long long unsigned)(ceil(d/l)-1);

	
	printf("%llu\n", cont);
	
	free(s.content);
	free(pontos);
	
	return 0;
}

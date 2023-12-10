#include <stdio.h>

typedef struct{
  char codigo[11], cnpj[18];
  int peso;
}Container;


void ver(Container c, int q){
  for(int i = 0; i < q; i++){
    printf("print: %s %s %d\n", c[i].codigo, c[i].cnpj, c[i].peso);
  }
}
int main(void) {
  FILE *file = fopen("input.txt", "r");
  if(file == NULL){
    perror("erro ao abrir o arquivo");
    return 1;
  }

  int i, quant;
  while(fscanf(file,"%d",&quant) == 1){
    Container c[quant];
    for(i = 0; i < quant; i++){
      fscanf(file, "%s %s %d", c[i].codigo, c[i].cnpj, &c[i].peso);
      ver(c, quant);
    }
  }
  fclose(file);
  return 0;
}
#include <stdio.h>

int main() {

  int N, M;
  int i = 0, j = 0;
  scanf("%d", &N);
  int fila[N];
  // input primeiro array
  while (i < N && scanf("%d", &fila[i]) == 1)
    i++;

  scanf("%d", &M);
  int remover[M];
  // input segundo array
  while (j < M && scanf("%d", &remover[j]) == 1)
    j++;

  // compara e remove o item
  int novo[N - M];
  int aux = 0;
  int achou;
  for(i = 0; i < N; i++){
    achou = 0;
    for(j=0; j<M; j++){
        if(fila[i] == remover[j]){
            achou = 1;
            break;
        }
    }
    if(!achou){
        novo[aux] = fila[i];
        aux++;
    }
  }

  for (size_t i = 0; i < N - M; i++) {
    printf("%d ", novo[i]);
  }

  return 0;
}

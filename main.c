#include <stdio.h>
#include <string.h>

int main() {

  int N, M;
  int i = 0, j = 0;
  scanf("%d", &N);
  int fila[N];
  scanf("%d", &M);
  int remover[M];
  //char * token = strtok(fila, " ");
  //char * toke = strtok(remover, " ");

  // input primeiro array
  while (i < N && scanf("%d", &fila[i]) == 1) {
    i++;
  }
  // input segundo array
  while (j < M && scanf("%d", &remover[j]) == 1) {
    j++;
  }
  // compara e remove o item
  i = 0;
  j = 0;
  while (1) {
    if (j == (M - 1)) {
      break;
    }
    else if (fila[i] == remover[j]) {
      fila[i] = fila[i + 1];
      j++;
      i = 0;
    }
    i++;
  }

  for (size_t i = 0; i < sizeof(fila); i++) {
    printf("%d ", fila[i]);
  }

  return 0;
}

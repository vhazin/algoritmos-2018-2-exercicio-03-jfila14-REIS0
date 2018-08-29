#include <stdio.h>
#include <string.h>

int main() {

  int N, M;
  int i = 0, j = 0;
  scanf("%d", &N);
  char fila[N];
  gets(fila);
  scanf("%d", &M);
  char remover[M];
  gets(remover);
  char * token = strtok(fila, " ");
  char * toke = strtok(remover, " ");

  // split primeiro array
  for (i = 0; token != NULL; i++) {
    fila[i] = *token;
    token = strtok(NULL, " ");
  }
  // split segundo array
  for (size_t i = 0; toke != NULL; i++) {
    remover[i] = *toke;
    toke = strtok(NULL, " ");
  }
  // compara e remove o item
  while (j < M) {
    if (fila[i] == remover[j]) {
      fila[i] = fila[i + 1];
      j++;
    }
    i++;
  }
  printf("%s", fila);

  return 0;
}

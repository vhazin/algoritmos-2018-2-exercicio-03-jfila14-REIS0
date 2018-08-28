#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct node {
  int val;
  struct node * next;
} ;

int main() {
  // input dos dados
  int count = 0;
  int N, M;
  gets("%d", &N);
  gets("%d", &M);
  int lista[N];
  int remover[M];
  // condicionais para programa
  if (M > N || N > 50000 || M > 50000) {
    return 0;
  }




  return 0;
}

#include <stdio.h>
#include <stdlib.h>

// cria um nó
typedef struct node {
  int data;
  struct node * next;
} node;

// criando fila
typedef struct fila {
  int size;
  struct node * begin;
  struct node * end;
} fila;


fila * createlist();
int insert(fila * FILA, int value);
void delete(fila * FILA, int value);
void displaylist(fila * FILA);
void destroy(fila * FILA);


int main() {

  int e, i = 0;
  int N, M;
  fila * FILA = createlist();
  printf("");
  scanf("%d", &N);
  if (N < 1 || N > 50000) {
    return 0;
  }

  while (i < N && scanf("%d", &e) == 1) {
    insert(FILA, e);
    i++;
  }
  // numeros que seram removidos
  scanf("%d", &M);
  if (M < 1 || M > 50000 || M > N) {
    return 0;
  }

  i = 0;
  while (i < M && scanf("%d", &e) == 1) {
    delete(FILA, e);
    i++;
  }

  displaylist(FILA);
  free(FILA);

  return 0;
}

// cria a fila
fila * createlist() {

  fila * head;
  head = (fila*)malloc(sizeof(fila));

  if (head != NULL) {
    head->size = 0;
    head->begin = NULL;
    head->end = NULL;
  }
  return head;
}

// inserir item na fila
int insert(fila * FILA, int value) {

  node * new;
  new = (node*)malloc(sizeof(node));
  new->data = value;
  new->next = NULL;

  if (new == NULL) {
    return 0;
  }
  else if (FILA->begin == NULL){
    FILA->begin = new;
    FILA->end = new;
    FILA->size = 1;
  }
  else {
    FILA->end->next = new;
    FILA->end = new;
    FILA->size = FILA->size + 1;
  }
  return 1;
}

//excluir em qualquer posição da fila
void delete(fila * FILA, int value) {

  node * aux;
  node * before;
  aux = FILA->begin;
  before =  NULL;

  while (aux != NULL) {
    if (aux->data == value) {
      // primeiro item da fila
      if (before == NULL) {
        FILA->begin = aux->next;
        break;
      }
      // ultimo item da fila
      else if (aux->next == NULL) {
        FILA->end = before;
        before->next = NULL;
        break;
      }
      // meio da fila
      else {
        before->next = aux->next;
        break;
      }
      FILA->size = FILA->size - 1;
    }
    else {
      before = aux;
      aux = aux->next;
    }
  }
}

// mostrar os elementos da fila na tela
void displaylist(fila * FILA) {

  node * p = FILA->begin;

  while (p != NULL)  {
    printf("%d ", p->data);
    p = p->next;
  }

}

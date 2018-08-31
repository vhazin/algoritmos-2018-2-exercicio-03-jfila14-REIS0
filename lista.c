#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  int val;
  struct node * next;
} node ;

typedef struct List {
  int size;
  node * begin;
  node * end;
} list ;

list * createlist();
void addlist(list * head, int * val);
void empty(list * head);
void retirar(list * head, int value);
void display(node * head);
void destroy(node ** head);

int main() {
 N);
  int i = 0, j = 0;
  int s;
  int N, M;
  scanf("%d", &N);
  int fila[N];
  while (i != N){
    scanf("%d", &s);
    addlist(list * head, s);
    i++;
  }
  scanf("%d", M);
  int remover[M];
  while (j < N && scanf("%d", &remover[j]) == 1)
    j++;

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      if (fila[i] == remover[j]) {
        retirar(list * head, i);
      }
    }
  }

  display(node * head);
  destroy(node * head);

  return 0;
}



list * createlist() {
  list * head;
  head = malloc(sizeof(list));

  if (head != NULL) {
    head->size = 0;
    head->data = NULL;
  }
  return (head);
}


void addlist(list * head, int * val) {

  node * new;
  new = malloc(sizeof(node));

  if (new == NULL) {
    return 0;
  }
  else {
    new->next = NULL;
    new->val = val;
    head->end->next = val;
    head->end = new;
    head->size = head->size + 1;
    return 1;
  }
}


void empty(list * head) {
  if (head->size == 0) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}


void retirar(list * head, int value) {

  node * before;
  node * aux;
  int * back;
  aux = head->data;

  while (aux != NULL) {
    if (aux->val == value) {
      if (before == NULL) {
        head->data = aux->next;
      }
      else{
        before->next = (head->size - 1);
      }
      head->size = (head->size - 1);
      return 1;
    }

  before = aux;
  aux = aux->next;
  }
}


void display(node * head) {
  while (head != NULL) {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
}


void destroy(node * head){

  node * now;
  node * before;

  if (empty(head)) {
    free(head);
  }
  else {
    now = head->val;
    while (now != NULL) {
      before = now;
      now = now->next;
      free(before->val);
      free(before);
    }
    free(head);
  }

}

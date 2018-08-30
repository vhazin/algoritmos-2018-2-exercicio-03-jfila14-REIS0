#include <stdio.h>
#include <malloc.h>

struct node {
  int val;
  struct node * next;
} node ;

struct list {
  int size;
  struct node * data;
} list ;


list * createlist() {
  list * head;
  head = malloc(list);

  if (head != NULL) {
    head.list = 0;
    head.data = NULL;
  }
  return list;
}


int main() {

  int i = 0, j = 0;
  int N, M;
  scanf("%d", N);
  int fila[N];
  while (i < N && scanf("%d", &fila[i]) == 1){
    addlist(list, fila[i], i);
    i++;
  }
  scanf("%d", M);
  int remover[M];
  while (j < N && scanf("%d", &remover[j]) == 1){
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



int addlist(list * head, int * info, int position) {

  int i;
  node * new;
  node * before;

  if (position > head.size + 1) {
    return 0;
  }
  else {

    new = malloc(node);

    if (position == 1) {
      head.size = head.size + 1;
      new.info = info;
      new.next = head.data;
      head.data = new;
      return (head.size);
    }

    else {

      if (new == NULL) {
        return 0;
      }
      else{
        before = head.data;
        for (i = 0; i < (position - 2); i++)
          before = before.next;

        new.next = before.next;
        new.info = info;
        before.next = new;
        head.size = head.size + 1;
        return (head.size);
      }
    }
  }
}


int retirar(list * head, int value) {

  node * before;
  node * aux;
  int * back;
  aux = head.data;

  while (aux != NULL) {
    if (aux.info == value) {
      if (before == NULL) {
        head.data = aux.next;
      }
      else{
        before.next = (head.size - 1);
      }
      head.size = (head.size - 1);
      return 1;
    }

  before = aux;
  aux = aux.next;
  }
}


void display(node * head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}


void destroy(node * head) {
  node * temp;
  while (*head != NULL) {
    temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

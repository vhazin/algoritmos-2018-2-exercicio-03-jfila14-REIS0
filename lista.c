#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  int val;
  struct node * next;
} node ;

typedef struct List {
  int size;
  struct node * data;
} list ;


list * createlist() {
  list * head;
  head = malloc(sizeof(list));

  if (head != NULL) {
    head->size = 0;
    head->data = NULL;
  }
  return (head);
}

int addlist(list * head, int * val, int position) {

  int i;
  node * new;
  node * before;

  if (position > head->size + 1) {
    return 0;
  }
  else {

    new = malloc(sizeof(node));

    if (position == 1) {
      head->size = head->size + 1;
      new->val = val;
      new->next = head->data;
      head->data = new;
      return (head->size);
    }

    else {

      if (new == NULL) {
        return 0;
      }
      else{
        before = head->data;
        for (i = 0; i < (position - 2); i++)
          before = before->next;

        new->next = before->next;
        new->val = val;
        before->next = new;
        head->size = head->size + 1;
        return (head->size);
      }
    }
  }
}


int retirar(list * head, int value) {

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


void destroy(node * head) {
  node * temp;
  node * before;

  if (empty(head)) {
    free(head);
  }
  else {
    temp = head->data;

    while (temp != NULL) {
      before = temp;
      temp = temp->next;
      free(before->val);
      free(before);
    }
    free(head);
  }

}



int main() {

  int i = 0, j = 0;
  int N, M;
  scanf("%d", N);
  int fila[N];
  while (i < N && scanf("%d", &fila[i]) == 1){
    addlist(list * head, fila[i], i);
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

#include <stdio.h>
#include <malloc.h>

// cria um nó
typedef struct node {
  int data;
  struct node * next;
} node;

typedef struct fila {
  struct node * begin;
  struct node * end;
} fila;


node * createlist(int N);
void displaylist(node * head);


int main() {

  int N, M;
  node * HEAD = NULL;
  printf("N: ");
  scanf("%d", &N);
  HEAD = createlist(N);

  displaylist(HEAD);

  return 0;
}


node * createlist(int N) {

  int i;
  node * head = NULL; // primeiro item da lista
  node * temp = NULL; // nó após o primeiro
  node * p = NULL; // posição para adicionar o nó

  // criando nó
  for (i = 0; i < N; i++) {
    temp = (node*)malloc(sizeof(node));
    printf("%d : ", i + 1);
    scanf("%d", &(temp->data));
    temp->next = NULL;

    // se a lista não conter items, temp irá virar primeiro item
    if (head == NULL) {
      head = temp;
    }
    // adiciona o nó ao final da lista
    else {
      p = head; // p se torna o primeiro item da lista
      while (p != NULL) // intera até p ser o ultimo da lista
        p = p->next;
      p->next = temp; // o ponteiro do antigo ultimo nó da lista se torna o novo nó que se torna o ultimo item da lista
    }
  }
  return head;
}


void displaylist(node * head) {

  node * p = head;
  // printa os elementos da lista
  while (p->next != NULL)  {
    printf("%d", p->data);
    p = p->next;
  }

}

#include <stdio.h>
#include <malloc.h>

struct node {
  int val;
  struct node * next;
} ;

int main() {

  int count = 0;
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  int remover[M];
  if (M > N || N > 50000 || M > 50000) {
    return 0;
  }

  else {
    struct note * head = NULL;
    struct node ** current = &head; // current refers there, where next node has to be placed

    while (count < N) { // do it for "N" nodes
      *current = malloc(sizeof(struct node)); // allocate memory for the node right to the target
      scanf("%d", &((*current)->val));        // read the data
      (*current)->next = NULL;                // node is last node in list, so its sucessor is NULL
      current = &((*current)->next);          // step on foward
      count++;
    }

    while (count < M) {
      scanf("%d", remover[count]);
      count++;
    }

    // print the list
    struct node * temp = head;
    while (temp != NULL) {
      printf("%d", temp->val);
      temp = temp->next;
    }

    // free the list at the end
    while (head != NULL) {
      struct node * next = head->next;
      free(head);
      head = next;
    }

  }
  return 0;
}

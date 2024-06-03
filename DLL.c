#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
  int info;
  struct node *prev, *next;
} node;

node* insertionSorted(node* head, int info){
  node* t;
  node* temp = malloc(sizeof(node));
  temp->info = info;
  temp->prev = NULL;
  temp->next = NULL;

  if(head == NULL){
    head = temp;
  }
  else if(head->info > info){
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  else{
    t = head;

    while(t->next != NULL && t->next->info < info)
      t = t->next;
    temp->next = t->next;
    temp->prev = t;
    t->next = temp;
  }

  return head;
}

void display(node* t)
{
  printf("Printing your linked list.......\n");
  while(t!=NULL)
  {
    if(t->next == NULL)
      printf("%d", t->info);
    else
      printf("%d -> ", t->info);
    t = t->next;
  }

  printf("\n");	
}

int main(void) {
  srand(time(0));
  node *head = NULL;
  int info;

  for(int i = 0; i < 10; i++){
    info = rand() % 20;
    head = insertionSorted(head, info);
    display(head);
  }
}
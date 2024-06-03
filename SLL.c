#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// James Phillips
// 6/3/24
// These are my practice notes while I learn about linked lists

typedef struct node{
  int info;
  struct node* next;
} node;

// If head is null, make temp the head. Else, make
// temp->next equal head and then set temp to be head.
node* insertBeginning(node* head, int info){
  node *temp = malloc(sizeof(node));
  temp->next = NULL;
  temp->info = info;

  if(head == NULL)
    head = temp;
  else{
    temp->next = head;
    head = temp;
  }

  return head;
}

// If head is null, temp becomes head, else traverse
// until t->next is null (end of the list) and make
// t->next temp
node* insertEnd(node* head, int info){
  node *t;
  node *temp = malloc(sizeof(node));
  temp->next = NULL;
  temp->info = info;
  
  if(head==NULL)
    head=temp;
  else{
    t = head;
    while(t->next != NULL){
      t = t->next;
    }
    t->next = temp;
  }
  return head;
}

// Make an ascending order linked list
// If head is null or info is smaller than head info
// then place at the begnning like in the insertBeginning
// funciton. Otherwise traverse through the list until the last
// t->next value that is smaller than info. Then if t->next
// is null (end of the list) just make t->next be temp. Otherwise
// temp->next = t->next and t->next = temp.
node* insertSorted(node* head, int info){
  node *t;
  node *temp = malloc(sizeof(node));
  temp->next = NULL;
  temp->info = info;

  if(head == NULL || head->info > info){
    temp->next = head;
    head=temp;
  }
  else{
    t = head;
    while(t->next != NULL && t->next->info < info)
      t = t->next;
    temp->next = t->next;
    t->next = temp;
  }
  return head;
}

// Delete node with info matching passed input info
// If head == NULL, head is just returned.
// If head is to be deleted, move head down the linked list
// and delete the previous head
// Otherwise traverse until the next node's info is what you
// want to delete, set the traverse node's next to be the one 
// after that, and delete the matching node.
// After the traversal while loop, I could also just return
// if t->next is NULL but I just check again to preserve 
// readability and return right at the end.
node* deleteNode(node *head, int info){
  node *t;
  node *temp = malloc(sizeof(temp));

  if(head != NULL && head->info == info){
    temp = head;
    head = head->next;
    free(temp);
  }
  else if(head != NULL){
    t = head;

    while(t->next != NULL && t->next->info != info)
      t = t->next;

    if(t->next != NULL && t->next->info == info){
      temp = t->next;
      t->next = t->next->next;
      free(temp);
    }
  }

  return head;
}

// Print out the linked list info
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
  int choice = 1, info;
  node* head = NULL;

  // Randomly fill it with 6 numbers to work with
  for(int i = 0; i < 10; i++){
    info = rand() % 20;
    head = insertSorted(head, info);
    display(head);
  }

  // Choice menu for insertion. Inserting in the beginning or
  // end after the auto fill will probably mess up the sorted
  // insert after.
  while(choice >= 1 && choice <= 4){
    scanf("%d", &choice);
    if(choice == 1){
      scanf("%d", &info);
      head = insertEnd(head, info);
      display(head);
    }
    else if(choice == 2){
      scanf("%d", &info);
      head = insertBeginning(head, info);
      display(head);
    }
    else if(choice == 3){
      scanf("%d", &info);
      head = insertSorted(head, info);
      display(head);
    }
    else if(choice == 4){
      scanf("%d", &info);
      head = deleteNode(head, info);
      display(head);
    }
  }
}
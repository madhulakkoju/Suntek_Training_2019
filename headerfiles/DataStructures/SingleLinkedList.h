/*
Madhu 
17241A05F3

TWO TYPES OF LINKED LIST are declared. 
one is a Size Limited LINKED LIST = SingleLinkedList_size
and 
other is a Size Unlimited Linked List =  SingleLinkedList
and other corresponding operations

OPERATION                           FUNCTION LIMITED SIZED LIST                                   FUNCTION UNLIMITED LIST
-------------------------------------------------------------------------------------------------------------------------------------------------------------
CREATE LL             || SingleLinkedList_size* createLinkedList_size(int length)         SingleLinkedList* createLinkedList()
INSERT NODE AT        || void InsertAt_LL_size(SingleLinkedList_size* s, int val,int position)   void InsertAt_LL(SingleLinkedList* s, int val,int position)
INSERT NODE AT BEGIN  || void InsertBeginning_LL_size(SingleLinkedList_size* s, int val)  void InsertBeginning_LL(SingleLinkedList* s, int val)
INSERT NODE AT END    || void InsertEnd_LL_size(SingleLinkedList_size* s, int val)        void InsertEnd_LL(SingleLinkedList* s, int val)
DELETE BEGINNING NODE || int delete_Beginning_LL_size(SingleLinkedList_size* s)           int delete_Beginning_LL(SingleLinkedList* s)
DELETE ENDING NODE    || int delete_End_LL_size(SingleLinkedList_size *s)                 int delete_End_LL(SingleLinkedList *s)
DELETE NODE AT        || int deleteNode_LL_size(SingleLinkedList_size* s,int position)    int deleteNode_LL(SingleLinkedList* s,int position)
PRINT ALL ELEMENTS    || void print_LL_size(SingleLinkedList_size* s)                     void print_LL(SingleLinkedList* s)

*/

#include<stdlib.h>
// Integer typed Single List node 
typedef struct SingleLinkedListNode 
{
  int data ;
  struct SingleLinkedListNode *next;
}SingleLinkedListNode;
// Fixed size Single Linked List 
typedef struct SingleLinkedList_size 
{
  int filled;
  int length;
  SingleLinkedListNode *head;
}SingleLinkedList_size;
// Single linked list without specific size
typedef struct SingleLinkedList // 
{
  int filled;
  SingleLinkedListNode *head;
}SingleLinkedList;

/*-------------------LINKED LIST APPLICATIONS FOR FIXED SIZE ------------*/


// To create a linked list without any size specifications
SingleLinkedList_size* createLinkedList_size(int length)
{
  SingleLinkedList_size* s = (SingleLinkedList_size*)malloc(sizeof(SingleLinkedList_size));
  s->length = length;
  s->filled =0;
  return s;
}

// To find whether the Linked list is Full or not
int isFull_LL_size(SingleLinkedList_size* s)
{
  if(s->filled == s->length) return 1;
  else return 0;
}

// To find if the list is Empty or not.
int isEmpty_LL_size(SingleLinkedList_size* s)
{
  if(s->filled==0)return 1;
  else return 0;
}

// A generic function to Insert a node at aposition desired to
void InsertAt_LL_size(SingleLinkedList_size* s, int val,int position)
{
  if(isFull_LL_size(s))
  {
    printf("LINKED LIST FULL");
    return;
  }
  if(position == 0)
  {
    SingleLinkedListNode *newnode = (SingleLinkedListNode *)malloc(sizeof(SingleLinkedListNode));
  newnode->data = val;
  newnode->next = s->head;
  s->head = newnode;
  s->filled += 1;
  return;
  }
  if(position >= s->filled )
  {
    SingleLinkedListNode *temp = s->head;
    SingleLinkedListNode *newnode = (SingleLinkedListNode *)malloc(sizeof(SingleLinkedListNode));
    newnode->data = val;
    while(temp->next != NULL )
    {
      temp = temp->next;
    }
    temp->next = newnode;
    s->filled += 1;
    return;
  }
  int counter =0;
  SingleLinkedListNode *temp = s->head;
  SingleLinkedListNode *temp2;
  while(counter < position)
  {
    temp2 =temp;
    temp = temp->next;
    counter++;
  }
  SingleLinkedListNode *newnode = (SingleLinkedListNode *)malloc(sizeof(SingleLinkedListNode));
  newnode->data = val;
  newnode->next = temp;
  temp2->next = temp;
  s->filled += 1;
  return;
}

// To Insert a node at beginning of te linked list.
void InsertBeginning_LL_size(SingleLinkedList_size* s, int val)
{
  InsertAt_LL_size(s,val,0);
  return;
}

// To Insert a node at end of the linked list
void InsertEnd_LL_size(SingleLinkedList_size* s, int val)
{
  InsertAt_LL_size(s,val,s->filled);
  return;
}

// To print all the elements from the Linked List 
void print_LL_size(SingleLinkedList_size* s)
{
  SingleLinkedListNode *temp = s->head;
  while(temp!= NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

//A generic function to delete a node from any position in the Linked List.
int deleteNode_LL_size(SingleLinkedList_size* s,int position)
{
  if(isEmpty_LL_size(s))
  {
    printf("Linked List Empty\n");
    return -1;
  }
  if(position ==0)
  {
    int val = s->head->data;
    SingleLinkedListNode *temp = s->head;
    s->head = s->head->next;
    free(temp);
    s->filled -=1;
    return val;
  }
 
  SingleLinkedListNode *temp = s->head;
  SingleLinkedListNode *temp2 = s->head;
  int counter = 0 ;
  while(counter < position)
  {
    temp2 = temp;
    temp = temp->next;
    counter++;
  }
  temp2->next = temp->next;
  int val = temp->data;
  free(temp);
  s->filled -=1;
  return val;
}

// To delete a node from the beginning of the Linked List
int delete_Beginning_LL_size(SingleLinkedList_size* s)
{
  return( deleteNode_LL_size(s, 0) );
}

// To delete a node from the end of the Linked List
int delete_End_LL_size(SingleLinkedList_size *s)
{
  return(deleteNode_LL_size(s,s->filled-1));
}


/*------------------------------ Linked List APPLICATIONS without Size specifications -------------------------------------------------------------------*/

// To create a linked list without any size specifications
SingleLinkedList* createLinkedList()
{
  SingleLinkedList* s = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));
  s->filled = 0;
  return s;
}

// To find whether the Linked list is Full or not
int isFull_LL(SingleLinkedList* s)
{
  if(malloc(sizeof(SingleLinkedList))== NULL) return 1; // True is FULL
  else return 0; // False is Not Full
}

// To find if the list is Empty or not.
int isEmpty_LL(SingleLinkedList* s)
{
  if(s->filled==0)return 1;// True is Empty
  else return 0; // False is Empty
}

// To find out the length of Linked List
int length_LL(SingleLinkedList* s)
{
  return s->filled;
}

// A generic function to Insert a node at aposition desired to
void InsertAt_LL(SingleLinkedList* s, int val,int position)
{
  if(isFull_LL(s))
  {
    printf("LINKED LIST FULL");
    return;
  }
  if(position == 0)
  {
    SingleLinkedListNode *newnode = (SingleLinkedListNode *)malloc(sizeof(SingleLinkedListNode));
    newnode->data = val;
    newnode->next = s->head;
    s->head = newnode;
    s->filled += 1;
    return;
  }
  if(position >= s->filled )
  {
    SingleLinkedListNode *temp = s->head;
    SingleLinkedListNode *newnode = (SingleLinkedListNode *)malloc(sizeof(SingleLinkedListNode));
    newnode->data = val;
    while(temp->next != NULL )
    {
      temp = temp->next;
    }
    temp->next = newnode;
    s->filled += 1;
    return;
  }
  int counter =0;
  SingleLinkedListNode *temp = s->head;
  SingleLinkedListNode *temp2;
  while(counter < position)
  {
    temp2 =temp;
    temp = temp->next;
    counter++;
  }
  SingleLinkedListNode *newnode = (SingleLinkedListNode *)malloc(sizeof(SingleLinkedListNode));
  newnode->data = val;
  newnode->next = temp;
  temp2->next = newnode;
  s->filled += 1;
  return;
}

// To Insert a node at beginning of te linked list.
void InsertBeginning_LL(SingleLinkedList* s, int val)
{
  InsertAt_LL(s,val,0);
  return;
}

// To Insert a node at end of the linked list
void InsertEnd_LL(SingleLinkedList* s, int val)
{
  InsertAt_LL(s,val,s->filled);
  return;
}

// To print all the elements from the Linked List 
void print_LL(SingleLinkedList* s)
{
  SingleLinkedListNode *temp = s->head;
  while(temp!= NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

//A generic function to delete a node from any position in the Linked List.
int deleteNode_LL(SingleLinkedList* s,int position)
{
  if(isEmpty_LL(s))
  {
    printf("Linked List Empty\n");
    return -1;
  }
  if(position ==0)
  {
    int val = s->head->data;
    SingleLinkedListNode *temp = s->head;
    s->head = s->head->next;
    free(temp);
    s->filled -=1;
    return val;
  }
 
  SingleLinkedListNode *temp = s->head;
  SingleLinkedListNode *temp2 = s->head;
  int counter = 0 ;
  while(counter < position)
  {
    temp2 = temp;
    temp = temp->next;
    counter++;
  }
  temp2->next = temp->next;
  int val = temp->data;
  free(temp);
  s->filled -=1;
  return val;
}

// To delete a node from the beginning of the Linked List
int delete_Beginning_LL(SingleLinkedList* s)
{
  return( deleteNode_LL(s, 0) );
}

// To delete a node from the end of the Linked List
int delete_End_LL(SingleLinkedList *s)
{
  return(deleteNode_LL(s,s->filled-1));
}

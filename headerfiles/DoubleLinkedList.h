/*
Madhu 
17241A05F3

TWO TYPES OF Double LINKED LIST are declared. 
one is a Size Limited Double LINKED LIST = DoubleLinkedList_size
and 
other is a Size Unlimited Double Linked List =  DoubleLinkedList
and other corresponding operations

OPERATION                           FUNCTION LIMITED SIZED LIST                                   FUNCTION UNLIMITED LIST
-------------------------------------------------------------------------------------------------------------------------------------------------------------
CREATE LL             || DoubleLinkedList_size* createDoubleLinkedList_size(int length)              DoubleLinkedList* createDoubleLinkedList()
INSERT NODE AT        || void InsertAt_DoubleLL_size(DoubleLinkedList_size* s, int val,int position) void InsertAt_DoubleLL(DoubleLinkedList* s, int val,int position)
INSERT NODE AT BEGIN  || void InsertBeginning_DoubleLL_size(DoubleLinkedList_size* s, int val)       void InsertBeginning_DoubleLL(DoubleLinkedList* s, int val)
INSERT NODE AT END    || void InsertEnd_DoubleLL_size(DoubleLinkedList_size* s, int val)             void InsertEnd_DoubleLL(DoubleLinkedList* s, int val)
DELETE BEGINNING NODE || int delete_Beginning_DoubleLL_size(DoubleLinkedList_size* s)                int delete_Beginning_DoubleLL(DoubleLinkedList* s)
DELETE ENDING NODE    || int delete_End_DoubleLL_size(DoubleLinkedList_size *s)                      int delete_End_DoubleLL(DoubleLinkedList *s)
DELETE NODE AT        || int deleteNode_DoubleLL_size(DoubleLinkedList_size* s,int position)         int deleteNode_DoubleLL(DoubleLinkedList* s,int position)
PRINT ALL ELEMENTS    || void print_DoubleLL_size(DoubleLinkedList_size* s)                          void print_DoubleLL(DoubleLinkedList* s)

*/




#include<stdlib.h>
// Double linked list node
typedef struct DoubleLinkedListNode 
{
  int data ;
  struct DoubleLinkedListNode *next;
  struct DoubleLinkedListNode *prev;
}DoubleLinkedListNode;
//Fixed size Single Linked List 
typedef struct DoubleLinkedList_size
{
  int length;
  int filled;
  DoubleLinkedListNode *head;
}DoubleLinkedList_size;
// Double Linked list without specifications
typedef struct DoubleLinkedList
{
  int filled;
  DoubleLinkedListNode *head;
}DoubleLinkedList;



/*-------------------LINKED LIST APPLICATIONS FOR FIXED SIZE ------------*/


// To create a linked list without any size specifications
DoubleLinkedList_size* createDoubleLinkedList_size(int length)
{
  DoubleLinkedList_size* s = (DoubleLinkedList_size*)malloc(sizeof(DoubleLinkedList_size));
  s->length = length;
  s->filled =0;
  return s;
}

// To find whether the Linked list is Full or not
int isFull_DoubleLL_size(DoubleLinkedList_size* s)
{
  if(s->filled == s->length) return 1;
  else return 0;
}

// To find if the list is Empty or not.
int isEmpty_DoubleLL_size(DoubleLinkedList_size* s)
{
  if(s->filled==0)return 1;
  else return 0;
}

// A generic function to Insert a node at aposition desired to
void InsertAt_DoubleLL_size(DoubleLinkedList_size* s, int val,int position)
{
  if(isFull_DoubleLL_size(s))
  {
    printf("LINKED LIST FULL");
    return;
  }
  if(position == 0)
  {
    DoubleLinkedListNode *newnode = (DoubleLinkedListNode *)malloc(sizeof(DoubleLinkedListNode));
  newnode->data = val;
  newnode->next = s->head;
  newnode->prev = NULL;
  s->head = newnode;
  s->filled += 1;
  return;
  }
  if(position >= s->filled )
  {
    DoubleLinkedListNode *temp = s->head;
    DoubleLinkedListNode *newnode = (DoubleLinkedListNode *)malloc(sizeof(DoubleLinkedListNode));
    newnode->data = val;
    while(temp->next != NULL )
    {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
    s->filled += 1;
    return;
  }
  int counter =0;
  DoubleLinkedListNode *temp = s->head;
  DoubleLinkedListNode *temp2;
  while(counter < position)
  {
    temp2 =temp;
    temp = temp->next;
    counter++;
  }
  DoubleLinkedListNode *newnode = (DoubleLinkedListNode *)malloc(sizeof(DoubleLinkedListNode));
  newnode->data = val;
  newnode->next = temp;
  temp2->next = newnode;
  newnode->prev = temp2;
  temp->prev = newnode;
  s->filled += 1;
  return;
}

// To Insert a node at beginning of te linked list.
void InsertBeginning_DoubleLL_size(DoubleLinkedList_size* s, int val)
{
  InsertAt_DoubleLL_size(s,val,0);
  return;
}

// To Insert a node at end of the linked list
void InsertEnd_DoubleLL_size(DoubleLinkedList_size* s, int val)
{
  InsertAt_DoubleLL_size(s,val,s->filled+1);
  return;
}

// To print all the elements from the Linked List 
void print_DoubleLL_size(DoubleLinkedList_size* s)
{
  DoubleLinkedListNode *temp = s->head;
  while(temp!= NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

//A generic function to delete a node from any position in the Linked List.
int deleteNode_DoubleLL_size(DoubleLinkedList_size* s,int position)
{
  if(isEmpty_DoubleLL_size(s))
  {
    printf("Linked List Empty\n");
    return -1;
  }
  if(position ==0)
  {
    int val = s->head->data;
    DoubleLinkedListNode *temp = s->head;
    s->head = s->head->next;
    s->head->prev = NULL;
    free(temp);
    s->filled -=1;
    return val;
  }
  if(position==s->filled-1)
  {
    DoubleLinkedListNode *temp = s->head;
    DoubleLinkedListNode *temp2 = s->head;
    while(temp->next != NULL)
    {
      temp2 = temp;
      temp=temp->next;
    }
    temp2->next = NULL;
    int c = temp->data;
    free(temp);
    return c;
  }
  DoubleLinkedListNode *temp = s->head;
  DoubleLinkedListNode *temp2 = s->head;
  int counter = 0 ;
  while(counter < position)
  {
    temp2 = temp;
    temp = temp->next;
    counter++;
  }
  temp->next->prev = temp2;
  temp2->next = temp->next;
  int val = temp->data;
  free(temp);
  s->filled -=1;
  return val;
}

// To delete a node from the beginning of the Linked List
int delete_Beginning_DoubleLL_size(DoubleLinkedList_size* s)
{
  return( deleteNode_DoubleLL_size(s, 0) );
}

// To delete a node from the end of the Linked List
int delete_End_DoubleLL_size(DoubleLinkedList_size *s)
{
  return(deleteNode_DoubleLL_size(s,s->filled-1));
}


/*------------------------------ Linked List APPLICATIONS without Size specifications -------------------------------------------------------------------*/



// To create a linked list without any size specifications
DoubleLinkedList* createDoubleLinkedList()
{
  DoubleLinkedList* s = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
  s->filled =0;
  return s;
}

// To find whether the Linked list is Full or not
int isFull_DoubleLL(DoubleLinkedList* s)
{
  if(malloc(sizeof(DoubleLinkedListNode)) == NULL) return 1;
  else return 0;
}

// To find if the list is Empty or not.
int isEmpty_DoubleLL(DoubleLinkedList* s)
{
  if(s->filled==0)return 1;
  else return 0;
}

// A generic function to Insert a node at aposition desired to
void InsertAt_DoubleLL(DoubleLinkedList* s, int val,int position)
{
  if(isFull_DoubleLL(s))
  {
    printf("LINKED LIST FULL\n");
    return;
  }
  if(position == 0)
  {
    DoubleLinkedListNode *newnode = (DoubleLinkedListNode *)malloc(sizeof(DoubleLinkedListNode));
  newnode->data = val;
  newnode->next = s->head;
  newnode->prev = NULL;
  s->head = newnode;
  s->filled += 1;
  return;
  }
  if(position >= s->filled )
  {
    DoubleLinkedListNode *temp = s->head;
    DoubleLinkedListNode *newnode = (DoubleLinkedListNode *)malloc(sizeof(DoubleLinkedListNode));
    newnode->data = val;
    while(temp->next != NULL )
    {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
    s->filled += 1;
    return;
  }
  int counter =0;
  DoubleLinkedListNode *temp = s->head;
  DoubleLinkedListNode *temp2;
  while(counter < position)
  {
    temp2 =temp;
    temp = temp->next;
    counter++;
  }
  DoubleLinkedListNode *newnode = (DoubleLinkedListNode *)malloc(sizeof(DoubleLinkedListNode));
  newnode->data = val;
  newnode->next = temp;
  temp2->next = newnode;
  newnode->prev = temp2;
  temp->prev = newnode;
  s->filled += 1;
  return;
}

// To Insert a node at beginning of te linked list.
void InsertBeginning_DoubleLL(DoubleLinkedList* s, int val)
{
  InsertAt_DoubleLL(s,val,0);
  return;
}

// To Insert a node at end of the linked list
void InsertEnd_DoubleLL(DoubleLinkedList* s, int val)
{
  InsertAt_DoubleLL(s,val,s->filled+1);
  return;
}

// To print all the elements from the Linked List 
void print_DoubleLL(DoubleLinkedList* s)
{
  DoubleLinkedListNode *temp = s->head;
  while(temp!= NULL)
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

//A generic function to delete a node from any position in the Linked List.
int deleteNode_DoubleLL(DoubleLinkedList* s,int position)
{
  if(isEmpty_DoubleLL(s))
  {
    printf("Linked List Empty\n");
    return -1;
  }
  if(position ==0)
  {
    int val = s->head->data;
    DoubleLinkedListNode *temp = s->head;
    s->head = s->head->next;
    s->head->prev = NULL;
    free(temp);
    s->filled -=1;
    return val;
  }
  if(position==s->filled-1)
  {
    DoubleLinkedListNode *temp = s->head;
    DoubleLinkedListNode *temp2 = s->head;
    while(temp->next != NULL)
    {
      temp2 = temp;
      temp=temp->next;
    }
    temp2->next = NULL;
    int c = temp->data;
    free(temp);
    return c;
  }
  DoubleLinkedListNode *temp = s->head;
  DoubleLinkedListNode *temp2 = s->head;
  int counter = 0 ;
  while(counter < position)
  {
    temp2 = temp;
    temp = temp->next;
    counter++;
  }
  temp->next->prev = temp2;
  temp2->next = temp->next;
  int val = temp->data;
  free(temp);
  s->filled -=1;
  return val;
}

// To delete a node from the beginning of the Linked List
int delete_Beginning_DoubleLL(DoubleLinkedList* s)
{
  return( deleteNode_DoubleLL(s, 0) );
}

// To delete a node from the end of the Linked List
int delete_End_DoubleLL(DoubleLinkedList *s)
{
  return(deleteNode_DoubleLL(s,s->filled-1));
}


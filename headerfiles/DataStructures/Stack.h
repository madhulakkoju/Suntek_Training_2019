/*
Madhu
17241A05F3

TWO TYPES OF STACKS are declared. 
one is a Limited Stack = Stack_size
and 
other is an Unlimited stack = Stack 
and other corresponding operations

OPERATION       FUNCTION LIMITED SIZED STACK                     FUNCTION UNLIMITED STACK
----------------------------------------------------------------------------------
CREATE STACK ||  Stack_size* createStack_size(int length)           Stack* createStack()          
PUSH         ||  void Push_into_Stack_size(Stack_size* s, int val)  void Push_into_Stack(Stack* s, int val)
POP          ||  int pop_Stack_size(Stack_size* s)                  int pop_Stack(Stack* s)
PEEK         ||  int peek_Stack_size(Stack_size* s)                 int peek_Stack(Stack* s)
EMPTY ?      ||  int isStack_sizeEmpty(Stack_size* s)               int isStackEmpty(Stack* s)
FULL ?       ||  int isStack_sizeFull(Stack_size* s)                int isStackFull(Stack* s)
PRINT ALL    ||  void print_Stack_size(Stack_size* s)               void print_Stack(Stack* s)
*/
#include<stdlib.h>
// Stack node
typedef struct StackNode 
{
  int data ;
  struct StackNode *prev;
}StackNode;
// Fixed size Stack 
typedef struct Stack_size
{
  int length;
  StackNode *head;
}Stack_size;
// Stack without specifications
typedef struct Stack
{
  StackNode *head;
}Stack;

/*--------------STACK APPLICATIONS-- FOR FIXED SIZE STACK -----------*/
// Create a New stack with length specifications.

int isStack_sizeEmpty(Stack_size* s)
{
  if(s->head==NULL) return 1; // TRUE indicates that it is EMPTY
  else return 0; // FALSE indicates that it is NOT EMPTY
}

int isStack_sizeFull(Stack_size* s)
{
  if(s->length == 0) return 1; // TRUE Indicates that it is FULL
  else return 0; // FALSE indicates that it is not FULL
}

Stack_size* createStack_size(int length)
{
  Stack_size *st = (Stack_size *) malloc(sizeof(Stack_size));
  st->length = length;
  return st;
}
// PUSH OPERATION into Size limited stack.
void Push_into_Stack_size(Stack_size* s, int val)
{
  if(s->length <= 0)
  {
    printf("Stack FULL\n");
  }
  if(s->head == NULL)
  {
    StackNode* g = (StackNode*)malloc(sizeof(StackNode));
    g->data = val;
    g->prev = NULL;
    s->head = g;
    s->length --;
  }
  else
  {
    StackNode* g = (StackNode*)malloc(sizeof(StackNode));
    g->data = val;
    g->prev = s->head;
    s->head = g;
    s->length --;
  }
}
// To print al the elements in the stack
void print_Stack_size(Stack_size* s)
{
  StackNode *k = s->head;
  while(k != NULL)
  {
    printf("%d  ",k->data);
    k = k->prev;
  }
  printf("\n");
}
// peek the top element in stack
int peek_Stack_size(Stack_size* s)
{
  if(isStack_sizeEmpty) return -1;
  else
  return s->head->data;
}
//Pop operation on  a stack
int pop_Stack_size(Stack_size* s)
{
  if(s->length <= 0 || s->head == NULL)
  {
    printf("STACK EMPTY");
    return -1;
  }
  StackNode *k = s->head;
  int val = k->data;
  s->head= s->head->prev;
  free(k);
  s->length++;
  return val;
}

/*--------Stack without SIZE specifications Applications------------*/

int isStackEmpty(Stack* s)
{
  if(s->head==NULL) return 1; // TRUE indicates that it is EMPTY
  else return 0; // FALSE indicates that it is NOT EMPTY
}

int isStackFull(Stack* s)
{
  if(malloc(sizeof(StackNode))==NULL) return 1; // TRUE Indicates that it is FULL
  else return 0; // FALSE indicates that it is not FULL
}

Stack* createStack()
{
  Stack *st = (Stack *) malloc(sizeof(Stack));
  return st;
}
// PUSH OPERATION into Size limited stack.
void Push_into_Stack(Stack* s, int val)
{
  if(isStackFull(s))
  {
    printf("Stack FULL\n");
  }
  if(s->head == NULL)
  {
    StackNode* g = (StackNode*)malloc(sizeof(StackNode));
    g->data = val;
    g->prev = NULL;
    s->head = g;
  }
  else
  {
    StackNode* g = (StackNode*)malloc(sizeof(StackNode));
    g->data = val;
    g->prev = s->head;
    s->head = g;
  }
}

void print_Stack(Stack* s)
{
  StackNode *k = s->head;
  while(k != NULL)
  {
    printf("%d  ",k->data);
    k = k->prev;
  }
  printf("\n");
}

int peek_Stack(Stack* s)
{
  return s->head->data;
}

int pop_Stack(Stack* s)
{
  if(isStackEmpty(s))
  {
    printf("STACK EMPTY");
    return -1;
  }
  StackNode *k = s->head;
  int val = k->data;
  s->head= s->head->prev;
  free(k);
  return val;
}

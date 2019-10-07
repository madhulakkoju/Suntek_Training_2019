/*Re ordering a List in the alternately from beginning and last ending
Rearrange a given linked list in-place.
Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …
You are required to do this in-place without altering the nodes’ values.
Examples:

Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3 
*/

#include <stdio.h>
#include<stdlib.h>
int length=0;
struct node
{
  int val;
  struct node *next;
};
struct node *head;
struct node *temp;
void create_end()
{
  int value;
  scanf("%d",&value);
  temp = (struct node*)malloc(sizeof(struct node));
  if(temp==NULL)
  {
    printf("No Memory present");
    return;
  }
  else
  {
    if(head != NULL)
    {
      struct node *t = malloc(sizeof(struct node));
      t = head;
      while(t->next != NULL)
      {
        t= t-> next;
      }
      t->next = temp;
      temp->next = NULL;
      temp->val = value;
    }
    else
    {
      head = (struct node*)malloc(sizeof(struct node));
        head->val = value;
        head->next = NULL;
    }
  }
}
void display()
{
    if(head != NULL)
    {
      struct node *t = malloc(sizeof(struct node));
      t = head;
      while(t->next != NULL)
      {
        printf(" %d  --> ",t->val);
        t= t-> next;
      }
      printf("%d  --> ",t->val);
    }
    else
    {
      printf("   EMPTY   LIST");
    }
}

void reorder(struct node* h)
{
    struct node* h1,*e,*e1,*t;
    h1 = h->next;
    t= h;
    int n=2;
    while(t->next->next !=NULL)
    {
        t=t->next;n++;
    }
    e1 = t;
    e = e1->next;
    //printf("%d\n",n);
    while(((h!=e)&&n%2==1) || ((h->next != e)&&n%2==0))
    {
        h->next = e;
        h = h1;
        h1 = h1->next;
        if(((h==e)&&n%2==1) || ((h->next == e)&&n%2==0)) break;
        e->next = h;
        e = e1;
        t =h1;
        while(t->next != e)
        {
            t=t->next;n++;
        }
        e1 = t;   
    }
    if(n%2==0)h->next->next = NULL;
    else
    {   e->next = h1;
        h->next = NULL;
    }
    return ;
}
void main() {
  int k;
  scanf("%d",&k);
  while(length < k)
  {
      length++;
       create_end();
  }
  reorder(head);
  display();
}


/*
INPUT 
7                                                                                                                                    
1 2 3 4 5 6 7

OUTPUT
 1  -->  7  -->  2  -->  6  -->  3  -->  5  --> 4  -->    

*/

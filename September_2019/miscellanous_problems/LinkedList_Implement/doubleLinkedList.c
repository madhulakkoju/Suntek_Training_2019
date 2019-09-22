/*
DOUBLE LINKED LIST USING STRUCTURES AND DYNAMIC MEMORY MANAGEMENT MALLOC
*/

#include <stdio.h>
#include<stdlib.h>
int length=0;
struct node
{
  int val;
  struct node *next;
  struct node *prev;
};
struct node *head;
struct node *end;
struct node *temp;


void create_end()
{
  int value;
  printf("Enter Value to node ");
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
      end->next = temp;
      temp->next = NULL;
      temp->prev = end;
      temp->val = value;
      end = temp;
    }
    else
    {
        head = temp;
        head->val = value;
        head->next = NULL;
        head->prev = NULL;
        end = head;
    }
  }
}

void create_beginning()
{
    int value;
  printf("Enter Value to node ");
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
      head->prev = temp;
      temp->next = head;
      temp->prev = NULL;
      temp->val = value;
      head = temp;
    }
    else
    {
        head = temp;
        head->val = value;
        head->next = NULL;
        head->prev = NULL;
        end = head;
    }
  }
}

void create_at( int loc)
{
  int value;
  printf("Enter Value to node ");
  scanf("%d",&value);
  temp = (struct node*)malloc(sizeof(struct node));
  if(temp==NULL)
  {
    printf("No Memory present");
    return;
  }
  else if(loc > length)
  {
    printf(" Location is out of bound\n ");
    return;
  }
  else
  {
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if(loc < length/2)
    {
      t = head;
      for(int i = 0;i<loc-1;i++)
      {
        t=t->next;
      }
      temp->next = t->next;
      temp->prev = t;
      temp->val = value;
      (t->next)->prev = temp;
      t->next = temp;
    }
    else
    {
      t = end;
      for(int i = length;i>=loc;i--)
      {
        t = t->prev;
      }
      temp->val = value;
      temp->prev = t->prev;
      temp->next = t;
      (t->prev)->next = temp;
      t->prev = temp;
      length++;
    }
  }
}

void del_end()
{
    if(head==NULL)
    {
      printf("Empty list\n");
      return;
    }
    else
    {
      end = end->prev;
      free(end->next);
      end->next = NULL;
      length--;
    }
}
void del_beginning()
{
  if(head==NULL)
    {
      printf("Empty list\n");
      return;
    }
    else
    {
      head = head->next;
      free(head->prev);
      head->prev = NULL;
      length--;
    }
}

void display_from_beginning()
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
      printf("%d --- \n",t->val);
    }
    else
    {
      printf("   EMPTY   LIST  \n");
    }
}

void del_at(int loc)
{
  if(loc > length)
  {
    printf(" Location is out of bound\n ");
    return;
  }
  else
  {
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if(loc < length/2)
    {
      t = head;
      for(int i = 0;i<loc;i++)
      {
        t=t->next;
      }
      t->next = (t->next)->next;
      (t->next)->prev = t;
      length++;
    }
    else
    {
      t = end;
      for(int i = length;i>=loc;i--)
      {
        t = t->prev;
      }
      t->prev = (t->prev)->prev;
      (t->prev)->next = t;
      length++;
    }
  }
}

void display_from_end()
{
  if(end != NULL)
  {
    struct node *t = malloc(sizeof(struct node));
    t =end;
    while(t->prev !=NULL)
    {
      printf("%d  --> ",t->val);
      t = t->prev;
    }
    printf("%d  --- \n",t->val);
  }
  else
  {
    printf("Empty List \n");
  }
}

void main() {
  int choice,value,loc;
  printf("ENter Choice: ");
  while(1)
  {
    printf("\n1.Add node at end \n2.delete node at end  \n3.Display from beginning \n4. Display from end\n5.Insert at beginning\n6.delete beginnig\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      printf("Insert at end\n");
      length++;
       create_end();
      break;
      case 2:
      printf("Delete at end\n");
      del_end();
      break;
      case 3:
      printf("Display from Beginning \n ");
      display_from_beginning();
      break;
      case 4:
      printf("Display from end  \n ");
      display_from_end();
      break;
      case 5:
      printf("Crewate at Beginning\n");
      create_beginning();
      break;
      case 6:
      printf("delete at beginning\n");
      del_beginning();
      break;
      case 7:
      printf("create at which location :: \n");
      scanf("%d",&loc);
      create_at(loc);
      break;
      case 8:
      printf("delete at which location ::  \n");
      scanf("%d",&loc);
      del_at(loc);
      break;
      default:display_from_beginning();break;
      
    }
  }
}

/*
INPUT  OUTPUT  ::::::::::::::::




*/

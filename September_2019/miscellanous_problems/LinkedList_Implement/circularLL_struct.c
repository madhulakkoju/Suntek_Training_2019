/*
CIRCULAR LINKED LIST USING STRICTURES AND LINKED LIST

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
struct node *end;
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
      struct node *t = malloc(sizeof(struct node));
      t = head;
      while(t->next != head)
      {
        t= t-> next;
      }
      t->next = temp;
      temp->next = head;
      temp->val = value;
      end = temp;
    }
    else
    {
      head = (struct node*)malloc(sizeof(struct node));
        head->val = value;
        head->next = head;
    }
  }
}
void create_after(int loc)
{
  int value;
  if(loc > length)
  {
    printf("  Location is outof bound \n");
  }
  else
  {
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
      struct node *t = malloc(sizeof(struct node));
      t = head;
      while(loc >= 1)
      {
        loc--;
        t= t-> next;
      }
      temp->val = value;
      temp->next = t->next;
      t->next = temp;
    }
    else
    {
      head = (struct node*)malloc(sizeof(struct node));
        head->val = value;
        head->next = NULL;
    }
  }
  }
}
void del_at(int loc)
{
  if(loc > length)
  {
    printf(" Location out of bound ");
    return;
  }
  else
  {
    if(head==NULL)
    {
      printf("Empty list\n");
    }
    else
    {
      struct node *t = malloc(sizeof(struct node));
      t = head;
      while(loc>2)
      {
        loc--;
        t = t -> next;
      }
      t->next = (t->next)->next;
    }
  }
  length--;
return;
}
void del_begin()
{
    if(head==NULL)
    {
      printf("Empty list\n");
    }
    else
    {
      length--;
      struct node *t = malloc(sizeof(struct node));
      t = head ;
      head = head->next;
      end->next = head;
      t->next = NULL;
      free(t);
    }
  
  length--;
return;
}
void del_end()
{
    if(head==NULL)
    {
      printf("Empty list\n");
    }
    else
    {
      struct node *t = malloc(sizeof(struct node));
      t = head;
      while((t->next)->next!= head)
      {
        t = t -> next;
      }
      free(t->next);
      t->next = head;
      t = end;
      length--;
    }

return;
}
void display()
{
    if(head != NULL)
    {
      struct node *t = malloc(sizeof(struct node));
      t = head;
      while(t->next != head)
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
void create_begin()
{
  struct node *t = malloc(sizeof(struct node));
  int value;
  printf("Enter value ::");
  scanf("%d",&value);
  t-> next = head;
  t -> val = value;
  head = t;
  end -> next = head;
  return;
}
void main() {
  int choice,value,loc;
  printf("ENter Choice: ");
  while(1)
  {
    printf("\n1.Add node\n2.delete node at \n3.add node after \n4. add node before\n5.Add node at beginning\n6.show\n7.Delete from beginning\n8.Delete from end\n9.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
      length++;
       create_end();
      break;
      case 2:
      printf(" Delete at ::");
      scanf("%d",&loc);
      del_at(loc);
      break;
      case 3:
      printf("Afetr which location :: ");
      length++;
      scanf("%d",&loc);
      create_after(loc-1);
      break;
      case 4:
      printf("before which location :: ");
      length++;
      scanf("%d",&loc);
      create_after(loc - 2 );
      break;
      case 5:
      printf("Inserting at start");
      create_begin();
      break;
      case 6:
      display();
      break;
      case 7:
      del_begin();
      break;
      case 8:
      del_end();
      break;
      case 9:
      exit(0);
    }
  }
}



/*
INPUT OUTPUT ::::::::::::

ENter Choice:
1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
1
Enter Value to node 1

1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
1
Enter Value to node 2

1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
4
before which location :: 1
Enter Value to node 10

1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
6
 1  -->  10  --> 2  -->
1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
4
before which location :: 0
Enter Value to node 0

1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
6
 1  -->  0  -->  10  --> 2  -->
1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
7

1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
6
 0  -->  10  --> 2  -->
1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
8

1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit
6
 0  --> 10  -->
1.Add node
2.delete node at
3.add node after
4. add node before
5.Add node at beginning
6.show
7.Delete from beginning
8.Delete from end
9.exit

*/

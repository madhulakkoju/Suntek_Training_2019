// ADD 2 NUMBERS AS LISTS.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  int val;
  struct node *next;
};
struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* head = NULL;

struct node* create(int a,struct node* h)
{
  if(h==NULL)
  {
    struct node *tp = (struct node*)malloc(sizeof(struct node));
    tp->val = a;
    tp->next = NULL;
    h=tp;
    return h;
  }
  else{
struct node *t = NULL;
struct node *tp = (struct node*)malloc(sizeof(struct node));
t= h;
while(t->next !=NULL)
{
  t=t->next;
}
tp->val = a;
tp->next = NULL;
t->next = tp;
return h;
}
}

struct node* add()
{
  int s=0,c=0;
  struct node *end = (struct node*)malloc(sizeof(struct node));
  while((head1 != NULL)&&(head2 != NULL))
  {
    s = head1->val + head2->val +c;
    c =s/10;
    s = s%10;
    head = create(s,head);
    head1 = head1->next;
    head2 = head2->next;
  }
  if(head2 != NULL)
  head1 = head2;

  while(head1 != NULL)
  {
    s = head1->val +c;
    c = s/10;
    s = s%10;
    head = create(s,head);
    head1=head1->next;
  }
  if(c>0)
  {
    while(c>0)
    {
      s=c;
      c =s/10;
      s = s%10;
      head = create(s,head);
    }
  }
  return head;
}

int main(int argc,char* argv[])
{
  int j =1;
  int n = atoi(argv[j++]);
  while(j<=(n+1))
  {
    head1 = create(atoi(argv[j++]),head1);
  }
  n = j + atoi(argv[j]);
  j++;
  while(j<=(n))
  {
    head2 = create(atoi(argv[j++]),head2);
  }
  add();
  while(head->next != NULL )
  {
    printf("%d ",head->val);
    head=head->next;
  }
  printf("%d",head->val);
  return 0;
}

/*
INPUT
3 5 9 7 3 5 9 7 (COMMAND LINE ARGS )
OUTPUT
0 9 5 1
*/

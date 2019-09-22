/*
STACK IMPLEMENTATION USING LINKED LIST WITH PREV POINTER FOR TRAVERSAL
*/

#include <stdio.h>
#include<stdlib.h>
int length=0;
struct node
{
  int val;
  struct node *prev;
};
struct node *head;
struct node *temp;
void push()
{
  int value;
  scanf("%d",&value);
  temp = (struct node*)malloc(sizeof(struct node));
  if(temp==NULL)
  {
    return;
  }
  else
  {
    if(head != NULL)
    {
      temp->prev = head;
      temp->val = value;
      head = temp;
    }
    else
    {
      head = temp;
      head->val = value;
      head->prev =NULL;
    }
  }
}

int pop()
{
	int valu;
	if(head==NULL)
	{
		printf("EMPTY STACK\n");
		return -1;
	}
	temp=head;
	head=head-> prev;
	valu=temp-> val;
	free(temp);
	return valu;
}

int peek()
{
	int valu;
	if(head==NULL)
	{
		printf("EMPTY STACK\n");
		return -1;
	}
	valu=head-> val;
	return valu;
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n1.push\n2.Pop\n3.Peek\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();break;
			case 2:printf("%d  delete\n",pop());break;
			case 3:printf("%d on top\n",peek()); break;
			case 4:exit(0);
		}
	}
}
    
    
/*


*/

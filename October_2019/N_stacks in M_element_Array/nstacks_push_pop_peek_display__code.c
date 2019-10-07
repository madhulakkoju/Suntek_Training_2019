#include <stdio.h>
#include<stdlib.h>

int *arr;
int m,n,length =0;
int *head[10];
int *end;

void display()
{
  for(int i=1;i<=length;i++)
  {
  printf("%d ",arr[i]);
  for(int k=0;k<n;k++)
  if(&arr[i]==(head[k]))
  {
  printf("      \nSTACK %d \n",k+1);
  }
  }
  printf("\n");
}

void push(int val,int stack_cnt)
{
  if(length >= m)
  {
    printf("ARRAY FULL\n");
    return ;
  }
  int st =stack_cnt -1;
  int hh =(int)(head[stack_cnt-1] - &arr[0]);
  for(int g =length+1;g>=hh;g--)
  {
    arr[g+1] = arr[g];
  }
    for(int i = stack_cnt-1;i<n;i++)
  {
    head[i]+=1;
  }
  *head[stack_cnt-1] = val;
  length ++;
  //display();
  printf("-------PUSH------\n");
}

int pop(int stack_cnt)
{
  int hh =(int)(head[stack_cnt-1] - &arr[0])+1;
  int ab = arr[hh-1];
  for(int i = stack_cnt-1;i<n;i++)
  {
    head[i]-=1;
  }
  if(stack_cnt == n)
  {
    length--;
    return ab ;
  }
  while(hh!= length)
  {
    arr[hh-1] = arr[hh];
    hh++;
  }
  length--;
  //display();
  printf("========== POP ===\n");
  return ab;
}

int peek(int stack_cnt)
{
  int hh =(int)(head[stack_cnt-1] - &arr[0])+1;
  int ab = arr[hh-1];
  return ab;
}

int main(void) {
  printf("How many elements in array ? \n");
  scanf("%d",&m);
  arr = (int *) malloc(sizeof(int)*m);
  printf("How many Stacks ?\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    head[i]= &arr[0];
  }
  end = &arr[0];
  int ch,s,v;
  while(1)
  {
      printf("Enter Choice \n 1.PUSH \n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        printf("Push to Which Stack ? : ");
        scanf("%d",&s);
        printf("Push Value ? : ");
        scanf("%d",&v);
        push(v,s);
        break;
        case 2:
        printf("Pop from Which Stack ? : ");
        scanf("%d",&s);
        printf("%d Popped\n",pop(s));
        break;
        case 3:
        printf("Peek from Which Stack ? : ");
        scanf("%d",&s);
        printf("%d is Top Element\n",peek(s));
        break;
        case 4:
        display();
        break;
        case 5:exit(0);
      }
  }

  display();
  return 0;
}
/*
OUTPUT FORMAT
---------------------
INPUT / OUTPUT

How many elements in array ?
20
How many Stacks ?
5
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 1
Push Value ? : 1
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 2
Push Value ? : 2
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 2
Push Value ? : 2
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 3
Push Value ? : 3
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 4
Push Value ? : 4
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 5
Push Value ? : 5
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 5
Push Value ? : 10
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
1
Push to Which Stack ? : 2
Push Value ? : 6
-------PUSH------
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
4
1
STACK 1
2 2 6
STACK 2
3
STACK 3
4
STACK 4
5 10
STACK 5

Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
3
Peek from Which Stack ? : 2
6 is Top Element
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
2
Pop from Which Stack ? : 2
========== POP ===
6 Popped
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
4
1
STACK 1
2 2
STACK 2
3
STACK 3
4
STACK 4
5 5
STACK 5

Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
2
Pop from Which Stack ? : 1
========== POP ===
1 Popped
Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
4
2 2
STACK 2
3
STACK 3
4
STACK 4
5 5
STACK 5

Enter Choice
 1.PUSH
2.POP
3.PEEK
4.DISPLAY
5.EXIT
5






*/

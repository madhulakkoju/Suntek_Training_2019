/*
Maximum in Sliding Window
Problem Introduction
Given a sequence 𝑎1, . . . , 𝑎𝑛 of integers and an integer 𝑚 ≤ 𝑛, find the maximum among {𝑎𝑖
, . . . , 𝑎𝑖+𝑚−1} for
every 1 ≤ 𝑖 ≤ 𝑛 − 𝑚 + 1. A naive 𝑂(𝑛𝑚) algorithm for solving this problem scans each window separately.
Your goal is to design an 𝑂(𝑛) algorithm.
Problem Description
Input Format. The first line contains an integer 𝑛, the second line contains 𝑛 integers 𝑎1, . . . , 𝑎𝑛 separated
by spaces, the third line contains an integer 𝑚.
Constraints. 1 ≤ 𝑛 ≤ 105
, 1 ≤ 𝑚 ≤ 𝑛, 0 ≤ 𝑎𝑖 ≤ 105
for all 1 ≤ 𝑖 ≤ 𝑛.
Output Format. Output max{𝑎𝑖
, . . . , 𝑎𝑖+𝑚−1} for every 1 ≤ 𝑖 ≤ 𝑛 − 𝑚 + 1.
Time Limits.
language C C++ Java Python C# Haskell JavaScript Ruby Scala
time (sec) 1 1 1.5 5 1.5 2 5 5 3
Memory Limit. 512MB.
Sample 1.
Input:
8
2 7 3 1 5 2 6 2
4
Output:
7 7 5 6 6
What to Do
We give hints for three different solutions.
1. Implement a queue using two stacks. Use a queue data structure for sliding a window through a se-
quence: for shifting a window one position to the right, pop the leftmost element of the queue and
push a new element from the new window. A queue can be implemented using two stacks such that
each queue operation takes constant time on average. Then, use your implementation of the stack with
maximum.
2. Preprocess block suffixes and prefixes. Partition the input sequence into blocks of length 𝑚 and pre-
compute the maximum for every suffix and every prefix of each block. Afterwards, the maximum in
each sliding window can be found by considering a suffix and a prefix of two consecutive blocks.
3. Store relevant items in a dequeue. Use a double-ended queue (dequeue) to store elements of the current
window. At the same time, store only relevant elements: before adding a new element drop all smaller
elements.

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

void main()
{
	int n,t,max;
	temp = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		create_end();
	}
	scanf("%d",&t);
	for(int i =0;i<=n-t;i++)
	{max=0;
	temp = head;
		for(int m=0;m<t;m++)
		{
			if(max<temp->val)
			{
				max=temp->val;
			}
			temp=temp->next;
		}
		head =head->next;
		printf("%d ",max);
	}
}


/*
INPUT ::::

8
1 3 5 2 7 5 1 9 
3

OUTPUT ::::
5 5 7 7 7 9 


*/
    

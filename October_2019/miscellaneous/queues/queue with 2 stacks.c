/*A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
Input Format

The first line contains a single integer, , denoting the number of queries.
Each line  of the  subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query ,
but only query  is followed by an additional space-separated value, , denoting the value to be enqueued.

Output Format

For each query of type , print the value of the element at the front of the queue on a new line.

*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* prev;
};
struct node* st1;
struct node* st2;
struct node* push(struct node *head,int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node *))  ;
    newnode->prev = head;
    newnode->val = val;
    return newnode;
}
struct node* pop(struct node* head)
{
    return head->prev;
}

void enq()
{
    int val;
    scanf("%d",&val);
    st1 = push(st1,val);
}
void deq()
{
    if(st2 != NULL)
    {
        st2 = pop(st2);
        return;
    }
    else if(st1 != NULL && st2 == NULL)
    {
        while(st1 != NULL)
        {
            st2 = push(st2,st1 -> val);
            st1 = pop(st1);
        }
        st2 = pop(st2);
        return;
    }
}
void display()
{

    if(st2 != NULL)
    {
        printf("%d\n",st2->val);
    }
    else if(st2 == NULL)
    {
        while(st1 != NULL)
        {
            st2 = push(st2,st1 -> val);
            st1 = pop(st1);
        }
        printf("%d\n",st2->val);
    }
    return;
}
int main() {

    int n =0,a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        switch(a)
        {
            case 1: 
            enq();
            break;
            case 2:
            deq();
            break;
            case 3:
            display();
            break;
        }
    }


    return 0;
}


/*

INPUT

10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2

OUTPUT

14
14

*/

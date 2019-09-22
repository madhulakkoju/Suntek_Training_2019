// STRING ROTATION MINIMUM COST .. STRINGS ARE ROTATED ON BASIS OF TIME % LENGTH(STRING) TYPE.. COMPLUTE MIN VOST TO MAKE ALL STRINGS SAME.

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	char val;
	struct node *next;
};
struct node *head;
struct node *end;
struct node *t;
struct node *q;
void create(char c)
{
	if(head==NULL)
	{
		head = (struct node *)(malloc(sizeof( struct node)));
		head->next = head;
		head->val =c;
		end=head;
	}
	else
	{
		t=(struct node *)(malloc(sizeof(struct node)));
		end->next=t;
		t->next =head;
		t->val= c;
		end=t;
	}
}

int rotate(char a[])
{
	int time1,i,g;
	//char *k = (char *)(malloc(sizeof(char)*strlen(a)));
	char k[10];
	for(i=0;i<strlen(a);i++)
	{
		create(a[i]);
	}
	t=head;
	q=head;
	time1=0;
	while(strcmp(k,a)!=0)
	{
	for(i=0;i<((time1+1) % strlen(a));i++)
		{
		    head=head->next;
		}
		q = head;
		t=head;
			g=0;
			
			while(t->next!= q)
			{
				k[g] = t->val;
			    g++;
			    t = t->next;
			}
			k[g++] = t->val;
			k[g]='\0';
	    time1 ++;
	    
	}
	free(head);
	return time1;
}

 int lcm(int num[],int n)
{
    int min = 9999;
    int i;
    unsigned int l;
    for(i=1;i<n;i++)
    {
        if(min>num[i])
        min = num[i];
    }
    l = min;
    while(1)
    {
        min=0;
        for(i=0;i<n;i++){
        if(l % num[i] != 0)
            min = 1;
        }
        if(min == 0)
        return l;
        l++;
    }
    return l;
}
int main(int argc,char* argv[])
{
    int *num = (int*)(malloc(sizeof(int)*(argc-1)));
    for(int i=1;i<argc;i++)
    {
        num[i-1]=rotate(argv[i]);
        printf("%s",argv[i]);
        printf("%d\n",num[i-1]);
    }
    printf("%d",lcm(num,argc-1));
	return 0;
}

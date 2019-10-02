/*
A given String which consists of lower case english alphabet and brackets.
Reverse the strings in each pait of matching paranthesis, 
starting from th einnermost one.
The result should not contain any brackets.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s
{
char c;
struct s *ptr;
};
int length = 0;
struct s *head;
void push(char c)
{
length ++;
if(head==NULL)
{
head=(struct s*)malloc(sizeof(struct s));
head->ptr = NULL;
head->c =c;
}
else
{
struct s *t = (struct s*)malloc(sizeof(struct s));
t->ptr = head;
t->c= c;
head = t;
}
}

char pop()
{
length--;
char kk = head->c;
head=head->ptr;
return kk;
}

char peek()
{
char kk = head->c;
return kk;
}

void check()
{

int ck = 0;
int nn = 5;
char *c = (char*)malloc(nn*sizeof(char));
while(peek()!='(')
{
if(ck >=nn)
{
c =(char *)realloc(c,(nn+5)*sizeof(char));
nn += 5;
}
c[ck++] = pop();
}
c[ck]='\0';
char ch = pop();
for(int i =0;i<ck;i++)
{
push(c[i]);
}
struct s *t = head;
}

int main()
{
int n;
char *a = (char*)malloc(200*sizeof(char));
scanf("%s",a);
for(int i=0;a[i]!='\0';i++)
{
if(a[i]==')')
check();
else
push(a[i]);
}
int k = 0;
while(head != NULL)
{
a[k++] = head->c;
head = head->ptr;
}a[k]='\0';
for(k=k-1;k>=0;k--)
printf("%c",a[k]);
return 0;
}

/*
INPUT 
(ED(TDO(OC))EL)   

OUTPUT
LETDOCODE  
*/

/*
Take 2 strings as input and perform sum of them both.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *reverse(char str[])
{
int i,j;
for(i=0,j=strlen(str)-1;i<j;++i,j--)
{
char ch = str[i];
str[i]=str[j];
str[j]=ch;
}
return str;
}

char *add(char s1[],char s2[])
{
strcpy(s1,reverse(s1));
strcpy(s2,reverse(s2));
int n1 = strlen(s1);
int n2 = strlen(s2);
char *pp = (char *)malloc(30*sizeof(char));
int c =0,s=0,i=0,k=0;
if(n1>n2)
{
int t = n1; n1 =n2;n2 = t;
char *str;
str = s1; s1 =s2; s2 = str;
}
while(1)
{
if(i<n1 && i<n2)
{
s = ((s1[i]-'0')+(s2[i]-'0')+c);
c = s/10;
s = s%10;
pp[k++]='0'+s;
i++;
}
else if(i>=n1 && i<n2)
{
s = ((s2[i]-'0')+c);
c = s/10;
s = s%10;
pp[k++]='0'+s;
i++;
}
else
{
if(c==0)break;
s = (c);
c = s/10;
s = s%10;
pp[k++]='0'+s;
}
}
pp[k] ='\0';
return reverse(pp);
}

int main()
{
char num1[30],num2[30];
scanf("%s%s",num1,num2);
printf("%s",add(num1,num2));
return 0;
}

/*
input 
1111111111111
2222222222222
output
3333333333333
*/

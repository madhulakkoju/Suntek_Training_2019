// Find the largest Binary number present in the given string 

#include<string.h>
#include<stdio.h>
void printBinary(char s[])
{
int i = 0,z=0,n=0;
for(i=0;i<strlen(s);i++)
if(s[i]=='z') z++;
else if(s[i]=='n') n++;
for(i=0;i<n;i++)
printf("1");
for(i=0;i<z;i++)
printf("1");
for(i=0;i<n;i++)
printf("0");
}
int main()
{
char str[200];
scanf("%s",str);
printBinary(str);
return 0;
}
/*
INPUT

zoenroezoenroe

OUTPUT

1100
*/

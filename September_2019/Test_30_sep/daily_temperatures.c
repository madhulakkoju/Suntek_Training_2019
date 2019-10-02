/*
A list of daily temperatures T , return a list such that for each day in the list , tells you how many days you would have to wait until a warmer temperature.
If there is no futire day in which this is possible, put 0 instead.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  int *a = (int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  int i=0,j=0,c=0;
  for(i=0;i<n;i++)
  {
  c=0;
  for(j=i+1;j<n;j++)
  {
  if(a[j]>a[i])
  {
  c = j-i;
  break;
  }
  }
if(i==n-1)
printf("%d",c);
else
printf("%d ",c);
}
return 0;
}

/*

INPUT 
8                                                                
73 74 75 71 69 72 76 73 
OUTPUT
1 1 4 2 1 1 0 0       
*/

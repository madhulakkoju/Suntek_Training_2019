
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv)
{
  int n = atoi(argv[1]);
  int *a = (int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
  {
  a[i] = atoi(argv[i+2]);
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

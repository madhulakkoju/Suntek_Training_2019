#include <stdio.h>
#include<stdlib.h>

void check(int arr[],int n)
{
  int i,ac,a,b;
  long long int sum_in=0,fac=1,prod_in=1;
  for(i=0;i<n;i++)
  {
    sum_in += (int)arr[i];
    fac *= (i+1);
    prod_in *= arr[i];
  }
  ac = n*(n+1)/2;
  a = ((sum_in - ac)/((fac/prod_in)-1));
  b = ac - sum_in + a;
  printf("%d  %d",a,b);
}

int main(void) {
  int n;
  scanf("%d",&n);
  int *arr = (int *)(malloc(n*(sizeof(int))));
  for(int i = 0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  check(arr,n);
  return 0;
}

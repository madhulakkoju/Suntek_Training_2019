// RECURSION

#include <stdio.h>
long int fac=1;
long int fact(long int n)
{
	if(n==1)
	return 1;
	else
	return n*fact(n-1);
}
int main()
{
	long int v;
	scanf("%lu",&v);
	printf("%lu",fact(v));
	return 0;
}

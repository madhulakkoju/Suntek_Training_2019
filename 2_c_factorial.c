 // ITERATION 
 
 #include <stdio.h>
long int fac=1;
long int fact(long int n)
{
	while(n>=1)
	{
		fac*= n;
		n--;
	}
	return fac;
}
int main()
{
	long int v;
	scanf("%lu",&v);
	printf("%lu",fact(v));
	return 0;
}

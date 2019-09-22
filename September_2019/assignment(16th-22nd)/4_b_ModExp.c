// ITERATION

    #include <stdio.h>
long int fac=1;
long int pow(long int n,int p)
{printf("see");
	int k=p;
	if(p>0)
	{
	while(k>=1)
	{
		fac*= n;
		k--;
	}
	}
	else
		fac=1/pow(n,-p);
	return fac;
}
int main()
{
	long int v;
	int a,b;
	scanf("%lu",&v);
	scanf("%d",&a);
	scanf("%d",&b);
	v=5;
	printf("hi %lu %d ",v,a);
	printf("%d",pow(v,a)%b);
	return 0;
}

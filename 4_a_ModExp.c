// RECURSION

   #include <stdio.h>
 
long int pow(double n,int p)
{printf("see");
long int fac=1;
	int k=p;
	if(k>1)
	{
		fac =n* pow(n,--k);
	}
	else if(p==1)
		return n;
	else if(p<0)
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
	printf("hi %lu %d %d",v,a,b);
	printf("%d",pow(v,a)%b);
	return 0;
}

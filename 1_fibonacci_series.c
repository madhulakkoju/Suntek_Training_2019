
#include <stdio.h>
long int a,b,sum,val;
void fibo(int num)
{
	if(num>=3)
	fibo(num-1);
	if(num==2)
	{
		a=0;
		b=1;
		sum=a+b;
		printf("%lu %lu ",a,b);
	}
	else
	{
		a=b;
		b=sum;
		sum=a+b;
		printf("%lu ",b);
	}
}
void fibo_upto(int n)
{
	if(n==0)
	{
	a=0;
	b=1;
	sum=a+b;
	printf("%lu %lu ",a,b);
	}
	else
	{
		a=b;
		b=sum;
		sum=a+b;
		printf("%lu ",b);
	}
	if(sum <=val)
	fibo_upto(sum);
	return;
}
int main()
{
	int ch;
	printf("1. FIBONACCI UPTO N\n2.N FIBONACCI SERIES ELEMENTS\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("upto ?? ");
			scanf("%lu",&val);
			fibo_upto(0);
			break;
		case 2:
			printf("how many elements of fibo??");
			scanf("%lu",&val);
			fibo(val);
	}
	return 0;
}

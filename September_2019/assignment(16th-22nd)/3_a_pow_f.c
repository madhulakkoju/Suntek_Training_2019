// RECURSION

  #include <stdio.h>
 
 double pow(double n,int p)
{printf("see");
double fac=1;
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
	double v;
	int a;
	scanf("%f",&v);
	scanf("%d",&a);
	v=5;
	printf("hi %f %d ",v,a);
	printf("%f",pow(v,a));
	return 0;
}

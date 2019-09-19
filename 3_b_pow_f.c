  // ITERATION
  
   #include <stdio.h>
 double fac=1;
 double pow(long int n,int p)
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
	double v;
	int a;
	scanf("%f",&v);
	scanf("%d",&a);
	printf("hi %f %d ",v,a);
	printf("%f",pow(v,a));
	return 0;
}

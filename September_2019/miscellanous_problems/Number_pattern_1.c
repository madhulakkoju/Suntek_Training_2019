  
  
  
    #include <stdio.h>
int main()
{
	int a=1,n,i,j,even_diff=0,odd_diff,even_ch;
	scanf("%d",&n);
	odd_diff=2*n-1;
	for(i=0;i<n;i++)
	{	a=i+1;
		even_ch=even_diff;
		for(j=0;j<=i;j++)
		{	printf("%d ",a);
			if(j%2==0)
			a+=odd_diff;
			else if(j%2!=0)
			a+=even_ch;
			even_ch -=2;
		}
		printf("\n");
		even_diff +=2;
		odd_diff -=2;
	}
	return 0;
}

/*
OUTPUT::

1 
2 19 
3 18 20 
4 17 21 34 
5 16 22 33 35 
6 15 23 32 36 45 
7 14 24 31 37 44 46 
8 13 25 30 38 43 47 52 
9 12 26 29 39 42 48 51 53 
10 11 27 28 40 41 49 50 54 55 


*/

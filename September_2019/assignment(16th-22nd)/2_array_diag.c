// GIVE AN ARRAY OF DIAGONALS IN N*N MATRIX

  #include <stdio.h>
int arr[4][4]={
	1,2,3,4,
	5,6,7,8,
	9,10,11,12,
	13,14,15,16
};

void diags(int n)
{
	int i,j,k,a,b,c,d,g,x[10][10]={0};
	for(i=0;i<n;i++)
	{
		a=i;
		b=0;
		k=0;
		while(a>=0)
		{
			x[i][k++]=arr[a][b];
			a--;
			b++;
		}
	}
	b=n-1;
	g=1;
	for(i=2*n-2;i>=n;i--)
	{
		c=n-1;
		d=b;
		k=0;
		for(j=0;j<g;j++)
		{
			x[i][j]=arr[c][d];
			c--;
			d++;
		}
		b--;
		g++;
	}
	for(i=0;i<=2*n-2;i++)
	{
		for(j=0;j<=n;j++)
			printf("%d ",x[i][j]);
		printf("\n");
	}
}

int main()
{int h=0,j,i,k,n=4;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
printf("\n---------\n");
	diags(4);
	
	return 0;
}

/*
OUTPUT FORMAT
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16 

---------
1 0 0 0 0 
5 2 0 0 0 
9 6 3 0 0 
13 10 7 4 0 
14 11 8 0 0 
15 12 0 0 0 
16 0 0 0 0 



*/

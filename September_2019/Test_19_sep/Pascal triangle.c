    //. PPRINT THE KTH ROW IN PAACALS TRIANGLE

  #include <stdio.h>
int main()
{
	int *arr[2];
	int k,i,j,a,b;
	scanf("%d",&k);
	if(k<0)
	{
		printf("INVALID INPUT ");
		exit(0);
	}
	arr[0] =(int *)(malloc(sizeof(int)*k));
	arr[1] =(int *)(malloc(sizeof(int)*k));
	arr[0][0]=1;
	for(i=0;i<=k;i++)
	{
		if(i%2==0)
		{
			a=0;
			b=1;
		}
		else
		{
			a=1;
			b=0;
		}
		for(j=0;j<=i;j++)
		{
			if(j==0)
			arr[b][j]=arr[a][j];
			else
			arr[b][j]=arr[a][j] + arr[a][j-1];
		}
	}
	
	if(k%2==0)
	a=1;
	else
	a=0;
	
	for(i=0;i<=k;i++)
	printf("%d ",arr[a][i]);
	return 0;
}

/*
OUTPUT
7
1 7 21 35 35 21 7 1 
*/

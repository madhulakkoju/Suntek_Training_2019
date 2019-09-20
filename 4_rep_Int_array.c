// repeated element in array
  
  
  #include <stdio.h>

int check(int arr[],int n)
{
	int sum=0,k=0,ac,min=9999;
	for(int i =0;i<n;i++)
	{
		if(arr[i]>0)
		{
		sum += (n- arr[i]);
		k++;
		
		if(min>arr[i])
		{
			min=arr[i];
		}
		}
	}
	ac=k*(k+1)/2 -(min*(min-1)/2);
	if(sum==0 && n>1)
		return 1;
	else
		return ac-sum;
}

int main()
{
	
	int n;
	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("%d ", check(arr,n));
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,n,k;
    scanf("%d",&n);
    int *a = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    if(a[0]>k)
    {
        printf("0");return 0;
    }
    else if(a[n-1]<k)
    {
        printf("%d",n);
        return 0;
    }
    for(i =0;i<n-1;i++)
    {
        if(a[i]<k && a[i+1]>=k)
        {
            printf("%d",i+1);
            return 0;
        }
    }
    return 0;
}


   
//   LONGEST PALINDROME SUBSTRING IN A STRING HIVEN BY COMMAND LINE ARGUMENTS
   
     #include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *ar;
int check(int i, int j)
{
	for(;i<=j;i++,j--)
	if(ar[i]!=ar[j])
	return 0;
	return 1;
}
int main(int argc, char* argv[])
{
	ar =(char *)(malloc(sizeof(char)*10));
	strcpy(ar,argv[1]);
	int i,j,maxl=0,maxi=0,maxj=0;
	int s = strlen(ar);
		for(i=0;i<=j;i++)
		{
			for(j=s-1;j>0;j--)
	{
			if(maxl<(j-i+1))
			{
				if(check(i,j))
				{
					maxi=i;
					maxj=j;
					maxl=(j-i+1);
				}
			}
		}
	}
	for(;maxi<=maxj;maxi++)
	printf("%c",ar[maxi]);
	return 0;
}
